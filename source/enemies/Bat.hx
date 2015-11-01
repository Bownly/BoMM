package enemies;

import flixel.FlxG;
import flixel.FlxObject;
import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;
import flixel.util.FlxPoint;
import weapons.Bullet;

/**
 * ...
 * @author ...
 */
class Bat extends EnemyTemplate
{
	private var XSPEED:Int = -30;
	private var GUN_DELAY:Float = 3;
	private var BULLET_SPEED:Int = 100;
	private var _HP:Int = 2;
	private var _bullets:FlxGroup;
	private var _cooldown:Float;	
	public var rangeX:Int = 64;
	public var postShotTimer:Float = 0;
	private var palette:Int = 0;	
	private var echoSpeed:Int = 200;
	private var perchDirection:Int = FlxObject.NONE;
	var ogY:Float;
	var newY:Float;
	var echoY:Float;
	var echoTimer:Float = -1;
	var hasBeenHit:Bool = false;
	
	public function new(X:Float, Y:Float, ThePlayer:Player, DropsGrp:FlxTypedGroup<Drops>, Bullets:FlxGroup, Palette:Int) 
	{
		super(X, Y, ThePlayer, _HP, DropsGrp);
		loadGraphic("assets/images/bat.png", true, 16, 16);
		width = 16;
		height = 8;
		offset = new FlxPoint(0, 4);
		
		ogY = Y;
		palette = Palette;
		
		_bullets = Bullets;
		_cooldown = 0;
		
		facing = FlxObject.LEFT; 
		flipX = true;	
		y -= 4;
		
		var o = 6; // the amount of sprites in the sheet per color
		switch (palette)
		{
			case(Reg.G):
				o *= 0;
			case(Reg.C):
				o *= 1;
			case(Reg.M):
				o *= 2;
			case(Reg.Y):
				o *= 3;
		}
		animation.add("idle", [0 + o]);
		animation.add("echo", [1 + o]);
		animation.add("flap", [2 + o, 3 + o, 4 + o, 3 + o], 9, true);
		
		velocity.y = -1;
		GUN_DELAY = 2.5;

	}
	
	
	public override function update():Void
	{
		if (isOnScreen()) 
		{
			
			if (_player.x > x)
			{
				facing = FlxObject.RIGHT;
				flipX = false;
			}
			else if (_player.x < x)
			{
				facing = FlxObject.LEFT;
				flipX = true;
			}
			
			if (this.isTouching(FlxObject.CEILING))
			{
				flipY = false;
				perchDirection = FlxObject.FLOOR;
			}
			else if (this.isTouching(FlxObject.FLOOR))
			{
				flipY = true;
				perchDirection = FlxObject.CEILING;
			}
			
			
			if (perchDirection == FlxObject.FLOOR || perchDirection == FlxObject.CEILING)
			{
				if (postShotTimer > 0)
				{
					animation.play("echo");
					postShotTimer -= FlxG.elapsed;	
				}
				else
				{
					animation.play("idle");
					shoot();
				}
			}
			else
			{
				animation.play("flap");
			}

			// physics stuff for yellow bats
			if (echoTimer >= 0 && !hasBeenHit)
				echoTimer += FlxG.elapsed;
			if (hasBeenHit)
			{
				echoY = (echoTimer * echoSpeed) / 4;
				newY = echoY + ogY;
			/*	trace("OGY:   " + ogY);
				trace("echoY: " + echoY);
				trace("newY:  " + newY);*/
			}
				
//			if (palette == Reg.Y && animation.name == "flap")
			if (palette == Reg.Y && animation.name == "flap" && 100 > 1000)  // todo: this is broked
			{
				// todo: fix up this movement, dude
				if (y > (newY - 10))
					velocity.y = -40;
				else if (y < (newY + 10))
					velocity.y = 40;
				else
					velocity.y = 0;
				
				if (_cooldown > GUN_DELAY)
				{
					var bullet = new weapons.Bullet(x + 4, y, echoSpeed, facing, 1, 256);
					_bullets.add(bullet);
					_cooldown = 0; 
					postShotTimer = .67;
				}
			}
			
		}
		
		_cooldown += FlxG.elapsed;
		
		super.update();
	}
	
	
	
	public function shoot():Void
	{
		if (_cooldown > GUN_DELAY)
		{	
			switch(palette)
			{
				case Reg.G:  // grey
				{
					// okay, so this isn't technically shooting. So sue me
					if (perchDirection == FlxObject.CEILING)
					{
						velocity.y = echoSpeed * -0.5;
						flipY = false;
						perchDirection = FlxObject.NONE;
					}
					else
					{
						velocity.y = echoSpeed;
						flipY = false;
					}

				}
				case Reg.C:  // cyan
				{
					var bullet = new weapons.Echo(x + 4, y, echoSpeed, perchDirection, 1, 256, flipY);
					_bullets.add(bullet);
				}
				case Reg.M:  // magenta
				{
					var bullet = new weapons.Echo(x + 4, y, echoSpeed, perchDirection, 1, 256, flipY);
					_bullets.add(bullet);
				}
				case Reg.Y:  // yellow
				{
					var bullet = new weapons.Bullet(x + 4, y, echoSpeed, perchDirection, 1, 256);
					_bullets.add(bullet);
					_cooldown = 0; 
					postShotTimer = .67;
				}
				
			}
			// reset the shot clock
			_cooldown = 0; 
			postShotTimer = .67;

		}

	}
	
	
	public override function collideBadBullet(B:weapons.Bullet):Void
	{
		if (B.name == "echo" && B.reflectable == false)
		{
			hasBeenHit = true;
			B.kill();
			if (palette == Reg.C)
			{
				//shootShot();
				var bullet = new weapons.Bullet(x + 4, y, echoSpeed, perchDirection, 1, 256);
				_bullets.add(bullet);
				_cooldown = 0; 
				postShotTimer = .67;
			}
			else
			{
				perchDirection = FlxObject.NONE;
				if (flipY)
					flipY = false;
				velocity.y = B.velocity.y * -0.5;
			}
			
		}
	}
	
}
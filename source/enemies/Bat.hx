package enemies;

import flixel.FlxG;
import flixel.FlxObject;
import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;
import flixel.util.FlxPoint;

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
	private var echoSpeed:Int = 40;
	
	public function new(X:Float, Y:Float, ThePlayer:Player, DropsGrp:FlxTypedGroup<Drops>, Bullets:FlxGroup, Palette:Int) 
	{
		super(X, Y, ThePlayer, _HP, DropsGrp);
		loadGraphic("assets/images/bat.png", true, 16, 16);
		width = 16;
		height = 10;
		offset = new FlxPoint(0, 0);
		
		palette = Palette;
		
		_bullets = Bullets;
		_cooldown = 0;
		
		facing = FlxObject.LEFT; 
		flipX = true;	
		
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
		GUN_DELAY = .67;

	}
	
	
	public override function update():Void
	{
		if (isOnScreen()) 
		{
			
			//velocity.y = 100;
			
			if (this.isTouching(FlxObject.ANY))
			{
				velocity.y = -1;
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
			
				
				/*
				shotTimer -= FlxG.elapsed;
				if shottimer >= 0 
					shoot();
					
				*/
		}
		else
		{
			animation.play("flap");
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
					var bullet = new weapons.Bullet(x + 8, y, echoSpeed, FlxObject.FLOOR, 1, 256);
					_bullets.add(bullet);
				}
				case Reg.C:  // cyan
				{
					var bullet = new weapons.Bullet(x + 8, y, echoSpeed, FlxObject.FLOOR, 1, 256);
					_bullets.add(bullet);
				}
				case Reg.M:  // magenta
				{
					var bullet = new weapons.Bullet(x + 8, y, echoSpeed, FlxObject.FLOOR, 1, 256);
					_bullets.add(bullet);
			}
				case Reg.Y:  // yellow
				{
					var bullet = new weapons.Bullet(x + 8, y, echoSpeed, FlxObject.FLOOR, 1, 256);
					_bullets.add(bullet);
				}
				
			}
			// reset the shot clock
			_cooldown = 0; 
			postShotTimer = .67;

		}

	}
	
	
	public function echoCollide():Void
	{
		/*if palette == turret
		{
			shoot();
		}
		else
		{
			move in direction of the bullet
		}
		
		*/
	}
	
}
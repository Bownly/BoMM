package enemies;

import flixel.FlxG;
import flixel.FlxObject;
import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;
import weapons.Spore;

/**
 * ...
 * @author me
 */
class Mush extends EnemyTemplate
{
	private var XSPEED:Int = -40;
	private var GRAVITY:Int = 9800;
	private var GUN_DELAY:Float = 3;
	private var BULLET_SPEED:Int = 100;
	private var _HP:Int = 2;
	private var _bullets:FlxGroup;
	private var _cooldown:Float;	
	public var rangeX:Int = 64;
	public var ogX:Float;
	public var postShotTimer:Float = 0;
	private var palette:Int = 0;
	private var colorString:String = "grey";
	
	private var sporeSpeed:Int = 40;
	
	public function new(X:Float, Y:Float, ThePlayer:Player, DropsGrp:FlxTypedGroup<Drops>, Bullets:FlxGroup, Palette:Int) 
	{
		super(X, Y, ThePlayer, _HP, DropsGrp);
		loadGraphic("assets/images/mush.png", true, 16, 16);
		width = 16;
		height = 16;
		
		palette = Palette;
		
		
		ogX = X;
		_bullets = Bullets;
		_cooldown = 0;
		
		facing = FlxObject.RIGHT; 
		flipX = true;	
		
		animation.add("walk0", [1, 0, 1, 2], 3, true);
		animation.add("walk1", [5, 4, 5, 6], 3, true);
		animation.add("walk2", [9, 8, 9, 10], 3, true);
		animation.add("walk3", [13, 12, 13, 14], 3, true);
		animation.add("jizz0", [1, 3, 3, 3, 3], 6, false);
		animation.add("jizz1", [5, 7, 7, 7, 7], 6, false);
		animation.add("jizz2", [9, 11, 11, 11, 11], 6, false);
		animation.add("jizz3", [13, 15, 15, 15, 15], 6, false);
		
	}
	
	public function changeColor():Void
	{
		// This mess is just for testing
		if (FlxG.keys.anyJustPressed(["C"])) 
		{
			palette += 1;
			if (palette > 3)
				palette = 0;
			switch(palette)
			{
				case 0:
					colorString = "grey";
				case 1:
					colorString = "yellow";
				case 2:
					colorString = "cyan";
				case 3:
					colorString = "magenta";
				
			}
		 
		}
	}
	
	
	public override function update():Void
	{
		if (isOnScreen()) 
		{
			if (postShotTimer <= 0)
			{
				velocity.x = XSPEED;			
				animation.play("walk" + palette);
				if (isTouching(FlxObject.WALL) || (Math.abs(ogX - x) >= rangeX))
					turnAround();
			}
			shoot();
			
			changeColor();
			
			super.update();
		}
	}
	
	public function shoot():Void
	{
		
		if (_cooldown > GUN_DELAY)
		{	
			switch(palette)
			{
				case 0:  // grey
				{
					// spores up
					velocity.x = 0;  // case dependent
					animation.play("jizz" + palette);  // case dependent
					var bullet = new weapons.Spore(x + 8, y + 8, sporeSpeed, FlxObject.CEILING, 1, 256);
					_bullets.add(bullet);
					
				}
				case 1:  // cyan
				{
					// spores forward
					velocity.x = 0;  // case dependent
					animation.play("jizz" + palette);  // case dependent
					var bullet = new weapons.Spore(x + 8, y, sporeSpeed, FlxObject.CEILING + facing, 1, 256);
					_bullets.add(bullet);
					
				}
				case 2:  // magenta
				{
					// spores up and to the sides
					velocity.x = 0;  // case dependent
					animation.play("jizz" + palette);  // case dependent
					var bullet = new weapons.Spore(x + 8, y, sporeSpeed, FlxObject.CEILING + FlxObject.LEFT, 1, 256);
					var bullet2 = new weapons.Spore(x + 8, y, sporeSpeed, FlxObject.CEILING + FlxObject.RIGHT, 1, 256);
					_bullets.add(bullet);
					_bullets.add(bullet2);
					
				}
				case 3:  // yellow
				{
					// walks around and leaves a constant spore trail
					//velocity.x = 0;  // case dependent
					animation.play("jizz" + palette);  // case dependent
					var bullet = new weapons.Spore(x + 8, y, sporeSpeed, FlxObject.CEILING + facing, 1, 256);
					_bullets.add(bullet);
					
				}
				
			}
			
			
			
			
			
			
			// reset the shot clock
			_cooldown = 0; 
			postShotTimer = .33;
		}
		_cooldown += FlxG.elapsed;
		postShotTimer -= FlxG.elapsed;
	}
		
		
	
	public function turnAround():Void
	{
		XSPEED = -XSPEED;
		
		if (facing == FlxObject.LEFT)
		{
			facing = FlxObject.RIGHT; 
			flipX = true;
			this.x -= 2;
		}
		else 
		{
			facing = FlxObject.LEFT; 
			flipX = false;	
			this.x += 2;
		}
		return;
	}
}



/*
 * if (postShotTimer <= 0)
			{
				velocity.x = XSPEED;
				
				animation.play("walk");
				
			}
			else
			{
				velocity.x = 0;
				animation.play("jizz");
				postShotTimer -= FlxG.elapsed;	
			}
			acceleration.y = GRAVITY;
			
			if (isTouching(FlxObject.WALL) || (Math.abs(ogX - x) >= rangeX))
				turnAround();
			
		
			if (_cooldown > GUN_DELAY)
			{	
				var bulletX:Int = Math.floor(x);
				var bulletY:Int = Math.floor(y + 4);
				var bullet = new weapons.Bullet(x - 8, y + 8, 500, FlxObject.CEILING, 1, 256);
				_bullets.add(bullet);
				
				// reset the shot clock
				_cooldown = 0; 
				postShotTimer = .33;
			}
				
			_cooldown += FlxG.elapsed;
			super.update();
		*/
package enemies;

import flixel.FlxG;
import flixel.FlxObject;
import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;
import weapons.Spore;

/**
 * ...
 * @author me
 * 
 * todo
 * 1. 
 * 
 */
class Mush extends EnemyTemplate
{
	private var XSPEED:Int = -30;
	private var GRAVITY:Int = 9800;
	private var GUN_DELAY:Float = 3;
	private var BULLET_SPEED:Int = 100;
	private var _HP:Int = 6;
	private var _bullets:FlxGroup;
	private var _cooldown:Float;	
	public var rangeX:Int = 32;
	public var ogX:Float;
	public var postShotTimer:Float = 0;
	private var palette:Int = Reg.G;	
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
		
		facing = FlxObject.LEFT; 
		flipX = true;	
		
		animation.add("walk" + Reg.G, [1, 0, 1, 2], 4, true);
		animation.add("walk" + Reg.C, [5, 4, 5, 6], 4, true);
		animation.add("walk" + Reg.M, [9, 8, 9, 10], 4, true);
		animation.add("walk" + Reg.Y, [13, 12, 13, 14], 4, true);
		animation.add("spore" + Reg.G, [1, 3, 3, 3, 3], 6, false);
		animation.add("spore" + Reg.C, [5, 7, 7, 7, 7], 6, false);
		animation.add("spore" + Reg.M, [9, 11, 11, 11, 11], 6, false);
		animation.add("spore" + Reg.Y, [13, 15, 15, 15, 15], 6, false);
		
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
			
			changeColor(); // just for testing
			
			if (palette == 3)
				GUN_DELAY = .67;
			else
				GUN_DELAY = 3;
			super.update();
		}
	}
	

	public function changeColor():Void  // This mess is just for testing
	{
		
		if (FlxG.keys.anyJustPressed(["C"])) 
		{
			palette += 1;
			if (palette > 3)
				palette = 0;
		 
		}
	}
		
	public function shoot():Void
	{
		if (_cooldown > GUN_DELAY)
		{	
			switch(palette)
			{
				case Reg.G:  // grey
				{
					// spores up
					velocity.x = 0;  // case dependent
					animation.play("spore" + palette);  // case dependent
					var bullet = new weapons.Spore(x, y + 8, sporeSpeed, FlxObject.CEILING, 1, 256, 0);
					_bullets.add(bullet);
				}
				case Reg.C:  // cyan
				{
					// spores forward
					velocity.x = 0;  // case dependent
					animation.play("spore" + palette);  // case dependent
					var bullet = new weapons.Spore(x, y, sporeSpeed * 0.5, FlxObject.CEILING + facing, 1, 256, 1);
					var bullet2 = new weapons.Spore(x, y, sporeSpeed * 0.75, FlxObject.CEILING + facing, 1, 256, 1);
					var bullet3 = new weapons.Spore(x, y, sporeSpeed * 1, FlxObject.CEILING + facing, 1, 256, 1);
					_bullets.add(bullet);
					_bullets.add(bullet2);
					_bullets.add(bullet3);
				}
				case Reg.M:  // magenta
				{
					// spores up and to the sides
					velocity.x = 0;  // case dependent
					animation.play("spore" + palette);  // case dependent
					var bullet = new weapons.Spore(x, y, sporeSpeed, FlxObject.CEILING + FlxObject.LEFT, 1, 256, 2);
					var bullet2 = new weapons.Spore(x, y, sporeSpeed, FlxObject.CEILING + FlxObject.RIGHT, 1, 256, 2);
					var bullet3 = new weapons.Spore(x, y + 8, sporeSpeed, FlxObject.CEILING, 1, 256, 2);
					_bullets.add(bullet);
					_bullets.add(bullet2);
					_bullets.add(bullet3);
				}
				case Reg.Y:  // yellow
				{
					// walks around and leaves a constant spore trail
					var direction:Int;
					if (facing == FlxObject.RIGHT)
						direction = FlxObject.LEFT;
					else
						direction = FlxObject.RIGHT;
					var bullet = new weapons.Spore(x - 8, y, sporeSpeed, FlxObject.CEILING + direction, 1, 256, 3);
					_bullets.add(bullet);
				}
				
			}
			// reset the shot clock
			_cooldown = 0; 
			if (palette != Reg.Y)
				postShotTimer = .67;
		}
		_cooldown += FlxG.elapsed;
		postShotTimer -= FlxG.elapsed;
	}

	public function turnAround():Void
	{
		XSPEED = -XSPEED;
		
		if (facing == FlxObject.RIGHT)
		{
			facing = FlxObject.LEFT; 
			flipX = true;
			this.x -= 2;
		}
		else 
		{
			facing = FlxObject.RIGHT; 
			flipX = false;	
			this.x += 2;
		}
		return;
	}
}

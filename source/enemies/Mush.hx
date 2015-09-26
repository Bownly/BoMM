package enemies;

import flixel.FlxG;
import flixel.FlxObject;
import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;

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
	public var rangeX:Int = 80;
	public var ogX:Float;
	public var postShotTimer:Float = 0;

	
	public function new(X:Float, Y:Float, ThePlayer:Player, DropsGrp:FlxTypedGroup<Drops>, Bullets:FlxGroup) 
	{
		super(X, Y, ThePlayer, _HP, DropsGrp);
		loadGraphic("assets/images/mush.png", true, 16, 16);
		//loadGraphic("assets/images/shakuhachiman.png", true, 16, 16);
		width = 16;
		height = 16;
		
		ogX = X;
		_bullets = Bullets;
		_cooldown = 0;
		
		facing = FlxObject.RIGHT; 
		flipX = true;	
		
		animation.add("walk", [1, 0, 1, 2], 3, true);
		animation.add("walk", [5, 4, 5, 6], 3, true);
		animation.add("walk", [9, 8, 9, 10], 3, true);
		animation.add("walk", [13, 12, 13, 14], 3, true);
		animation.add("jizz", [1, 3, 3, 3, 3], 6, false);
		animation.add("jizz", [5, 7, 7, 7, 7], 6, false);
		animation.add("jizz", [9, 11, 11, 11, 11], 6, false);
		animation.add("jizz", [13, 15, 15, 15, 15], 6, false);
		
	}
	
	public override function update():Void
	{
		if (isOnScreen()) 
		{
			if (postShotTimer <= 0)
			{
				velocity.x = XSPEED;			
				animation.play("walk");
				if (isTouching(FlxObject.WALL) || (Math.abs(ogX - x) >= rangeX))
					turnAround();
			}
			else
				shoot();
			
			
			super.update();

		}
	}
	
	public function shoot():Void
	{
		velocity.x = 0;  // case dependent
		animation.play("jizz");  // case dependent
		postShotTimer -= FlxG.elapsed;	
		
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
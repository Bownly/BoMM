package enemies;
import enemies.EnemyTemplate;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.group.FlxGroup;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.math.FlxPoint;

/**
 * ...
 * @author ...
 */
class Bombox extends enemies.EnemyTemplate
{
	//private var XSPEED:Int = 25;
	private var XSPEED:Int = 0;
	private var GRAVITY:Int = 9800;
	private var GUN_DELAY:Float = 1.5;
	private var BULLET_SPEED:Int = 100;
	private var _HP:Int = 2;

	private var _bullets:FlxGroup;
	private var _cooldown:Float;
	var palette:Int;
	
	public function new(X:Float, Y:Float, ThePlayer:Player, Spawner:EnemySpawner, DropsGrp:FlxTypedGroup<Drops>, Enemies:FlxGroup, Bullets:FlxGroup, Palette:Int) 
	{
		super(X, Y, ThePlayer, Spawner, _HP, DropsGrp);
		loadGraphic("assets/images/bombox.png", true, 32, 32);
		width = 18;
		height = 17;
		offset = new FlxPoint(7, 15);
		
		palette = Palette;
		_bullets = Bullets;
		_cooldown = 0;
		
		flipX = true;
		
		var o = 2; // the amount of sprites in the sheet per color
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
		
		animation.add("hide", [0 + o]);
		animation.add("open", [1 + o]);		
	}
	
	public override function update(elapsed:Float):Void
	{
		if (isOnScreen()) 
		{
			velocity.x = velocity.y = 0;
			
			var xdistance:Float = _player.x - x;
			var ydistance:Float = _player.y - y; 
			var distancesquared:Float = xdistance * xdistance + ydistance * ydistance; 
			acceleration.y = GRAVITY;
			
			if (distancesquared < 16000) 
			{
				if (_player.x < x)
				{
					// The sprite is facing the opposite direction than flixel is expecting, so hack it into the right direction
					
					facing = FlxObject.RIGHT; 
					flipX = false;
					velocity.x = -XSPEED;
				}
				else if (_player.x > x)
				{
					facing = FlxObject.LEFT;
					flipX = true;
					velocity.x = XSPEED;
				}
				if (_player.facing == FlxObject.RIGHT)
					animation.play("hide"); 
				else
					animation.play("open");
			}		
			else 
			{
				animation.play("open");
				shoot(_player);
			}
			_cooldown += FlxG.elapsed;
			super.update(elapsed);
		}
	}
	
	private function shoot(P:Player):Void 
	{
		// Bullet code will go here
		var bulletX:Int = Math.floor(x);
		var bulletY:Int = Math.floor(y + 4);
		
		if (_cooldown > GUN_DELAY)
		{	
			var bullet = new weapons.Bullet(x - 8, y + 8, 500, FlxObject.LEFT, 1, 256, palette, facing);
			_bullets.add(bullet);
			
			
			// reset the shot clock
			_cooldown = 0; 
		}
	}
	
	public override function takeDamage(damage:Int):Void
	{
		if (animation.name == "open")
		{
			// TODO quick blinking effect
			// TODO sound of being hurt
			_health -= damage;
			
			if (_health <= 0)
				kill();
		}
	}
	
}
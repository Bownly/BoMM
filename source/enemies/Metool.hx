package enemies;
import enemies.EnemyTemplate;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;

/**
 * ...
 * @author ...
 */
class Metool extends enemies.EnemyTemplate
{
	//private var XSPEED:Int = 25;
	private var XSPEED:Int = 0;
	private var GRAVITY:Int = 9800;
	private var GUN_DELAY:Float = 1.5;
	private var BULLET_SPEED:Int = 100;
	private var _HP:Int = 2;

	private var _bullets:FlxGroup;
	private var _cooldown:Float;
	
	public function new(X:Float, Y:Float, ThePlayer:Player, DropsGrp:FlxTypedGroup<Drops>, Bullets:FlxGroup) 
	{
		super(X, Y, ThePlayer, _HP, DropsGrp);
		loadGraphic("assets/images/metool.png", true, 16, 16);
		width = 16;
		height = 16;
		
		_bullets = Bullets;
		_cooldown = 0;
		
		animation.add("hide", [0]);
		animation.add("open", [1]);		
	}
	
	public override function update():Void
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
			super.update();
		}
	}
	
	private function shoot(P:Player):Void 
	{
		// Bullet code will go here
		var bulletX:Int = Math.floor(x);
		var bulletY:Int = Math.floor(y + 4);
		
		if (_cooldown > GUN_DELAY)
		{	
			var bullet = new weapons.Bullet(x - 8, y + 8, 500, FlxObject.LEFT, 1, 256);
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
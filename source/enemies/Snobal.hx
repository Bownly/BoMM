package enemies;
import enemies.EnemyTemplate;
import flixel.FlxObject;
import flixel.group.FlxGroup;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.math.FlxPoint;

/**
 * ...
 * @author ...
 */
class Snobal extends enemies.EnemyTemplate
{
	private var XSPEED:Int = 25;
	private var GRAVITY:Int = 9800;
	private var _HP:Int = 1;

	
	public function new(X:Float, Y:Float, ThePlayer:Player, Spawner:EnemySpawner, DropsGrp:FlxTypedGroup<Drops>) 
	{
		super(X, Y, ThePlayer, Spawner, _HP, DropsGrp);
		loadGraphic("assets/images/snobal.png", true, 16, 16);
		width = 16;
		height = 16;
	//	offset = new FlxPoint(2, 2);
		
		animation.add("idle", [0], 10, true);
		animation.add("roll", [0, 1, 2, 3], 15, true);
		
	}
	
	public override function update(elapsed:Float):Void
	{
		velocity.x = velocity.y = 0;
		
		var xdistance:Float = _player.x - x;
		var ydistance:Float = _player.y - y; 
		var distancesquared:Float = xdistance * xdistance + ydistance * ydistance; 
		acceleration.y = GRAVITY;
		
		
		if (distancesquared < 32000) 
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
		}
		
		// Animation
		if ((velocity.x == 0) && (velocity.y == 0)) 
		{ 
			animation.play("idle"); 
		}
		else 
		{
			animation.play("roll");
		}
		
		super.update(elapsed);
	}
	
	

}
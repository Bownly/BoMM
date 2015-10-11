package enemies;
import enemies.EnemyTemplate;
import flixel.FlxObject;
import flixel.group.FlxTypedGroup;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;

/**
 * ...
 * @author ...
 */

 // TODO: This dude needs walls to bump into or will run off the edge...
 
class Snaake extends enemies.EnemyTemplate
{
	//private var XSPEED:Int = 25;
	private var XSPEED:Int = 50;
	private var XSPEED2:Int = 100;
	private var GRAVITY:Int = 9800;
	private var _HP:Int = 1;
	
	public function new(X:Float, Y:Float, ThePlayer:Player, DropsGrp:FlxTypedGroup<Drops>) 
	{
		super(X, Y, ThePlayer, _HP, DropsGrp);
		//loadGraphic("assets/images/notey.png", true, 16, 16);
		loadGraphic("assets/images/crawler.png", true, 16, 8);
		width = 16;
		height = 8;
		
		facing = FlxObject.LEFT; 
		//flipX = true;	
		
		animation.add("walk", [0, 1], 8, true);
		
	}
	
	public override function update():Void
	{
		if (isOnScreen()) 
		{			
			velocity.x = XSPEED;
			
			animation.play("walk");
			acceleration.y = GRAVITY;
			
			if (isTouching(FlxObject.WALL))
				turnAround();
				
			if ((_player.y + _player.height) == (y + height))
				XSPEED = 150;
			else
				XSPEED = 50;
			
			if (flipX == true)
				XSPEED *= -1;
				
			super.update();
		}
	}
	
	public function turnAround():Void
	{
		XSPEED = -XSPEED;
		
		if (facing == FlxObject.RIGHT)
		{
			facing = FlxObject.LEFT; 
			flipX = true;	
			this.x += XSPEED/25;
		}
		else 
		{
			facing = FlxObject.RIGHT; 
			flipX = false;
			this.x += XSPEED/25;
		}
		return;
	}
}
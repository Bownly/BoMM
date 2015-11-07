package enemies;
import enemies.EnemyTemplate;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.group.FlxTypedGroup;

/**
 * ...
 * @author ...
 */
class Notey extends enemies.EnemyTemplate
{
	private var XSPEED:Int = -75;
	private var GRAVITY:Int = 9800;
	private var _HP:Int = 1;
	
	public function new(X:Float, Y:Float, ThePlayer:Player, Spawner:EnemySpawner, DropsGrp:FlxTypedGroup<Drops>) 
	{
		super(X, Y, ThePlayer, Spawner, _HP, DropsGrp);
		loadGraphic("assets/images/notey.png", true, 16, 16);
		//loadGraphic("assets/images/shakuhachiman.png", true, 16, 16);
		width = 16;
		height = 16;
		
		facing = FlxObject.RIGHT; 
		flipX = true;	
		
		animation.add("walk", [0, 1, 0, 2], 3, true);
		
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
			
			super.update();
		}
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
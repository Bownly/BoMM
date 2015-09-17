package;
import flixel.FlxObject;
import flixel.group.FlxTypedGroup;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxRandom;

/**
 * ...
 * @author ...
 * TODO: make them not collide with walls, lol
 */
class BabyBurd extends EnemyTemplate
{
	private var XSPEED:Int = 50;
	private var YSPEED:Int = 25;
	private var _HP:Int = 1;
	
	public function new(X:Float, Y:Float, ThePlayer:Player, DropsGrp:FlxTypedGroup<Drops>) 
	{
		super(X, Y, ThePlayer, _HP, DropsGrp);
		YSPEED = FlxRandom.intRanged( -10, 10);
		velocity.y = YSPEED;
		
		loadGraphic("assets/images/burdsmall.png", true, 8, 8);
		width = 8;
		height = 8;
		
		//allowCollisions = FlxObject.NONE;
		
		animation.add("flap", [0, 1], 10, true);
		
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
	
	public override function update():Void
	{	
		animation.play("flap");
		
		super.update();
	}

}
package enemies;

import flixel.FlxObject;
import flixel.group.FlxTypedGroup;
import flixel.util.FlxPoint;

/**
 * ...
 * @author ...
 */
class Stalagmite extends EnemyTemplate
{
	private var GRAVITY:Int = 700;
	private var _HP:Int = 1;
	private var palette:Int = Reg.G;	
	var ogY:Float;
	var activated:Bool = false;

	public function new(X:Float, Y:Float, ThePlayer:Player, Spawner:EnemySpawner, DropsGrp:FlxTypedGroup<Drops>) 
	{
		super(X, Y, ThePlayer, Spawner, _HP, DropsGrp);
		loadGraphic("assets/images/stalagmite.png", true, 16, 16);
		width = 14;
		height = 16;
		offset = new FlxPoint(0, 0);
		
		ogY = Y;
		
		animation.add("idle", [0]);
		animation.add("idle_legs", [4, 4, 4, 4, 3], 5, true);
		animation.add("jump", [5]);
		animation.add("fall", [6]);
	}
	
	public override function update():Void
	{
		if (isOnScreen()) 
		{
			//velocity.x = velocity.y = 0;
			
			var xdistance:Float = Math.abs(_player.x - x);
			acceleration.y = GRAVITY;
			
			if (xdistance < 24 && y >= ogY) 
			{
				activated = true;
				velocity.y = -400;
			}		
			
			resolveAnimations();
			
		}
			super.update();
	}

	public function resolveAnimations():Void
	{
		if (activated && velocity.y == 0)
			animation.play("idle_legs");
		else if (!activated && velocity.y == 0)
			animation.play("idle");
			
		if (velocity.y > 0)
			animation.play("fall");
		if (velocity.y < 0)
			animation.play("jump");
	}
	
	
}
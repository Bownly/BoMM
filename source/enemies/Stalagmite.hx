package enemies;

import flixel.FlxObject;
import flixel.group.FlxGroup;
import flixel.math.FlxPoint;
import flixel.FlxG;
/**
 * ...
 * @author ...
 */
class Stalagmite extends EnemyTemplate
{
	private var GRAVITY:Int = 700;
	private var _HP:Int = 20;
	private var palette:Int = Reg.G;	
	var ogY:Float;
	var activated:Bool = false;
	var jumpTimer:Float = 1;
	var jumpDuration:Float = 0.5;
	
	public function new(X:Float, Y:Float, ThePlayer:Player, Spawner:EnemySpawner, DropsGrp:FlxTypedGroup<Drops>) 
	{
		super(X, Y, ThePlayer, Spawner, _HP, DropsGrp);
		loadGraphic("assets/images/stalagmite.png", true, 16, 16);
		width = 12;
		height = 14;
		offset = new FlxPoint(2, 1);
		
		// ghetto offset
		x += 2;
		y += 1;
		
		ogY = Y;
		
		animation.add("idle", [0]);
		animation.add("idle_legs", [4, 4, 4, 4, 3], 5, true);
		animation.add("jump", [5]);
		animation.add("fall", [6]);
	}
	
	public override function update(elapsed:Float):Void
	{
		if (isOnScreen()) 
		{
			//velocity.x = velocity.y = 0;
			
			var xdistance:Float = Math.abs(_player.x - x);
			acceleration.y = GRAVITY;
			
			//jump
			if (xdistance < 24 && y >= ogY && jumpTimer >= jumpDuration) 
			{
				activated = true;
				velocity.y = -400;
				jumpTimer = 0;
			}		
			
			if ( y >= ogY)
				jumpTimer += FlxG.elapsed;
				
			resolveAnimations();
			
		}
			super.update(elapsed);
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
package enemies;

import flixel.FlxObject;
import flixel.group.FlxGroup;
import flixel.math.FlxPoint;

/**
 * ...
 * @author ...
 */
class Stalactyke extends EnemyTemplate
{
	private var GRAVITY:Int = 700;
	private var _HP:Int = 1;
	private var palette:Int = Reg.G;	
	var ogY:Float;
	var activated:Bool = false;

	public function new(X:Float, Y:Float, ThePlayer:Player, Spawner:EnemySpawner, DropsGrp:FlxTypedGroup<Drops>) 
	{
		super(X, Y, ThePlayer, Spawner, _HP, DropsGrp);
		loadGraphic("assets/images/stalagtyke.png", true, 16, 16);
		width = 14;
		height = 16;
		offset = new FlxPoint(0, 0);
		
		ogY = Y;
		
		animation.add("idle", [2]);
		animation.add("fall", [3]);
		animation.add("flail", [4, 5, 6, 5], 6, true);
	}
	
	public override function update(elapsed:Float):Void
	{
		if (isOnScreen()) 
		{
			var xdistance:Float = Math.abs(_player.x - x);
			if (xdistance < 30 && !activated) 
			{
				activated = true;
				velocity.y = 300;
			}		
			
			resolveAnimations();
			
		}
			super.update(elapsed);
	}

	public function resolveAnimations():Void
	{
	
		if (velocity.y == 0 && activated == false)
			animation.play("idle");
		else if (velocity.y > 0)
			animation.play("fall");
		if (velocity.y == 0 && activated)
			animation.play("flail");
	}
	
	
}
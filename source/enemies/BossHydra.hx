package enemies;

import flixel.FlxObject;
import flixel.group.FlxGroup;
import flixel.math.FlxPoint;

/**
 * ...
 * @author ...
 */
class BossHydra extends EnemyTemplate
{
	private var GRAVITY:Int = 700;
	private var _HP:Int = 1;
	private var palette:Int = Reg.G;	
	var ogY:Float;
	var activated:Bool = false;

	public function new(X:Float, Y:Float, ThePlayer:Player, Spawner:EnemySpawner, DropsGrp:FlxTypedGroup<Drops>) 
	{
		super(X, Y, ThePlayer, Spawner, _HP, DropsGrp);
		loadGraphic("assets/images/hydra.png", true, 80, 64);
		loadGraphic("assets/images/boss_hydra_rightside.png", true, 32, 64);
		width = 14;
		height = 64;
		offset = new FlxPoint(0, -8);
		
		ogY = Y;
		
		animation.add("idle", [0, 1, 2, 3, 4, 5], 7, true);
		animation.add("idle", [0, 1, 2, 4, 5, 6], 7, true);
		animation.play("idle");
	}

	
	
}
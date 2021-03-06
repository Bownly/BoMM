package enemies;

import flixel.group.FlxGroup;
import flixel.math.FlxPoint;

/**
 * ...
 * @author ...
 */
class BossHydraA extends EnemyTemplate
{
	private var GRAVITY:Int = 700;
	private var _HP:Int = 1;
	private var palette:Int = Reg.G;	
	var ogY:Float;
	var activated:Bool = false;

	public function new(X:Float, Y:Float, ThePlayer:Player, Spawner:EnemySpawner, DropsGrp:FlxTypedGroup<Drops>) 
	{
		super(X, Y, ThePlayer, Spawner, _HP, DropsGrp);
		loadGraphic("assets/images/boss_hydra_a.png", true, 64, 64);
		width = 14;
		height = 64;
		offset = new FlxPoint(0, -8);
		
		ogY = Y;
		
		animation.add("idle", [0, 1, 2, 3, 2, 1], 6, true);
		animation.play("idle");
	}

	
}
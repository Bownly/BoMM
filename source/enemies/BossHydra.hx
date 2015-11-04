package enemies;

import flixel.FlxObject;
import flixel.group.FlxTypedGroup;
import flixel.util.FlxPoint;

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

	public function new(X:Float, Y:Float, ThePlayer:Player, DropsGrp:FlxTypedGroup<Drops>) 
	{
		super(X, Y, ThePlayer, _HP, DropsGrp);
		loadGraphic("assets/images/hydra.png", true, 80, 64);
		width = 14;
		height = 64;
		offset = new FlxPoint(0, -8);
		
		ogY = Y;
		
		animation.add("idle", [0]);

	}

	
	
}
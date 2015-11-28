package enemies;

import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;

/**
 * ...
 * @author ...
 */
class Flowerguy extends EnemyTemplate
{
	private var _HP:Int = 2;
	public function new(X:Float, Y:Float, ThePlayer:Player, Spawner:EnemySpawner, DropsGrp:FlxTypedGroup<Drops>, Bullets:FlxGroup, Palette:Int) 
	{
		super(X, Y, ThePlayer, Spawner, _HP, DropsGrp);
		
		_palette = Palette;
		
		loadGraphic("assets/images/enemy_flower.png", true, 16, 16);
		var o = 4; // the amount of sprites in the sheet per color
		switch (_palette)
		{
			case(Reg.G):
				o *= 0;
			case(Reg.C):
				o *= 1;
			case(Reg.M):
				o *= 2;
			case(Reg.Y):
				o *= 3;
		}
		trace("palette for flowerguy: " + _palette);

		animation.add("idle", [3 + o, 1 + o, 3 + o, 2 + o], 4, true);
		animation.play("idle");
	}
	
}
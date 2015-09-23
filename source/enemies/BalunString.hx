package enemies;

import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.group.FlxTypedGroup;

/**
 * ...
 * @author me
 */
class BalunString extends EnemyTemplate
{
	//facing = 0;
	public var _moving:Int;
	private var _HP:Int = 9999;

	public function new(X:Float=0, Y:Float=0, ThePlayer:Player, DropsGrp:FlxTypedGroup<Drops>) 
	{
		super(X, Y, ThePlayer, _HP, DropsGrp);
		loadGraphic("assets/images/balun.png", true, 16, 16);
		width = 0;
		height = 0;
		
		_moving = FlxObject.NONE;
		
		animation.add("idle", [8, 9], 3, true);
		animation.add("left", [10, 11], 6, true);
		animation.add("right", [12, 13], 6, true);		
	}
	
	public override function update():Void
	{
		if (alive == true)
		{
			if (_moving == FlxObject.NONE)
				animation.play("idle");
			else if (_moving == FlxObject.LEFT)
			{
				animation.play("left");
			}
			else if (_moving == FlxObject.RIGHT)
			{
				animation.play("right");
			}
			super.update();
		}
	}
}
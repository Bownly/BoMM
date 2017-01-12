package;

import flixel.FlxSprite;
import flixel.math.FlxPoint;

/**
 * ...
 * @author ...
 */
class Spike extends FlxSprite
{

	public var dmg:Int = 1;
	
	public function new(X:Float=0, Y:Float=0, Damage:Int) 
	{
		super(X, Y);
		
		loadGraphic(AssetPaths.spike__png, false, 12, 12);
		//width = 5;
		//height = 5;
		//offset = new FlxPoint(9, 6);
		
		animation.add("stupid", [0]);
		animation.play("stupid");
		dmg = Damage;
	}
	
	public override function update(elapsed:Float):Void
	{
		super.update(elapsed);
	}
}
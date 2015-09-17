package;

import flixel.FlxSprite;
import flixel.util.FlxPoint;

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

		loadGraphic(AssetPaths.spike__png, false, 16, 16);
		width = 16;
		height = 15;
		offset = new FlxPoint(0, 1);
		
		
		dmg = Damage;
	}
	
}
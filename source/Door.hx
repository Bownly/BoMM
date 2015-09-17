package;
import flixel.FlxSprite;

/**
 * ...
 * @author ...
 */
class Door extends FlxSprite
{

	public function new(inX:Int=0, inY:Int=0) 
	{
		super(inX, inY);
		loadGraphic("assets/images/burdsmall.png", true, 8, 8);
	}
	
}
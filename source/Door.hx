package;
import flixel.FlxSprite;

/**
 * ...
 * @author ...
 */
class Door extends FlxSprite
{

	public var palette:Int;
	public var levelId:Int;
	
	public function new(inX:Int=0, inY:Int=0, ID:Int, Palette:Int) 
	{
		super(inX, inY);
		loadGraphic("assets/images/door.png", true, 16, 32);
		
		animation.add("" + Reg.G, [0]);
		animation.add("" + Reg.C, [1]);
		animation.add("" + Reg.M, [2]);
		animation.add("" + Reg.Y, [3]);
		
		palette = Palette;
		
		levelId = ID;
		
		animation.play("" + palette);
	}
	
}
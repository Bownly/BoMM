package;

/**
 * ...
 * @author ...
 */
class ColorBlock
{
	var _color:String;
	

	public function new(X:Float=0, Y:Float=0, Color:String) 
	{
		super(X, Y);
		
		_color = Color;
		
		loadGraphic(AssetPaths.picross_colors__png, false, 60, 60);
		animation.add("red", [0]);
		animation.add("yellow", [1]);
		animation.add("blue", [2]);
		animation.add("purple", [3]);
		animation.add("orange", [4]);
		animation.add("green", [5]);
		animation.add("white", [6]);

		animation.play(_color);
	}
	
}
package;

import flixel.FlxSprite;
import flixel.util.FlxRandom;

/**
 * ...
 * @author ...
 */
class Decoration extends FlxSprite
{
	public var id:Int = 0;
	public var price:Int = 0;
	public var free:Bool = true;
	
	/* Legend for drops:
	 * 0 = Crystal
	 * 12 = Fossil
	 * 24 = Grass
	 * 36 = Tiny tree
	 */
	
	public function new(X:Float=0, Y:Float=0, Index:Int, ?SpeciesCount:Int=1) 
	{
		super(X, Y);
		loadGraphic(AssetPaths.decorations__png, false, 16, 16);
		
		x = X;
		y = Y;
		id = Index;
		
		var color_offset = FlxRandom.intRanged(0, Reg.colorArray.length - 1);
		var style_offset = FlxRandom.intRanged(0, 2);
		
		id = id + (4 * style_offset) + color_offset;
		animation.add("idle", [id], 5, true);
		
		
	}
	
	public override function update():Void
	{
		if (isOnScreen())
		{
			animation.play("idle");
			super.update();
		}
	}
	
}
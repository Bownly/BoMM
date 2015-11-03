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
	 * Crystal:      id = 000, species = 3, size = 16 x 16, frames = 1
	 * Fossil:       id = 012, species = 3, size = 16 x 16, frames = 1
	 * Big rock:     id = 024, species = 1, size = 32 x 32, frames = 1
	 * Cave dirt 1:  id = 032, species = 1, size = 16 x 16, frames = 1
	 * Cave dirt 2:  id = 044, species = 1, size = 16 x 16, frames = 1
	 * Cave torch:   id = 072, species = 1, size = 48 x 48, frames = 3
	 * 
	 */
	
	public function new(X:Float=0, Y:Float=0, Index:Int, SpeciesCount:Int=3, Size:Int=1, Frames:Int=1) 
	{
		super(X, Y);
		
		
		loadGraphic(AssetPaths.cave_decorations__png, false, 16*Size, 16*Size);
		
		x = X;
		y = Y;
		id = Std.int(Index / (Size * Size));
		
		var color_offset = FlxRandom.intRanged(0, Reg.colorArray.length - 1);
		var species_offset = FlxRandom.intRanged(0, SpeciesCount -1);
		
		id = id + (4 * species_offset) + (color_offset * Frames);
		var framesArray:Array<Int> = [];
		for (f in 0...(Frames))
		{
			framesArray.push(id + f);
		}
		
		animation.add("idle", framesArray, 5, true);
		
		animation.play("idle");
			
	}
	
}
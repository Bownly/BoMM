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
	 * 
	 * Cave:
	 * Crystal:      id = 000, species = 3, size = 16 x 16, frames = 1
	 * Fossil:       id = 012, species = 3, size = 16 x 16, frames = 1
	 * Boulder:      id = 024, species = 1, size = 32 x 32, frames = 1
	 * Cave dirt 1:  id = 032, species = 1, size = 16 x 16, frames = 1
	 * Cave dirt 2:  id = 044, species = 1, size = 16 x 16, frames = 1
	 * Forest mush:  id = 048, species = 3, size = 16 x 16, frames = 1
	 * Cave torch:   id = 072, species = 1, size = 48 x 48, frames = 3
	 * 
	 * 
	 * Forest:
	 * Flower:       id = 000, species = 4, size = 16 x 32, frames = 1
	 * TinyTree:     id = 032, species = 2, size = 32 x 32, frames = 1
	 * Grass:        id = 064, species = 4, size = 16 x 16, frames = 1
	 * BigTree:      id = 080, species = 2, size = 64 x 80, frames = 1
	 * Cave mush:    id = 180, species = 3, size = 16 x 16, frames = 1
	 */
	
	public function new(SheetName:String = "cave", X:Float = 0, Y:Float = 0, 
		Index:Int, SpeciesCount:Int=3, Xsize:Int=1, Ysize:Int=1, Frames:Int=1) 
	{
		super(X, Y);
		
		
		loadGraphic("assets/images/" + SheetName + "_decorations.png", false, 16*Xsize, 16*Ysize);
		
		x = X;
		y = Y;
		id = Std.int(Index / (Xsize * Ysize));
		
		var _palette = FlxRandom.intRanged(0, Reg.colorArray.length - 1);
		_palette = Reg.colorArray[_palette];
		var color_offset:Int = 0;
		switch (_palette)
		{
			case(Reg.G):
				color_offset = 0;
			case(Reg.C):
				color_offset = 1;
			case(Reg.M):
				color_offset = 2;
			case(Reg.Y):
				color_offset = 3;
		}
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
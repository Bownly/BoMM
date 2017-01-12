package;

import flixel.FlxG;
import flixel.FlxSprite;

/**
 * ...
 * @author ...
 */
class JumpPuff extends FlxSprite
{

	
	public function new(X:Float=0, Y:Float=0, Palette:Int) 
	{
		super(X, Y);
		loadGraphic("assets/images/jumppuff.png", true, 16, 16);
		
		var o = 3; // the amount of sprites in the sheet per color
		o *= Palette;		
		animation.add("puff", [0, 1, 2, 3, 5, 6], 35, false);		
		animation.play("puff");
	}
	
	
	public override function update(elapsed:Float):Void
	{
		super.update(elapsed);
//		FlxG.watch.add(animation.getFrameIndex, "?" + animation.name);
		if (animation.finished)
			this.destroy();
	
	}
	
}
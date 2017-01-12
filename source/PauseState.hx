package;

import flixel.FlxG;
import flixel.FlxSubState;
import flixel.text.FlxText;
import flixel.util.FlxColor;

/**
 * ...
 * @author ...
 */
class PauseState extends FlxSubState
{

	public function new(BGColor:Int=FlxColor.TRANSPARENT) 
	{
		super(BGColor);
		var text:FlxText = new FlxText(175, 120, 0, "PAUSED", 16);
		//add(new FlxText(150, 150, 0, "PAUSED", 16)); 		
		text.scrollFactor.set(0, 0);
		
		add(text);
	}
	
	public override function update(elapsed:Float)
	{
		if (FlxG.keys.anyJustReleased(["P"]))
		{
			//this.destroy();
			this.close();
		}
		super.update(elapsed);
	}
	
}
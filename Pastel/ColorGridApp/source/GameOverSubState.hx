package;

import flixel.FlxSubState;
import flixel.text.FlxText;
import flixel.util.FlxColor;

/**
 * ...
 * @author ...
 */
class GameOverSubState extends FlxSubState
{

	public function new(Score:Int = 0, BGColor:Int=FlxColor.WHITE) 
	{
		trace("score:" + Score);
		
		super(BGColor);
		
	}
	
}
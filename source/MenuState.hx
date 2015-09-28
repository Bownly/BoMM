package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;

/**
 * A FlxState which can be used for the game's menu.
 */
class MenuState extends FlxState
{
	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{
		super.create();
		add(new FlxText(6, 9, 200, "Hello, HaxeFlixel!"));
		FlxG.camera.bgColor = 0xFFBADA55;
		
		add(new FlxButton(0, 25, "Start", gotoNextStates));
	}
	
	function gotoNextStates():Void
	{
		//FlxG.switchState(new PlayState());
		FlxG.switchState(new PlayState());
	}
	
	/**
	 * Function that is called when this state is destroyed - you might want to 
	 * consider setting all objects this state uses to null to help garbage collection.
	 */
	override public function destroy():Void
	{
		super.destroy();
	}

	/**
	 * Function that is called once every frame.
	 */
	override public function update():Void
	{
		gotoNextStates();

		if (FlxG.keys.anyPressed(["SPACE"])) 
		{
			gotoNextStates();
		}
		super.update();
	}	
}
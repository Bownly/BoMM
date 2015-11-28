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
	
	var _btnNewGame:FlxButton;
	
	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{
		_btnNewGame = new FlxButton(50, 50, "New Game", onNewGameTrigger);
//		_btnNewGame.loadGraphic("assets/images/mctest.png", false, 160, 16);
		
		add(_btnNewGame);
		super.create();
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
		super.update();
		
	}	
	
	
	private function onNewGameTrigger():Void
	{
		FlxG.switchState(new PlayState());

	}
	
}
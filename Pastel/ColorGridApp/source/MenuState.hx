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
	var _txtTitle:FlxText;
	
	var sub:GameOverSubState;  // kill me before syncing
	
	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{
		_btnNewGame = new FlxButton(50, 50, Strings.newGame, onNewGameTrigger);
		_btnNewGame.loadGraphic("assets/images/button.png", 128, 16);
		_btnNewGame.x = FlxG.width / 2 - _btnNewGame.width / 2;
		_btnNewGame.y = FlxG.height * .6;
		
		_txtTitle = new FlxText(0, FlxG.height * .25, FlxG.width, Strings.title, 24);
		_txtTitle.alignment = "center";
		
		add(_btnNewGame);
		add(_txtTitle);		
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
		sub = new GameOverSubState(69);
		this.openSubState(sub);
		//FlxG.switchState(new PlayState());

	}
	
}
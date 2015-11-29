package;

import flixel.addons.editors.ogmo.FlxOgmoLoader;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;
import flixel.text.FlxText;
import flixel.tile.FlxTilemap;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;

/**
 * A FlxState which can be used for the game's menu.
 */
class CreditsState extends FlxState
{
	var colorDefault = 0xffffff;
	var colorSelected = 0x0099FF;
	var selectedSelection = 0;
	
	var _txtTwitter:FlxText;
	var _txtLD:FlxText;
	var _txtTitle:FlxText;
	var _txtFurigana:FlxText;
	var _txtControls:FlxText;
	
	var _txtCredits:FlxText;


	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{
		FlxG.camera.bgColor = 0x0000000;
		
		_txtTitle = new FlxText(0, 0, FlxG.width, "Pi X RPG", 32);
		_txtTitle.alignment = "center";
		_txtTitle.y = (FlxG.height - _txtTitle.height * 3) / 2;
		
		_txtFurigana = new FlxText(0, 0, FlxG.width, "(Credits)", 8);
		_txtFurigana.setPosition(120, _txtTitle.y - _txtFurigana.height);
		
		_txtTwitter = new FlxText(0, 0, 0, "@Bownly", 8);
		_txtTwitter.y = FlxG.height - _txtTwitter.height;
		_txtLD = new FlxText(0, _txtTwitter.y, 0, "mini Ludum Dare 63", 8);
		_txtLD.x = FlxG.width - _txtLD.width;
		
		_txtCredits= new FlxText(8, _txtTitle.y + _txtTitle.height + 16, FlxG.width - 8, "-Some tiles modified from art by Sharm from http://opengameart.org/content/tiny-16-basic \n-Some other tiles and NPC art lifted and modified from a GBC DBZ game and various NES/GBC Dragon Quest games\n-Most enemy sprites taken from another game that I'm working on and were arted by @Mishuun\n-Music by cgMusic\n-Sound by YOU! (I cut out sounds to save time. Please make your own audible sfx when you play.)", 8);
		
		_txtControls = new FlxText(0, 0, FlxG.width, "J = care, K = not care, WASD/Arrows = stay still, m = mute");
		_txtControls.alignment = "center";
		
		add(_txtCredits);		
		add(_txtTitle);
		add(_txtFurigana);
		add(_txtTwitter);
		add(_txtLD);
		add(_txtControls);
		
		FlxG.mouse.visible = false;		
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
		
		if (FlxG.keys.anyJustPressed(["K"]))
		{
			FlxG.switchState(new MenuState());
		}
		super.update();
	}	

	

}
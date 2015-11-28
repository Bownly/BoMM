package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.group.FlxTypedGroup;
import flixel.text.FlxText;
import flixel.util.FlxColor;

/**
 * ...
 * @author ...
 */
class DialogBox extends FlxTypedGroup<FlxSprite>
{
	private var _sprBack:FlxSprite;
    private var _txtDialog:FlxText;
	
	
	public function new() 
	{
		super();
		_sprBack = new FlxSprite().makeGraphic(FlxG.width, 20, FlxColor.BLACK);
		_sprBack.y = 220;
//		_sprBack.drawRect(0, 19, FlxG.width, 1, FlxColor.WHITE);
	//	_sprBack.makeGraphic(80, 240, FlxColor.BLACK);
		
		_txtDialog = new FlxText(_sprBack.x, _sprBack.y, FlxG.width, "sample text", 16);
		_txtDialog.setBorderStyle(FlxText.BORDER_SHADOW, FlxColor.GRAY, 1, 1);
		
		add(_sprBack);
		add(_txtDialog);
	}
	
	public function updateText(Index:Int)
	{
		this.visible = true;
		_txtDialog.text = Strings.stringArray[Index];
	}
	
	public function hideBox():Void
	{
		this.visible = false;
	}
	
}
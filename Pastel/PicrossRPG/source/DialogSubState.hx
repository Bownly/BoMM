package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxSubState;
import flixel.text.FlxText;
import flixel.util.FlxColor;

/**
 * ...
 * @author ...
 */
class DialogSubState extends FlxSubState
{

	private var _sprBack:FlxSprite;
    private var _txtDialog:FlxText;
	private var _lineNumber:Int;
	private var _endLine:Int;
	private var _endBoss:Bool = false;
	
	
	public function new(Index:Int, LineCount:Int, Npc:NPC, ?Endboss:Bool, ?BGColor:Int=FlxColor.TRANSPARENT) 
	{
		super();
		
		_lineNumber = Index;
		_endLine = Index + LineCount - 1;		
		_endBoss = Endboss;
		
		_sprBack = new FlxSprite().makeGraphic(FlxG.width, 48, FlxColor.BLACK);
		_sprBack.y = 192;
		
		_txtDialog = new FlxText(_sprBack.x, _sprBack.y, FlxG.width, Strings.stringArray[Index], 16);
		
		add(_sprBack);
		add(_txtDialog);
	}
	
	public override function update()
	{
		if (FlxG.keys.anyJustPressed(["J", "SPACE", "W", "A", "S", "D", "UP", "DOWN", "LEFT", "RIGHT", "K"]))
		{
			_lineNumber += 1;
			if (_lineNumber <= _endLine)
				updateText(_lineNumber);
			else
			{
				if (_endBoss)
					Reg.postDialogBattleFlag = true;
				this.close();
			}
		}
		super.update();
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
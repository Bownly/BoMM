package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;
import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;
import flixel.util.FlxColor;

/**
 * A FlxState which can be used for the actual gameplay.
 */
class PlayState extends FlxState
{
	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	
	var _rowArray:Array<Int> = new Array<Int>();
	var _colArray:Array<Array<Int>> = new Array<Array<Int>>();	 
	var _cellsNum:Int = 5;
	var _winCount:Int = 0;
	var _curCount:Int = 0;
	var count:Int = 0;

	var _grpTexts:FlxTypedGroup<FlxText>;
	private var _sprBack:FlxSprite;

	 
	 
	override public function create():Void
	{
		_sprBack = new FlxSprite().makeGraphic(160, 160, FlxColor.BLUE);
		_sprBack.x = FlxG.width / 2 - _sprBack.width / 2;
		_sprBack.y = FlxG.height / 2 - _sprBack.height / 2;

		_grpTexts = new FlxTypedGroup<FlxText>();
		
		for (X in 0..._cellsNum)
		{
			for (Y in 0..._cellsNum)
			{
			_rowArray.push(count);
			var txt:FlxText = new FlxText(_sprBack.x + 48 + X * 10, _sprBack.y + 48 + Y * 10, 320, "" + count, 8);
			_grpTexts.add(txt);

			count += 1;
			
			}
			_colArray.push(_rowArray);

		}
		
		add(_sprBack);
		add(_grpTexts);
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
}
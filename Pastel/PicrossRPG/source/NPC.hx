package;

import flixel.FlxObject;
import flixel.FlxSprite;

/**
 * ...
 * @author ...
 */
class NPC extends FlxSprite
{

	var _dLine:Int;
	var _lineCount:Int;
	var _state:TownState;
	
	
	public function new(X:Float=0, Y:Float=0, Direction:Int, Species:Int, DialogLine:Int, LineCount:Int, State:TownState) 
	{
		super(X, Y);
		
		_dLine = DialogLine;
		_lineCount = LineCount;
		_state = State;
		facing = Direction;
		
		immovable = true;
		
		
		// gwaphics
		var o = 8;  // number of sprites per char
		loadGraphic(AssetPaths.NPC__png, true, 16, 16);
		animation.add("up", [0 + o * Species, 1 + o * Species], 4, true);
		animation.add("dn", [2 + o * Species, 3 + o * Species], 4, true);
		animation.add("lf", [4 + o * Species, 5 + o * Species], 4, true);
		animation.add("rt", [6 + o * Species, 7 + o * Species], 4, true);
		switch(facing)
		{
			case FlxObject.UP:
			{
				animation.play("up");
			}
			case FlxObject.DOWN:
			{
				animation.play("dn");
			}
			case FlxObject.LEFT:
			{
				animation.play("lf");
			}
			case FlxObject.RIGHT:
			{
				animation.play("rt");
			}
		}	
	}
	
	override public function update():Void
	{
		super.update();  
	}
	
	public function triggered(Dir:Int):Void
	{
		switch(Dir)
		{
			case FlxObject.DOWN:
			{
				facing = FlxObject.UP;
				animation.play("up");
			}
			case FlxObject.UP:
			{
				facing = FlxObject.DOWN;
				animation.play("dn");
			}
			case FlxObject.RIGHT:
			{
				facing = FlxObject.LEFT;
				animation.play("lf");
			}
			case FlxObject.LEFT:
			{
				facing = FlxObject.RIGHT;
				animation.play("rt");
			}
		}
		dialogBox();
	}
	
	private function dialogBox():Void
	{
		var sub = new DialogSubState(_dLine, _lineCount, this);
		_state.openSubState(sub);
		return;
	}
	
}
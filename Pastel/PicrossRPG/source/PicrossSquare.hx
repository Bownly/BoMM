package;

import flixel.FlxSprite;

/**
 * ...
 * @author ...
 */
class PicrossSquare extends FlxSprite
{

	static public var ON:Int = 1;
	static public var OFF:Int = 0;
	static public var MARK:Int = 2;
	
	static public var NOTHING:Int = 0;
	static public var HURT:Int = 1;
	static public var CORRECT:Int = 2;
	static public var GOODHURT:Int = 3;
	
	var _id:Int = 0;
	var _status:Int = 0;  // 0 = off, 1 = on, 2 == marked
	var _answer:Int = 2;
	public var isActive:Bool = true;
	
	public function new(X:Float=0, Y:Float=0, ID:Int, Answer:Int) 
	{
		super(X, Y);
		
		_id = ID;
		_answer = Answer;
		
		var o = 4;  // number of colors per type
		loadGraphic(AssetPaths.picross_colors__png, false, 9, 9);
		animation.add("off",  [0 + o * _id]);
		animation.add("on",   [1 + o * _id]);
		animation.add("mark", [2 + o * _id]);
		animation.play("off");
	}
	
	public function turnOnOrOff(Status:Int):Int
	{
		
			
			
		if (isActive)
		{
			if (Status == ON)
			{
				isActive = false;
				if (_answer == ON)
				{
					animation.play("on");
					return CORRECT;
				}
				else
				{
					animation.play("mark");
					return HURT;
				}
			}
			else if (Status == MARK)
			{
				animation.play("mark");
				return NOTHING;
			}
			else 
				return NOTHING;
		}
		else
			return NOTHING;
	}
	
	
	public function playAnimation():Void
	{
		if (_answer == ON)
			animation.play("on");
		else
			animation.play("mark");
	}
	
}
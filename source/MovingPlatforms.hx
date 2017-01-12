package;

import flixel.FlxSprite;

/**
 * ...
 * @author ...
 */
class MovingPlatforms extends FlxSprite
{
	var _sinTimer:Float = 0;
	var _sinSpeed:Float = .05;
	var _cosTimer:Float = 0;
	var _cosSpeed:Float = .05;
	var _numBlocksTravelled:Float = 5;
	
	var _ogX:Float;
	var _ogY:Float;
	var _xDist:Float;
	var _yDist:Float;
	var _speed:Int;
	
	public function new(X:Float=0, Y:Float=0, Size:Int, XDist:Float, YDist:Float, Speed:Int, Level:PlayState) 
	{
		super(X, Y);
		immovable = true;
		
		_ogX = x;
		_ogY = y;
		_xDist = XDist;
		_yDist = YDist;
		_speed = Speed;
		
		if (XDist > 0)
			velocity.x = Speed;
		
		if (YDist > 0)
			velocity.y = Speed;
		acceleration.x = 0;
		acceleration.y = 0;
		
		loadGraphic("assets/images/moving_platforms.png", true, 16 * Size, 16);
		
		var frame:Int = 0;
		switch(Size)
		{
			case 2:
				frame = 2 + 6 * (Std.parseInt(Level.levelId) - 1);
			case 3:
				frame = 2 + 4 * (Std.parseInt(Level.levelId) - 1);
				
			case 4:
				frame = 0 + 3 * (Std.parseInt(Level.levelId) - 1);	
				
		}
		animation.add("move", [frame]);		
		animation.play("move");		
	}
	
	
	override public function update(elapsed:Float):Void 
	{
		
		if (x > _ogX + 16 * _xDist)
			velocity.x *= -1;
		if (y > _ogY + 16 * _yDist)
			velocity.y *= -1;
		if (x < _ogX)
			velocity.x *= -1;
		if (y < _ogY)
			velocity.y *= -1;
			
			
		super.update(elapsed);
	}
}
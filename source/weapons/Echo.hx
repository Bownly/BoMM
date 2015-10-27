package weapons;
import flixel.FlxObject;

/**
 * ...
 * @author ...
 */
class Echo extends Bullet
{
	var dir:Int = 0;
	var ySpeed:Float = 0;
	
	public function new(X:Float, Y:Float, Speed:Float, Direction:Int, Damage:Int, Range:Int, YFlip:Bool) 
	{
		super(X, Y, Speed, Direction, Damage, Range);
		loadGraphic("assets/images/echo.png", true, 8, 8, true);
	
		damage = 0;
		
		flipY = YFlip;
		reflectable = true;
		name = "echo";
		dir = Direction;
		ySpeed = Speed;
	}
	
	public override function onCollision():Void
	{
		if (reflectable == false)
			kill(); 
		else
		{
			if (flipY)
			{
				flipY = false;
				velocity.y = ySpeed;
			}
			else
			{
				flipY = true;
				velocity.y = -ySpeed;
			}
			
			reflectable = false;
		}
	}
	
}
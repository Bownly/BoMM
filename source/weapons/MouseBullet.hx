package weapons;
import flixel.FlxObject;
import flixel.group.FlxTypedGroup;

/**
 * ...
 * @author ...
 */
class MouseBullet extends Bullet
{

	var current_p:Player;
	var current_s:Float;
	var g:Int = -500;
	var current_d:Int;
	public function new(X:Float, Y:Float, Speed:Float, Direction:Int, Damage:Int, Range:Int, P:Player) 
	{
		super(X, Y, Speed, Direction, Damage, Range);
		current_p = P;		
		current_d = Direction;
		acceleration.y = -g;
		
	}
	
	override public function update():Void
    {
		super.update();
    }
			
	
	override public function onCollision():Void
    {
		if (reflectable == false)
		{
			kill();

				
				if (current_d == FlxObject.CEILING + FlxObject.LEFT || current_d == FlxObject.LEFT)
				{	
					var newBullet = new MouseBullet(x, y, 80, FlxObject.CEILING + FlxObject.LEFT, current_p.damage + damage, 256, current_p);
					current_p.bulletArray.add(newBullet);
				}
				else
				{
					var newBullet = new MouseBullet(x, y, 80, FlxObject.CEILING + FlxObject.RIGHT, current_p.damage + damage, 256, current_p);
					current_p.bulletArray.add(newBullet);
				}

		}	
			else
			{
				kill();
			}
	}	
		
}	
	

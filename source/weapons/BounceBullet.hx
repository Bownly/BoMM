package weapons;
import flixel.FlxObject;
import flixel.group.FlxTypedGroup;

/**
 * ...
 * @author ...
 */
class BounceBullet extends Bullet
{

	var current_p:Player;
	var current_s:Float;
	var g:Int = 0;
	var b:Int = 0;
	var current_d:Int;
	public function new(X:Float, Y:Float, Speed:Float, Direction:Int, Damage:Int, Range:Int, P:Player, bounce_num:Int, gravity_num:Int) 
	{
		super(X, Y, Speed, Direction, Damage, Range);
		current_p = P;
		velocity.y = -80;		
		current_d = Direction;
		b = bounce_num;		
		g = gravity_num;
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
			if (b != 2)
			{
				kill();
				g -= 50;
				b += 1;
				
				if (current_d == FlxObject.CEILING + FlxObject.LEFT)
				{	
					var newBullet = new BounceBullet(x, y, 80, FlxObject.CEILING + FlxObject.LEFT, current_p.damage + damage, 256, current_p, b, g);
					current_p.bulletArray.add(newBullet);
				}
				else
				{
					var newBullet = new BounceBullet(x, y, 80, FlxObject.CEILING + FlxObject.RIGHT, current_p.damage + damage, 256, current_p, b, g);
					current_p.bulletArray.add(newBullet);
				}

			}	
			else
			{
				kill();
			}
		}	
		
	}	
	
}
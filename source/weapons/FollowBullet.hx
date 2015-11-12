package weapons;
import flixel.FlxObject;
import flixel.group.FlxTypedGroup;
import flixel.util.FlxAngle;
import flixel.util.FlxPoint;

/**
 * ...
 * @author ...
 */
class FollowBullet extends Bullet
{

	var a:Int = 0;
	var current_p:Player;
	var current_s:Float;
	var current_d:Int;
	var current_v:Float;
	var c:FlxPoint;
	var current_x:Float;
	var current_y:Float;

	public function new(X:Float, Y:Float, Speed:Float, Direction:Int, Damage:Int, Range:Int, P:Player, Palette:Int) 
	{
		super(X, Y, Speed, Direction, Damage, Range, Palette, 4);
		
		current_p = P;		
		current_d = Direction;
		current_v = Speed;
		current_x = current_p.x;
		current_y = current_p.y;
	
		palette = Palette;

	}
	
	override public function update():Void
    {	
		if (current_d == FlxObject.LEFT)
			a -= 10;
		else
			a += 10;
			
		c = FlxAngle.rotatePoint(x, y, current_p.x + (current_p.width / 2), current_p.y + (current_p.height / 2), a);
		
		x = c.x + ((current_p.x + (current_p.width / 2)) - current_x);
		y = c.y+ ((current_p.y + (current_p.height / 2)) - current_y);

		current_x = (current_p.x + (current_p.width / 2));
		current_y = (current_p.y + (current_p.height / 2));
		super.update();
    }
			
		
}	
	

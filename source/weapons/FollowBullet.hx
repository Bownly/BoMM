package weapons;
import flixel.FlxObject;
import flixel.group.FlxTypedGroup;

/**
 * ...
 * @author ...
 */
class FollowBullet extends Bullet
{

	var current_p:Player;
	var current_s:Float;
	var current_d:Int;
	public function new(X:Float, Y:Float, Speed:Float, Direction:Int, Damage:Int, Range:Int, P:Player) 
	{
		super(X, Y, Speed, Direction, Damage, Range);
		current_p = P;		
		current_d = Direction;
		
	}
	
	override public function update():Void
    {
		if (current_d == FlxObject.RIGHT)
			x = current_p.x + 20;
		if (current_d == FlxObject.LEFT)
			x = current_p.x - 20;

		y = current_p.y + 8;
		
		super.update();
    }
			
		
}	
	

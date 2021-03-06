package weapons;
import flixel.FlxObject;
import flixel.group.FlxGroup;
/**
 * ...
 * @author ...
 */
class SlashBullet extends Bullet
{
	var current_p:Player;
	
	
	public function new(X:Float, Y:Float, Speed:Float, Direction:Int, Damage:Int, Range:Int, P:Player, Palette:Int) 
	{
		super(X, Y, Speed, Direction, Damage, Range, Palette, 4);
		current_p = P;
	}
	
	override public function update(elapsed:Float):Void
    {
		if(x == (current_p.x - 20))
			direction = FlxObject.CEILING + FlxObject.LEFT;
		else	
			direction = FlxObject.CEILING + FlxObject.RIGHT;
			
		super.update(elapsed);
    }
}
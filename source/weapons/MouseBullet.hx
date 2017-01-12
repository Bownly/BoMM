package weapons;
import flixel.FlxObject;
import flixel.group.FlxGroup;

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
	
	
	public function new(X:Float, Y:Float, Speed:Float, Direction:Int, Damage:Int, Range:Int, P:Player, Palette:Int) 
	{
		super(X, Y, Speed, Direction, Damage, Range, Palette, 4);
		current_p = P;		
		current_d = Direction;
		acceleration.y = -g;
		
		palette = Palette;
		
	}
	
	override public function update(elapsed:Float):Void
    {
		super.update(elapsed);
    }
			
	
	override public function onCollision():Void
    {
		if (reflectable == false)
		{
			kill();

				
				if (current_d == FlxObject.CEILING + FlxObject.LEFT || current_d == FlxObject.LEFT)
				{	
					var newBullet = new MouseBullet(x, y, 80, FlxObject.CEILING + FlxObject.LEFT, current_p.damage + damage, 256, current_p, palette);
					current_p.bulletArray.add(newBullet);
				}
				else
				{
					var newBullet = new MouseBullet(x, y, 80, FlxObject.CEILING + FlxObject.RIGHT, current_p.damage + damage, 256, current_p, palette);
					current_p.bulletArray.add(newBullet);
				}

		}	
			else
			{
				kill();
			}
	}	
		
}	
	

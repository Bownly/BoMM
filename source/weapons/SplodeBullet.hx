package weapons;
import flixel.FlxG;

import flixel.FlxObject;
import flixel.group.FlxTypedGroup;
/**
 * ...
 * @author ...
 */
class SplodeBullet extends Bullet
{
	private var gravity:Int = -200;

	var current_p:Player;
	
	public function new(X:Float, Y:Float, Speed:Float, Direction:Int, Damage:Int, Range:Int, P:Player) 
	{
		super(X, Y, Speed, Direction, Damage, Range);
		current_p = P;
		velocity.y = -120;		
		acceleration.y = -gravity;
	}
	
	override public function update():Void
    {
		if ((Math.abs(x - ogX) > RANGE || Math.abs(y - ogY) > RANGE) || (FlxG.keys.anyJustReleased(["SPACE"]))) 
		{ 
			kill(); 
				var newBullet = new Bullet(x,  y, 100, FlxObject.LEFT, current_p.damage + damage, 20);
				var newBullet1 = new Bullet(x,  y, 100, FlxObject.CEILING, current_p.damage + damage, 20);
				var newBullet2 = new Bullet(x,  y, 100, FlxObject.RIGHT, current_p.damage + damage, 20);
				var newBullet3 = new Bullet(x,  y, 100, FlxObject.FLOOR, current_p.damage + damage, 20);

				var newBullet4 = new Bullet(x,  y, 100, FlxObject.LEFT + FlxObject.CEILING, current_p.damage + damage, 13);
				var newBullet5 = new Bullet(x, y, 100, FlxObject.RIGHT + FlxObject.CEILING, current_p.damage + damage, 13);
				var newBullet6 = new Bullet(x, y, 100, FlxObject.LEFT + FlxObject.FLOOR, current_p.damage + damage, 13);		
				var newBullet7 = new Bullet(x, y, 100, FlxObject.RIGHT + FlxObject.FLOOR, current_p.damage + damage, 13);		

				current_p.bulletArray.add(newBullet);
				current_p.bulletArray.add(newBullet1);
				current_p.bulletArray.add(newBullet2);
				current_p.bulletArray.add(newBullet3);	
				current_p.bulletArray.add(newBullet4);	
				current_p.bulletArray.add(newBullet5);	
				current_p.bulletArray.add(newBullet6);	
				current_p.bulletArray.add(newBullet7);		
		}
		super.update();
	}
			
	
		override public function onCollision():Void
    {
		if (reflectable == false)
		{
			kill();
			var newBullet = new Bullet(x,  y, 100, FlxObject.LEFT, current_p.damage + damage, 20);
			var newBullet1 = new Bullet(x,  y, 100, FlxObject.CEILING, current_p.damage + damage, 20);
			var newBullet2 = new Bullet(x,  y, 100, FlxObject.RIGHT, current_p.damage + damage, 20);
			var newBullet3 = new Bullet(x,  y, 100, FlxObject.FLOOR, current_p.damage + damage, 20);

			var newBullet4 = new Bullet(x,  y, 100, FlxObject.LEFT + FlxObject.CEILING, current_p.damage + damage, 13);
			var newBullet5 = new Bullet(x, y, 100, FlxObject.RIGHT + FlxObject.CEILING, current_p.damage + damage, 13);
			var newBullet6 = new Bullet(x, y, 100, FlxObject.LEFT + FlxObject.FLOOR, current_p.damage + damage, 13);		
			var newBullet7 = new Bullet(x, y, 100, FlxObject.RIGHT + FlxObject.FLOOR, current_p.damage + damage, 13);		

			current_p.bulletArray.add(newBullet);
			current_p.bulletArray.add(newBullet1);
			current_p.bulletArray.add(newBullet2);
			current_p.bulletArray.add(newBullet3);	
			current_p.bulletArray.add(newBullet4);	
			current_p.bulletArray.add(newBullet5);	
			current_p.bulletArray.add(newBullet6);	
			current_p.bulletArray.add(newBullet7);			
		}	
		
	}
}
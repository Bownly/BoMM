package weapons;
import flixel.FlxG;

import flixel.FlxObject;
import flixel.group.FlxGroup;
/**
 * ...
 * @author ...
 */
class SplodeBullet extends Bullet
{
	private var gravity:Int = -200;
	var current_p:Player;
	
	public function new(X:Float, Y:Float, Speed:Float, Direction:Int, Damage:Int, Range:Int, P:Player, Palette:Int) 
	{
		super(X, Y, Speed, Direction, Damage, Range, Palette, 4);
		current_p = P;
		palette = Palette;
		velocity.y = -120;		
		acceleration.y = -gravity;
	}
	
	override public function update(elapsed:Float):Void
    {
		if ((Math.abs(x - ogX) > RANGE || Math.abs(y - ogY) > RANGE) || (FlxG.keys.anyJustReleased(["SPACE", "K"]))) 
		{ 
			kill(); 
				var newBullet = new Bullet(x,  y, 100, FlxObject.LEFT, current_p.damage + damage, 20, palette, FlxObject.LEFT);
				var newBullet1 = new Bullet(x,  y, 100, FlxObject.CEILING, current_p.damage + damage, 20, palette, FlxObject.CEILING);
				var newBullet2 = new Bullet(x,  y, 100, FlxObject.RIGHT, current_p.damage + damage, 20, palette, FlxObject.RIGHT);
				var newBullet3 = new Bullet(x,  y, 100, FlxObject.FLOOR, current_p.damage + damage, 20, palette, FlxObject.FLOOR);

				var newBullet4 = new Bullet(x,  y, 100, FlxObject.LEFT + FlxObject.CEILING, current_p.damage + damage, 13, palette, FlxObject.LEFT + FlxObject.CEILING);
				var newBullet5 = new Bullet(x, y, 100, FlxObject.RIGHT + FlxObject.CEILING, current_p.damage + damage, 13, palette, FlxObject.RIGHT + FlxObject.CEILING);
				var newBullet6 = new Bullet(x, y, 100, FlxObject.LEFT + FlxObject.FLOOR, current_p.damage + damage, 13, palette, FlxObject.LEFT + FlxObject.FLOOR);		
				var newBullet7 = new Bullet(x, y, 100, FlxObject.RIGHT + FlxObject.FLOOR, current_p.damage + damage, 13, palette, FlxObject.RIGHT + FlxObject.FLOOR);		

				current_p.bulletArray.add(newBullet);
				current_p.bulletArray.add(newBullet1);
				current_p.bulletArray.add(newBullet2);
				current_p.bulletArray.add(newBullet3);	
				current_p.bulletArray.add(newBullet4);	
				current_p.bulletArray.add(newBullet5);	
				current_p.bulletArray.add(newBullet6);	
				current_p.bulletArray.add(newBullet7);		
		}
		super.update(elapsed);
	}
			
	
		override public function onCollision():Void
    {
		if (reflectable == false)
		{
			kill();
					var newBullet = new Bullet(x,  y, 100, FlxObject.LEFT, current_p.damage + damage, 20, palette, FlxObject.LEFT);
				var newBullet1 = new Bullet(x,  y, 100, FlxObject.CEILING, current_p.damage + damage, 20, palette, FlxObject.CEILING);
				var newBullet2 = new Bullet(x,  y, 100, FlxObject.RIGHT, current_p.damage + damage, 20, palette, FlxObject.RIGHT);
				var newBullet3 = new Bullet(x,  y, 100, FlxObject.FLOOR, current_p.damage + damage, 20, palette, FlxObject.FLOOR);

				var newBullet4 = new Bullet(x,  y, 100, FlxObject.LEFT + FlxObject.CEILING, current_p.damage + damage, 13, palette, FlxObject.LEFT + FlxObject.CEILING);
				var newBullet5 = new Bullet(x, y, 100, FlxObject.RIGHT + FlxObject.CEILING, current_p.damage + damage, 13, palette, FlxObject.RIGHT + FlxObject.CEILING);
				var newBullet6 = new Bullet(x, y, 100, FlxObject.LEFT + FlxObject.FLOOR, current_p.damage + damage, 13, palette, FlxObject.LEFT + FlxObject.FLOOR);		
				var newBullet7 = new Bullet(x, y, 100, FlxObject.RIGHT + FlxObject.FLOOR, current_p.damage + damage, 13, palette, FlxObject.RIGHT + FlxObject.FLOOR);		

				current_p.bulletArray.add(newBullet);
				current_p.bulletArray.add(newBullet1);
				current_p.bulletArray.add(newBullet2);
				current_p.bulletArray.add(newBullet3);	
				current_p.bulletArray.add(newBullet4);	
				current_p.bulletArray.add(newBullet5);	
				current_p.bulletArray.add(newBullet6);	
				current_p.bulletArray.add(newBullet7);		
				
				super.onCollision();
		}	
		
	}
}
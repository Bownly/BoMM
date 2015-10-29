package weapons;

import flixel.FlxSprite;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.util.FlxVelocity;
import flixel.util.FlxAngle;
import flixel.util.FlxPoint;

/**
 * ...
 * @author ...
 * 
 * todo
 * 1 split all functions into small functions and make it reclassable or whatever. 
 * 
 */
class Bullet extends FlxSprite
{
	public var name:String = "pea";
    private var speed:Float;
    private var direction:Int;
    private var damage:Int;
	private var ogX:Float;
	private var ogY:Float;
	private var RANGE:Int = 128;
	
	public var reflectable:Bool = false;
	
	/* Weapon ideas list
	 * 
	 * Shoot for 9 weapons, 3 of each color
	 * Should they be roughly grouped by function? I think so.
	 
	 * leaf shield
	 * reflector
		
     * horizontal both directions
	 * 8 direction
		
	 * charge
	 * grenade
	 * melee
	 * ricochet
	 * homing
	 * spread
	 * boomerang
	 * ground hugger
	 * anti-air
	 
	 * */
	
	public function new(X:Float, Y:Float, Speed:Float, Direction:Int, Damage:Int, Range:Int)
    {
        super(X, Y);
		ogX = X;
		ogY = Y;
        speed = Speed;
        direction = Direction;
        damage = Damage;
		RANGE = Range;
        loadGraphic("assets/images/coin.png", true, 6, 6, true, "bullet");
		resolveVelocity();
		
    }
 
    override public function update():Void
    {
		
		// If the bullet travels too far from its spawn point
		if (Math.abs(x - ogX) > RANGE || Math.abs(y - ogY) > RANGE) 
		{ 
			kill(); 
		} 
	
		super.update();

    }
 	
    override public function destroy():Void
    {
		alive = false;
//		exists = false;
        super.destroy();
    }
 
	
	public function getDamage():Int
	{
		return damage;
	}
	
	public function resolveVelocity():Void
	{
		if (direction == FlxObject.LEFT)
			velocity.x = -speed;     
        if (direction == FlxObject.RIGHT)
            velocity.x = speed;     
        if (direction == FlxObject.FLOOR)
            velocity.y = speed;     
        if (direction == FlxObject.CEILING)
            velocity.y = -speed;     
		if (direction == FlxObject.LEFT + FlxObject.FLOOR)
		{
			velocity.x = -speed * 0.707;
			velocity.y = speed * 0.707;
		}
		if (direction == FlxObject.LEFT + FlxObject.CEILING)
		{
			velocity.x = -speed * 0.707;
			velocity.y = -speed * 0.707;
		}
		
		if (direction == FlxObject.LEFT + FlxObject.CEILING + FlxObject.LEFT)
		{
			velocity.x = -speed * 0.966;
			velocity.y = speed * 0.259;
		}
		
		if (direction == FlxObject.LEFT + FlxObject.FLOOR + FlxObject.LEFT)
		{
			velocity.x = -speed * 0.966;
			velocity.y = -speed * 0.259;
		}	
		
		if (direction == FlxObject.RIGHT + FlxObject.FLOOR)
		{
			velocity.x = speed * 0.707;
			velocity.y = speed * 0.707;
		}
		if (direction == FlxObject.RIGHT + FlxObject.CEILING)
		{
			velocity.x = speed * 0.707;
			velocity.y = -speed * 0.707;
		}
		
		if (direction == FlxObject.RIGHT + FlxObject.CEILING + FlxObject.RIGHT)
		{
			velocity.x = speed * 0.966;
			velocity.y = speed * 0.259;
		}
		
		if (direction == FlxObject.RIGHT + FlxObject.FLOOR + FlxObject.RIGHT)
		{
			velocity.x = speed * 0.966;
			velocity.y = -speed * 0.259;
		}			

	}
	
	public function onCollision():Void
	{
		//if (isTouching(FlxObject.ANY)) 
		//{
			if (reflectable == false)
				kill(); 

		//}	
	}
	
}

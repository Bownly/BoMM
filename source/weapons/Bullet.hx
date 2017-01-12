package weapons;

import flixel.FlxSprite;
import flixel.FlxG;
import flixel.FlxObject;
// import flixel.util.FlxVelocity;
// import flixel.util.FlxAngle;
// import flixel.util.FlxPoint;

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
	private var palette:Int;
	private var frameID:Int;
	
	public var reflectable:Bool = false;
	
	/* Weapon ideas list
	 * 
	 * Shoot for 9 weapons, 3 of each color
	 * Should they be roughly grouped by function? I think so.
	 
	 * leaf shield
	 * reflector
		
     * horizontal both directions
		
	 * charge
	 * melee
	 * ricochet
	 * homing
	 * boomerang
	 * anti-air
	 
	 * */
	
	public function new(X:Float, Y:Float, Speed:Float, Direction:Int, Damage:Int, Range:Int, Palette:Int, FaceDir:Int)
    {
        super(X, Y);
		ogX = X;
		ogY = Y;
        speed = Speed;
        direction = Direction;
        damage = Damage;
		RANGE = Range;
		palette = Palette;
		frameID = FaceDir;
		
		resolveAnimations();
		
		
		resolveVelocity();
		
    }
 
	public function resolveAnimations():Void
	{
		switch(frameID)
		{
			case FlxObject.RIGHT:
				frameID = 0;
			case FlxObject.LEFT:
			{
				frameID = 0;
				flipX = true;
			}
			case FlxObject.UP:
				frameID = 1;
			case FlxObject.DOWN:
			{
				frameID = 1;
				flipY = true;
			}
			// DOWN = x1000, UP = x0100, RIGHT = x0010, LEFT = x0001
			case (0x1010):  
				frameID = 2;
			case (0x1001):
			{
				frameID = 2;
				flipX = true;
			}
			case (0x0110):
				frameID = 3;	
			case (0x0101):
			{
				frameID = 3;
				flipX = true;
			}				
		}
		frameID *= 4;
		var o = 4; // the amount of sprites in the sheet per color
		switch (palette)
		{
			case(Reg.G):
				o = 0;
			case(Reg.C):
				o = 1;
			case(Reg.M):
				o = 2;
			case(Reg.Y):
				o = 3;
		}
		
		loadGraphic("assets/images/bullet.png", true, 6, 6);
		width = 6;
		height = 6;
		animation.add("bullet", [frameID + o]);
		animation.play("bullet");
	}
	
    override public function update(elapsed:Float):Void
    {
		
		// If the bullet travels too far from its spawn point
		if (Math.abs(x - ogX) > RANGE || Math.abs(y - ogY) > RANGE || !isOnScreen()) 
		{ 
			kill(); 
		} 
	
		super.update(elapsed);

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
		
		if (direction == FlxObject.LEFT + FlxObject.CEILING)
		{
			velocity.x = -speed * 0.707;
			velocity.y = -speed * 0.707;
		}
		if (direction == FlxObject.LEFT + FlxObject.FLOOR)
		{
			velocity.x = -speed * 0.707;
			velocity.y = speed * 0.707;
		}
		if (direction == FlxObject.LEFT * 2 + FlxObject.CEILING)
		{
			velocity.x = -speed * 0.966;
			velocity.y = speed * 0.2;
		}
		if (direction == FlxObject.LEFT * 2 + FlxObject.FLOOR)
		{
			velocity.x = -speed * 0.966;
			velocity.y = -speed * 0.2;
		}	
		
		if (direction == FlxObject.RIGHT + FlxObject.CEILING)
		{
			velocity.x = speed * 0.707;
			velocity.y = -speed * 0.707;
		}
		if (direction == FlxObject.RIGHT + FlxObject.FLOOR)
		{
			velocity.x = speed * 0.707;
			velocity.y = speed * 0.707;
		}
		if (direction == FlxObject.RIGHT * 2 + FlxObject.CEILING)
		{
			velocity.x = speed * 0.966;
			velocity.y = speed * 0.2;
		}	
		if (direction == FlxObject.RIGHT * 2 + FlxObject.FLOOR)
		{
			velocity.x = speed * 0.966;
			velocity.y = -speed * 0.2;
		}			

		if (direction == FlxObject.FLOOR * 8 + FlxObject.LEFT)
		{
			velocity.x = -speed * 0.173;
			velocity.y = speed * 0.985;
		}		
		if (direction == FlxObject.FLOOR * 8 + FlxObject.RIGHT)
		{
			velocity.x = speed * 0.173;
			velocity.y = speed * 0.985;
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

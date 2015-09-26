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
 * 
 * 1 split all functions into small functions and make it reclassable or whatever. 
 * 
 */
class Bullet extends FlxSprite
{
    private var speed:Float;
    private var direction:Int;
    private var damage:Int;
	private var ogX:Float;
	private var ogY:Float;
	private var RANGE:Int = 128;
	
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
		
		//if (collide with anything)
			//destroy();
    }
 
    override public function update():Void
    {
        super.update();
        if (direction == FlxObject.LEFT){
            velocity.x = -speed;     
        }
        if (direction == FlxObject.RIGHT){
            velocity.x = speed;     
        }
        if (direction == FlxObject.FLOOR){
            velocity.y = speed;     
        }
        if (direction == FlxObject.CEILING){
            velocity.y = -speed;     
        }
		
		
		// If the bullet travels too far from its spawn point
		
		if (Math.abs(x - ogX) > RANGE || Math.abs(y - ogY) > RANGE) 
		{ 
			kill(); 
		} 
		else if (touching != 0)
		{
			// We want the bullet to go away when it hits something, not just stop.
			kill(); 
		}
        
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
	
}

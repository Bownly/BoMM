package;

import flixel.FlxSprite;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.util.FlxVelocity;
import flixel.util.FlxAngle;
import flixel.util.FlxPoint;

/**
 * ...
 * @author ...
 */
class Bullet extends FlxSprite
{
    private var speed:Float;
    private var direction:Int;
    private var damage:Int;
	
	public function new(X:Float, Y:Float,Speed:Float,Direction:Int,Damage:Int)
	   {
        super(X,Y);
        speed = Speed;
        direction = Direction;
        damage = Damage;
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
		
		
		if (getScreenXY().x < -64 || getScreenXY().x > FlxG.width + 64) 
		{ 
			// If the bullet makes it 64 pixels off the side of the screen, kill it
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

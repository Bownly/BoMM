package weapons;

/**
 * ...
 * @author ...
 */
class ArcBullet extends Bullet
{
	private var gravity:Int = -200;
	
	public function new(X:Float, Y:Float, Speed:Float, Direction:Int, Damage:Int, Range:Int) 
	{
		super(X, Y, Speed, Direction, Damage, Range);
		
		velocity.y = -150;		
		acceleration.y = -gravity;
	}
	
	override public function update():Void
    {
		super.update();
    }
}
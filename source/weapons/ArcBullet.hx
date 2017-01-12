package weapons;

/**
 * ...
 * @author ...
 */
class ArcBullet extends Bullet
{
	private var gravity:Int = -200;
	
	public function new(X:Float, Y:Float, Speed:Float, Direction:Int, Damage:Int, Range:Int, Palette:Int) 
	{
		super(X, Y, Speed, Direction, Damage, Range, Palette, 4);
		
		velocity.y = -120;		
		acceleration.y = -gravity;
	}
	
	override public function update(elapsed:Float):Void
    {
		super.update(elapsed);
    }
}
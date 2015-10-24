package weapons;

/**
 * ...
 * @author ...
 */
class Arc extends Bullet
{
	private var gravity:Int = -30;
	
	public function new(X:Float, Y:Float, Speed:Float, Direction:Int, Damage:Int, Range:Int) 
	{
		super(X, Y, Speed, Direction, Damage, Range);
		acceleration.y = -gravity;
				

	}
	
	
	override public function update():Void
    {
		super.update();
    }
}
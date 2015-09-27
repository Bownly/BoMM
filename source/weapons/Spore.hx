package weapons;

/**
 * ...
 * @author ...
 */
class Spore extends Bullet
{
	private var gravity:Int = -30;
	
	public function new(X:Float, Y:Float, Speed:Float, Direction:Int, Damage:Int, Range:Int) 
	{
		super(X, Y, Speed, Direction, Damage, Range);
		loadGraphic("assets/images/ladder.png", true, 16, 16, true);
		acceleration.y = -gravity;
	}
	
	
}
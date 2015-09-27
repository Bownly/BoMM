package weapons;

/**
 * ...
 * @author ...
 */
class Spore extends Bullet
{
	private var gravity:Int = -30;
	
	public function new(X:Float, Y:Float, Speed:Float, Direction:Int, Damage:Int, Range:Int, Palette:Int) 
	{
		super(X, Y, Speed, Direction, Damage, Range);
		loadGraphic("assets/images/spore.png", true, 16, 16, true);
		acceleration.y = -gravity;
		
		var clrBfr:Int = Palette * 4;
		
		animation.add("spore", [0 + clrBfr, 1 + clrBfr, 
			2 + clrBfr, 3 + clrBfr, 2 + clrBfr, 3 + clrBfr, 
			2 + clrBfr, 3 + clrBfr, 2 + clrBfr, 3 + clrBfr], 2, true);
	}
	
	override public function update():Void
    {
        animation.play("spore");
		super.update();
    }
}
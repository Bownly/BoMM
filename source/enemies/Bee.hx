package enemies;
import enemies.Egg;
import enemies.EnemyTemplate;
import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;

/**
 * ...
 * @author ...
 */
class Bee extends enemies.EnemyTemplate
{
	//private var XSPEED:Int = 25;
	private var XSPEED:Int = -75;
	private var GRAVITY:Int = 9800;
	private var _HP:Int = 1;

	private var haveEgg:Bool = false;
	private var egg:enemies.Egg;
	var palette:Int;
	
	public function new(X:Float, Y:Float, ThePlayer:Player, DropsGrp:FlxTypedGroup<Drops>, Enemies:FlxGroup, Palette:Int) 
	{
		super(X, Y, ThePlayer, _HP, DropsGrp);
		loadGraphic("assets/images/bee.png", true, 16, 16);
		width = 16;
		height = 16;
		
		palette = Palette;
		
		var o = 4; // the amount of sprites in the sheet per color
		switch (palette)
		{
			case(Reg.G):
				o *= 0;
			case(Reg.C):
				o *= 1;
			case(Reg.M):
				o *= 2;
			case(Reg.Y):
				o *= 3;
		}
		
		animation.add("flap", [0 + o, 1 + o], 5, true);
		
		egg = new enemies.Egg(x, y + height, ThePlayer, _drops, XSPEED, Enemies);
		Enemies.add(egg);
		haveEgg = true;
	}
	
	public override function update():Void
	{
		if (isOnScreen()) 
		{
			velocity.x = XSPEED;
			velocity.y = 0;
			
			animation.play("flap");
			
			var xdistance:Float = _player.x - x;
			var ydistance:Float = _player.y - y; 
			var distancesquared:Float = xdistance * xdistance + ydistance * ydistance; 
			
			if (distancesquared < 24000 && haveEgg) 
			{	
				dropEgg();
			}
			super.update();
		}
	}
	
	public function dropEgg()
	{
		haveEgg = false;
		egg.dropped();
	}
	
}
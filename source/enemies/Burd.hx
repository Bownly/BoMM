package enemies;
import enemies.Egg;
import enemies.EnemyTemplate;
import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;

/**
 * ...
 * @author ...
 */
class Burd extends enemies.EnemyTemplate
{
	//private var XSPEED:Int = 25;
	private var XSPEED:Int = -75;
	private var GRAVITY:Int = 9800;
	private var _HP:Int = 1;

	private var haveEgg:Bool = false;
	private var egg:enemies.Egg;
	
	public function new(X:Float, Y:Float, ThePlayer:Player, DropsGrp:FlxTypedGroup<Drops>, Enemies:FlxGroup) 
	{
		super(X, Y, ThePlayer, _HP, DropsGrp);
		loadGraphic("assets/images/burd.png", true, 16, 16);
		width = 16;
		height = 16;
		
		animation.add("flap", [0, 1], 5, true);
		
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
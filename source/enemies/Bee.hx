package enemies;
import enemies.Beehive;
import enemies.EnemyTemplate;
import flixel.group.FlxGroup;

/**
 * ...
 * @author ...
 */
class Bee extends enemies.EnemyTemplate
{
	//private var XSPEED:Int = 25;
	private var XSPEED:Int = -50;
	private var GRAVITY:Int = 9800;
	private var _HP:Int = 1;

	private var haveEgg:Bool = false;
	private var egg:enemies.Beehive;
	var palette:Int;
	
	public function new(X:Float, Y:Float, ThePlayer:Player, Spawner:EnemySpawner, DropsGrp:FlxTypedGroup<Drops>, Enemies:FlxGroup, SVNoClipEnemies:FlxGroup, Palette:Int) 
	{
		super(X, Y, ThePlayer, Spawner, _HP, DropsGrp);
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
		
		if (x < ThePlayer.x)
		{
			flipX = true;
			XSPEED = -XSPEED;
		}
		
		
		egg = new enemies.Beehive(x, y + height, ThePlayer, _spawner, _drops, XSPEED, SVNoClipEnemies, palette);
		Enemies.add(egg);
		haveEgg = true;
	}
	
	public override function update(elapsed:Float):Void
	{

		velocity.x = XSPEED;
		velocity.y = 0;
		
		animation.play("flap");
		
		var xdistance:Float = Math.abs(_player.x - x);
		
		if (xdistance < 80 && haveEgg) 
		{	
			dropEgg();
		}
		super.update(elapsed);
	}
	
	public function dropEgg()
	{
		haveEgg = false;
		egg.dropped();
	}
	
}
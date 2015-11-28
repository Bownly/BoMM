package enemies;

import enemies.BeeBabby;
import enemies.EnemyTemplate;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxRandom;

/**
 * ...
 * @author ...
 */
class Beehive extends enemies.EnemyTemplate
{
	private var XSPEED:Int;
	private var GRAVITY:Int = 9800;
	private var _HP:Int = 1;

	private var _cracked:Bool = false;
	private var babby:enemies.BeeBabby;
	private var babby2:enemies.BeeBabby;
	private var babby3:enemies.BeeBabby;
	private var babby4:enemies.BeeBabby;
	private var burdArray:FlxTypedGroup<enemies.BeeBabby>;
	private var enemArray:FlxGroup;
	var palette:Int = Reg.G;

	public function new(X:Float=0, Y:Float=0, ThePlayer:Player, Spawner:EnemySpawner, DropsGrp:FlxTypedGroup<Drops>, XVel:Int, SVNoClipEnemies:FlxGroup, Palette:Int) 
	{
		super(X, Y, ThePlayer, Spawner, _HP, DropsGrp);
		XSPEED = XVel;
		
	//	loadGraphic("assets/images/burdegg.png", true, 16, 8);
		loadGraphic("assets/images/beehive.png", true, 16, 16);
		width = 16;
		height = 8;
		
		palette = Palette;
		
		enemArray = SVNoClipEnemies;
		burdArray = new FlxTypedGroup<enemies.BeeBabby>();
		var o = 2; // the amount of sprites in the sheet per color
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
		
		animation.add("idle", [0 + o]);
		animation.add("open", [1 + o]);
	}
	
	public override function update():Void
	{
		if (isOnScreen())
		{
			velocity.x = XSPEED; // = -50;
			velocity.y = 0;
			if (_cracked == false)
				animation.play("idle");
			else
				animation.play("open");
				
			if (isTouching(FlxObject.FLOOR) && alive)
			{
				spawnBirds();
				_cracked = true;
				animation.play("open");	
				kill();
			}
			super.update();
		}
	}
	
	public function dropped():Void
	{
		acceleration.y = GRAVITY;
	}
	
	private function spawnBirds():Void
	{
		for (i in 0...6)
		{
			var babbyX = FlxRandom.intRanged(Math.floor(x) - 8, Math.floor(x) + 24);
			var babbyY = FlxRandom.intRanged(Math.floor(y - 16), Math.floor(y) + 16);
			babby = new enemies.BeeBabby(babbyX, babbyY, _player, _spawner, _drops, palette);
			burdArray.add(babby);
		}
		enemArray.add(burdArray);
		
	}
}
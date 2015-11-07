package enemies;

import enemies.BabyBurd;
import enemies.EnemyTemplate;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;

/**
 * ...
 * @author ...
 */
class Egg extends enemies.EnemyTemplate
{
	private var XSPEED:Int;
	private var GRAVITY:Int = 9800;
	private var _HP:Int = 1;

	private var _cracked:Bool = false;
	private var babby:enemies.BabyBurd;
	private var babby2:enemies.BabyBurd;
	private var babby3:enemies.BabyBurd;
	private var babby4:enemies.BabyBurd;
	private var burdArray:FlxTypedGroup<enemies.BabyBurd>;
	private var enemArray:FlxGroup;

	public function new(X:Float=0, Y:Float=0, ThePlayer:Player, Spawner:EnemySpawner, DropsGrp:FlxTypedGroup<Drops>, XVel:Int, Enemies:FlxGroup) 
	{
		super(X, Y, ThePlayer, Spawner, _HP, DropsGrp);
		XSPEED = XVel;
		
		loadGraphic("assets/images/burdegg.png", true, 16, 8);
		width = 16;
		height = 8;
		
		enemArray = Enemies;
		burdArray = new FlxTypedGroup<enemies.BabyBurd>();
		
		animation.add("idle", [0]);
		animation.add("open", [1]);
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
				
			if (isTouching(FlxObject.FLOOR))
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
		babby = new enemies.BabyBurd(x, y, _player, _spawner, _drops);
		babby2 = new enemies.BabyBurd(x, y - 10, _player, _spawner, _drops);
		babby3 = new enemies.BabyBurd(x + 10, y - 10 + height, _player, _spawner, _drops);
		babby4 = new enemies.BabyBurd(x - 10, y - 10 + height, _player, _spawner, _drops);
		
		burdArray.add(babby);
		burdArray.add(babby2);
		burdArray.add(babby3);
		burdArray.add(babby4);
		
		enemArray.add(burdArray);
		
	}
}
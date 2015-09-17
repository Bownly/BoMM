package;

import BabyBurd;
import EnemyTemplate;
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
class Egg extends EnemyTemplate
{
	private var XSPEED:Int;
	private var GRAVITY:Int = 9800;
	private var _HP:Int = 1;

	private var _cracked:Bool = false;
	private var babby:BabyBurd;
	private var babby2:BabyBurd;
	private var babby3:BabyBurd;
	private var babby4:BabyBurd;
	private var burdArray:FlxTypedGroup<BabyBurd>;
	private var enemArray:FlxGroup;

	public function new(X:Float=0, Y:Float=0, ThePlayer:Player, DropsGrp:FlxTypedGroup<Drops>, XVel:Int, Enemies:FlxGroup) 
	{
		super(X, Y, ThePlayer, _HP, DropsGrp);
		XSPEED = XVel;
		
		loadGraphic("assets/images/burdegg.png", true, 16, 8);
		width = 16;
		height = 8;
		
		enemArray = Enemies;
		burdArray = new FlxTypedGroup<BabyBurd>();
		
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
		babby = new BabyBurd(x, y, _player, _drops);
		babby2 = new BabyBurd(x, y - 10, _player, _drops);
		babby3 = new BabyBurd(x + 10, y - 10 + height, _player, _drops);
		babby4 = new BabyBurd(x - 10, y - 10 + height, _player, _drops);
		
		burdArray.add(babby);
		burdArray.add(babby2);
		burdArray.add(babby3);
		burdArray.add(babby4);
		
		enemArray.add(burdArray);
		
	}
}
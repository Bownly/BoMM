package enemies;

import flixel.FlxSprite;
import flixel.group.FlxTypedGroup;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxRandom;
import weapons.Bullet;

/**
 * ...
 * @author me
 */

/*

	
	
	Sticking enemy.
	
  * 
  * */
 
 
 
class EnemyTemplate extends FlxSprite 
{
	private var _startx:Float;
	private var _starty:Float;
	private var _player:Player;
	private var _health:Int = 2;
	private var _drops:FlxTypedGroup<Drops>;
	public var _killed:Bool = false;
	private var _spawner:EnemySpawner;
	private var _palette:Int;
	
	private var GREY:Int = 0;
	private var CYAN:Int = 1;
	private var MAGENTA:Int = 2;
	private var YELLOW:Int = 3;

	
	public function new(X:Float, Y:Float, ThePlayer:Player, Spawner:EnemySpawner, Health:Int, DropsGrp:FlxTypedGroup<Drops>) 
	{
		super(X, Y);
		x = X;
		y = Y;
		_startx = X;
		_starty = Y;
		_player = ThePlayer;
		_health = Health;
		_drops = DropsGrp;
		_spawner = Spawner;
	}
	
	override public function update():Void 
	{
		if (!isOnScreen() && !_spawner.isOnScreen())
		{
			alive = false;
			exists = false;
		}
		
		super.update();
		
	}
	
	public function takeDamage(damage:Int):Void
	{
		// TODO quick blinking effect
		// TODO sound of being hurt
		_health -= damage;
		
		if (_health <= 0)
			kill();
	}
	
	override public function kill():Void
	{
		
		var dropChance = FlxRandom.intRanged(0, 265 - _player.luck * 10);
		//var dropChance = 1;
		
		/* Drop table
		 * name         | id| rarity| fraction|    index|
		 * small hp:    |  0|    15%|   38/256|  000-037|
		 * large hp:    |  2|     5%|   13/256|  038-050|
		 * small juice: |  4|    15%|   38/256|  051-088|
		 * large juice: |  6|     5%|   13/256|  089-101|
		 * small dosh:  |  8|    15%|   38/256|  102-139|
		 * large dosh:  | 10|     5%|   13/256|  140-152|
		*/
		var dropID:Int = -1;
		if (dropChance <= 37)
			dropID = 0;
		else if (dropChance <= 50)
			dropID = 2;
		else if (dropChance <= 88)
			dropID = 4;
		else if (dropChance <= 101)
			dropID = 6;
		else if (dropChance <= 139)
			dropID = 8;
		else if (dropChance <= 152)
			dropID = 10;
		
		if (dropID != -1)
		{
			var newDrop = new Drops(this.x, this.y, dropID, _player, true);
			_drops.add(newDrop);
		}
		
		_killed = true;
		alive = false;
		FlxTween.tween(this, { alpha:0, y:y - 16 }, .33, { ease:FlxEase.circOut, complete:finishKill } );
	}
	
	private function finishKill(_):Void
	{
		exists = false;
	}
	
	public function collideBadBullet(B:weapons.Bullet):Void
	{
		return;
	}
}
package;

import flixel.FlxSprite;
import flixel.group.FlxTypedGroup;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxRandom;

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

	
	public function new(X:Float, Y:Float, ThePlayer:Player, Health:Int, DropsGrp:FlxTypedGroup<Drops>) 
	{
		super(X, Y);
		_startx = X;
		_starty = Y;
		_player = ThePlayer;
		_health = Health;
		_drops = DropsGrp;
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
		var dropChance = FlxRandom.intRanged(0, 1);
		var dropChance = 1;
		var dropID = FlxRandom.intRanged(0, 3) * 2;
		
		var newDrop = new Drops(this.x, this.y, dropID, _player);
		_drops.add(newDrop);
		
		alive = false;
		FlxTween.tween(this, { alpha:0, y:y - 16 }, .33, { ease:FlxEase.circOut, complete:finishKill } );
	}
	
	private function finishKill(_):Void
	{

		
		exists = false;
	}
}
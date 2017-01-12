package;
import enemies.EnemyTemplate;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.group.FlxGroup;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;

/**
 * ...
 * @author ...
 */
class Testboss extends enemies.EnemyTemplate
{
	
	/* Stuff to do for a boss
	 * healthbar
	 * immune damage timer thing
	 * good ai...lol
	 * */
	
	
	private var XSPEED:Int = 0;
	private var GRAVITY:Int = 9800;
	private var GUN_DELAY:Float = 1.5;
	private var BULLET_SPEED:Int = 100;
	private var _HP:Int = 10;

	private var _bullets:FlxGroup;
	private var _cooldown:Float;
	
	private var playstate:PlayState;
	
	public function new(X:Float, Y:Float, ThePlayer:Player, DropsGrp:FlxTypedGroup<Drops>, Bullets:FlxGroup, Playstate:PlayState) 
	{
		super(X, Y, ThePlayer, _HP, DropsGrp);
		loadGraphic("assets/images/mcbeck.png", true, 34, 32);
		width = 16;
		height = 16;
		
		playstate = Playstate;
	}
	
	override public function finishKill(_):Void
	{
		super.finishKill(_);
		playstate.gotoNextLevel();
	}

}
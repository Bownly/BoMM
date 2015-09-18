package;
import flixel.addons.effects.FlxGlitchSprite;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.group.FlxTypedGroup;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxPoint;
import flixel.util.FlxPoint;

/**
 * ...
 * @author: me
 */
class Player extends FlxSprite
{
	private var jumpPower:Int = 2250;
	private var GRAVITY:Int = 690;
	private var XSPEED:Int = 200;
	private var remainingJumps:Int = 2;
	public var hp:Int = 3;
	
	// Stats
	private var MAXHP:Int = 3;
	private var MAXJUMPS:Int = 2;
	private var shotRange:Int = 10;
	private var _DAMAGE:Int = 1;
	private var _luck:Int = 5;
	
	private var bulletArray:FlxTypedGroup<Bullet>;
	private var _maxBullets:Int = 3;
	public var bulletCount:Int = 0;
	
	private var shootingString:String = "";
	private var postShotTimer:Float = 0;
	private var _cooldown:Float;

	
	private var touchingLadder:Bool = false;
	private var climbing:Bool = false;
	
	private var hurtTimer:Float = 0;
	private var _glitch:FlxGlitchSprite;
	
	
	public function new(inX:Int=0, inY:Int=0, Bullets:FlxTypedGroup<Bullet>) 
	{
		super(inX, inY);
		
		loadGraphic("assets/images/mm.png", true, 32, 32);
		width = 16;
		height = 22;
		offset = new FlxPoint(8, 4);
		
		/*loadGraphic("assets/images/mc.png", true, 16, 16);
		width = 10;
		height = 14;
		offset = new FlxPoint(3, 1);*/
		
		bulletArray = Bullets;
		
		//acceleration.y = GRAVITY;
		velocity.y = GRAVITY;
		
		maxVelocity.set(200, 200);
		drag.set(1600, 1600);
		
		animation.add("walk", [3, 2, 3, 4], 10, true);
		animation.add("idle", [0, 0, 0, 0, 0, 1], 3, true);
		animation.add("jump", [5], 15, true);
		animation.add("fall", [6], 15, true);
		animation.add("hurt", [5], 15, true);
		
		animation.add("walk_shoot", [10, 9, 10, 11], 10, true);
		animation.add("idle_shoot", [8], 3, true);
		animation.add("jump_shoot", [13], 15, true);
		animation.add("fall_shoot", [13], 15, true);
		
/*		animation.add("walk", [29, 30, 31], 10, true);
		animation.add("idle", [15, 16, 17], 3, true);
		animation.add("jump", [32], 15, true);
		animation.add("fall", [33], 15, true);
		animation.add("hurt", [19], 15, true);
		
		animation.add("walk_shoot", [71, 72, 73], 10, true);
		animation.add("idle_shoot", [46], 3, true);
		animation.add("jump_shoot", [57], 15, true);
		animation.add("fall_shoot", [58], 15, true);*/
		
	}
	
	/*
	So there are a few ways to handle weapon / player upgrades.
	1. Firstly, stats will just upgrade the _max vars. Simple enough.
	2. But what about the cyclable weapons that cost MP, like the proposed boss drop weapons?
	Right now I'm thinking about hardcoding in each of them in 2 arrays:
		one for storage purposes aka locked, and one for those accessible by the player aka unlocked.
	Should each be a class with an mp cost, damage amount, etc? Or are they Bullet objects? 
		Probably not. Maybe a melee weapon?
	3. Or perhaps weapons work with a flag system like "chargeable", "huge", "spread", etc.
	4. And in that vein, the Player should have those flags too. Maybe as params for Bullets?
	*/
	
	
	/*
	At this point in time it seems as though I have limited options without any actual art or
	concrete concepts. I could work on:
	1. bosses and/or a boss class/system
	2. touch up on some stuff like BabyBurd collision and random spread (but it's not a final enemy, probably, so why bother?)
	3. Title Screen?
	4. Weapons / upgrades systems / stats (save this for Mario)
	6. movement tweaking with the mc (kinda pointless without overhauling all of my maps...)
	7. ...which leads to making new levels...
	8. What to heck else is there to even do? Oh god it's all dependent on the art and music. 
	9. Adding powerups to treasure rooms, but then I'd have to make powerups first...
	10. Overhaul ladders. Make them oneway collidible. ...but how?
	11. Redo / overhaul the map stiching. It really is pretty bad atm. :T
	*/
	

	/*
	 * Is there any good reason why I would make a boss template class instead of just using enemyTemplate?
	 * I can't quite think of any. 
	 * Well what does a boss need that a normal enemy doesn't?
	 * An on death trigger to goto the next stage
	 * An on death trigger to unlock a new weapon for the player
	 * A health bar
	 * That... That's it I'm pretty sure. A health bar can be done in the level and I can always override kill()...
	 * But then again, I'd be writing essentially the same code each time. Hmm... I dunno.
	 * I'm leaning towards no BossTemplate class right now.
	 * */
	
		/* Moving tiles:
		 make them entities, but one for each square, or one entity per platform, and use a value thing for length?
		 I like the latter option more.
		 Oh shoot, can I make them the same class as falling platforms? 
		 Yes, I think I can
		 So, as entities, I have 2 params: direction and speed? At least direction...
		 Well at that point, what do the two have in common? They both move in one direction (or two!) following a trigger
		 The horizontal ones' trigger is spawning and the falling ones' trigger is the player steping on them. 
		 Well that's not too similar actually. Other than the fact that they are collidable objects...
		 
		 params(ish):
		 speed?
		 distance
		 direction
		 placement
		 size/length
		 
		 Eh, maybe these are too complicated for right now. No doubt I could ghetto-rig some implementation, 
		 but it would probably be a bad one.
		 
	*/
	
	override public function update():Void 
	{
		
		velocity.x = 0;
		
		if (hp <= 0)
			FlxTween.tween(this, { alpha:0 }, .33, { ease:FlxEase.circOut } );
		
		
		if (hurtTimer > 0)
			hurtTimer -= FlxG.elapsed;
		
		if (climbing)
			acceleration.y = 0;
		else
			acceleration.y = GRAVITY;
		
		if (this.isTouching(FlxObject.FLOOR))
			remainingJumps = MAXJUMPS;
		
		
		playerInputs();
		resolveAnimations();
		
		
		
		super.update();
	}

	private function playerInputs():Void
	{
		if (FlxG.keys.anyPressed(["LEFT", "A"]) && climbing == false) 
		{
			velocity.x = -XSPEED;
			flipX = true;
			climbing = false;
		} 
		else if (FlxG.keys.anyPressed(["RIGHT", "D"]) && climbing == false) 
		{
			velocity.x = XSPEED;
			flipX = false;
			climbing = false;
		}
		
		if (FlxG.keys.anyPressed(["UP", "W"]) && touchingLadder == true) 
		{
			velocity.y = -100;
			climbing = true;
			remainingJumps = MAXJUMPS;
		}
		
		if (FlxG.keys.anyPressed(["DOWN", "S"]) && touchingLadder == true)
		{
			velocity.y = 100;
			climbing = true;
			remainingJumps = MAXJUMPS;
		}
		
		if (FlxG.keys.anyJustPressed(["UP", "J"]) && remainingJumps > 0) 
		{
			velocity.y = -jumpPower;
			remainingJumps--;
			climbing = false;
		} 
		
		if (FlxG.keys.anyJustPressed(["SPACE", "K"]))
			shoot();
	}
	
	private function resolveAnimations():Void
	{
		if (postShotTimer > 0)
		{
			shootingString = "_shoot";
			postShotTimer -= FlxG.elapsed;	
		}
		else
			shootingString = "";
		
		if (velocity.x == 0 && hurtTimer <= 0) 
			animation.play("idle" + shootingString);
		
		if (velocity.x != 0)
			animation.play("walk" + shootingString);
		
		if (velocity.y < 0) 
			animation.play("jump" + shootingString);
		else if (velocity.y > 0) 
		{
			animation.play("fall" + shootingString);
			// prevent player from having max jumps after walking off a platform
			if (remainingJumps == MAXJUMPS)
				remainingJumps--;
			
		}
	}
	
	private function shoot():Void
	{

		if (bulletArray.countLiving() < _maxBullets) 
		{
			postShotTimer = .33;
			
			if (flipX)
			{
				var newBullet = new Bullet(x - 8, y + 8, 500, FlxObject.LEFT, _DAMAGE);
				bulletArray.add(newBullet);
			}
			else
			{
				var newBullet = new Bullet(x + 8, y + 8, 500, FlxObject.RIGHT, _DAMAGE);
				bulletArray.add(newBullet);
			}
		}
		
    }
	
	public function setTouchingLadder(bool:Bool):Void
	{
		touchingLadder = bool;
	}
	
	public function getHurt(dmg:Int):Void
	{
		if (hurtTimer <= 0)
		{
			hurtTimer = 1;
			hp -= dmg;
			animation.play("hurt");
		}
		
		
	}
	
}
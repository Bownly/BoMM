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
import weapons.Bullet;
import weapons.CyanWeapon;
import weapons.MagentaWeapon;
import weapons.WeaponTemplate;
import weapons.YellowWeapon;

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
	public var _DAMAGE:Int = 1;
	private var _luck:Int = 5;
	
	public var bulletArray:FlxTypedGroup<weapons.Bullet>;
	public var _maxBullets:Int = 3;
	public var bulletCount:Int = 0;
	
	// Weapons...?
	public var curWeaponLoc:Int;
	public var curWeapon:WeaponTemplate;
	public var weapon1:WeaponTemplate;
	public var weapon2:WeaponTemplate;
	public var weapon3:WeaponTemplate;
	public var weapon4:WeaponTemplate;
	public var weaponArray:Array<WeaponTemplate>;
	

	
	public var shootingString:String = "";
	public var postShotTimer:Float = 0;
	public var _cooldown:Float;

	
	private var touchingLadder:Bool = false;
	private var climbing:Bool = false;
	
	private var hurtTimer:Float = 0;
	private var _glitch:FlxGlitchSprite;
	
	
	public function new(inX:Int=0, inY:Int=0, Bullets:FlxTypedGroup<weapons.Bullet>) 
	{
		super(inX, inY);
		
		
		weapon1 = new WeaponTemplate("pea", bulletArray);
		weapon2 = new CyanWeapon("cyan", bulletArray);
		weapon3 = new YellowWeapon("yellow", bulletArray);
		weapon4 = new MagentaWeapon("magenta", bulletArray);
		
		weaponArray = [weapon1, weapon2, weapon3, weapon4];
		curWeaponLoc = 0;
		curWeapon = weaponArray[curWeaponLoc];
		
		loadGraphic("assets/images/mm.png", true, 32, 32);
		width = 16;
		height = 22;
		offset = new FlxPoint(8, 4);
		
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
		
		
	}
	

	
	/* So... let's talk weapons for a tick.
	 * 
	 * Since I have no idea how exactly weapons will be handled in this game, I want to layout the 
	 * most, uh, universal implementation right now. If that even makes sense.
	 * I want weapon switching in the game in some form asap even though I'll probably have to
	 * rewrite all of the code between now and completion. So, I want to try to minimize the amount
	 * that I'll have to rewrite.
	 * 
	 * Each main weapon will have its own Bullet class since they will all function differently
	 * Similarly, I think they'll have a shoot function that the player just calls. 
	 * Further, they'll have stats like damage and speed that will be parameters.
	 * The values passed will be the player's equiv stats and will be added to the bullet's default stats.
	 * 
	 * But... this only makes sense with a 3-4 weapon paradigm... or maybe it makes sense always. 
	 * I'm not too sure on that point.
	 * 
	 * Wait, shoot. It doesn't make much sense to have weapons be bullets bluhbluhbluh.
	 * I'm thinking that I might just make a weaponstemplate class and work like that... I think
	 * 
	 * Wait wait wait. So why do I need a weptemplate class? 
	 * I do think I need to overhaul the bullet class itself to add different types of bullets, or add bullet subclasses, BUT!
	 * I don't probably even need a weapontemplate class at all. If anything, I'd just give the player different parameters depending on
	 * which weapons are unlocked or not. I spoke about that earlier, but have since deleted that comment block.
	 * 
	 * Powerups for the player's base stats will be first in the form of drops with activation upon collision.
	 * 
	 * */
	
	
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
			
		if (FlxG.keys.anyJustPressed(["L"]))
			switchWeapon();
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
		curWeapon.shoot(this);
		
    }
	
	private function switchWeapon():Void
	{
		do 
		{
			curWeaponLoc++; 
			if (curWeaponLoc == weaponArray.length)
				curWeaponLoc = 0;
		}
		while (weaponArray[curWeaponLoc].unlocked == false);
		
		
		curWeapon = weaponArray[curWeaponLoc];
		
		if (curWeaponLoc == 0)  // pea atm
		{
			animation.add("walk", [3, 2, 3, 4], 10, true);
			animation.add("idle", [0, 0, 0, 0, 0, 1], 3, true);
			animation.add("jump", [5], 15, true);
			animation.add("fall", [6], 15, true);
			animation.add("hurt", [5], 15, true);
			
			animation.add("walk_shoot", [10, 9, 10, 11], 10, true);
			animation.add("idle_shoot", [8], 3, true);
			animation.add("jump_shoot", [13], 15, true);
			animation.add("fall_shoot", [13], 15, true);
		}
		else if (curWeaponLoc == 1)  // cyan atm
		{
			animation.add("walk", [31, 30, 31, 32], 10, true);
			animation.add("idle", [28, 28, 28, 28, 28, 29], 3, true);
			animation.add("jump", [33], 15, true);
			animation.add("fall", [34], 15, true);
			animation.add("hurt", [33], 15, true);
			
			animation.add("walk_shoot", [38, 37, 38, 39], 10, true);
			animation.add("idle_shoot", [35], 3, true);
			animation.add("jump_shoot", [40], 15, true);
			animation.add("fall_shoot", [40], 15, true);
		}
		else if (curWeaponLoc == 2)  // yellow atm
		{
			animation.add("walk", [17, 16, 17, 18], 10, true);
			animation.add("idle", [14, 14, 14, 14, 14, 15], 3, true);
			animation.add("jump", [19], 15, true);
			animation.add("fall", [20], 15, true);
			animation.add("hurt", [19], 15, true);
			
			animation.add("walk_shoot", [24, 23, 24, 25], 10, true);
			animation.add("idle_shoot", [21], 3, true);
			animation.add("jump_shoot", [26], 15, true);
			animation.add("fall_shoot", [26], 15, true);
		}
		else if (curWeaponLoc == 3)  // magenta atm
		{
			animation.add("walk", [45, 44, 45, 46], 10, true);
			animation.add("idle", [42, 42, 42, 42, 42, 43], 3, true);
			animation.add("jump", [47], 15, true);
			animation.add("fall", [48], 15, true);
			animation.add("hurt", [47], 15, true);
			
			animation.add("walk_shoot", [52, 51, 52, 53], 10, true);
			animation.add("idle_shoot", [49], 3, true);
			animation.add("jump_shoot", [54], 15, true);
			animation.add("fall_shoot", [54], 15, true);
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
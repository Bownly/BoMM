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
import weapons.EightWayWeapon;
import weapons.MagentaWeapon;
import weapons.WeaponTemplate;
import weapons.YellowWeapon;

/**
 * ...
 * @author: me
 */
class Player extends FlxSprite
{
	// vars from Reg.hx
	public var hp:Int = 3;
	public var maxHP:Int = 3;
	public var maxJumps:Int = 2;
	public var damage:Int = 1;
	public var luck:Int = 5;	
	
	var GRAVITY:Int = 690;
	var ySpeedJumping:Int = 2250;
	var ySpeedClimbing:Int = 75;
	var xSpeedWalking:Int = 138;
	var xSpeedSliding:Int = 250;
	var xSpeedHurt:Int = 50;
	var remainingJumps:Int = 2;
	var isSliding:Bool = false;
	var slideTimer:Float = 0;
	var slideDuration:Float = .33;

	public var bulletArray:FlxTypedGroup<weapons.Bullet>;
	public var maxBullets:Int = 3;
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
	public var cooldown:Float;

	
	private var touchingLadder:Bool = false;
	public var isClimbing:Bool = false;
	
	private var hurtTimer:Float = 0;
	
	private var canMove:Bool = true;
	
	
	public function new(inX:Int=0, inY:Int=0, Bullets:FlxTypedGroup<weapons.Bullet>) 
	{
		super(inX, inY);
		
		// sets up player's stats etc from Reg.hx values
		maxHP = Reg.pMaxHP;
		hp = maxHP;
		maxJumps = Reg.pMaxJumps;
		damage = Reg.pDamage;
		luck = Reg.pLuck;
		
		/*weapon1 = new WeaponTemplate("pea", bulletArray);
		weapon2 = new EightWayWeapon("cyan", bulletArray);
		weapon3 = new YellowWeapon("yellow", bulletArray);
		weapon4 = new MagentaWeapon("magenta", bulletArray);
		
		weaponArray = [weapon1, weapon2, weapon3, weapon4];
		curWeaponLoc = 0;
		*/
		weaponArray = Reg.weaponArray;
		curWeaponLoc = 0;
		curWeapon = weaponArray[curWeaponLoc];
		for (wpn in weaponArray)  // restores the weapons' ammo
		{
			wpn.juice = wpn.juiceMax;
		}
		
		bulletArray = Bullets;
		velocity.y = GRAVITY;
		maxVelocity.set(200, 200);
		drag.set(1600, 1600);
		
		loadGraphic(AssetPaths.mm__png, true, 32, 32);
		width = 14;
		height = 22;
		offset = new FlxPoint(8, 4);
		
		
		var offset = 18; // the amount of sprites in the sheet per color
		for (i in 0...3)
		{
			var o = i * offset;  // offseting for colors
			animation.add("idle_" + i, [0 + o, 0 + o, 0 + o, 0 + o, 0 + o, 1 + o], 3, true);
			animation.add("walk_" + i, [3 + o, 2 + o, 3 + o, 4 + o], 10, true);
			animation.add("jump_" + i, [5 + o], 15, true);
			animation.add("fall_" + i, [5 + o], 15, true);
			animation.add("hurt_" + i, [10 + o], 15, true);
			animation.add("climb_" + i, [6 + o, 7 + o], 5, true);
			animation.add("climbup_" + i, [15 + o], 15, true);
			animation.add("slide_" + i, [8 + o], 3, true);
			
			animation.add("idle_" + i + "_shoot", [9 + o]);
			animation.add("walk_" + i + "_shoot", [12 + o, 11 + o, 12 + o, 13 + o], 10, true);
			animation.add("jump_" + i + "_shoot", [14 + o], 15, true);
			animation.add("fall_" + i + "_shoot", [14 + o], 15, true);
			animation.add("climb_" + i + "_shoot", [15 + o], 1, true);
		}
		
	}
	

	/* General checklist
	 * 
	At this point in time it seems as though I have limited options without any actual art or
	concrete concepts. I could work on:
	1. bosses and/or a boss class/system
	2. touch up on some stuff like BabyBurd collision and random spread (but it's not a final enemy, probably, so why bother?)
	3. Title Screen?
	4. Weapons / upgrades systems / stats 
	6. movement tweaking with the mc (kinda pointless without overhauling all of my maps...)
	7. ...which leads to making new levels...
	8. What to heck else is there to even do? Oh god it's all dependent on the art and music. 
	9. Adding powerups to treasure rooms, but then I'd have to make powerups first...
	10. Overhaul ladders. Make them oneway collidible. ...but how?
	11. Redo / overhaul the map stiching. It really is pretty bad atm. :T
	12. STORE!!!!
	*/
	

	/* Boss musings
	 * 
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
	 make them ogmo entities, but one for each square, or one entity per platform, and use a value thing for length?
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
		
		if (hurtTimer > 0)  // todo, make immune time longer than forced move time, lol
		{
			canMove = false;
			if (facing == FlxObject.RIGHT)
				velocity.x = -xSpeedHurt;
			else
				velocity.x = xSpeedHurt;
			hurtTimer -= FlxG.elapsed;
		}
		else
			canMove = true;
			
		if (canMove == true) 
		{
			if (hp <= 0)
				FlxTween.tween(this, { alpha:0 }, .33, { ease:FlxEase.circOut } );
			
			
			if (isClimbing)
				acceleration.y = 0;
			else
				acceleration.y = GRAVITY;
			
			if (this.isTouching(FlxObject.FLOOR))
				remainingJumps = maxJumps;
			else
				slideTimer = 0;
			
			if (slideTimer > 0)
			{
				if (facing == FlxObject.RIGHT)
					velocity.x = xSpeedSliding;
				else
					velocity.x = -xSpeedSliding;
				slideTimer -= FlxG.elapsed;
			}
			else
				isSliding = false;
			
			playerInputs();
		}
		
		resolveAnimations();
		
		super.update();
	}

	override public function destroy():Void
	{
		/*Reg.pHP = hp;
		Reg.pMaxHP = maxHP;
		Reg.pMaxJumps = maxJumps;
		Reg.pDamage = damage;
		Reg.pLuck = luck;*/
		
		super.destroy();
	}
	
	public function enterBossDoor():Void
	{
		canMove = false;
		x += 32;
		canMove = true;
	}
	
	private function playerInputs():Void
	{
		//walking
		if (FlxG.keys.anyPressed(["RIGHT", "D"]) && isClimbing == false) 
		{
			if (isSliding)
				velocity.x = xSpeedSliding;
			else
				velocity.x = xSpeedWalking;
			flipX = false;
			facing = FlxObject.RIGHT;
			isClimbing = false;
		}
		else if (FlxG.keys.anyPressed(["LEFT", "A"]) && isClimbing == false) 
		{
			if (isSliding)
				velocity.x = -xSpeedSliding;
			else
				velocity.x = -xSpeedWalking;
			flipX = true;
			facing = FlxObject.LEFT;
			isClimbing = false;
		} 
		
		// left/right movement while climbing
		if (FlxG.keys.anyPressed(["LEFT", "A"]) && isClimbing) 
		{
			flipX = true;
			facing = FlxObject.LEFT;
		}
		else if (FlxG.keys.anyPressed(["RIGHT", "D"]) && isClimbing) 
		{
			flipX = false;
			facing = FlxObject.RIGHT;
		}
		
		// climbing up and down
		if (FlxG.keys.anyPressed(["UP", "W"]) && touchingLadder) 
		{
			velocity.y = -ySpeedClimbing;
			isClimbing = true;
			remainingJumps = maxJumps;
		}
		else if (FlxG.keys.anyPressed(["DOWN", "S"]) && touchingLadder)
		{
			velocity.y = ySpeedClimbing;
			isClimbing = true;
			remainingJumps = maxJumps;
		}
		
		// slide
		if (FlxG.keys.anyPressed(["DOWN", "S"]) && FlxG.keys.anyJustPressed(["J"]) && isTouching(FlxObject.FLOOR))
		{
			isSliding = true;
			slideTimer = slideDuration;
		}
		
		// jump
		if (FlxG.keys.anyJustPressed(["UP", "J"]) && remainingJumps > 0 && isSliding == false) 
		{
			if (isClimbing == false)
				velocity.y = -ySpeedJumping;
			remainingJumps--;
			isClimbing = false;
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
			
			
		if (velocity.x == 0 && hurtTimer <= 0 && isClimbing == false) 
			animation.play("idle_" + curWeaponLoc + shootingString);
		if (velocity.x == 0 && hurtTimer <= 0 && isClimbing) 
		{
			animation.play("climb_" + curWeaponLoc + shootingString);		
			animation.pause(); 	
		}
		if (velocity.x != 0 && isSliding == false)
			animation.play("walk_" + curWeaponLoc + shootingString);
		else if (velocity.x != 0 && isSliding)
			animation.play("slide_" + curWeaponLoc + shootingString);
		
		if (velocity.y != 0 && isClimbing) 
			animation.play("climb_" + curWeaponLoc + shootingString);			
		else if (velocity.y < 0) 
			animation.play("jump_" + curWeaponLoc + shootingString);
		else if (velocity.y > 0) 
		{
			animation.play("fall_" + curWeaponLoc + shootingString);
			// prevent player from having max jumps after walking off a platform
			if (remainingJumps == maxJumps)
				remainingJumps--;
		}
		
		if (hurtTimer > 0)
		{
			animation.play("hurt_" + curWeaponLoc);
		}
		
	}
	
	public function setTouchingLadder(bool:Bool):Void
	{
		touchingLadder = bool;
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
	}

	public function takeDamage(dmg:Int):Void
	{
		if (hurtTimer <= 0)
		{
			hurtTimer = 1;
			hp -= dmg;
			animation.play("hurt_" + curWeaponLoc);
		}		
	}	
	
}
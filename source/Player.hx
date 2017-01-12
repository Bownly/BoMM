package;
// import flixel.addons.effects.FlxGlitchSprite;
import flixel.effects.FlxFlicker;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.group.FlxGroup;
import flixel.system.FlxSound;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.math.FlxPoint;
// import flixel.math.FlxRandom;
// import neko.Random;
import weapons.Bullet;
import weapons.EightWayWeapon;
import weapons.WeaponTemplate;
import weapons.YellowWeapon;
using flixel.util.FlxSpriteUtil;

/**
 * ...
 * @author: me
 */
class Player extends FlxSprite
{
	// vars from Reg.hx
	public var hp:Int = 3;
	public var maxHP:Int = 3;
	public var maxMaxHP:Int = 12;
	public var maxJumps:Int = 2;
	public var damage:Int = 0;
	public var luck:Int = 5;	
	
	var GRAVITY:Int = 15;
	var xSpeedWalking:Int =  120;
	var xSpeedInAir:Int =    110;
	var xSpeedInching:Int =   20;
	var xSpeedSliding:Int =  250;
	var xSpeedHurt:Int =       0;
	var ySpeedJumping:Int =  300;
	var ySpeedClimbing:Int =  75;
	public var xSpeedBonus:Float = 0;
	public var ySpeedBonus:Float = 0;	
	var remainingJumps:Int = 2;
	
	var isSliding:Bool = false;
	var slideTimer:Float = 0;
	var slideDuration:Float = .33;

	var isInching:Bool = false;
	var inchingTimer:Float = 0;
	var inchingDuration:Float = .025;

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
	public var isClimbingUp:Bool = false;
	
	public var hurtTimer:Float = 0;
	public var invincTimer:Float = 0;
	public var stompTimer:Float = 0;
	
	private var canMove:Bool = true;
	
	var state:FlxState;

	var _sndArray:Array<FlxSound>;
	private var _sndShoot:FlxSound;
	private var _sndGetHit:FlxSound;	
	private var _sndStep:FlxSound;
	private var _sndJump:FlxSound;
	private var _sndSwitch:FlxSound;
 
	public function new(inX:Int=0, inY:Int=0, Bullets:FlxTypedGroup<weapons.Bullet>, ?State:FlxState) 
	{
		super(inX, inY);
		
		state = State;
		
		// sets up player's stats etc from Reg.hx values
		maxHP = Reg.pMaxHP;
		hp = maxHP;
		maxJumps = Reg.pMaxJumps;
		damage = Reg.pDamage;
		luck = Reg.pLuck;
		
		weaponArray = Reg.weaponArray;
		curWeaponLoc = 0;
		curWeapon = weaponArray[curWeaponLoc];
		for (wpn in weaponArray)  // restores the weapons' ammo
		{
			wpn.juice = wpn.juiceMax;
		}
		bulletArray = Bullets;
		
		velocity.y = GRAVITY;
		
		drag.set(0, 0);
		
		loadGraphic(AssetPaths.mcgurlhair__png, true, 32, 32);
		width = 14;
		height = 22;
		offset = new FlxPoint(9, 6);
		
		
		_sndShoot = FlxG.sound.load(AssetPaths.player_shoot__wav, .7);
		_sndGetHit = FlxG.sound.load(AssetPaths.player_hit__wav, .33);
		_sndJump = FlxG.sound.load(AssetPaths.player_jump__wav, .2);
		_sndSwitch = FlxG.sound.load(AssetPaths.switch_weapon__wav, .15);
		//_sndArray = new Array<FlxSound>();
		/*for (i in 1...11)
		{
			_sndStep = FlxG.sound.load("assets/sounds/forest_run_" + i + ".wav", .1);
			_sndArray.push(_sndStep);
		}*/
		
		
		var offset = 18; // the amount of sprites in the sheet per color
		for (i in 0...3)
		{
			var o = i * offset;  // offseting for colors
			animation.add("idle_" + i, [0 + o, 0 + o, 0 + o, 1 + o, 1 + o, 1 + o], 3, true);
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
		
		// these are for mcgurl(hair).png
		for (i in 0...4) 
		{
			var o = 24 * i;
			
			animation.add("idle_" + i, [0 + o, 1 + o], 3, true);
			animation.add("walk_" + i, [3 + o, 4 + o, 5 + o, 4 + o], 8, true);
			animation.add("inch_" + i, [16 + o], 8, true);
			animation.add("jump_" + i, [11 + o]);
			animation.add("fall_" + i, [12 + o]);
			animation.add("hurt_" + i, [15 + o]);
			animation.add("climb_" + i, [17 + o, 18 + o], 7, true); 
			animation.add("climbup_" + i, [21 + o], 7, true); 
			
			animation.add("walk_" + i + "_shoot", [8 + o, 9 + o, 10 + o, 9 + o], 8, true);
			animation.add("idle_" + i + "_shoot", [2 + o]);
			animation.add("inch_" + i + "_shoot", [2 + o]);
			animation.add("jump_" + i + "_shoot", [13 + o]);
			animation.add("fall_" + i + "_shoot", [14 + o]);
			animation.add("climb_" + i + "_shoot", [20 + o], 7, true); 
		}
		
	}
	

	
	override public function update(elapsed:Float):Void 
	{
		
		if (stompTimer > 0)
		{
			stompTimer -= FlxG.elapsed;
		}	
		if (!touchingLadder)
			isClimbing = false;
		
		if (inchingTimer > 0)
			inchingTimer -= FlxG.elapsed;		
		else
			isInching = false;
		
		if (hurtTimer > 0) 
		{
			if (velocity.y < 0)
				velocity.y = 0;
			if (!isClimbing)
				velocity.y += GRAVITY;
				
			canMove = false;
			if (facing == FlxObject.RIGHT)
				velocity.x = -xSpeedHurt;
			else
				velocity.x = xSpeedHurt;
			hurtTimer -= FlxG.elapsed;
		}
		else
			canMove = true;
		
		if (invincTimer > 0)
			invincTimer -= FlxG.elapsed;
			
		// walking sound
		/*if ((velocity.x != 0 ) && touching == FlxObject.FLOOR)
		{
			var id = FlxRandom.intRanged(0, _sndArray.length - 1);
			_sndArray[id].play();
		}*/
		
		
		if (canMove == true) 
		{			
			if (isClimbing)
				velocity.y = 0;
			else
				velocity.y += GRAVITY;
			
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
		
		velocity.x += xSpeedBonus;
		velocity.y += ySpeedBonus;
		
		super.update(elapsed);
	}

	override public function destroy():Void
	{
		/*Reg.pHP = hp;
		Reg.pMaxHP = maxHP;
		Reg.pMaxJumps = maxJumps;
		Reg.pDamage = damage;
		Reg.pLuck = luck;*/
		
		Reg.pMaxHP = maxHP;
		Reg.pMaxMaxHP = maxMaxHP;
		
		
		super.destroy();
	}
	
	
	public function enterBossDoor():Void
	{
		canMove = false;
		x += 32;
		canMove = true;
	}
	
	public function increaseMaxHP(Val:Int):Void
	{
		maxHP += Val;
		if (maxHP > maxMaxHP)
			maxHP = maxMaxHP;
		hp = maxHP;
	}
	
	private function killed():Void
	{
		//open dead state
		visible = false;
		var sub = new DeadState(this);
		state.openSubState(sub);
	}
	
	private function playerInputs():Void
	{
		//walking
		if (FlxG.keys.anyPressed(["RIGHT", "D"]) && isClimbing == false) 
		{
			if (animation.name.substr(0, 4) == "idle") 
			{
				inchingTimer = inchingDuration;
				isInching = true;
			}
			if (isSliding)
				velocity.x = xSpeedSliding;
			else if (isInching)
				velocity.x = xSpeedInching;
			else if (!isTouching(FlxObject.FLOOR))
				velocity.x = xSpeedInAir;
			else 
				velocity.x = xSpeedWalking;
			flipX = false;
			facing = FlxObject.RIGHT;
			isClimbing = false;
			
		}
		else if (FlxG.keys.anyPressed(["LEFT", "A"]) && isClimbing == false) 
		{
			if (animation.name.substr(0, 4) == "idle") 
			{
				inchingTimer = inchingDuration;
				isInching = true;
			}
			if (isSliding)
				velocity.x = -xSpeedSliding;
			else if (isInching)
				velocity.x = -xSpeedInching;
			else if (!isTouching(FlxObject.FLOOR))
				velocity.x = -xSpeedInAir;
			else
				velocity.x = -xSpeedWalking;
			flipX = true;
			facing = FlxObject.LEFT;
			isClimbing = false;
			
		} 
		else
			velocity.x = 0;
		
		
		// move 1px. For debug/testing stuff
		if (FlxG.keys.anyJustPressed(["H"]) && isClimbing == false) 
		{
			x += 1;
			flipX = false;
			facing = FlxObject.RIGHT;
			isClimbing = false;
		}
		else if (FlxG.keys.anyJustPressed(["G"]) && isClimbing == false) 
		{
			x -= 1;
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
		else if (FlxG.keys.anyPressed(["DOWN", "S"]) && isClimbing)
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
		if (FlxG.keys.anyJustPressed(["UP", "J"]) && isSliding == false) 
		{
			if (remainingJumps > 0 && (isTouching(FlxObject.FLOOR) || isClimbing)) 
			{
				if (isClimbing == false)
					velocity.y = -ySpeedJumping;
				remainingJumps--;
				remainingJumps--;
				isClimbing = false;
				state.add(new JumpPuff(x - 1, y + height - 16, curWeaponLoc)); // the "6" is the height of the jumppuff sprite
				_sndJump.play();
			}
			else if (curWeapon.doubleJump && !isTouching(FlxObject.FLOOR) && curWeapon.isUsable())
			{
				curWeapon.juice -= curWeapon.juiceCost;
				velocity.y = -ySpeedJumping;
				state.add(new JumpPuff(x, y + height - 6, curWeaponLoc));
				_sndJump.play();
			}		
			
		} 	
		else if (!FlxG.keys.anyPressed(["UP", "J"]) && velocity.y < -150)
			velocity.y = -100;
		
		
		//shoot
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
		if (velocity.x != 0 && isSliding == false && isInching == false)
			animation.play("walk_" + curWeaponLoc + shootingString);
		else if (velocity.x != 0 && isSliding == false && isInching)
			animation.play("inch_" + curWeaponLoc + shootingString);
		else if (velocity.x != 0 && isSliding)
			animation.play("slide_" + curWeaponLoc);
		
		if (velocity.y != 0 && isClimbing) 
			animation.play("climb_" + curWeaponLoc + shootingString);	
		else if (velocity.y == 0 && isClimbing)
			animation.pause();
		else if (velocity.y <= 0) 
		{
			animation.play("jump_" + curWeaponLoc + shootingString);
		}
		else if (velocity.y > 0 && !isTouching(FlxObject.FLOOR))
		{
			animation.play("fall_" + curWeaponLoc + shootingString);
			// prevent player from having max jumps after walking off a platform
			if (remainingJumps == maxJumps)
				remainingJumps--;
		}
		if (isClimbingUp) 
		{
			animation.play("climbup_" + curWeaponLoc);
		}
		if (hurtTimer > 0)
		{
			animation.play("hurt_" + curWeaponLoc);
		}
		
	}
	public function restoreJuice(Val:Int):Void
	{
		curWeapon.juice += Val;
		if (curWeapon.juice > curWeapon.juiceMax)
			curWeapon.juice = curWeapon.juiceMax;
	}
	public function restoreHP(Val:Int):Void
	{
		hp += Val;
		if (hp > maxHP)
			hp = maxHP;
	}

	public function setTouchingLadder(bool:Bool):Void
	{
		touchingLadder = bool;
	}
	
	private function shoot():Void
	{
		curWeapon.shoot(this);
		_sndShoot.play(true);
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
		_sndSwitch.play(true);
		
		curWeapon = weaponArray[curWeaponLoc];
	}

	public function takeDamage(dmg:Int):Void
	{
		if (invincTimer <= 0)
		{
			_sndGetHit.play();
			hurtTimer = .5;
			hp -= dmg;
			if (dmg != 0 && hp > 0)
			{
				invincTimer = 1.5;
				FlxFlicker.flicker(this, 1.5, .1, true, false, null, null);
			}
			if (hp <= 0)
			{
				hp = 0;
				killed();
				//FlxG.switchState(new MenuState());
			}
			animation.play("hurt_" + curWeaponLoc);
		}		
	}	
	
}
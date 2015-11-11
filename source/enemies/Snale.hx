package enemies;
import enemies.EnemyTemplate;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxPoint;

/**
 * ...
 * @author ...
 */
class Snale extends enemies.EnemyTemplate
{
	//private var XSPEED:Int = 25;
	private var XSPEED:Int = 0;
	private var GRAVITY:Int = 98;
	private var GUN_DELAY:Float = .5;
	private var BULLET_SPEED:Int = 100;
	private var _HP:Int = 2;

	var _bulletDmg:Int = 1;
	var _bulletXVel:Int = 200;
	private var _bullets:FlxGroup;
	private var _cooldown:Float;
	var shotCount:Int = 0;
	var shotCountMax:Int = 2;
	
	var palette:Int;
	
	var isHiding:Bool = true;
	var hideTimer:Float = 5;
	var hideDuration:Float = 2;
	
	public function new(X:Float, Y:Float, ThePlayer:Player, Spawner:EnemySpawner, DropsGrp:FlxTypedGroup<Drops>, Enemies:FlxGroup, Bullets:FlxGroup, Palette:Int) 
	{
		super(X, Y, ThePlayer, Spawner, _HP, DropsGrp);
		loadGraphic("assets/images/snale.png", true, 16, 16);
		width = 12;
		height = 11;
		offset = new FlxPoint(2, 5);
		
		palette = Palette;
		_bullets = Bullets;
		_cooldown = 0;
		
		//flipX = true;
		velocity.y = GRAVITY;
		
		if (palette == Reg.G)
		{
			GUN_DELAY = 1;
			shotCountMax = 1;
		}
		else if (palette == Reg.C)
		{
			GUN_DELAY = .33;
			shotCountMax = 3;
		}
		
		else if (palette == Reg.M)
		{
			_bulletDmg = 3;
			_bulletXVel = 75;
			GUN_DELAY = 1;
		}
		
		var o = 6; // the amount of sprites in the sheet per color
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
		
		animation.add("hide", [0 + o, 1 + o, 2 + o, 3 + o, 4 + o, 5 + o], 15, false);
		animation.add("open", [5 + o, 4 + o, 3 + o, 2 + o, 1 + o, 0 + o], 15, false);		
	}
	
	public override function update():Void
	{
		if (alive)
		{
			// controls when snale hides and opens
			if (hideTimer >= hideDuration) 
			{
				if (isHiding)
				{
					animation.play("open");
					isHiding = false;
					hideTimer = 0;
				}
				else
				{
					animation.play("hide");
					isHiding = true;
					if (palette != Reg.Y)
						hideTimer = 0;
					else
						hideTimer = -2;
					shotCount = 0;
				}
			}
			
			// controls which direction snail faces
			if (_player.x > x)
			{					
				facing = FlxObject.RIGHT; 
				flipX = true;
			}
			else if (_player.x < x)
			{
				facing = FlxObject.LEFT;
				flipX = false;
			}
			
			if (!isHiding)
			{
				shoot(_player);
				_cooldown += FlxG.elapsed;
			}
			hideTimer += FlxG.elapsed;
		}
		super.update();
		
	}
	
	private function shoot(P:Player):Void 
	{
		// Bullet code will go here
		var bulletX:Int = Math.floor(x);
		var bulletY:Int = Math.floor(y + 4);
		
		if (_cooldown > GUN_DELAY && shotCount < shotCountMax)
		{	
			var bullet = new weapons.Bullet(x + 8, y, _bulletXVel, facing, _bulletDmg, 256, palette, facing);
			_bullets.add(bullet);
			shotCount++;
			// reset the shot clock
			_cooldown = 0; 
		}
	}
	
	public override function takeDamage(damage:Int):Void
	{
		if (animation.frameIndex != 5)
		{
			// TODO quick blinking effect
			// TODO sound of being hurt
			_health -= damage;
			
			if (_health <= 0)
				kill();
		}
	}
	
}
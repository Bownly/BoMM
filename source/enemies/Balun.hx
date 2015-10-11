package enemies;

import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;

/**
 * ...
 * @author me
 */
class Balun extends EnemyTemplate
{

	/* Todo
	 * 
	 * 2 make the projectiles better (requires an overhaul of the bullet class probably.
	 * 3 why is color even an Int? It could just be a string the whole way through, right?
	 * 5 fix the weirdness of the string colliding through the ground somehow. It's not exactly a layers issue.
	 * 6 fix the stupid non-collision bs bluhbluhbluh
	 * 7 move shoot outside of movement
	 * */
	
	private var palette:Int = 0;
	private var colorString:String = "grey";

	private var idealY:Float;
	private var XSPEED:Int = 35;
	private var GRAVITY:Int = 0;
	private var _HP:Int = 20;
	
	private var GUN_DELAY:Float = 1.5;
	private var BULLET_SPEED:Int = 100;
	private var _bullets:FlxGroup;
	private var _cooldown:Float = 0;
	
	private var tail:BalunString;
	
	public function new(X:Float, Y:Float, ThePlayer:Player, DropsGrp:FlxTypedGroup<Drops>, Enemies:FlxGroup, Bullets:FlxGroup, Color:Int) 
	{
		super(X, Y, ThePlayer, _HP, DropsGrp);
		
		palette = Color;
		tail = new BalunString(x, y + 16, ThePlayer, DropsGrp);
		Enemies.add(tail);
		
		loadGraphic("assets/images/balun.png", true, 16, 16);
		width = 16;
		height = 16;
		
		_bullets = Bullets;
		
		switch(palette)
		{
			case Reg.G:
				colorString = "grey";
			case Reg.C:
				colorString = "cyan";
			case Reg.M:
				colorString = "magenta";
			case Reg.Y:
				colorString = "yellow";
			
		}	
		
		animation.add("grey", [0]);
		animation.add("grey2", [1]);
		animation.add("yellow", [2]);
		animation.add("yellow2", [3]);
		animation.add("cyan", [4]);
		animation.add("cyan2", [5]);
		animation.add("magenta", [6]);
		animation.add("magenta2", [7]);
	}
	
	override public function update():Void
	{
		if (isOnScreen()) 
		{
			
			
			
			// This mess is just for testing
			if (FlxG.keys.anyJustPressed(["C"])) 
			{
		
				switch(palette)
				{
					case Reg.G:
					{
						palette = Reg.C;
						colorString = "cyan";
					}
					case Reg.C:
					{
						palette = Reg.M;
						colorString = "magenta";
					}
					case Reg.M:
					{
						palette = Reg.Y;
						colorString = "yellow";
					}
					case Reg.Y:
					{
						palette = Reg.G;
						colorString = "grey";
					}
					
				}
			 
			}
			
				
			
			velocity.x = velocity.y = 0;
			
			var xdistance:Float = _player.x - x;
			var ydistance:Float = _player.y - y; 
			var distancesquared:Float = xdistance * xdistance + ydistance * ydistance; 
			acceleration.y = GRAVITY;
			
			
			if (distancesquared < 24000) 
			{
					
				if (Math.floor(_player.x) < x)
				{							
					// The sprite is facing the opposite direction than flixel is expecting, so hack it into the right direction
					facing = FlxObject.RIGHT; 
					flipX = false;
					switch (colorString) 
					{
						case "grey":
						{
							x -= 1;
							tail._moving = FlxObject.RIGHT;
						}
						case "yellow":
						{
							x -= 1;
							tail._moving = FlxObject.RIGHT;
						}
						case "cyan":
						{
							x += 1;
							tail._moving = FlxObject.LEFT;
							shoot(_player);
						}
						case "magenta":
						{
							x -= 1;
							tail._moving = FlxObject.RIGHT;
							shoot(_player);
						}
					}
				}
				else if (Math.floor(_player.x) > x)
				{
					facing = FlxObject.LEFT;
					flipX = true;
					switch (colorString) 
					{
						case "grey":
						{
							x += 1;
							tail._moving = FlxObject.LEFT;
						}
						case "yellow":
						{
							x += 1;
							tail._moving = FlxObject.LEFT;
						}
						case "cyan":
						{
							x -= 1;
							tail._moving = FlxObject.RIGHT;
							shoot(_player);
						}
						case "magenta":
						{
							x += 1;
							tail._moving = FlxObject.LEFT;
						}
					}
				}
				else
					tail._moving = FlxObject.NONE;
				
					
				idealY = _player.y - 8;
				if (colorString == "magenta")
					idealY = _player.y - 40;
					
				if (y > idealY)
					y -= 1;
				else if (y < idealY)
					y += 1;

				/*if (y > idealY)
					velocity.y = -XSPEED;
				else if (y < idealY)
					velocity.y = XSPEED;
				else
					velocity.y = 0;*/
			}
			
			// Animation
			resolveAnims();
			
			_cooldown += FlxG.elapsed;
			
			if (tail.alive)
			{
				tail.x = this.x;
				tail.y = this.y + 16;
			}
			
			super.update();
		}
	}
	
	private function shoot(P:Player):Void 
	{
		// Bullet code will go here
		var bulletX:Int = Math.floor(x);
		var bulletY:Int = Math.floor(y + 4);
		
		if (_cooldown > GUN_DELAY)
		{
			
			if (colorString == "cyan")
			{
				if (P.x < x)
				{
					var bullet = new weapons.Bullet(x + 8, y + 8, 500, FlxObject.LEFT, 1, 256);
					_bullets.add(bullet);			
				}
				else
				{
					var bullet = new weapons.Bullet(x + 8, y + 8, 500, FlxObject.RIGHT, 1, 256);
					_bullets.add(bullet);			
				}
			}
			else if (colorString == "magenta")
			{
				var bullet = new weapons.Bullet(x + 8, y + 8, 500, FlxObject.DOWN, 1, 256);
				_bullets.add(bullet);	
			}
			
			// reset the shot clock
			_cooldown = 0; 
			
		}
	}
	
	private function resolveAnims():Void
	{	
		
		// Animation
		if ((velocity.x == 0) && (velocity.y == 0)) 
		{ 
			animation.play(colorString); 
		}
		else 
		{
			animation.play(colorString + "2");
		}
	}
	
	override public function kill():Void
	{
		tail.alive = false;
		tail.exists = false;
		super.kill();
	}
	

}
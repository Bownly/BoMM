package enemies;
import enemies.EnemyTemplate;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.group.FlxTypedGroup;
import flixel.tile.FlxTilemap;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxPoint;

/**
 * ...
 * @author ...
 */

 // TODO: This dude needs walls to bump into or will run off the edge...
 
class Snaake extends enemies.EnemyTemplate
{
	private var XSPEED:Int = 50;
	private var XSPEED1:Int = 50;
	private var XSPEED2:Int = 100;
	private var GRAVITY:Int = 200;
	private var _HP:Int = 1;
	private var palette:Int = Reg.G;	
	private var map:FlxTilemap;

	public function new(X:Float, Y:Float, ThePlayer:Player, DropsGrp:FlxTypedGroup<Drops>, Palette:Int, Room:FlxTilemap) 
	{
		super(X, Y, ThePlayer, _HP, DropsGrp);
		loadGraphic("assets/images/crawler.png", true, 16, 8);
		width = 16;
		height = 8;
		offset = new FlxPoint(0, -2);
		
		palette = Palette;
		map = Room;
		
		facing = FlxObject.LEFT; 
		//flipX = true;	
		
		var o = 2; // the amount of sprites in the sheet per color
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
		animation.add("walk", [0 + o, 1 + o], 8, true);
		
	}
	
	public override function update():Void
	{
		if (isOnScreen()) 
		{			
			velocity.x = XSPEED;
			
			animation.play("walk");
			if (!isTouching(FlxObject.FLOOR))
				acceleration.y = GRAVITY;

			
//			if (isTouching(FlxObject.WALL) || velocity.y > 0)
//				turnAround();
			
			horizontalMovement();
			
			switch (palette)
			{
				case Reg.G:
				{
					XSPEED = XSPEED1;
				}
				case Reg.C:
				{
					if ((_player.y + _player.height) == (y + height))
						XSPEED = XSPEED2;
					else
						XSPEED = XSPEED1;
				}
				case Reg.M:
				{
					XSPEED = XSPEED2;
					//if (isTouching(FlxObject.FLOOR))
						//velocity.y = -100;	
				}
				case Reg.Y:
				{
					if ((_player.y + _player.height) == (y + height))
						XSPEED = XSPEED1;
					else
						XSPEED = XSPEED2;
				}
					
			}
			
			if (flipX == true)
				XSPEED *= -1;
				
		}
			super.update();
	}
	
	public function turnAround():Void
	{
		XSPEED = -XSPEED;
		
		if (facing == FlxObject.RIGHT)
		{
			facing = FlxObject.LEFT; 
			flipX = true;	
			this.x += XSPEED/25;
		}
		else 
		{
			facing = FlxObject.RIGHT; 
			flipX = false;
			this.x += XSPEED/25;
		}
		return;
	}

	public function horizontalMovement():Void
	{
		if (!flipX && (isTouching(FlxObject.RIGHT) || map.getTile( Math.floor((x + width - map.x) / Reg.TILESIZE ), Math.floor((y + height - map.y) / Reg.TILESIZE )) == -1 ))
		{
			turnAround();
		}		
		if (flipX && (isTouching(FlxObject.LEFT) || map.getTile( Math.floor((x - map.x) / Reg.TILESIZE ), Math.floor((y + height - map.y) / Reg.TILESIZE )) == -1 ))
		{
			turnAround();
		}
	}
	
}
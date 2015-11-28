package enemies;
import flixel.FlxObject;
import flixel.group.FlxTypedGroup;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxRandom;

/**
 * ...
 * @author ...
 * TODO: make them not collide with walls, lol
 */
class BeeBabby extends enemies.EnemyTemplate
{
	var SPEED:Int = 50;
	private var XSPEED:Int;
	private var YSPEED:Int;
	private var _HP:Int = 1;
	var palette:Int = Reg.G;
	
	public function new(X:Float, Y:Float, ThePlayer:Player, Spawner:EnemySpawner, DropsGrp:FlxTypedGroup<Drops>, Palette:Int) 
	{
		super(X, Y, ThePlayer, Spawner, _HP, DropsGrp);
		
		var xdistance:Float = Math.abs(_player.x - x);
		var ydistance:Float = Math.abs(_player.y - y);
		var angle:Float = Math.atan(ydistance / xdistance);
		
		var _randSpeedFactor:Float = FlxRandom.floatRanged(.9, 1.1);
		XSPEED = Math.floor(SPEED * Math.cos(angle) * _randSpeedFactor);
		YSPEED = Math.floor(SPEED * Math.sin(angle) * _randSpeedFactor);
		
		
		velocity.x = XSPEED;
		velocity.y = YSPEED;
		
		loadGraphic("assets/images/beebabby.png", true, 8, 8);
		width = 8;
		height = 8;
		
		palette = Palette;
		
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
		
		animation.add("flap", [0 + o, 1 + o], 5, true);
		
		if (_player.x < x)
		{
			// The sprite is facing the opposite direction than flixel is expecting, so hack it into the right direction
			facing = FlxObject.RIGHT; 
			flipX = false;
			velocity.x = -XSPEED;
		}
		else if (_player.x > x)
		{
			facing = FlxObject.LEFT;
			flipX = true;
			velocity.x = XSPEED;
		}
		if (_player.y < y)
			velocity.y = -YSPEED;
		else
			velocity.y = YSPEED;
	}
	
	public override function update():Void
	{	
		animation.play("flap");
		
		super.update();
	}

}
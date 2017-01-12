package enemies;

import flixel.group.FlxGroup;
import flixel.math.FlxPoint;

/**
 * ...
 * @author ...
 */
class CoolSun extends EnemyTemplate
{
	private var _HP:Int = 5;

	var _sinTimer:Float = 0;
	var _sinSpeed:Float = .05;
	var _cosTimer:Float = 0;
	var _cosSpeed:Float = .25;
	var _numBlocksTravelled:Float = 7;
	//var hideDuration:Float = 2;
	
	public function new(X:Float, Y:Float, ThePlayer:Player, Spawner:EnemySpawner, DropsGrp:FlxTypedGroup<Drops>, Bullets:FlxGroup, Palette:Int) 
	{
		super(X, Y, ThePlayer, Spawner, _HP, DropsGrp);
		
		_palette = Palette;
		
		if (_palette == Reg.C)
		{
			_sinSpeed = .1;
		}
		
		loadGraphic("assets/images/enemy_coolsun.png", true, 32, 32);
		width = 19;
		height = 18;
		offset = new FlxPoint(7, 6);
		var o = 6; // the amount of sprites in the sheet per color
		switch (_palette)
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
		
		animation.add("idle", [0 + o, 1 + o, 2 + o, 3 + o, 4 + o, 5 + o], 8, true);
		animation.play("idle");
	}

	
	public override function update(elapsed:Float):Void
	{
		if (alive)
		{
			_sinTimer += _sinSpeed;
			if (_palette == Reg.C)
				y += Math.cos(_sinTimer) * _numBlocksTravelled / 1.5;
			else
				y += Math.cos(_sinTimer) * _numBlocksTravelled / 3;
			
			_cosTimer += _cosSpeed;
			if (_palette == Reg.Y)
				x -= Math.cos(_cosTimer) * 1.5;
			
		}
		super.update(elapsed);
		
	}
	
	
}
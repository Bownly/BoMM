package enemies;

import flixel.FlxObject;
import flixel.group.FlxTypedGroup;
import flixel.util.FlxPoint;

/**
 * ...
 * @author ...
 */
class Lightning extends EnemyTemplate
{
	private var GRAVITY:Int = 700;
	private var _HP:Int = 5;
	private var palette:Int = Reg.G;	
	var activated:Bool = false;

	public function new(X:Float, Y:Float, ThePlayer:Player, Spawner:EnemySpawner, DropsGrp:FlxTypedGroup<Drops>, Palette:Int) 
	{
		super(X, Y, ThePlayer, Spawner, _HP, DropsGrp);
		loadGraphic("assets/images/lightning_fall.png", true, 16, 16);
		width = 10;
		height = 16;
		offset = new FlxPoint(0, 0);
		
		y -= 4;
		x += 3;
		
		var o = 1; // the amount of sprites in the sheet per color
		switch (Palette)
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
		
		animation.add("anim", [0]);
		animation.play("anim");
	}
	
	public override function update():Void
	{
		if (isOnScreen()) 
		{
			var xdistance:Float = Math.abs(_player.x - x);
			if (xdistance < 30 && !activated) 
			{
				activated = true;
				velocity.y = 300;
			}		
			
			//resolveAnimations();
			
			if (isTouching(FlxObject.ANY))
			{
				alive = false;
				visible = false;
			}
				
			
		}
			super.update();
	}

	public function resolveAnimations():Void
	{
	
		if (velocity.y == 0 && activated == false)
			animation.play("idle");
		else if (velocity.y > 0)
			animation.play("fall");
		if (velocity.y == 0 && activated)
			animation.play("flail");
	}
	
	
}
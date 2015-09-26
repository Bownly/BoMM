package;

import flixel.FlxSprite;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;

/**
 * ...
 * @author ...
 */
class Drops extends FlxSprite
{
	private var _player:Player;
	
	public var i:Int = 0;
	public var price:Int = 0;
	public var free:Bool = true;
	
	/* Legend for drops:
	 * 0 = Mushroom
	 * 2 = Butterfly
	 * 4 = Juice goblet
	 * 6 = Sword in stone
	 */
	
	public function new(X:Float=0, Y:Float=0, Index:Int, ThePlayer:Player, Free:Bool) 
	{
		super(X, Y);
		loadGraphic(AssetPaths.drops__png, false, 8, 8);
		width = 8;
		height = 8;
		
		free = Free;
		
		_player = ThePlayer;
		i = Index;
		
		animation.add("idle", [i, i+1], 5, true);
		
		price = allocatePrices();
		
	}
	
	public override function update():Void
	{
		if (isOnScreen())
		{
			animation.play("idle");
			super.update();
		}
	}
	
	public function allocatePrices():Int
	{
		switch(i)
		{
			case 0:  // do Mushroom stuff
				return 10;
			case 2:  // do Butterfly stuff
				return 20;
			case 4:  // do Juice goblet stuff
				return 10;
			case 6:  // do sword in stone stuff
				return 30;
		}
		return 0;
	}
	
	private function playerHeal(Val:Int):Void
	{
		_player.hp += Val;
	}
	
	private function playerJuiceRestore(Val:Int):Void
	{
		if (_player.curWeapon.juice + Val > _player.curWeapon.juiceMax)
			_player.curWeapon.juice = _player.curWeapon.juiceMax;
		else
			_player.curWeapon.juice += Val;
	}
	
	private function weaponStrengthUp(Val:Int):Void
	{
		_player.curWeapon.damage += Val;
	}
	
	
	public function doStuff(score:Int):Int  // called on collision with player
	{
		if (price <= score || free == true)
		{
			trace("score: " + score);
			trace("price: " + price);
			switch(i)
			{
				case 0:
					// do Mushroom stuff
					playerHeal(10);
				case 2:
					// do Butterfly stuff
					playerHeal(20);
				case 4:
					// do Juice goblet stuff
					playerJuiceRestore(5);
				case 6:
					// do sword in stone stuff
					weaponStrengthUp(1);
			}
//			score -= price;
			if (free == true)
			{
				this.kill();
				return 0;
			}
			else
			{
				this.kill();	
				return price;	
			}
		}
		return 0;
	}
	
	override public function kill():Void
	{
		alive = false;
		FlxTween.tween(this, { alpha:0, y:y - 16 }, .33, { ease:FlxEase.circOut, complete:finishKill } );
	}
	
	private function finishKill(_):Void
	{
		exists = false;
	}
}
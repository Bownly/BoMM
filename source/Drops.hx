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
	
	/* Legend for drops:
	 * 0 = Mushroom
	 * 2 = Butterfly
	 */
	
	public function new(X:Float=0, Y:Float=0, Index:Int, ThePlayer:Player) 
	{
		super(X, Y);
		loadGraphic(AssetPaths.drops__png, false, 8, 8);
		width = 8;
		height = 8;
		
		_player = ThePlayer;
		i = Index;
		
		animation.add("idle", [i, i+1], 5, true);
		
	}
	
	public override function update():Void
	{
		if (isOnScreen())
		{
			animation.play("idle");
			super.update();
		}
	}
	
	private function playerHeal(Val:Int):Void
	{
		_player.hp += Val;
	}
	
	
	public function doStuff():Void  // called on collision with player
	{
		switch(i)
		{
			case 0:
				//do Mushroom stuff
				playerHeal(10);
			case 2:
				//do Butterfly stuff
				playerHeal(20);
		}
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
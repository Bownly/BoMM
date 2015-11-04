package;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;

/**
 * ...
 * @author ...
 */
class Ladder extends FlxSprite
{
	
	/* Ladders todo (note: some of this pertains to player movement)
	 * (in fact, pretty much all of it does)
	 * 
	 * when player is climbing a ladder and nearly reaches the top, play climbing anim...
	 * ...and teleport the player the remaining few pixels upwards.
	 * 
	 * Also, what to heck is going on with the collision when the player is on top...
	 * ...and tries to climb down? Blurgh.
	 * */
	
	
	public var top:Bool = false;
	
	public function new(X:Float=0, Y:Float=0, Top:Bool) 
	{
		super(X, Y);
		loadGraphic(AssetPaths.ladder__png, false, 16, 16);
		visible = false;
		top = Top;
		
		allowCollisions = FlxObject.CEILING;
		
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
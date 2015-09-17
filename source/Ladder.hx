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

	public function new(X:Float=0, Y:Float=0) 
	{
		super(X, Y);
		loadGraphic(AssetPaths.ladder__png, false, 16, 16);
		
		
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
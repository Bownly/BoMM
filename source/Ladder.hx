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
		FlxTween.tween(this, { alpha:0, y:y - 16 }, .33, { ease:FlxEase.circOut, onComplete:finishKill } );
		
	}
	
	private function finishKill(_):Void
	{
		exists = false;
	}
}
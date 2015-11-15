package weapons;

import flixel.FlxSprite;

/**
 * ...
 * @author ...
 */
class BulletAfterimage extends FlxSprite
{

	public function new(X:Float=0, Y:Float=0) 
	{
		super(X, Y);
		loadGraphic(AssetPaths.bullet_afterimage__png, false, 8, 8);
		
		
		animation.add("anim", [0, 1, 2, 3], 20, false);
		animation.play("anim");
	}
	
	public override function update():Void
	{
		if (animation.finished)
		{
			this.kill();
		}
		super.update();
	}
}
package;

import flixel.FlxSprite;

/**
 * ...
 * @author ...
 */
class BossDoor extends FlxSprite
{
	public var status:Int = 0;  // 0 = shut, 1 = opening, 2 = closing
	
	public function new(X:Float=0, Y:Float=0) 
	{
		super(X, Y);
		loadGraphic(AssetPaths.bossdoor__png, false, 16, 48);
		
		animation.add("open", [0, 1, 2, 3, 4, 3, 2, 1, 0], 15, false);
		animation.add("shut", [4, 3, 2, 1, 0], 5, false);
		
	}
	
	override public function update():Void 
	{	
		if (status == 1)
		{
			animation.play("open");
			status = 2;
		}
		
		if (animation.getByName("open").finished)
			status = 0;
		super.update();
	}
	
	public function open()
	{
		status = 1;
	}
	public function shut()
	{
		status = 2;
	}
	
	
}
package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.group.FlxGroup;
import flixel.text.FlxText;
import flixel.util.FlxColor;

/**
 * ...
 * @author me
 * 
 * todo
 * 
 * 1 prettify the text and coin icon and other such prettifications
 * 2 something about using real prices and whatnot. Really, that's a Drops.hx problem.
 * 
 * 
 */
class ShopPodium extends FlxSprite
{
	private var _txtMoney:FlxText;
    private var _sprMoney:FlxSprite;
	private var price:Int;
	
	public function new(X:Float=0, Y:Float=0, ThePlayer:Player, DropsGrp:FlxTypedGroup<Drops>, MiscGrp:FlxGroup) 
	{
		super(X, Y + 16);
		
		//visible = false;
		loadGraphic("assets/images/podium.png", true, 16, 16);

		
		var dropID = FlxG.random.int(0, 3) * 2;
		//price = dropID * 5;
		var newDrop = new Drops(this.x + 4, this.y - 12, dropID, ThePlayer, false);
		price = newDrop.price;
		DropsGrp.add(newDrop);
		
		_txtMoney = new FlxText(x, y - 24, 0, ""+price, 8);
        _txtMoney.setBorderStyle(FlxTextBorderStyle.SHADOW, FlxColor.GRAY, 1, 1);
        _sprMoney = new FlxSprite(_txtMoney.x + _txtMoney.width, _txtMoney.y + 4, AssetPaths.coin__png);
        _txtMoney.alignment = "right";
		
		MiscGrp.add(_txtMoney);
		MiscGrp.add(_sprMoney);
	}
	
}
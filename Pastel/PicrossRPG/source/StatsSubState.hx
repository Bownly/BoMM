package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxSubState;
import flixel.group.FlxTypedGroup;
import flixel.text.FlxText;
import flixel.util.FlxColor;

/**
 * ...
 * @author ...
 */
class StatsSubState extends FlxSubState
{

	private var _sprBack:FlxSprite;
    private var _txtLevel:FlxText;
    private var _txtHP:FlxText;
    private var _txtMP:FlxText;
    private var _txtXP:FlxText;
	var _grpEverything:FlxTypedGroup<FlxText>;
	
	
	public function new(X:Float, Y:Float, ?BGColor:Int=FlxColor.TRANSPARENT) 
	{
		super();
		
		_grpEverything = new FlxTypedGroup<FlxText>();
		
		_sprBack = new FlxSprite().makeGraphic(64, 96, FlxColor.BLACK);
		_sprBack.x = FlxG.width / 2 - _sprBack.width / 2;
		_sprBack.y = FlxG.height / 2 - _sprBack.height / 2;
		_sprBack.scrollFactor.set(0, 0);

		_txtLevel = new FlxText(_sprBack.x, _sprBack.y + 8, 64, "Stats:\n\nLvl: " + Reg.pLV, 8);
		_txtHP = new FlxText(_sprBack.x, _txtLevel.y + _txtLevel.height, 64, "HP: 999", 8);
		_txtMP = new FlxText(_sprBack.x, _txtHP.y + _txtHP.height, 64, "MP: " + Reg.pMP, 8);
		_txtXP = new FlxText(_sprBack.x, _txtMP.y + _txtMP.height, 64, "XP: " + Reg.pXP, 8);
		
		add(_sprBack);
		_grpEverything.add(_txtLevel);
		_grpEverything.add(_txtHP);
		_grpEverything.add(_txtMP);
		_grpEverything.add(_txtXP);
		add(_grpEverything);
		
		for(text in _grpEverything) 
		{
			text.scrollFactor.set();
        }
	}
	
	public override function update()
	{
		if (FlxG.keys.anyJustPressed(["J", "SPACE", "W", "A", "S", "D", "UP", "DOWN", "LEFT", "RIGHT", "K"]))
		{
			this.close();
		}
		super.update();
	}

}
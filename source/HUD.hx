package;

 import flixel.FlxBasic;
 import flixel.FlxG;
 import flixel.FlxSprite;
 import flixel.group.FlxTypedGroup;
 import flixel.text.FlxText;
 import flixel.util.FlxColor;
 using flixel.util.FlxSpriteUtil;

/**
 * ...
 * @author ...
 */

 class HUD extends FlxTypedGroup<FlxSprite>
 {
    private var _sprBack:FlxSprite;
    private var _txtHealth:FlxText;
    private var _txtJuice:FlxText;
    private var _txtWeapon:FlxText;
	private var _txtMoney:FlxText;
	
    private var _sprHealth:FlxSprite;
	private var _sprJuice:FlxSprite;
    private var _sprWeapon:FlxSprite;
    private var _sprMoney:FlxSprite;

    public function new()
    {
        super();
        _sprBack = new FlxSprite().makeGraphic(FlxG.width, 20, FlxColor.BLACK);
        _sprBack.drawRect(0, 19, FlxG.width, 1, FlxColor.WHITE);
        
		_txtHealth = new FlxText(16, 2, 0, "3 / 3", 8);
        _txtHealth.setBorderStyle(FlxText.BORDER_SHADOW, FlxColor.GRAY, 1, 1);
        _sprHealth = new FlxSprite(0, _txtHealth.y + (_txtHealth.height/2)  - 8, AssetPaths.heart__png);
        
		_txtJuice = new FlxText(64, 2, 0, "6 / 9", 8);
		_txtJuice.setBorderStyle(FlxText.BORDER_SHADOW, FlxColor.GRAY, 1, 1);
		_sprJuice = new FlxSprite(_txtHealth.x + _txtHealth.width, _txtJuice.y + (_txtJuice.height / 2) - 8, AssetPaths.juice__png);
		
		_txtWeapon = new FlxText(_txtJuice.x + _txtJuice.width, 2, 0, "Cur Weapon: ", 8);
		_txtWeapon.setBorderStyle(FlxText.BORDER_SHADOW, FlxColor.GRAY, 1, 1);
		_sprWeapon = new FlxSprite(_txtWeapon.x + _txtWeapon.width, _txtWeapon.y + (_txtWeapon.height / 2 - 4), AssetPaths.coin__png);
		
		_txtMoney = new FlxText(0, 2, 0, "0", 8);
        _txtMoney.setBorderStyle(FlxText.BORDER_SHADOW, FlxColor.GRAY, 1, 1);
        _sprMoney = new FlxSprite(FlxG.width - 12, _txtMoney.y + (_txtMoney.height/2)  - 4, AssetPaths.coin__png);
        _txtMoney.alignment = "right";
        _txtMoney.x = _sprMoney.x - _txtMoney.width - 4;
        
		add(_sprBack);
        add(_sprHealth);
        add(_sprMoney);
		add(_sprJuice);
		//add(_sprWeapon);
        add(_txtHealth);
        add(_txtMoney);
		add(_txtJuice);
		add(_txtWeapon);
		
        forEach(function(spr:FlxSprite) {
            spr.scrollFactor.set();
        });
    }

	
    public function updateHUD(Health:Int = 0, Juice:Int = 0, Money:Int = 0, Weapon:String):Void
    {
        _txtHealth.text = Std.string(Health) + " / 3";
        _txtMoney.text = Std.string(Money);
        _txtMoney.x = _sprMoney.x - _txtMoney.width - 4;
		
		_txtJuice.text = Std.string(Juice) + " / 9";
		_txtWeapon.text = "Cur Weapon: " + Weapon;
    }
 }
package;

 import flixel.FlxBasic;
 import flixel.FlxG;
 import flixel.FlxSprite;
 import flixel.group.FlxGroup;
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
	
    private var _sprHealth2:FlxSprite;
	private var _sprJuice:FlxSprite;
    private var _sprWeapon:FlxSprite;
    private var _sprMoney:FlxSprite;

	private var _grpHealth:FlxTypedGroup<FlxSprite>;
	
	var _palette:Int;
	var _player:Player;
	
	
		
	/* Weapon ID legend:
	 * 0  =  pea
	 * 1  =  arc
	 * 2  =  bounce
	 * 3  =  cluster
	 * 4  =  8 way
	 * 5  =  x shot
	 * 6  =  follow
	 * 7  =  mouse
	 * 8  =  plus
	 * 9  =  slash
	 * 10 =  splode
	 * 11 =  spread
	 * 12 =  stomp
	 * 13 =  string
	 * 14 =  wings
	*/
	
	
    public function new(P:Player)
    {
        super();
		
		_player = P;
		_palette = _player.curWeaponLoc;
        
		var sprWidth = 5;
		_grpHealth = new FlxTypedGroup<FlxSprite>();
		for (i in 0...12)
		{
			var _sprHealth = new FlxSprite(17 + (sprWidth * i % 6) , 1 + 7 * Math.floor(i / 6));
			_sprHealth.loadGraphic("assets/images/tictacs.png", true, 4, 6);
			for (color in 0...4)
			{
				_sprHealth.animation.add(color + "" + 0, [0 + color * (2)]);  // full
				_sprHealth.animation.add(color + "" + 1, [1 + color * (2)]);  // empty
			}
			_grpHealth.add(_sprHealth);
			add(_sprHealth);
		}
		
		
		_txtHealth = new FlxText(16, 2, 0, "3 / 3", 8);
        _txtHealth.setBorderStyle(FlxText.BORDER_SHADOW, FlxColor.GRAY, 1, 1);
        _sprHealth2 = new FlxSprite(1, 1, AssetPaths.heart__png);
		
		_txtJuice = new FlxText(64, 2, 0, "6 / 9", 8);
		_txtJuice.setBorderStyle(FlxText.BORDER_SHADOW, FlxColor.GRAY, 1, 1);
		_sprJuice = new FlxSprite(_txtHealth.x + _txtHealth.width, _txtJuice.y + (_txtJuice.height / 2) - 8, AssetPaths.juice__png);
		_sprJuice.visible = false;
		
		_txtWeapon = new FlxText(_txtJuice.x + _txtJuice.width, 2, 0, "Cur Weapon: ", 8);
		_txtWeapon.setBorderStyle(FlxText.BORDER_SHADOW, FlxColor.GRAY, 1, 1);
		_sprWeapon = new FlxSprite(_txtWeapon.x + _txtWeapon.width, _txtWeapon.y + (_txtWeapon.height / 2 - 4));
		_sprWeapon.loadGraphic(AssetPaths.weapon_icons__png, true, 16, 16);
		var o:Int;
		var id:Int;
		
		for (o in 0...4)
		{
			for (id in 0...Reg.weaponCount)
			{
				var frameNum = id + Reg.weaponCount * o;
				_sprWeapon.animation.add(id + "+" + o, [frameNum]);
			}
		}	
		
		_txtMoney = new FlxText(0, 2, 0, "0", 8);
        _txtMoney.setBorderStyle(FlxText.BORDER_SHADOW, FlxColor.GRAY, 1, 1);
        _sprMoney = new FlxSprite(FlxG.width - 12, _txtMoney.y + (_txtMoney.height/2)  - 4, AssetPaths.coin__png);
        _txtMoney.alignment = "right";
        _txtMoney.x = _sprMoney.x - _txtMoney.width - 4;
        
        add(_sprHealth2);
        add(_sprMoney);
		add(_sprJuice);
		add(_sprWeapon);
        add(_txtHealth);
        add(_txtMoney);
		add(_txtJuice);
		//add(_txtWeapon);
		
        forEach(function(spr:FlxSprite) {
            spr.scrollFactor.set();
        });
    }

	
    public function updateHUD(Health:Int = 0, Juice:Int = 0, Money:Int = 0, Weapon:String):Void
    {
        //_txtHealth.text = Std.string(Health) + " / 3";
        _txtHealth.text = "";
        _txtMoney.text = Std.string(Money);
        _txtMoney.x = _sprMoney.x - _txtMoney.width - 4;
		
		for (i in 0..._player.hp)
		{
			_grpHealth.members[i].animation.play(_player.curWeaponLoc + "0");
		}
		for (i in _player.hp..._player.maxHP)
		{
			_grpHealth.members[i].animation.play(_player.curWeaponLoc + "1");
		}
		for (i in _player.maxHP...12)
		{
			_grpHealth.members[i].visible = false;
		}
		
		_sprWeapon.animation.play(_player.curWeapon.weaponID + "+" + _player.curWeaponLoc);
		
		_txtJuice.text = "";
		_txtWeapon.text = "Cur Weapon: " + Weapon;
    }
 }
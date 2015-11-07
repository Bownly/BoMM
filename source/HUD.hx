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
	
    private var _sprHealth:FlxSprite;
	private var _sprJuice:FlxSprite;
    private var _sprWeapon:FlxSprite;
    private var _sprMoney:FlxSprite;

	private var _grpHealth:FlxTypedGroup<FlxSprite>;
	private var _grpWeapon:FlxTypedGroup<FlxSprite>;
	
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
		
		// setting up the health and health tictacs
        _sprHealth = new FlxSprite(1, 1, AssetPaths.heart__png);
		
		var sprWidth = 5;
		_grpHealth = new FlxTypedGroup<FlxSprite>();
		for (i in 0...12)
		{
			var _sprHealthTictac = new FlxSprite(_sprHealth.x + _sprHealth.width + 2 + (sprWidth * i % 6),
				_sprHealth.y + 1 + 7 * Math.floor(i / 6));
			_sprHealthTictac.loadGraphic("assets/images/tictacs.png", true, 4, 6);
			
			_sprHealthTictac.animation.add("0", [0]);  // full
			_sprHealthTictac.animation.add("1", [1]);  // empty
			
			_grpHealth.add(_sprHealthTictac);
			add(_sprHealthTictac);
		}
		
		
		// setting up the weapon icon and ammo tictacs
		_sprWeapon = new FlxSprite(_sprHealth.x, _sprHealth.y + _sprHealth.height + 2);
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
		
		_grpWeapon = new FlxTypedGroup<FlxSprite>();
		for (i in 0...12)
		{
			var _sprWeaponTictac = new FlxSprite(_sprWeapon.x + _sprWeapon.width + 2 + (sprWidth * i % 6),
				_sprWeapon.y + 1 + 7 * Math.floor(i / 6));
			_sprWeaponTictac.loadGraphic("assets/images/tictacs.png", true, 4, 6);
			for (color in 0...4)
			{
				_sprWeaponTictac.animation.add(color + "" + 0, [0 + color * (2)]);  // full
				_sprWeaponTictac.animation.add(color + "" + 1, [1 + color * (2)]);  // empty
			}
			_grpWeapon.add(_sprWeaponTictac);
			add(_sprWeaponTictac);
		}
		
		
		/*_txtMoney = new FlxText(0, 2, 0, "0", 8);
        _txtMoney.setBorderStyle(FlxText.BORDER_SHADOW, FlxColor.GRAY, 1, 1);
        _sprMoney = new FlxSprite(FlxG.width - 12, _txtMoney.y + (_txtMoney.height/2)  - 4, AssetPaths.coin__png);
        _txtMoney.alignment = "right";
        _txtMoney.x = _sprMoney.x - _txtMoney.width - 4;*/
        
        add(_sprHealth);
       // add(_sprMoney);
		add(_sprJuice);
		add(_sprWeapon);
		
        forEach(function(spr:FlxSprite) {
            spr.scrollFactor.set();
        });
    }

	// todo make separate update functions
    public function updateHUD(Health:Int = 0, Juice:Int = 0, Money:Int = 0, Weapon:String):Void
    {

       // _txtMoney.text = Std.string(Money);
       // _txtMoney.x = _sprMoney.x - _txtMoney.width - 4;
		
		for (i in 0..._player.hp)
		{
			_grpHealth.members[i].animation.play("0");
			_grpHealth.members[i].visible = true;
			}
		for (i in _player.hp..._player.maxHP)
		{
			_grpHealth.members[i].animation.play("1");
		}
		for (i in _player.maxHP...12)
		{
			_grpHealth.members[i].visible = false;
		}
		
		
		
		_sprWeapon.animation.play(_player.curWeapon.weaponID + "+" + _player.curWeaponLoc);
		for (i in 0..._player.curWeapon.juice)
		{
			_grpWeapon.members[i].animation.play(_player.curWeaponLoc + "0");
			_grpWeapon.members[i].visible = true;
		}
		for (i in _player.curWeapon.juice..._player.curWeapon.juiceMax)
		{
			_grpWeapon.members[i].animation.play(_player.curWeaponLoc + "1");
			_grpWeapon.members[i].visible = true;
		}
		for (i in _player.curWeapon.juiceMax...12)
		{
			_grpWeapon.members[i].visible = false;
		}
		//_txtJuice.text = "";
		//_txtWeapon.text = "Cur Weapon: " + Weapon;
    }
 }	
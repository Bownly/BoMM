package;

import enemies.Balun;
import enemies.Burd;
import enemies.EnemyTemplate;
import enemies.Metool;
import enemies.Notey;
import enemies.Snaake;
import enemies.Snobal;
import flixel.FlxCamera;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.group.FlxGroup;
import flixel.group.FlxSpriteGroup;
import flixel.group.FlxTypedGroup;
import flixel.text.FlxText;
import flixel.tile.FlxTilemap;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;
import flixel.util.FlxPoint;
import flixel.addons.editors.ogmo.FlxOgmoLoader;
import flixel.util.FlxRandom;
import weapons.Bullet;

/**
 * A FlxState which can be used for the actual gameplay.
 */
class PlayState extends FlxState
{
	private var _grpPlayer:FlxGroup;
	static private var player:Player;
	//static private var _grpPlayer:FlxGroup;
	private var _player:Player;
	public var playerBullets:FlxTypedGroup<weapons.Bullet>;
	
	private var _grpEnemies:FlxGroup;
	private var _grpBadBullets:FlxGroup;
	
	private var _grpCoins:FlxTypedGroup<Coin>;
	private var _grpLadders:FlxTypedGroup<Ladder>;
	private var _grpHazards:FlxTypedGroup<Spike>;
	
	private var _door:Door;
	
	private var _grpWalls:FlxTypedGroup<FlxTilemap>;
	private var _levelWidth:Float;
	private var _levelHeight:Float;
	
	var mOogmoLoader:FlxOgmoLoader;
	var mTileMap:FlxTilemap;
	
	private var loader:FlxOgmoLoader;
	private var midgroundMap:FlxTilemap;

	private var coinGroup:FlxGroup;
	
	private var dropsGroup:FlxTypedGroup<Drops>;
	
	private var miscGroup:FlxGroup;
	
	private var _newEntrance:Int;
	
	private var _curMapX:Float = 0;
	private var _curMapY:Float = 0;
	
	private var _hud:HUD;
	public var _score:Int = 0;
	
	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{
		
		_levelHeight = _levelWidth = 0;
		
		
		_grpWalls = new FlxTypedGroup<FlxTilemap>();
		
		_grpLadders = new FlxTypedGroup<Ladder>();
		add(_grpLadders);
		
		_grpHazards = new FlxTypedGroup<Spike>();
		add(_grpHazards);
		
		_grpEnemies = new FlxGroup();
		add(_grpEnemies);

		
		_door = new Door();
		add(_door);
		
		_grpCoins = new FlxTypedGroup<Coin>();
		add(_grpCoins);
		
		playerBullets = new FlxTypedGroup<weapons.Bullet>();
		add(playerBullets);
		
		_player = new Player(100, 100, playerBullets);

		/* this is stuff for trying to get static player stuff working for passing between playstates
		if (player == null)
		{
			_player = new Player(100, 100, playerBullets);
			player = _player;
			trace("is null");
		}
		else
		{
			_player = new Player(100, 100, playerBullets);
			_player = player;
			trace("should work");
			
		}*/
			
		dropsGroup = new FlxTypedGroup<Drops>();
		add(dropsGroup);
		
		var drop = new Drops(320, 320, 0, _player, true);
		var drop2 = new Drops(340, 320, 2, _player, true);
		var drop4 = new Drops(360, 320, 4, _player, true);
		var drop6 = new Drops(380, 320, 6, _player, true);
		
		dropsGroup.add(drop);
		dropsGroup.add(drop2);
		dropsGroup.add(drop4);
		dropsGroup.add(drop6);
		
		
		_grpBadBullets = new FlxGroup();
		add(_grpBadBullets);
		miscGroup = new FlxGroup();
		add(miscGroup);
	
		setUpLevel();		
		add(_grpWalls);		
		
		
		_grpPlayer = new FlxGroup();
		add(_grpPlayer);
		_grpPlayer.add(_player);
		_grpPlayer.add(playerBullets);
		
		
		FlxG.mouse.visible = false;		
		
		//FlxG.camera.bgColor = 0x093930FF;
		FlxG.camera.bgColor = 0xFF555555;
		
		FlxG.camera.follow(_player,1);
		FlxG.camera.style = FlxCamera.STYLE_PLATFORMER;
		FlxG.camera.setBounds(0, -_levelHeight, _levelWidth, _levelHeight*2);
		FlxG.worldBounds.set(0, -_levelHeight, _levelWidth, _levelHeight*2);
		
		_hud = new HUD();
		add(_hud);
		
		super.create();
	}
	
	
	/**
	 * Function that is called when this state is destroyed - you might want to 
	 * consider setting all objects this state uses to null to help garbage collection.
	 */
	override public function destroy():Void
	{
		super.destroy();
	}

	/**
	 * Function that is called once every frame.
	 */
	override public function update():Void
	{

		FlxG.collide(_grpWalls, _player);
		FlxG.collide(_grpWalls, _grpEnemies);
		FlxG.collide(_grpWalls, _grpBadBullets);
		FlxG.collide(_grpWalls, playerBullets);
		
		FlxG.overlap(_player, _door, nextLevel);
		
		FlxG.overlap(_player, _grpEnemies, touchEnemy);
		FlxG.overlap(_player, _grpBadBullets, playerGetHit);
		FlxG.overlap(playerBullets, _grpEnemies, bulletTouchEnemy);
		FlxG.overlap(_player, _grpCoins, playerTouchCoin);
		FlxG.overlap(_player, dropsGroup, playerTouchDrops);
		FlxG.overlap(_player, _grpHazards, playerTouchHazard);
		
		if (!FlxG.overlap(_player, _grpLadders, playerTouchLadder))
		{
			_player.setTouchingLadder(false);
		}
		
		
		if (FlxG.keys.anyPressed(["R"])) 
		{
			FlxG.switchState(new PlayState());
		}
		
		
		// possible todo: Call this only when something changes, and not every frame
		// right now it's more convenient being in one place...
		// could just make it a function unto itself, but whatever
		_hud.updateHUD(_player.hp, _player.curWeapon.juice, _score, _player.curWeapon.name);	

		
		//FlxG.overlap(playerBullets, _grpLadders, bulletTouchLadder);
		
		super.update();
	}	
	
	private function nextLevel(P:Player, D:Door):Void
	{
		FlxG.switchState(new PlayState());

	}
	
	
	private function setUpLevel():Void
	{
		
		/* Stuff regarding a future level stitching overhaul
		 * 
		 * Uh... stuff
		 * Limited verticality perhaps...
		 * ...and... yeah, stuff...
		 * */
		
		
		
		// stuff for the start room
		_newEntrance = FlxRandom.intRanged(4, 4);
		mOogmoLoader = new FlxOgmoLoader("assets/levels/level_1_start_" + _newEntrance + ".oel");
		mTileMap = mOogmoLoader.loadTilemap(AssetPaths.wood_tiles__png, 16, 16, "walls");
		
		mOogmoLoader.loadEntities(placeEntities, "entities");
		
		_levelHeight += mTileMap.height;
		_levelWidth += mTileMap.width;		
		_grpWalls.add(mTileMap);
		
		
		var itemRoomPos:Int;
		itemRoomPos = FlxRandom.intRanged(1, 3);  // Same bounds as the for loop right below, but max is one less than below's. 
		// TODO Should make those numbers less magic later
		
		// stuff for the middle rooms
		for (i in 1...4) 
		{
			if (i == itemRoomPos)
			{
				// stuff for the item room
				var myOgmoLoader  = new FlxOgmoLoader("assets/levels/level_1_item_start_" + _newEntrance + ".oel");
				var myTileMap = myOgmoLoader.loadTilemap(AssetPaths.wood_tiles__png, 16, 16, "walls");
				setUpMaps(myOgmoLoader, myTileMap);
				
				var endId:Int = FlxRandom.intRanged(1, 2);
				//myOgmoLoader = new FlxOgmoLoader("assets/levels/level_1_item_end_" + endId + ".oel");
				myOgmoLoader = new FlxOgmoLoader("assets/levels/level_1_shop_end_" + endId + ".oel");
				myTileMap = myOgmoLoader.loadTilemap(AssetPaths.wood_tiles__png, 16, 16, "walls");
				setUpMaps(myOgmoLoader, myTileMap);
			}	
			
			var id:Int;
			id = FlxRandom.intRanged(1, 2);
			
			var myOgmoLoader = new FlxOgmoLoader("assets/levels/level_1_" + _newEntrance + "_" + id + ".oel");
			var myTileMap = myOgmoLoader.loadTilemap(AssetPaths.wood_tiles__png, 16, 16, "walls");
			setUpMaps(myOgmoLoader, myTileMap);
		}
		
		// stuff for the end room
		var myOgmoLoader = new FlxOgmoLoader("assets/levels/level_1_end_" + _newEntrance + ".oel");
		var myTileMap = myOgmoLoader.loadTilemap(AssetPaths.wood_tiles__png, 16, 16, "walls");
		setUpMaps(myOgmoLoader, myTileMap);
	}
	
	private function setUpMaps(ogmo:FlxOgmoLoader, map:FlxTilemap):Void
	{
		
		var previousWall:FlxTilemap = _grpWalls.members[_grpWalls.length - 1]; 
		
		if (_newEntrance == 1 || _newEntrance == 2)
		{
			map.x += previousWall.x + previousWall.width;
			map.y += previousWall.y;
		}
		else if (_newEntrance == 3)
		{
			map.x += previousWall.x + previousWall.width - 96;
			map.y += previousWall.y + previousWall.height;
		}
		else //if (_entrance == 4)
		{
			map.x += previousWall.x + previousWall.width - 96;
			map.y += previousWall.y - previousWall.height;
		}
		
		_curMapX = map.x;
		_curMapY = map.y;
		
		ogmo.loadEntities(placeEntities, "entities");
		ogmo.loadEntities(getExit, "entities");
		
		_levelHeight += map.height;
		_levelWidth += map.width;
		
		_grpWalls.add(map);
	} 
	
	
	private function touchEnemy(P:Player, E:enemies.EnemyTemplate):Void 
	{
		if (E.alive == true)
		{
			P.getHurt(1);
			//_hud.updateHUD(_player.hp, _score, _player.curWeapon.name);
		}
	}
	private function playerGetHit(P:Player, B:weapons.Bullet):Void 
	{
		if (B.alive == true)
		{
			P.getHurt(B.getDamage());
			//_hud.updateHUD(_player.hp, _score, _player.curWeapon.name);
		}
	}
	private function bulletTouchEnemy(B:weapons.Bullet, E:enemies.EnemyTemplate):Void 
	{
		if (B.alive && B.exists && E.alive && E.exists)
		{
			E.takeDamage(B.getDamage());
				
		}
		if (E.alive == false)
		{
			_score++;
			var health:Int;
			health = _player.hp;
			//_hud.updateHUD(health, _score, _player.curWeapon.name);	
			
			//_hud.updateHUD(_health, _money);	
		}
	}
	private function bulletTouchLadder(B:weapons.Bullet, L:Ladder):Void 
	{
		if (B.alive && B.exists && L.alive && L.exists)
		{
			L.kill();
			_score++;
			//_hud.updateHUD(_player.hp, _score, _player.curWeapon.name);	
			
			//_hud.updateHUD(_health, _money);		
		
		}
		
	}
	private function playerTouchDrops(P:Player, D:Drops):Void 
	{
		if (P.alive && P.exists && D.alive && D.exists)
		{
			var cost:Int = D.doStuff(_score);
			_score -= cost;
			//_hud.updateHUD(_player.hp, _score, _player.curWeapon.name);	
		}
		
	}
	private function playerTouchCoin(P:Player, C:Coin):Void 
	{
		if (P.alive && P.exists && C.alive && C.exists)
		{
			C.kill();
			_score++;
			//_hud.updateHUD(_player.hp, _score, _player.curWeapon.name);	
			
			//_hud.updateHUD(_health, _money);		
		
		}
		
	}
	private function playerTouchLadder(P:Player, L:Ladder):Void
	{
		P.setTouchingLadder(true);
		
		// make it so that you can stand on top of the ladder
		if (L.top == true && (P.y < L.y - (P.height - 3)))
		{
			L.immovable = true;
			FlxG.collide(P, L);
			
		}
	}
	private function playerTouchHazard(P:Player, S:Spike):Void
	{
		P.getHurt(S.dmg);
		//_hud.updateHUD(_player.hp, _score, _player.weaponArray[_player.curWeaponLoc].name);
	}
	
	private function placeEntities(entityName:String, entityData:Xml):Void
	{
		var x:Float = Std.parseFloat(entityData.get("x"));
		var y:Float = Std.parseFloat(entityData.get("y"));
		x += _curMapX;
		y += _curMapY;
	
		if (entityName == "player")
		{
			_player.x = x;
			_player.y = y;
		}
		else if (entityName == "coin")
		{
			_grpCoins.add(new Coin(x + 4, y + 4));
		}
		else if (entityName == "ladder")
		{
			if (entityData.get("top") == "True")
				_grpLadders.add(new Ladder(x, y, true));
			else
				_grpLadders.add(new Ladder(x, y, false));
		}
		else if (entityName == "door")
		{
			_door.x = x;
			_door.y = y;
		}
		else if (entityName == "spike")
		{
			var dmg:Int = Std.parseInt(entityData.get("damage"));
			_grpHazards.add(new Spike(x, y, dmg));
		}
		else if (entityName == "StorePodium")
		{
			add(new ShopPodium(x, y, _player, dropsGroup, miscGroup));
		}
		else if (entityName == "enemy")
		{
			switch(entityData.get("name"))
			{
				case "snobal":
					_grpEnemies.add(new enemies.Snobal(x, y, _player, dropsGroup));
				case "snaake":
					_grpEnemies.add(new enemies.Snaake(x, y, _player, dropsGroup));
				case "metool":
					_grpEnemies.add(new enemies.Metool(x, y, _player, dropsGroup, _grpBadBullets));
				case "burd":
					_grpEnemies.add(new enemies.Burd(x, y, _player, dropsGroup, _grpEnemies));
				case "notey":
					_grpEnemies.add(new enemies.Notey(x, y, _player, dropsGroup));
				case "testboss":
					_grpEnemies.add(new Testboss(x, y, _player, dropsGroup, _grpBadBullets));
				case "balun":
					_grpEnemies.add(new Balun(x, y, _player, dropsGroup, _grpEnemies, _grpBadBullets, 1));
				case "mush":
					_grpEnemies.add(new enemies.Mush(x, y, _player, dropsGroup, _grpBadBullets, 1));			}
		}
	}
	
	private function getExit(entityName:String, entityData:Xml):Void
	{
		if (entityName == "exit")
		{
			_newEntrance = Std.parseInt(entityData.get("val"));
		}
	}
	
	private function getEntrance(entityName:String, entityData:Xml):Void
	{
		if (entityName == "entrance")
		{
			_newEntrance = Std.parseInt(entityData.get("val"));
			
		}
	}
	
}
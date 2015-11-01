package;

import enemies.Balun;
import enemies.Burd;
import enemies.EnemySpawner;
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
import flixel.FlxSubState;
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
import weapons.StompEquipment;
import weapons.WeaponTemplate;

/**
 * A FlxState which can be used for the actual gameplay.
 */
class PlayState extends FlxState
{
	var unlockableColor:Int = Reg.C;
	
	private var _grpPlayer:FlxGroup;
	private var _player:Player;
	public var playerBullets:FlxTypedGroup<weapons.Bullet>;
	
	private var _grpEnemies:FlxGroup;
	private var _grpBadBullets:FlxGroup;
	
	private var _grpCoins:FlxTypedGroup<Coin>;
	private var _grpLadders:FlxTypedGroup<Ladder>;
	private var _grpHazards:FlxTypedGroup<Spike>;
	
	private var _door:Door;
	private var _bossDoor:BossDoor;
	
	private var _grpWalls:FlxTypedGroup<FlxTilemap>;
	private var _levelWidth:Float = 0;
	private var _levelHeight:Float = 0;
	
	var myOgmoLoader:FlxOgmoLoader;
	var mTileMap:FlxTilemap;
	
	private var levelId:String = "1";
	private var tileName:String = "assets/images/wood_tiles.png";
	
	private var loader:FlxOgmoLoader;
	private var midgroundMap:FlxTilemap;

	private var coinGroup:FlxGroup;
	
	private var dropsGroup:FlxTypedGroup<Drops>;
	
	private var decorationGroup:FlxGroup;
	private var miscGroup:FlxGroup;
	
	private var _newEntrance:Int;
	var _oldRoomEndY:Int = 0;
	var _newRoomStartY:Int = 0;

	private var _curMapX:Float = 0;
	private var _curMapY:Float = 0;
	
	private var _hud:HUD;
	public var _score:Int = 0;
	
	
	public function new(UnlockableColor:Int) 
	{
		unlockableColor = UnlockableColor;
		super();
	}
	
	
	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{
		
		_levelHeight = _levelWidth = 0;
		
		
		_grpWalls = new FlxTypedGroup<FlxTilemap>();
		
		_grpLadders = new FlxTypedGroup<Ladder>();
		
		_grpHazards = new FlxTypedGroup<Spike>();
		add(_grpHazards);
		
		_grpEnemies = new FlxGroup();

		
		_door = new Door(0, 0, 1, Reg.door1Color);
		add(_door);
		_bossDoor = new BossDoor();
		add(_bossDoor);
		
		_grpCoins = new FlxTypedGroup<Coin>();
		add(_grpCoins);
		
		playerBullets = new FlxTypedGroup<weapons.Bullet>();
		add(playerBullets);
		
		
		_player = new Player(0, 0, playerBullets);
		
		
		dropsGroup = new FlxTypedGroup<Drops>();
		add(dropsGroup);
		
		/*var drop = new Drops(320, 320, 0, _player, true);
		var drop2 = new Drops(340, 320, 2, _player, true);
		var drop4 = new Drops(360, 320, 4, _player, true);
		var drop6 = new Drops(380, 320, 6, _player, true);
		
		dropsGroup.add(drop);
		dropsGroup.add(drop2);
		dropsGroup.add(drop4);
		dropsGroup.add(drop6);
		*/
		
		_grpBadBullets = new FlxGroup();
		decorationGroup = new FlxGroup();
		miscGroup = new FlxGroup();
		add(miscGroup);
		add(decorationGroup);
		
		
		setUpLevel();	
		
		
		add(_grpWalls);		
		
		add(_grpLadders);
		add(_grpEnemies);
		
		add(_grpBadBullets);
		
		
		_grpPlayer = new FlxGroup();
		add(_grpPlayer);
		_grpPlayer.add(_player);
		_grpPlayer.add(playerBullets);
		
		
		FlxG.mouse.visible = false;		

		FlxG.camera.bgColor = 0x00000000;
		
		FlxG.camera.follow(_player,1);
		FlxG.camera.style = FlxCamera.STYLE_PLATFORMER;
		FlxG.camera.setBounds(0, -_levelHeight, _levelWidth, _levelHeight*2);
		FlxG.worldBounds.set(0, -_levelHeight, _levelWidth, _levelHeight*2);
		
		_hud = new HUD();
		add(_hud);
		
		super.create();
	}
	
	override public function update():Void
	{

		FlxG.collide(_grpWalls, _player);
		FlxG.collide(_grpWalls, playerBullets, bulletTouchWall);
		FlxG.collide(_grpWalls, _grpEnemies);
		FlxG.collide(_grpWalls, _grpBadBullets, bulletTouchWall);
		
		FlxG.overlap(_player, _grpEnemies, touchEnemy);
		FlxG.overlap(_player, _grpBadBullets, playerGetHit);
		FlxG.overlap(playerBullets, _grpEnemies, bulletTouchEnemy);
		FlxG.overlap(_grpBadBullets, _grpEnemies, badBulletTouchEnemy);
		FlxG.overlap(_player, _grpCoins, playerTouchCoin);
		FlxG.overlap(_player, dropsGroup, playerTouchDrops);
		FlxG.overlap(_player, _grpHazards, playerTouchHazard);
		FlxG.overlap(_player, _bossDoor, playerTouchBossDoor);
		
		
		if (!FlxG.overlap(_player, _grpLadders, playerTouchLadder))
		{
			_player.setTouchingLadder(false);
		}
		
		
		if (FlxG.keys.anyPressed(["R"])) 
		{
			FlxG.switchState(new Level1(unlockableColor));
		}
		if (FlxG.keys.anyPressed(["T"])) 
		{
			FlxG.switchState(new HubState());
		}
		
		if (FlxG.keys.anyJustPressed(["P"]))
		{
			var sub = new PauseState();
			//var sub = new FlxSubState(0xFFFFAAAA);
			this.openSubState(sub);
		}
		
		
		
		// possible todo: Call this only when something changes, and not every frame
		// right now it's more convenient being in one place...
		// could just make it a function unto itself, but whatever
		_hud.updateHUD(_player.hp, _player.curWeapon.juice, _score, _player.curWeapon.name);	
				
		


		super.update();
	}	
	
	/**
	 * Function that is called when this state is destroyed - you might want to 
	 * consider setting all objects this state uses to null to help garbage collection.
	 */
	override public function destroy():Void
	{
		//Reg.player = _player;
		//_player = null;
		super.destroy();
	}


	public function gotoNextLevel():Void
	{
		if (Reg.colorArray.indexOf(unlockableColor) == -1)
		{
			Reg.colorArray.push(unlockableColor);
			Reg.globalPalette += unlockableColor;
		}
		FlxG.switchState(new MenuState());

	}
	
	private function setUpLevel():Void
	{
		
		/* Stuff regarding a future level stitching overhaul
		 * 
		 * Uh... stuff
		 * Limited verticality perhaps...
		 * ...and... yeah, stuff...
		 * */
		
		 
		 /*
		 
		 
		 */
		 
		 
		 
		 
		 
		// stuff for the start room
		_newEntrance = FlxRandom.intRanged(1, 1);
		myOgmoLoader = new FlxOgmoLoader("assets/levels/level_" + levelId + "_start_" + _newEntrance + ".oel");
		mTileMap = myOgmoLoader.loadTilemap(tileName, 16, 16, "walls");
		
		for (tile in 6...7)  // tile collision settings
		{
			mTileMap.setTileProperties(tile, FlxObject.NONE); // misc walkthroughable tiles
		}
		
		myOgmoLoader.loadEntities(placeEntities, "entities");
		
		myOgmoLoader.loadEntities(getExitHeight, "entities");
		
		
		_levelHeight += mTileMap.height;
		_levelWidth += mTileMap.width;		
		_grpWalls.add(mTileMap);
		
		
		var itemRoomPos:Int;
		itemRoomPos = FlxRandom.intRanged(1, 1000);  // Same bounds as the for loop right below, but max is one less than below's. 
		// TODO Should make those numbers less magic later
		
		// stuff for the middle rooms
		for (i in 1...17) 
		{
			if (i == itemRoomPos)
			{
				// stuff for the item room
				var myOgmoLoader  = new FlxOgmoLoader("assets/levels/level_" + levelId + "_item_start_" + _newEntrance + ".oel");
				var myTileMap = myOgmoLoader.loadTilemap(tileName, 16, 16, "walls");
				setUpMaps(myOgmoLoader, myTileMap);
				
				var endId:Int = FlxRandom.intRanged(1, 1);
				//myOgmoLoader = new FlxOgmoLoader("assets/levels/level_" + levelId + "_item_end_" + endId + ".oel");
				myOgmoLoader = new FlxOgmoLoader("assets/levels/level_" + levelId + "_shop_end_" + endId + ".oel");
				myTileMap = myOgmoLoader.loadTilemap(tileName, 16, 16, "walls");
				setUpMaps(myOgmoLoader, myTileMap);
			}	
			
			var id:Int;
			id = FlxRandom.intRanged(1, 4);
			
			var myOgmoLoader = new FlxOgmoLoader("assets/levels/level_" + levelId + "_" + _newEntrance + "_" + id + ".oel");
			var myTileMap = myOgmoLoader.loadTilemap(tileName, 16, 16, "walls");
			setUpMaps(myOgmoLoader, myTileMap);
		}
		
		// stuff for the end room
		var myOgmoLoader = new FlxOgmoLoader("assets/levels/level_" + levelId + "_end_" + _newEntrance + ".oel");
		var myTileMap = myOgmoLoader.loadTilemap(tileName, 16, 16, "walls");
		setUpMaps(myOgmoLoader, myTileMap);
	}
	
	private function setUpMaps(ogmo:FlxOgmoLoader, map:FlxTilemap):Void
	{
		for (tile in 6...7)  // tile collision settings
		{
			map.setTileProperties(tile, FlxObject.NONE); // misc walkthroughable tiles
		}
		
		var previousWall:FlxTilemap = _grpWalls.members[_grpWalls.length - 1]; 
		
		if (_newEntrance == 1)
		{
			map.x += previousWall.x + previousWall.width;
			ogmo.loadEntities(getEntryHeight, "entities");
			map.y += previousWall.y + (_oldRoomEndY - _newRoomStartY);
			
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
		ogmo.loadEntities(getExitHeight, "entities");

		_levelHeight += map.height;
		_levelWidth += map.width;
		
		_grpWalls.add(map);
	} 

	private function touchEnemy(P:Player, E:enemies.EnemyTemplate):Void 
	{
		
		/**
		 * set E.immovable. No moving enemy!
		 * 
		 * if player is not stomping, somehow fallthrough
		 */
		
		if (P.curWeapon.stomp && (P.y + E.height) <= E.y && P.curWeapon.isUsable() && P.stompTimer <= 0 && E.alive && P.velocity.y > 0)
		{
			P.invincTimer = .1;
			E.takeDamage(P.curWeapon.damage);
			P.velocity.y = -150;
			P.stompTimer = .1;
			P.curWeapon.juice -= P.curWeapon.juiceCost;
		}
		else 
		{
					
			if (E.alive == true)
			{
				P.takeDamage(1);
			}
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
	private function playerGetHit(P:Player, B:weapons.Bullet):Void 
	{
		if (B.alive == true && B.getDamage() != -1 )
		{
			if (P.hurtTimer <= 0)
				B.onCollision();
			P.takeDamage(B.getDamage());

			//_hud.updateHUD(_player.hp, _score, _player.curWeapon.name);
		}
	}
	private function bulletTouchEnemy(B:weapons.Bullet, E:enemies.EnemyTemplate):Void 
	{
		if (B.alive && B.exists && E.alive && E.exists)
		{
			E.takeDamage(B.getDamage());
			B.kill();
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
	private function badBulletTouchEnemy(B:weapons.Bullet, E:enemies.EnemyTemplate):Void 
	{
		if (B.alive && B.exists && E.alive && E.exists)
		{
			E.collideBadBullet(B);
		
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
	private function bulletTouchWall(F:FlxTilemap, B:weapons.Bullet):Void 
	{
		if (B.alive && B.exists)
		{
			B.onCollision();
		}
		
	}
	
	private function playerTouchBossDoor(P:Player, BD:BossDoor):Void
	{
		if (P.alive && P.exists && BD.alive && BD.exists)
		{
			BD.open();
			P.enterBossDoor();
			
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
	private function playerTouchDrops(P:Player, D:Drops):Void 
	{
		if (P.alive && P.exists && D.alive && D.exists)
		{
			var cost:Int = D.doStuff(_score);
			_score -= cost;
			//_hud.updateHUD(_player.hp, _score, _player.curWeapon.name);	
		}
		
	}
	private function playerTouchLadder(P:Player, L:Ladder):Void
	{
		P.setTouchingLadder(true);
		
		// make it so that you can stand on top of the ladder
		if (L.top == true && (P.y < L.y) && P.isClimbing == false)
		{
			L.immovable = true;
			FlxG.collide(P, L);
			
			if (FlxG.keys.anyPressed(["DOWN", "S"]))
			{
				P.isClimbing = true;
				P.x = L.x;
			}	
			
			if (FlxG.keys.anyPressed(["UP", "W"]) && P.velocity.y == 0) 
				P.setTouchingLadder(false);	
		}
		
		if (P.isClimbing)
			P.x = L.x;
			
		if (L.top == true && (P.x == L.x) && ((P.y <= L.y) && (P.y >= L.y-20)))
			P.isClimbingUp = true;
		else
			P.isClimbingUp = false;		

	}	
		
	private function playerTouchHazard(P:Player, S:Spike):Void
	{
		P.takeDamage(S.dmg);
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
		else if (entityName == "bossDoor")
		{
			_bossDoor.x = x;
			_bossDoor.y = y;
		}
		else if (entityName == "spike")
		{
			var dmg:Int = Std.parseInt(entityData.get("damage"));
			_grpHazards.add(new Spike(x, y, dmg));
		}
		else if (entityName == "storePodium")
		{
			add(new ShopPodium(x, y, _player, dropsGroup, miscGroup));
		}
		else if (entityName == "decoration")
		{
			var palette = FlxRandom.intRanged(0, Reg.colorArray.length - 1);
			
			switch(entityData.get("name"))
			{
				case "crystal":
					decorationGroup.add(new Decoration(x, y, 0));
					
			}
		}
		else if (entityName == "enemy")
		{
			
			// put the code to determine the individual mob's color here
			// something like a random # based on Reg.globalPallete
			var palette = FlxRandom.intRanged(0, Reg.colorArray.length - 1);
			
			
			switch(entityData.get("name"))
			{
				case "snobal":
					_grpEnemies.add(new enemies.Snobal(x, y, _player, dropsGroup));
				case "snaake":
					_grpEnemies.add(new enemies.EnemySpawner(x, y, "snaake", _player, dropsGroup, _grpEnemies, _grpBadBullets, Reg.colorArray[palette]));
				case "metool":
					_grpEnemies.add(new enemies.EnemySpawner(x, y, "metool", _player, dropsGroup, _grpEnemies, _grpBadBullets, Reg.colorArray[palette]));
				case "burd":
					_grpEnemies.add(new enemies.Burd(x, y, _player, dropsGroup, _grpEnemies));
				case "notey":
					_grpEnemies.add(new enemies.Notey(x, y, _player, dropsGroup));
				case "testboss":
					_grpEnemies.add(new Testboss(x, y, _player, dropsGroup, _grpBadBullets, this));
				case "balun":
					_grpEnemies.add(new enemies.EnemySpawner(x, y, "balun", _player, dropsGroup, _grpEnemies, _grpBadBullets, Reg.colorArray[palette]));
				case "mush":
					_grpEnemies.add(new enemies.EnemySpawner(x, y, "metool", _player, dropsGroup, _grpEnemies, _grpBadBullets, Reg.colorArray[palette]));
				case "bat":
					_grpEnemies.add(new enemies.EnemySpawner(x, y, "bat", _player, dropsGroup, _grpEnemies, _grpBadBullets, Reg.colorArray[palette]));
			}
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
	
	private function getEntryHeight(entityName:String, entityData:Xml):Void
	{
		if (entityName == "entrance")
		{
			_newRoomStartY = Std.parseInt(entityData.get("y"));
			
		}
	}
	
	private function getExitHeight(entityName:String, entityData:Xml):Void
	{
		if (entityName == "exit")
		{
			_oldRoomEndY = Std.parseInt(entityData.get("y"));			
		}
	}
	
}
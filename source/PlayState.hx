package;

import Burd;
import EnemyTemplate;
import Metool;
import Notey;
import Snaake;
import Snobal;
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

/**
 * A FlxState which can be used for the actual gameplay.
 */
class PlayState extends FlxState
{
	private var _grpPlayer:FlxGroup;
	private var _player:Player;
	public var playerBullets:FlxTypedGroup<Bullet>;
	
	private var _grpEnemies:FlxGroup;
	private var _grpBadBullets:FlxGroup;
	
	private var _grpCoins:FlxTypedGroup<Coin>;
	private var _grpLadders:FlxTypedGroup<Ladder>;
	private var _grpHazards:FlxTypedGroup<Spike>;
	
	private var _door:Door;
	
	private var _grpWalls:FlxTypedGroup<FlxTilemap>;
	private var _levelWidth:Float;
	private var _levelHeight:Float;
	
	/*private var _map:FlxOgmoLoader;
	private var _mWalls:FlxTilemap;
	private var floor:FlxSprite;
	
	private var _map2:FlxOgmoLoader;
	private var _mWalls2:FlxTilemap;
	
	var _mapT:FlxOgmoLoader;
	var _mWallsT:FlxTilemap;
	*/
	
	var mOogmoLoader:FlxOgmoLoader;
	var mTileMap:FlxTilemap;
	
	private var loader:FlxOgmoLoader;
	private var midgroundMap:FlxTilemap;

	private var coinGroup:FlxGroup;
	
	private var dropsGroup:FlxTypedGroup<Drops>;
	
	private var _newEntrance:Int;
	
	private var _curMapX:Float = 0;
	private var _curMapY:Float = 0;
	
	private var _hud:HUD;
	private var _score:Int = 0;
	
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
		
		playerBullets = new FlxTypedGroup<Bullet>();
		add(playerBullets);
		_player = new Player(100,100,playerBullets);
		
		
		dropsGroup = new FlxTypedGroup<Drops>();
		add(dropsGroup);
		
		var drop = new Drops(320, 320, 0, _player);
		var drop2 = new Drops(340, 320, 2, _player);
		
		dropsGroup.add(drop);
		dropsGroup.add(drop2);
		
		
		_grpBadBullets = new FlxGroup();
		add(_grpBadBullets);
		
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
		_newEntrance = FlxRandom.intRanged(1, 4);
		mOogmoLoader = new FlxOgmoLoader("assets/data/level_1_start_" + _newEntrance + ".oel");
		mTileMap = mOogmoLoader.loadTilemap(AssetPaths.wood_tiles__png, 16, 16, "walls");
		
		mOogmoLoader.loadEntities(placeEntities, "entities");
		
		_levelHeight += mTileMap.height;
		_levelWidth += mTileMap.width;		
		_grpWalls.add(mTileMap);
		
		
		var itemRoomPos:Int;
		itemRoomPos = FlxRandom.intRanged(1, 5);  // Same bounds as the for loop right below, but max is one less than below's. 
		// TODO Should make those numbers less magic later
		
		// stuff for the middle rooms
		for (i in 1...6) 
		{
			if (i == itemRoomPos)
			{
				// stuff for the item room
				var myOgmoLoader  = new FlxOgmoLoader("assets/data/level_1_item_start_" + _newEntrance + ".oel");
				var myTileMap = myOgmoLoader.loadTilemap(AssetPaths.wood_tiles__png, 16, 16, "walls");
				setUpMaps(myOgmoLoader, myTileMap);
				
				var endId:Int = FlxRandom.intRanged(1, 4);
				myOgmoLoader = new FlxOgmoLoader("assets/data/level_1_item_end_" + endId + ".oel");
				myTileMap = myOgmoLoader.loadTilemap(AssetPaths.wood_tiles__png, 16, 16, "walls");
				setUpMaps(myOgmoLoader, myTileMap);
			}	
			
			var id:Int;
			id = FlxRandom.intRanged(1, 4);
			
			var myOgmoLoader = new FlxOgmoLoader("assets/data/level_1_" + _newEntrance + "_" + id + ".oel");
			var myTileMap = myOgmoLoader.loadTilemap(AssetPaths.wood_tiles__png, 16, 16, "walls");
			setUpMaps(myOgmoLoader, myTileMap);
		}
		
		// stuff for the end room
		var myOgmoLoader = new FlxOgmoLoader("assets/data/level_1_end_" + _newEntrance + ".oel");
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
	
	private function touchEnemy(P:Player, E:EnemyTemplate):Void 
	{
		if (E.alive == true)
		{
			P.getHurt(1);
			_hud.updateHUD(_player.hp, _score);
		}
	}
	private function playerGetHit(P:Player, B:Bullet):Void 
	{
		if (B.alive == true)
		{
			P.getHurt(B.getDamage());
			_hud.updateHUD(_player.hp, _score);
		}
	}
	private function bulletTouchEnemy(B:Bullet, E:EnemyTemplate):Void 
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
			_hud.updateHUD(health, _score);	
			
			//_hud.updateHUD(_health, _money);	
		}
	}
	private function bulletTouchLadder(B:Bullet, L:Ladder):Void 
	{
		if (B.alive && B.exists && L.alive && L.exists)
		{
			L.kill();
			_score++;
			_hud.updateHUD(_player.hp, _score);	
			
			//_hud.updateHUD(_health, _money);		
		
		}
		
	}
	private function playerTouchDrops(P:Player, D:Drops):Void 
	{
		if (P.alive && P.exists && D.alive && D.exists)
		{
			D.doStuff();
			D.kill();
			_hud.updateHUD(_player.hp, _score);	
			
		}
		
	}
	private function playerTouchCoin(P:Player, C:Coin):Void 
	{
		if (P.alive && P.exists && C.alive && C.exists)
		{
			C.kill();
			_score++;
			_hud.updateHUD(_player.hp, _score);	
			
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
		_hud.updateHUD(_player.hp, _score);
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
		else if (entityName == "enemy")
		{
			switch(entityData.get("name"))
			{
				case "snobal":
					_grpEnemies.add(new Snobal(x, y, _player, dropsGroup));
				case "snaake":
					_grpEnemies.add(new Snaake(x, y, _player, dropsGroup));
				case "metool":
					_grpEnemies.add(new Metool(x, y, _player, dropsGroup, _grpBadBullets));
				case "burd":
					_grpEnemies.add(new Burd(x, y, _player, dropsGroup, _grpEnemies));
				case "notey":
					_grpEnemies.add(new Notey(x, y, _player, dropsGroup));
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
	
}
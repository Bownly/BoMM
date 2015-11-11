package;

import flixel.addons.editors.ogmo.FlxOgmoLoader;
import flixel.FlxCamera;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;
import flixel.text.FlxText;
import flixel.tile.FlxTilemap;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;
import flixel.util.FlxRandom;
import weapons.Bullet;

/**
 * A FlxState which can be used for the game's menu.
 */
class HubState extends FlxState
{
	
	private var txtLevel1:FlxText;
	private var txtLevel2:FlxText;
	private var txtLevel3:FlxText;
	private var grpLevel:FlxTypedGroup<FlxText>;
	
	var palette:Int = Reg.G;
	
	private var _grpPlayer:FlxGroup;
	private var _player:Player;
	public var playerBullets:FlxTypedGroup<weapons.Bullet>;

	private var _grpWalls:FlxTypedGroup<FlxTilemap>;
	private var _levelWidth:Float;
	private var _levelHeight:Float;
	
	var myOgmoLoader:FlxOgmoLoader;
	var mTileMap:FlxTilemap;
	
	private var loader:FlxOgmoLoader;
	private var midgroundMap:FlxTilemap;

	private var miscGroup:FlxGroup;
	
	private var _door1:Door;
	private var _door2:Door;
	private var _door3:Door;
	private var _grpDoors:FlxTypedGroup<Door>;
	
	private var _curMapX:Float = 0;
	private var _curMapY:Float = 0;
		private var _grpLadders:FlxTypedGroup<Ladder>;
	
	
	public function new(?Palette:Int):Void
	{
		palette = Palette;
		super();
	}
		
	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{
		// TODO: kill this line when you add a start game menu. Shuffle colors on newgame start.
		if (Reg.door1Color == -1)
			Reg.shuffleColors();
		
		
		
		super.create();
		add(new FlxText(6, 9, 200, "Hub world (lol)"));
		FlxG.camera.bgColor = 0x000000;
		
		_levelHeight = _levelWidth = 0;
		
		_grpWalls = new FlxTypedGroup<FlxTilemap>();
		
		_grpLadders = new FlxTypedGroup<Ladder>();
		add(_grpLadders);
		
		_grpDoors = new FlxTypedGroup<Door>();
		add(_grpDoors);
		
		// this sets the doors to a random color each time. This code is for testing only atm. Move it to Reg and maybe make it less offensive
		_door1 = new Door(0, 0, 1, Reg.door1Color);
		_door2 = new Door(0, 0, 2, Reg.door2Color);
		_door3 = new Door(0, 0, 3, Reg.door3Color);	
		
		_grpDoors.add(_door1);
		_grpDoors.add(_door2);
		_grpDoors.add(_door3);
		
		
		
		playerBullets = new FlxTypedGroup<weapons.Bullet>();
		add(playerBullets);
		
		_player = new Player(100, 100, playerBullets);
		
		
		// TODO: This whole paragraph is a mess and also make the tileset reactive to the palette. ;)
		myOgmoLoader = new FlxOgmoLoader("assets/levels/hubworld.oel");
		mTileMap = myOgmoLoader.loadTilemap("assets/images/wood_tiles_persist.png", 16, 16, "walls");
		_grpWalls.add(mTileMap);
		_levelHeight += mTileMap.height;
		_levelWidth += mTileMap.width;	
		myOgmoLoader.loadEntities(placeEntities, "entities");
		add(_grpWalls);	
		
		
		_grpPlayer = new FlxGroup();
		add(_grpPlayer);
		_grpPlayer.add(_player);
		_grpPlayer.add(playerBullets);
		
		FlxG.mouse.visible = false;		
		
		
		FlxG.camera.follow(_player,1);
		FlxG.camera.style = FlxCamera.STYLE_PLATFORMER;
		FlxG.camera.setBounds(0, 0, _levelWidth, _levelHeight*2);
		FlxG.worldBounds.set(0, 0, _levelWidth, _levelHeight*2);
		
		/*_hud = new HUD();
		add(_hud);*/
		
		super.create();
	}

	override public function update():Void
	{
		FlxG.collide(_grpWalls, _player);
		FlxG.collide(_grpWalls, playerBullets, bulletTouchWall);
		FlxG.overlap(_player, _grpDoors, playerTouchDoor);
		
		if (FlxG.keys.anyPressed(["R"])) 
		{
			FlxG.switchState(new HubState());
		}
		if (FlxG.keys.anyPressed(["Z"])) 
		{
			Reg.shuffleColors();
		}
		
		super.update();
	}	
	
	private function playerTouchDoor(P:Player, D:Door):Void 
	{
		if (P.alive && P.exists && D.alive && D.exists)
		{		
			switch (D.levelId)
			{
				case (1):
					gotoLevel1();
				case (2):
					gotoLevel2();
				case (3):
					gotoLevel3();
			}
			
		}
		
	}

	private function bulletTouchWall(F:FlxTilemap, B:weapons.Bullet):Void 
	{
		if (B.alive && B.exists)
		{
			B.onCollision();
		}
		
	}
	
	function gotoLevel1():Void
	{
		FlxG.switchState(new Level1(Reg.door1Color));
	}
	function gotoLevel2():Void
	{
		FlxG.switchState(new Level2(Reg.door2Color));
	}
	function gotoLevel3():Void
	{
		FlxG.switchState(new Level3(Reg.door3Color));
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
	/*	else if (entityName == "ladder")
		{
			if (entityData.get("top") == "True")
				_grpLadders.add(new Ladder(x, y, true));
			else
				_grpLadders.add(new Ladder(x, y, false));
		}*/
		else if (entityName == "door")
		{
			switch(entityData.get("level_id"))
			{
				case ("1"):
				{
					_door1.x = x;
					_door1.y = y;
				}
				case ("2"):
				{
					_door2.x = x;
					_door2.y = y;
				}
				case ("3"):
				{
					_door3.x = x;
					_door3.y = y;
				}
			}
			
			
		}


	}
	
	override public function destroy():Void
	{
		super.destroy();
	}


}
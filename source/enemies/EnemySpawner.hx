package enemies;

import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.group.FlxGroup;
import flixel.tile.FlxTilemap;
import flixel.math.FlxRandom;

/**
 * ...
 * @author Me
 */
class EnemySpawner extends FlxSprite
{
	var _enemyName:String;
	var _player:Player;
	var _grpDrops:FlxTypedGroup<Drops>;
	var _grpEnemies:FlxGroup;
	var _grpSVNoClipEnemies:FlxGroup;
	var _grpBadBullets:FlxGroup;
	var _palette:Int;
	var _map:FlxTilemap;
	
	var _enemy:EnemyTemplate;
	var _wasEnemyKilled:Bool = false;
	var _canSpawnEnemy:Bool = true;
	var _notFirstSpawn:Bool = true;
	var _wasOffScreen:Bool = true;
	
	/*
	 *  The spawner will spawn its enemy if the spawner is on screen and if the enemy isn't already spawned. 
	 * If the enemy gets off screen, it's killed and despawned. 
	 * Then, if the spawner is on screen, the enemy won't respawn until the spawner 
	 * ...goes off screen and then back on screen. 
	 * This way an enemy won't spawn in the middle of the screen
	 * ...if it walks off the screen when its spawner is still on screen. */
	
	public function new(X:Float = 0, Y:Float = 0, EnemyName:String, ThePlayer:Player, DropsGrp:FlxTypedGroup<Drops>,
		Enemies:FlxGroup, SVNoClipEnemies:FlxGroup, Bullets:FlxGroup, Palette:Int, Room:FlxTilemap) 
	{
		super(X, Y);
		loadGraphic("assets/images/spike.png", true, 16, 16);
		width = 16;
		height = 16;
		
		allowCollisions = FlxObject.NONE;
		
		_enemyName = EnemyName;
		_player = ThePlayer;
		_grpDrops = DropsGrp;
		_grpEnemies = Enemies;
		_grpSVNoClipEnemies = SVNoClipEnemies;
		_grpBadBullets = Bullets;
		_palette = Palette;
		_map = Room;
		
	}
	
	override public function update(elapsed:Float):Void
	{
		if (_enemy != null)
		{
			if (_enemy != null && _enemy._killed == true)
			{
				_wasEnemyKilled = true;
				_canSpawnEnemy = false; 
			}
			
			if (isOnScreen() && _wasOffScreen)
				_canSpawnEnemy = true;
				
			if (isOnScreen() && _enemy.exists == false && _wasEnemyKilled == false && _canSpawnEnemy)
			{
				spawnEnemy();
			
			}
			
			if (!isOnScreen())
			{
				_canSpawnEnemy = false;
				_wasOffScreen = true;
			}
		}
		else if (isOnScreen())
			spawnEnemy();
		
		super.update(elapsed);
	}
	
	private function spawnEnemy():Void
	{
		_canSpawnEnemy = false;
		_wasOffScreen = false;
		
		_enemy = null;	
		
		switch(_enemyName)
		{
			case "balun":
				_enemy = new Balun(x, y, _player, this, _grpDrops, _grpEnemies, _grpBadBullets, _palette);
			case "bat":
				_enemy = new Bat(x, y, _player, this, _grpDrops, _grpBadBullets, _palette);	
			case "bee":
				{
					_enemy = new Bee(x, y, _player, this, _grpDrops, _grpEnemies, _grpSVNoClipEnemies, _palette);
					_grpSVNoClipEnemies.add(_enemy);
					return;
				}
			case "bombox":
				//_enemy = new Bombox(x, y, _player, this, _grpDrops, _grpEnemies, _grpBadBullets, _palette);
				_enemy = new Snale(x, y, _player, this, _grpDrops, _grpEnemies, _grpBadBullets, _palette);
			case "coolsun":
				_enemy = new CoolSun(x, y, _player, this, _grpDrops, _grpBadBullets, _palette);
			case "flowerguy":
				_enemy = new Flowerguy(x, y, _player, this, _grpDrops, _grpBadBullets, _palette);
			case "lightning":
				_enemy = new Lightning(x, y, _player, this, _grpDrops, _palette);
			
			case "mush":
				_enemy = new Mush(x, y, _player, this, _grpDrops, _grpBadBullets, _palette, _map);
			case "snaake":
				_enemy = new Snaake(x, y, _player, this, _grpDrops, _palette, _map);
			case "snale":
				_enemy = new Snale(x, y, _player, this, _grpDrops, _grpEnemies, _grpBadBullets, _palette);
			case "stalagmite":
				_enemy = new Stalagmite(x, y, _player, this, _grpDrops);
			case "stalactyke":
				_enemy = new Stalactyke(x, y, _player, this, _grpDrops);
			
			case "hydra":
				{
					var _enemy2 = new BossHydraA(x, y, _player, this, _grpDrops);
					 _enemy = new BossHydraB(x, y, _player, this, _grpDrops);
					var _enemy3 = new BossHydraC(x + 32, y, _player, this, _grpDrops);
					_grpEnemies.add(_enemy2);
					_grpEnemies.add(_enemy3);
				}
		}

			_notFirstSpawn = false;
			_grpEnemies.add(_enemy);
		
	}
}  
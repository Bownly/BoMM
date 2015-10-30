package enemies;

import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;
import flixel.util.FlxRandom;

/**
 * ...
 * @author ...
 */
class EnemySpawner extends FlxSprite
{
	var _enemyName:String;
	var _player:Player;
	var _grpDrops:FlxTypedGroup<Drops>;
	var _grpEnemies:FlxGroup;
	var _grpBadBullets:FlxGroup;
	var _palette:Int;
	
	var _enemy:EnemyTemplate;
	var _isEnemyDead:Bool = false;
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
		Enemies:FlxGroup, Bullets:FlxGroup, Palette:Int) 
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
		_grpBadBullets = Bullets;
		_palette = Palette;
		
	}
	
	override public function update():Void
	{
		
		FlxG.watch.add(_enemy, "exists");
		
		if (_enemy != null && _enemy._killed == true)
		{
			_isEnemyDead = true;
			_canSpawnEnemy = false; 
		}

			
		if (isOnScreen() && _isEnemyDead == false && _wasOffScreen)
		{
			spawnEnemy();
			trace("enemy spawn");

		}
		
		if (!isOnScreen())
		{
			trace("off screen spawner");
			_canSpawnEnemy = false;
			_wasOffScreen = true;
		}
		
		super.update();
	}
	
	private function spawnEnemy():Void
	{
		_canSpawnEnemy = false;
		_wasOffScreen = false;
		var palette = FlxRandom.intRanged(0, Reg.colorArray.length - 1);
		
		_enemy = null;	
		
		switch(_enemyName)
		{
			case "snaake":
				_enemy = new enemies.Snaake(x, y, _player, _grpDrops, _palette);
			case "metool":
			//	_enemy = new enemies.Metool(x, y, _player, _grpDrops, _grpBadBullets);
				_enemy = new enemies.Mush(x, y, _player, _grpDrops, _grpBadBullets, palette);
			case "balun":
				_enemy = new Balun(x, y, _player, _grpDrops, _grpEnemies, _grpBadBullets, _palette);
			case "mush":
				_enemy = new enemies.Mush(x, y, _player, _grpDrops, _grpBadBullets, _palette);
			case "bat":
				_enemy = new enemies.Bat(x, y, _player, _grpDrops, _grpBadBullets, _palette);				
		}

			_notFirstSpawn = false;
			_grpEnemies.add(_enemy);
		
	}
}
package weapons;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.group.FlxTypedGroup;

/**
 * ...
 * @author me
 */
class EightWayWeapon extends WeaponTemplate
{


	public function new(Name:String, Palette:Int, ?Bullets:FlxTypedGroup<Bullet>) 
	{
		super(Name, Palette, Bullets);
		weaponID = 4;
		
		damage = 5;
		juice = 9;
		juiceMax = 9;
		juiceCost = 1;
		palette = 1;
	}
	
	public override function shoot(_player:Player)
	{
		if (_player.bulletArray.countLiving() < _player.maxBullets && juice >= juiceCost) 
		{
			_player.postShotTimer = .33;
			
			var direction:Int = 0;
			
			if (FlxG.keys.anyPressed(["LEFT", "A"])) 
				direction += FlxObject.LEFT;
			else if (FlxG.keys.anyPressed(["RIGHT", "D"])) 
				direction += FlxObject.RIGHT;
			if (FlxG.keys.anyPressed(["UP", "W"])) 
				direction += FlxObject.CEILING;
			else if (FlxG.keys.anyPressed(["DOWN", "S"])) 
				direction += FlxObject.FLOOR;
				
			if (direction == 0)
			{
				direction = _player.facing;
			}
			var newBullet = new Bullet(_player.x + 8, _player.y + 8, 500, direction, _player.damage + damage, 256, palette, direction);
			_player.bulletArray.add(newBullet);
			
			
			/*var newBullet = new Bullet(_player.x - 8, _player.y + 8, 500, FlxObject.LEFT, _player.damage + damage, 256);
			var newBullet2 = new Bullet(_player.x + 8, _player.y + 8, 500, FlxObject.RIGHT, _player.damage + damage, 256);
			_player.bulletArray.add(newBullet);
			_player.bulletArray.add(newBullet2);*/

			juice -= juiceCost;
		}
	}
}
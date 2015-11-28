package weapons;
import flixel.FlxObject;
import flixel.group.FlxTypedGroup;

/**
 * ...
 * @author me
 */
class SpreadWeapon extends WeaponTemplate
{


	public function new(Name:String, Palette:Int, ?Bullets:FlxTypedGroup<Bullet>) 
	{
		super(Name, Palette, Bullets);
		weaponID = 11;
		
		damage = 3;
		juice = 9;
		juiceMax = 9;
		juiceCost = 1;
	}
	
	public override function shoot(_player:Player)
	{
		if (_player.bulletArray.countLiving() < maxBullets && juice >= juiceCost) 
		{
			_player.postShotTimer = .33;
			
			if (_player.flipX)
			{	
				var newBullet = new Bullet(_player.x - 8, _player.y + 8, 200, FlxObject.LEFT, _player.damage + damage, 80, palette, FlxObject.LEFT);
				var newBullet1 = new Bullet(_player.x - 2, _player.y + 8, 200, FlxObject.LEFT + FlxObject.CEILING + FlxObject.LEFT, _player.damage + damage, 80, palette, FlxObject.LEFT + FlxObject.CEILING);
				var newBullet2 = new Bullet(_player.x - 2, _player.y + 8, 200, FlxObject.LEFT + FlxObject.FLOOR + FlxObject.LEFT, _player.damage + damage, 80, palette, FlxObject.LEFT + FlxObject.FLOOR);
				
				_player.bulletArray.add(newBullet);
				_player.bulletArray.add(newBullet1);
				_player.bulletArray.add(newBullet2);
			}
			else
			{
				var newBullet = new Bullet(_player.x + 8, _player.y + 8, 200, FlxObject.RIGHT, _player.damage + damage, 80, palette, FlxObject.RIGHT);
				var newBullet1 = new Bullet(_player.x + 2, _player.y + 8, 200, FlxObject.RIGHT + FlxObject.CEILING + FlxObject.RIGHT, _player.damage + damage, 80, palette, FlxObject.RIGHT + FlxObject.CEILING);
				var newBullet2 = new Bullet(_player.x + 2, _player.y + 8, 200, FlxObject.RIGHT + FlxObject.FLOOR + FlxObject.RIGHT, _player.damage + damage, 80, palette, FlxObject.RIGHT + FlxObject.FLOOR);
				
				_player.bulletArray.add(newBullet);
				_player.bulletArray.add(newBullet1);
				_player.bulletArray.add(newBullet2);
				
			}
			juice -= juiceCost;
		}
	}
}
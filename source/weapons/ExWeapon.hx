package weapons;
import flixel.FlxObject;
import flixel.group.FlxTypedGroup;

/**
 * ...
 * @author me
 */
class ExWeapon extends WeaponTemplate
{


	public function new(Name:String, ?Bullets:FlxTypedGroup<Bullet>) 
	{
		super(Name, Bullets);
		
		damage = 5;
		juice = 9;
		juiceMax = 9;
		juiceCost = 1;
	}
	
	public override function shoot(_player:Player)
	{
		if (_player.bulletArray.countLiving() < maxBullets && juice >= juiceCost) 
		{
			_player.postShotTimer = .33;
	
				var newBullet = new Bullet(_player.x,  _player.y + 8, 200, FlxObject.LEFT + FlxObject.CEILING, _player.damage + damage, 256);
				var newBullet1 = new Bullet(_player.x, _player.y + 8, 200, FlxObject.RIGHT + FlxObject.CEILING, _player.damage + damage, 256);
				var newBullet2 = new Bullet(_player.x, _player.y + 8, 200, FlxObject.LEFT + FlxObject.FLOOR, _player.damage + damage, 256);		
				var newBullet3 = new Bullet(_player.x, _player.y + 8, 200, FlxObject.RIGHT + FlxObject.FLOOR, _player.damage + damage, 256);		
				
				_player.bulletArray.add(newBullet);
				_player.bulletArray.add(newBullet1);
				_player.bulletArray.add(newBullet2);
				_player.bulletArray.add(newBullet3);

	
			juice -= juiceCost;
		}
	}
}
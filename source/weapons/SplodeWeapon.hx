package weapons;
import flixel.FlxObject;
import flixel.group.FlxTypedGroup;

/**
 * ...
 * @author me
 */
class SplodeWeapon extends WeaponTemplate
{


	public function new(Name:String, ?Bullets:FlxTypedGroup<Bullet>) 
	{
		super(Name, Bullets);
		weaponID = 10;
			
		damage = 10;
		juice = 5;
		juiceMax = 5;
		juiceCost = 1;
	}
	
	public override function shoot(_player:Player)
	{
		if (_player.bulletArray.countLiving() < 1 && juice >= juiceCost) 
		{
			_player.postShotTimer = .33;
			
			if (_player.flipX)
			{	
				var newBullet = new SplodeBullet(_player.x - 8, _player.y + 8, 80-(_player.velocity.x/2) , FlxObject.CEILING + _player.facing, _player.damage + damage, 256, _player);
				
				_player.bulletArray.add(newBullet);

			}	
			else
			{
				var newBullet = new SplodeBullet(_player.x + 8, _player.y + 8, 80+(_player.velocity.x/2) , FlxObject.CEILING + _player.facing, _player.damage + damage, 256, _player);
				
				_player.bulletArray.add(newBullet);
			}
			juice -= juiceCost;
		}
	}
}
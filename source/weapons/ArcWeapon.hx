package weapons;
import flixel.FlxObject;
import flixel.group.FlxTypedGroup;

/**
 * ...
 * @author me
 */
class ArcWeapon extends WeaponTemplate
{
	private var gravity:Int = -30;


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
			
			if (_player.flipX)
			{
				var newBullet = new ArcBullet(_player.x - 8, _player.y + 8, 80-(_player.velocity.x/2), FlxObject.CEILING + _player.facing, _player.damage + damage, 256);

				_player.bulletArray.add(newBullet);
			}
			else
			{
				var newBullet = new ArcBullet(_player.x + 8, _player.y + 8, 80+(_player.velocity.x/2), FlxObject.CEILING + _player.facing, _player.damage + damage, 256);

				_player.bulletArray.add(newBullet);
			}
			juice -= juiceCost;
		}
	}
}
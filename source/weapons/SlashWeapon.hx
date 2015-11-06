package weapons;
import flixel.FlxObject;
import flixel.group.FlxTypedGroup;

/**
 * ...
 * @author me
 */
class SlashWeapon extends WeaponTemplate
{

	public function new(Name:String, ?Bullets:FlxTypedGroup<Bullet>) 
	{
		super(Name, Bullets);
		weaponID = 9;
		
		damage = 10;
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
				var newBullet = new SlashBullet(_player.x - 16, _player.y + 16, 200, FlxObject.CEILING + FlxObject.LEFT, _player.damage + damage, 256, _player);

				_player.bulletArray.add(newBullet);
			}
			else
			{
				var newBullet = new SlashBullet(_player.x + 16, _player.y + 16, 200, FlxObject.CEILING + FlxObject.RIGHT, _player.damage + damage, 256, _player);

				_player.bulletArray.add(newBullet);
			}
			juice -= juiceCost;
		}
	}
}
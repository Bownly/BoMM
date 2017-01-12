package weapons;
import flixel.FlxObject;
import flixel.group.FlxGroup;

/**
 * ...
 * @author me
 */
class ArcWeapon extends WeaponTemplate
{

	public function new(Name:String, Palette:Int, ?Bullets:FlxTypedGroup<Bullet>) 
	{
		super(Name, Palette, Bullets);
		weaponID = 1;
		
		damage = 1;
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
				var newBullet = new ArcBullet(_player.x - 8, _player.y + 8, 80-(_player.velocity.x/2), FlxObject.CEILING + _player.facing, _player.damage + damage, 256, palette);

				_player.bulletArray.add(newBullet);
			}
			else
			{
				var newBullet = new ArcBullet(_player.x + 8, _player.y + 8, 80+(_player.velocity.x/2), FlxObject.CEILING + _player.facing, _player.damage + damage, 256, palette);

				_player.bulletArray.add(newBullet);
			}
			juice -= juiceCost;
		}
	}
}
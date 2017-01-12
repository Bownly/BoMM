package weapons;
import flixel.FlxObject;
import flixel.group.FlxGroup;

/**
 * ...
 * @author me
 */
class FollowWeapon extends WeaponTemplate
{

	public function new(Name:String, Palette:Int, ?Bullets:FlxTypedGroup<Bullet>) 
	{
		super(Name, Palette, Bullets);
		weaponID = 6;
		
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
				var newBullet = new FollowBullet(_player.x-10, _player.y + 8, 0 , FlxObject.LEFT, _player.damage + damage, 256, _player, palette);
				//var newBullet2 = new FollowBullet(_player.x + 20, _player.y + 8, 50 , FlxObject.RIGHT, _player.damage + damage, 256, _player);

				_player.bulletArray.add(newBullet);
				//_player.bulletArray.add(newBullet2);
				
			}
			else
			{
				var newBullet = new FollowBullet(_player.x+10, _player.y + 8, 0 , FlxObject.RIGHT, _player.damage + damage, 256, _player, palette);
				//var newBullet2 = new FollowBullet(_player.x + 20, _player.y + 8, 50 , FlxObject.RIGHT, _player.damage + damage, 256, _player);

				_player.bulletArray.add(newBullet);
				//_player.bulletArray.add(newBullet2);
			}
			juice -= juiceCost;
		}
	}
}
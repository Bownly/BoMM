package weapons;
import flixel.FlxObject;
import flixel.group.FlxGroup;

/**
 * ...
 * @author me
 * Issues:
 * -bullet wont despawn (new bullet is made each time)
 * -bullet cannot travel down walls
 * -bullet cannot travel under walls
 */
class MouseWeapon extends WeaponTemplate
{

	public function new(Name:String, Palette:Int, ?Bullets:FlxTypedGroup<Bullet>) 
	{
		super(Name, Palette, Bullets);
		weaponID = 7;
		
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
				var newBullet = new MouseBullet(_player.x - 8, _player.y + 8, 80-(_player.velocity.x/2) , FlxObject.LEFT, _player.damage + damage, 256, _player, palette);

				_player.bulletArray.add(newBullet);
			}
			else
			{
				var newBullet = new MouseBullet(_player.x + 8, _player.y + 8, 80+(_player.velocity.x/2) , FlxObject.RIGHT, _player.damage + damage, 256, _player, palette);

				_player.bulletArray.add(newBullet);
			}
			juice -= juiceCost;
		}
	}
}
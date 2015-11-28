package weapons;
import flixel.FlxObject;
import flixel.group.FlxTypedGroup;

/**
 * ...
 * @author me
 */
class StringWeapon extends WeaponTemplate
{

	public function new(Name:String, Palette:Int, ?Bullets:FlxTypedGroup<Bullet>) 
	{
		super(Name, Palette, Bullets);
		weaponID = 13;
		
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
				var newBullet = new Bullet(_player.x - 16, _player.y + 8, 250, FlxObject.LEFT, _player.damage + damage, 256, palette, FlxObject.LEFT);
				var newBullet1 = new Bullet(_player.x - 8, _player.y + 8, 250, FlxObject.LEFT, _player.damage + damage, 256, palette, FlxObject.LEFT);
				var newBullet2 = new Bullet(_player.x, _player.y + 8, 250, FlxObject.LEFT, _player.damage + damage, 256, palette, FlxObject.LEFT);
				
				_player.bulletArray.add(newBullet);
				_player.bulletArray.add(newBullet1);
				_player.bulletArray.add(newBullet2);
			}	
			else
			{
				var newBullet = new Bullet(_player.x + 16, _player.y + 8, 250, FlxObject.RIGHT, _player.damage + damage, 256, palette, FlxObject.RIGHT);
				var newBullet1 = new Bullet(_player.x + 8, _player.y + 8, 250, FlxObject.RIGHT, _player.damage + damage, 256, palette, FlxObject.RIGHT);
				var newBullet2 = new Bullet(_player.x, _player.y + 8, 250, FlxObject.RIGHT, _player.damage + damage, 256, palette, FlxObject.RIGHT);
				
				_player.bulletArray.add(newBullet);
				_player.bulletArray.add(newBullet1);
				_player.bulletArray.add(newBullet2);	
			}
			juice -= juiceCost;
		}
	}
}
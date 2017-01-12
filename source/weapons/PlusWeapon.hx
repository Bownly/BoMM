package weapons;
import flixel.FlxObject;
import flixel.group.FlxGroup;

/**
 * ...
 * @author me
 */
class PlusWeapon extends WeaponTemplate
{


	public function new(Name:String, Palette:Int, ?Bullets:FlxTypedGroup<Bullet>) 
	{
		super(Name, Palette, Bullets);
		weaponID = 8;
		
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
	
				var newBullet = new Bullet(_player.x,  _player.y + 8, 200, FlxObject.LEFT, _player.damage + damage, 256, palette, FlxObject.UP);
				var newBullet1 = new Bullet(_player.x, _player.y + 8, 200, FlxObject.RIGHT, _player.damage + damage, 256, palette, FlxObject.DOWN);
				var newBullet2 = new Bullet(_player.x, _player.y + 8, 200, FlxObject.CEILING, _player.damage + damage, 256, palette, FlxObject.LEFT);		
				var newBullet3 = new Bullet(_player.x, _player.y + 8, 200, FlxObject.FLOOR, _player.damage + damage, 256, palette, FlxObject.RIGHT);		
				
				_player.bulletArray.add(newBullet);
				_player.bulletArray.add(newBullet1);
				_player.bulletArray.add(newBullet2);
				_player.bulletArray.add(newBullet3);

	
			juice -= juiceCost;
		}
	}
}
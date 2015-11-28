package weapons;
import flixel.FlxObject;
import flixel.group.FlxTypedGroup;

/**
 * ...
 * @author me
 */
class ExWeapon extends WeaponTemplate
{


	public function new(Name:String, Palette:Int, ?Bullets:FlxTypedGroup<Bullet>) 
	{
		super(Name, Palette, Bullets);
		weaponID = 5;
		
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
				var newBullet = new Bullet(_player.x,  _player.y + 8, 200 - _player.velocity.x, FlxObject.LEFT + FlxObject.CEILING, _player.damage + damage, 256, palette, FlxObject.LEFT + FlxObject.CEILING);
				var newBullet1 = new Bullet(_player.x, _player.y + 8, 200 - _player.velocity.x, FlxObject.RIGHT + FlxObject.CEILING, _player.damage + damage, 256, palette, FlxObject.RIGHT + FlxObject.CEILING);
				var newBullet2 = new Bullet(_player.x, _player.y + 8, 200 - _player.velocity.x, FlxObject.LEFT + FlxObject.FLOOR, _player.damage + damage, 256, palette,FlxObject.LEFT + FlxObject.FLOOR);		
				var newBullet3 = new Bullet(_player.x, _player.y + 8, 200 - _player.velocity.x, FlxObject.RIGHT + FlxObject.FLOOR, _player.damage + damage, 256, palette, FlxObject.RIGHT + FlxObject.FLOOR);		
				_player.bulletArray.add(newBullet);
				_player.bulletArray.add(newBullet1);
				_player.bulletArray.add(newBullet2);
				_player.bulletArray.add(newBullet3);		
				
				}
			else
			{
				var newBullet = new Bullet(_player.x,  _player.y + 8, 200 + _player.velocity.x, FlxObject.LEFT + FlxObject.CEILING, _player.damage + damage, 256, palette, FlxObject.LEFT + FlxObject.CEILING);
				var newBullet1 = new Bullet(_player.x, _player.y + 8, 200 + _player.velocity.x, FlxObject.RIGHT + FlxObject.CEILING, _player.damage + damage, 256, palette, FlxObject.RIGHT + FlxObject.CEILING);
				var newBullet2 = new Bullet(_player.x, _player.y + 8, 200 + _player.velocity.x, FlxObject.LEFT + FlxObject.FLOOR, _player.damage + damage, 256, palette,FlxObject.LEFT + FlxObject.FLOOR);		
				var newBullet3 = new Bullet(_player.x, _player.y + 8, 200 + _player.velocity.x, FlxObject.RIGHT + FlxObject.FLOOR, _player.damage + damage, 256, palette, FlxObject.RIGHT + FlxObject.FLOOR);		
				_player.bulletArray.add(newBullet);
				_player.bulletArray.add(newBullet1);
				_player.bulletArray.add(newBullet2);
				_player.bulletArray.add(newBullet3);
				
				}
			


	
			juice -= juiceCost;
		}
	}
}
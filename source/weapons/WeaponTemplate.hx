package weapons;

import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.group.FlxTypedGroup;

/**
 * ...
 * @author me
 */
class WeaponTemplate
{
	public var name:String;
	private var bulletArray:FlxTypedGroup<Bullet>;
	public var damage:Int = 1;
	
	public var juice:Int = 12;
	public var juiceMax:Int =12;
	public var juiceCost:Int = 0;
	
	public var maxBullets:Int = 3;
	public var bulletCount:Int = 0;
	
	public var doubleJump:Bool = false;
	public var stomp:Bool = false;

	public var isEquipment:Bool = false;
	
	public var palette:Int = 0;
	public var unlocked:Bool = true;
	
	public var weaponID:Int = 0;

	
	/* Weapon ID legend:
	 * 0  =  pea
	 * 1  =  arc
	 * 2  =  bounce
	 * 3  =  cluster
	 * 4  =  8 way
	 * 5  =  x shot
	 * 6  =  follow
	 * 7  =  mouse
	 * 8  =  plus
	 * 9  =  slash
	 * 10 =  splode
	 * 11 =  spread
	 * 12 =  stomp
	 * 13 =  string
	 * 14 =  wings
	*/
	
	public function new(Name:String, ?Palette:Int, ?Bullets:FlxTypedGroup<Bullet>) 
	{
		name = Name;
		bulletArray = Bullets;
		palette = Palette;
	}
	
	public function isUsable():Bool
	{
		if (juiceCost > juice)
			return false;
		else
			return true;
	}
	
	public function shoot(_player:Player)
	{
		if (_player.bulletArray.countLiving() < maxBullets && (isUsable() || isEquipment))
		{
			_player.postShotTimer = .33;
			
			if (_player.flipX)
			{
				var newBullet = new Bullet(_player.x - 8, _player.y + 8, 500, FlxObject.LEFT, _player.damage + damage, 256);
				_player.bulletArray.add(newBullet);
			}
			else
			{
				var newBullet = new Bullet(_player.x + 8, _player.y + 8, 500, FlxObject.RIGHT, _player.damage + damage, 256);
				_player.bulletArray.add(newBullet);
			}
			if (!isEquipment)
				juice -= juiceCost;
		}
	}
}
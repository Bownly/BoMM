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
	public var damage:Int = 1000;
	
	public var juice:Int = 9;
	public var juiceMax:Int = 9;
	public var juiceCost:Int = 0;
	
	public var maxBullets:Int = 3;
	public var bulletCount:Int = 0;
	
	public var doubleJump:Bool = false;
	public var isEquipment:Bool = false;
	
	public var palette:Int = 0;
	public var unlocked:Bool = true;

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
		if (_player.bulletArray.countLiving() < maxBullets && juice > 0) 
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
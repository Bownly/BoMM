package weapons;
import flixel.FlxObject;
import flixel.group.FlxGroup;

/**
 * ...
 * @author me
 */
class YellowWeapon extends WeaponTemplate
{


	public function new(Name:String, Palette:Int, ?Bullets:FlxTypedGroup<Bullet>) 
	{
		super(Name, Palette, Bullets);
		
		damage = 5;
		juice = 9;
		juiceMax = 9;
		juiceCost = 1;
		//unlocked = false;
	}
	
	public override function shoot(_player:Player)
	{
		if (_player.bulletArray.countLiving() < maxBullets && juice >= juiceCost) 
		{
			_player.postShotTimer = .33;

			juice -= juiceCost;
		}
	}
}
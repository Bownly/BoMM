package weapons;
import flixel.FlxG;

/**
 * ...
 * @author ...
 */
class StompEquipment extends WeaponTemplate
{

	public function new(Name:String, Palette:Int) 
	{
		super(Name, Palette);
		weaponID = 12;
		
		stomp = true;
		juiceCost = 1;
		isEquipment = true;
		
		
	}
	
}
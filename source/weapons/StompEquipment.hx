package weapons;
import flixel.FlxG;

/**
 * ...
 * @author ...
 */
class StompEquipment extends WeaponTemplate
{

	public function new(Name:String) 
	{
		super(Name);
		stomp = true;
		juiceCost = 1;
		isEquipment = true;
		
		
	}
	
}
package weapons;

/**
 * ...
 * @author ...
 */
class WingsEquipment extends WeaponTemplate
{

	public function new(Name:String, Palette:Int) 
	{
		super(Name, Palette);
		weaponID = 14;
		
		doubleJump = true;
		juiceCost = 1;
		isEquipment = true;
	}
	
}
package weapons;

/**
 * ...
 * @author ...
 */
class WingsEquipment extends WeaponTemplate
{

	public function new(Name:String) 
	{
		super(Name);
		doubleJump = true;
		juiceCost = 1;
		isEquipment = true;
	}
	
}
package;

import flixel.group.FlxTypedGroup;
import flixel.util.FlxSave;
import weapons.Bullet;
import weapons.EightWayWeapon;
import weapons.WeaponTemplate;

/**
 * Handy, pre-built Registry class that can be used to store 
 * references to objects and other things for quick-access. Feel
 * free to simply ignore it or change it in any way you like.
 */
class Reg
{
	/**
	 * Generic levels Array that can be used for cross-state stuff.
	 * Example usage: Storing the levels of a platformer.
	 */
	public static var levels:Array<Dynamic> = [];
	/**
	 * Generic level variable that can be used for cross-state stuff.
	 * Example usage: Storing the current level number.
	 */
	public static var level:Int = 0;
	/**
	 * Generic scores Array that can be used for cross-state stuff.
	 * Example usage: Storing the scores for level.
	 */
	public static var scores:Array<Dynamic> = [];
	/**
	 * Generic score variable that can be used for cross-state stuff.
	 * Example usage: Storing the current score.
	 */
	public static var score:Int = 0;
	/**
	 * Generic bucket for storing different FlxSaves.
	 * Especially useful for setting up multiple save slots.
	 */
	public static var saves:Array<FlxSave> = [];
	
	public static var bullets:FlxTypedGroup<weapons.Bullet> = new FlxTypedGroup<weapons.Bullet>();
	
	public static var player:Player;
	//public static var player:Player = new Player(0, 0, bullets);
	
	//public static var pHP:Int = 3;
	public static var pMaxHP:Int = 3;
	public static var pMaxJumps:Int = 2;
	public static var pDamage:Int = 1;
	public static var pLuck:Int = 5;	
	
	public static var weapon1:WeaponTemplate = new WeaponTemplate("pea");
	public static var weapon2:WeaponTemplate = new EightWayWeapon("cyan");
		
	public static var weaponArray:Array<WeaponTemplate> = [weapon1, weapon2];
}
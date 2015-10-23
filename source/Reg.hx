package;

import flixel.group.FlxTypedGroup;
import flixel.util.FlxRandom;
import flixel.util.FlxSave;
import weapons.ArcWeapon;
import weapons.Bullet;
import weapons.EightWayWeapon;
import weapons.StompEquipment;
import weapons.WeaponTemplate;
import weapons.WingsEquipment;
import weapons.YellowWeapon;

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
	

	// color constants
	public static inline var G:Int = 0x1000;
	public static inline var C:Int = 0x0100;
	public static inline var M:Int = 0x0010;
	public static inline var Y:Int = 0x0001;
	
	public static inline var CM:Int = 0x110;
	public static inline var CY:Int = 0x101;
	public static inline var MY:Int = 0x011;
	public static inline var CMY:Int = 0x111;


	
	//public static var colorArray:Array<Int> = [G, C, M, Y];
	public static var colorArray:Array<Int> = [G];
	
	public static var globalPalette:Int = G;
	
	
	public static var bullets:FlxTypedGroup<weapons.Bullet> = new FlxTypedGroup<weapons.Bullet>();
	
	public static var player:Player;
	//public static var player:Player = new Player(0, 0, bullets);
	
	//public static var pHP:Int = 3;
	public static var pMaxHP:Int = 3;
	public static var pMaxJumps:Int = 2;
	public static var pDamage:Int = 1;
	public static var pLuck:Int = 5;	
	
	public static var weapon2:WeaponTemplate = new ArcWeapon("arc");
	public static var weapon1:WeaponTemplate = new WingsEquipment("wings");
	public static var weapon3:WeaponTemplate = new StompEquipment("stomp");
	
	public static var weaponArray:Array<WeaponTemplate> = [weapon1, weapon2, weapon3];

	
	
	public static var door1Color:Int;
	public static var door2Color:Int;
	public static var door3Color:Int;
	
	public static function shuffleColors()
	{
		var randoor:Int;
		randoor = FlxRandom.intRanged(1, 6);
		switch (randoor)
		{
			case (1):
			{
				door1Color = C;
				door2Color = M;
				door3Color = Y;
			}
			case (2):
			{
				door1Color = C;
				door2Color = Y;
				door3Color = M;
			}
			case (3):
			{
				door1Color = M;
				door2Color = C;
				door3Color = Y;
			}
			case (4):
			{
				door1Color = M;
				door2Color = Y;
				door3Color = C;
			}
			case (5):
			{
				door1Color = Y;
				door2Color = C;
				door3Color = M;
			}
			case (6):
			{
				door1Color = Y;
				door2Color = M;
				door3Color = C;
			}
		
		}
	}
	
	
}
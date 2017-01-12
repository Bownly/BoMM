package;

import flixel.FlxG;
import flixel.group.FlxGroup;
import flixel.util.FlxSave;
import weapons.ArcWeapon;
import weapons.BounceWeapon;
import weapons.Bullet;
import weapons.ClusterWeapon;
import weapons.EightWayWeapon;
import weapons.ExWeapon;
import weapons.MouseWeapon;
import weapons.PlusWeapon;
import weapons.SlashWeapon;
import weapons.SplodeWeapon;
import weapons.SpreadWeapon;
import weapons.StompEquipment;
import weapons.StringWeapon;
import weapons.WeaponTemplate;
import weapons.WingsEquipment;

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
	

	public static var TILESIZE = 16;
	
	// color constants
	public static inline var G:Int = 0x1000;
	public static inline var C:Int = 0x0100;
	public static inline var M:Int = 0x0010;
	public static inline var Y:Int = 0x0001;
	
	public static inline var CM:Int = 0x110;
	public static inline var CY:Int = 0x101;
	public static inline var MY:Int = 0x011;
	public static inline var CMY:Int = 0x111;


	public static var colorArray:Array<Int> = [G];
	//public static var colorArray:Array<Int> = [G, C, M, Y];

	public static var globalPalette:Int = G;
	
	
	public static var bullets:FlxTypedGroup<weapons.Bullet> = new FlxTypedGroup<weapons.Bullet>();
	
	public static var player:Player;
	
	public static var pMaxHP:Int = 3;
	public static var pMaxMaxHP:Int = 3;
	public static var pMaxJumps:Int = 2;
	public static var pDamage:Int = 0;
	public static var pLuck:Int = 1;	
	public static var pDosh:Int = 0;
	
	public static var weaponCount:Int = 16;
	public static var weapon1:WeaponTemplate = new WeaponTemplate("pea", Reg.G);
	public static var weapon2:WeaponTemplate = new WingsEquipment("wings", Reg.C);
	public static var weapon3:WeaponTemplate = new SplodeWeapon("splode", Reg.M);
	public static var weapon4:WeaponTemplate = new SpreadWeapon("stomp", Reg.Y);
	
	public static var weaponArray:Array<WeaponTemplate> = [weapon1, weapon2, weapon3, weapon4];

	
	public static var door1Color:Int = -1;
	public static var door2Color:Int;
	public static var door3Color:Int;
	
	// called when you start a new game
	public static function resetValues()
	{
		colorArray = [G];

		globalPalette= G;
		
		
		bullets= new FlxTypedGroup<weapons.Bullet>();
		
		pMaxHP = 3;
		pMaxMaxHP = 3;
		pMaxJumps = 2;
		pDamage = 0;
		pLuck = 1;	
		pDosh = 0;
		
		weapon1 = new WeaponTemplate("pea", Reg.G);
		weapon2 = new WingsEquipment("wings", Reg.C);
		weapon3 = new SplodeWeapon("splode", Reg.M);
		weapon4 = new SpreadWeapon("stomp", Reg.Y);
		
		weaponArray = [weapon1, weapon2, weapon3, weapon4];

		
		door1Color;
		door2Color;
		door3Color;

	}
	
	public static function shuffleColors()
	{
		var randoor:Int;
		randoor = FlxG.random.int(1, 6);

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
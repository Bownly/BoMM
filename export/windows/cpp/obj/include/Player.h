#ifndef INCLUDED_Player
#define INCLUDED_Player

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxSprite.h>
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS1(weapons,WeaponTemplate)


class HXCPP_CLASS_ATTRIBUTES  Player_obj : public ::flixel::FlxSprite_obj{
	public:
		typedef ::flixel::FlxSprite_obj super;
		typedef Player_obj OBJ_;
		Player_obj();
		Void __construct(hx::Null< int >  __o_inX,hx::Null< int >  __o_inY,::flixel::group::FlxTypedGroup Bullets);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Player_obj > __new(hx::Null< int >  __o_inX,hx::Null< int >  __o_inY,::flixel::group::FlxTypedGroup Bullets);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Player_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Player"); }

		int jumpPower;
		int GRAVITY;
		int xSpeed;
		int remainingJumps;
		int hp;
		int maxHP;
		int maxJumps;
		int shotRange;
		int damage;
		int luck;
		::flixel::group::FlxTypedGroup bulletArray;
		int maxBullets;
		int bulletCount;
		int curWeaponLoc;
		::weapons::WeaponTemplate curWeapon;
		::weapons::WeaponTemplate weapon1;
		::weapons::WeaponTemplate weapon2;
		::weapons::WeaponTemplate weapon3;
		::weapons::WeaponTemplate weapon4;
		Array< ::Dynamic > weaponArray;
		::String shootingString;
		Float postShotTimer;
		Float cooldown;
		bool touchingLadder;
		bool climbing;
		Float hurtTimer;
		virtual Void update( );

		virtual Void playerInputs( );
		Dynamic playerInputs_dyn();

		virtual Void resolveAnimations( );
		Dynamic resolveAnimations_dyn();

		virtual Void setTouchingLadder( bool _bool);
		Dynamic setTouchingLadder_dyn();

		virtual Void shoot( );
		Dynamic shoot_dyn();

		virtual Void switchWeapon( );
		Dynamic switchWeapon_dyn();

		virtual Void takeDamage( int dmg);
		Dynamic takeDamage_dyn();

};


#endif /* INCLUDED_Player */ 

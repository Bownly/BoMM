#ifndef INCLUDED_Testboss
#define INCLUDED_Testboss

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <enemies/EnemyTemplate.h>
HX_DECLARE_CLASS0(PlayState)
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS0(Testboss)
HX_DECLARE_CLASS1(enemies,EnemyTemplate)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,tweens,FlxTween)


class HXCPP_CLASS_ATTRIBUTES  Testboss_obj : public ::enemies::EnemyTemplate_obj{
	public:
		typedef ::enemies::EnemyTemplate_obj super;
		typedef Testboss_obj OBJ_;
		Testboss_obj();
		Void __construct(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup Bullets,::PlayState Playstate);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Testboss_obj > __new(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup Bullets,::PlayState Playstate);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Testboss_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Testboss"); }

		int XSPEED;
		int GRAVITY;
		Float GUN_DELAY;
		int BULLET_SPEED;
		int _HP;
		::flixel::group::FlxGroup _bullets;
		Float _cooldown;
		::PlayState playstate;
		virtual Void finishKill( ::flixel::tweens::FlxTween _);

};


#endif /* INCLUDED_Testboss */ 

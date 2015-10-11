#ifndef INCLUDED_enemies_Mush
#define INCLUDED_enemies_Mush

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <enemies/EnemyTemplate.h>
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS1(enemies,EnemyTemplate)
HX_DECLARE_CLASS1(enemies,Mush)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
namespace enemies{


class HXCPP_CLASS_ATTRIBUTES  Mush_obj : public ::enemies::EnemyTemplate_obj{
	public:
		typedef ::enemies::EnemyTemplate_obj super;
		typedef Mush_obj OBJ_;
		Mush_obj();
		Void __construct(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup Bullets,int Palette);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Mush_obj > __new(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup Bullets,int Palette);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Mush_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Mush"); }

		int XSPEED;
		int GRAVITY;
		Float GUN_DELAY;
		int BULLET_SPEED;
		int _HP;
		::flixel::group::FlxGroup _bullets;
		Float _cooldown;
		int rangeX;
		Float ogX;
		Float postShotTimer;
		int palette;
		int sporeSpeed;
		virtual Void update( );

		virtual Void changeColor( );
		Dynamic changeColor_dyn();

		virtual Void shoot( );
		Dynamic shoot_dyn();

		virtual Void turnAround( );
		Dynamic turnAround_dyn();

};

} // end namespace enemies

#endif /* INCLUDED_enemies_Mush */ 

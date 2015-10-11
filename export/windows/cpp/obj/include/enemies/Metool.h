#ifndef INCLUDED_enemies_Metool
#define INCLUDED_enemies_Metool

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <enemies/EnemyTemplate.h>
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS1(enemies,EnemyTemplate)
HX_DECLARE_CLASS1(enemies,Metool)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
namespace enemies{


class HXCPP_CLASS_ATTRIBUTES  Metool_obj : public ::enemies::EnemyTemplate_obj{
	public:
		typedef ::enemies::EnemyTemplate_obj super;
		typedef Metool_obj OBJ_;
		Metool_obj();
		Void __construct(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup Bullets);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Metool_obj > __new(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup Bullets);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Metool_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Metool"); }

		int XSPEED;
		int GRAVITY;
		Float GUN_DELAY;
		int BULLET_SPEED;
		int _HP;
		::flixel::group::FlxGroup _bullets;
		Float _cooldown;
		virtual Void update( );

		virtual Void shoot( ::Player P);
		Dynamic shoot_dyn();

		virtual Void takeDamage( int damage);

};

} // end namespace enemies

#endif /* INCLUDED_enemies_Metool */ 

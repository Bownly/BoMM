#ifndef INCLUDED_enemies_Balun
#define INCLUDED_enemies_Balun

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <enemies/EnemyTemplate.h>
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS1(enemies,Balun)
HX_DECLARE_CLASS1(enemies,BalunString)
HX_DECLARE_CLASS1(enemies,EnemyTemplate)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
namespace enemies{


class HXCPP_CLASS_ATTRIBUTES  Balun_obj : public ::enemies::EnemyTemplate_obj{
	public:
		typedef ::enemies::EnemyTemplate_obj super;
		typedef Balun_obj OBJ_;
		Balun_obj();
		Void __construct(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup Enemies,::flixel::group::FlxGroup Bullets,int Color);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Balun_obj > __new(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup Enemies,::flixel::group::FlxGroup Bullets,int Color);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Balun_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Balun"); }

		int palette;
		::String colorString;
		Float idealY;
		int XSPEED;
		int GRAVITY;
		int _HP;
		Float GUN_DELAY;
		int BULLET_SPEED;
		::flixel::group::FlxGroup _bullets;
		Float _cooldown;
		::enemies::BalunString tail;
		virtual Void update( );

		virtual Void shoot( ::Player P);
		Dynamic shoot_dyn();

		virtual Void resolveAnims( );
		Dynamic resolveAnims_dyn();

		virtual Void kill( );

};

} // end namespace enemies

#endif /* INCLUDED_enemies_Balun */ 

#ifndef INCLUDED_enemies_Egg
#define INCLUDED_enemies_Egg

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <enemies/EnemyTemplate.h>
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS1(enemies,BabyBurd)
HX_DECLARE_CLASS1(enemies,Egg)
HX_DECLARE_CLASS1(enemies,EnemyTemplate)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
namespace enemies{


class HXCPP_CLASS_ATTRIBUTES  Egg_obj : public ::enemies::EnemyTemplate_obj{
	public:
		typedef ::enemies::EnemyTemplate_obj super;
		typedef Egg_obj OBJ_;
		Egg_obj();
		Void __construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,int XVel,::flixel::group::FlxGroup Enemies);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Egg_obj > __new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,int XVel,::flixel::group::FlxGroup Enemies);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Egg_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Egg"); }

		int XSPEED;
		int GRAVITY;
		int _HP;
		bool _cracked;
		::enemies::BabyBurd babby;
		::enemies::BabyBurd babby2;
		::enemies::BabyBurd babby3;
		::enemies::BabyBurd babby4;
		::flixel::group::FlxTypedGroup burdArray;
		::flixel::group::FlxGroup enemArray;
		virtual Void update( );

		virtual Void dropped( );
		Dynamic dropped_dyn();

		virtual Void spawnBirds( );
		Dynamic spawnBirds_dyn();

};

} // end namespace enemies

#endif /* INCLUDED_enemies_Egg */ 

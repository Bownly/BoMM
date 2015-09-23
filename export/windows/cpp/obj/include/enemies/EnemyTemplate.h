#ifndef INCLUDED_enemies_EnemyTemplate
#define INCLUDED_enemies_EnemyTemplate

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxSprite.h>
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS1(enemies,EnemyTemplate)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,tweens,FlxTween)
namespace enemies{


class HXCPP_CLASS_ATTRIBUTES  EnemyTemplate_obj : public ::flixel::FlxSprite_obj{
	public:
		typedef ::flixel::FlxSprite_obj super;
		typedef EnemyTemplate_obj OBJ_;
		EnemyTemplate_obj();
		Void __construct(Float X,Float Y,::Player ThePlayer,int Health,::flixel::group::FlxTypedGroup DropsGrp);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< EnemyTemplate_obj > __new(Float X,Float Y,::Player ThePlayer,int Health,::flixel::group::FlxTypedGroup DropsGrp);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~EnemyTemplate_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EnemyTemplate"); }

		Float _startx;
		Float _starty;
		::Player _player;
		int _health;
		::flixel::group::FlxTypedGroup _drops;
		virtual Void takeDamage( int damage);
		Dynamic takeDamage_dyn();

		virtual Void kill( );

		virtual Void finishKill( ::flixel::tweens::FlxTween _);
		Dynamic finishKill_dyn();

};

} // end namespace enemies

#endif /* INCLUDED_enemies_EnemyTemplate */ 

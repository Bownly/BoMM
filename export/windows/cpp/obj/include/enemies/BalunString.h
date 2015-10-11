#ifndef INCLUDED_enemies_BalunString
#define INCLUDED_enemies_BalunString

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <enemies/EnemyTemplate.h>
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS1(enemies,BalunString)
HX_DECLARE_CLASS1(enemies,EnemyTemplate)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
namespace enemies{


class HXCPP_CLASS_ATTRIBUTES  BalunString_obj : public ::enemies::EnemyTemplate_obj{
	public:
		typedef ::enemies::EnemyTemplate_obj super;
		typedef BalunString_obj OBJ_;
		BalunString_obj();
		Void __construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BalunString_obj > __new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BalunString_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("BalunString"); }

		int _moving;
		int _HP;
		virtual Void update( );

};

} // end namespace enemies

#endif /* INCLUDED_enemies_BalunString */ 

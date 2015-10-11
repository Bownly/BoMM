#ifndef INCLUDED_HUD
#define INCLUDED_HUD

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/group/FlxTypedGroup.h>
HX_DECLARE_CLASS0(HUD)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,text,FlxText)


class HXCPP_CLASS_ATTRIBUTES  HUD_obj : public ::flixel::group::FlxTypedGroup_obj{
	public:
		typedef ::flixel::group::FlxTypedGroup_obj super;
		typedef HUD_obj OBJ_;
		HUD_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< HUD_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~HUD_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HUD"); }

		::flixel::FlxSprite _sprBack;
		::flixel::text::FlxText _txtHealth;
		::flixel::text::FlxText _txtJuice;
		::flixel::text::FlxText _txtWeapon;
		::flixel::text::FlxText _txtMoney;
		::flixel::FlxSprite _sprHealth;
		::flixel::FlxSprite _sprJuice;
		::flixel::FlxSprite _sprWeapon;
		::flixel::FlxSprite _sprMoney;
		virtual Void updateHUD( hx::Null< int >  Health,hx::Null< int >  Juice,hx::Null< int >  Money,::String Weapon);
		Dynamic updateHUD_dyn();

};


#endif /* INCLUDED_HUD */ 

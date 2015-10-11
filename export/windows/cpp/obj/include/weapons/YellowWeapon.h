#ifndef INCLUDED_weapons_YellowWeapon
#define INCLUDED_weapons_YellowWeapon

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <weapons/WeaponTemplate.h>
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS1(weapons,WeaponTemplate)
HX_DECLARE_CLASS1(weapons,YellowWeapon)
namespace weapons{


class HXCPP_CLASS_ATTRIBUTES  YellowWeapon_obj : public ::weapons::WeaponTemplate_obj{
	public:
		typedef ::weapons::WeaponTemplate_obj super;
		typedef YellowWeapon_obj OBJ_;
		YellowWeapon_obj();
		Void __construct(::String Name,::flixel::group::FlxTypedGroup Bullets);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< YellowWeapon_obj > __new(::String Name,::flixel::group::FlxTypedGroup Bullets);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~YellowWeapon_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("YellowWeapon"); }

		virtual Void shoot( ::Player _player);

};

} // end namespace weapons

#endif /* INCLUDED_weapons_YellowWeapon */ 

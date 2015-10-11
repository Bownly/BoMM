#ifndef INCLUDED_weapons_EightWayWeapon
#define INCLUDED_weapons_EightWayWeapon

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
HX_DECLARE_CLASS1(weapons,EightWayWeapon)
HX_DECLARE_CLASS1(weapons,WeaponTemplate)
namespace weapons{


class HXCPP_CLASS_ATTRIBUTES  EightWayWeapon_obj : public ::weapons::WeaponTemplate_obj{
	public:
		typedef ::weapons::WeaponTemplate_obj super;
		typedef EightWayWeapon_obj OBJ_;
		EightWayWeapon_obj();
		Void __construct(::String Name,::flixel::group::FlxTypedGroup Bullets);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< EightWayWeapon_obj > __new(::String Name,::flixel::group::FlxTypedGroup Bullets);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~EightWayWeapon_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("EightWayWeapon"); }

		virtual Void shoot( ::Player _player);

};

} // end namespace weapons

#endif /* INCLUDED_weapons_EightWayWeapon */ 

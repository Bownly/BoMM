#ifndef INCLUDED_weapons_WeaponTemplate
#define INCLUDED_weapons_WeaponTemplate

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS1(weapons,WeaponTemplate)
namespace weapons{


class HXCPP_CLASS_ATTRIBUTES  WeaponTemplate_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef WeaponTemplate_obj OBJ_;
		WeaponTemplate_obj();
		Void __construct(::String Name,::flixel::group::FlxTypedGroup Bullets);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< WeaponTemplate_obj > __new(::String Name,::flixel::group::FlxTypedGroup Bullets);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~WeaponTemplate_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("WeaponTemplate"); }

		::String name;
		::flixel::group::FlxTypedGroup bulletArray;
		int damage;
		int juice;
		int juiceMax;
		int juiceCost;
		bool unlocked;
		virtual Void shoot( ::Player _player);
		Dynamic shoot_dyn();

};

} // end namespace weapons

#endif /* INCLUDED_weapons_WeaponTemplate */ 

#ifndef INCLUDED_weapons_Spore
#define INCLUDED_weapons_Spore

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <weapons/Bullet.h>
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS1(weapons,Bullet)
HX_DECLARE_CLASS1(weapons,Spore)
namespace weapons{


class HXCPP_CLASS_ATTRIBUTES  Spore_obj : public ::weapons::Bullet_obj{
	public:
		typedef ::weapons::Bullet_obj super;
		typedef Spore_obj OBJ_;
		Spore_obj();
		Void __construct(Float X,Float Y,Float Speed,int Direction,int Damage,int Range,int Palette);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Spore_obj > __new(Float X,Float Y,Float Speed,int Direction,int Damage,int Range,int Palette);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Spore_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Spore"); }

		int gravity;
		virtual Void update( );

};

} // end namespace weapons

#endif /* INCLUDED_weapons_Spore */ 

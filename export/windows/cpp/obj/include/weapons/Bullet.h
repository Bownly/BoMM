#ifndef INCLUDED_weapons_Bullet
#define INCLUDED_weapons_Bullet

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxSprite.h>
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS1(weapons,Bullet)
namespace weapons{


class HXCPP_CLASS_ATTRIBUTES  Bullet_obj : public ::flixel::FlxSprite_obj{
	public:
		typedef ::flixel::FlxSprite_obj super;
		typedef Bullet_obj OBJ_;
		Bullet_obj();
		Void __construct(Float X,Float Y,Float Speed,int Direction,int Damage,int Range);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Bullet_obj > __new(Float X,Float Y,Float Speed,int Direction,int Damage,int Range);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Bullet_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Bullet"); }

		Float speed;
		int direction;
		int damage;
		Float ogX;
		Float ogY;
		int RANGE;
		virtual Void update( );

		virtual Void destroy( );

		virtual int getDamage( );
		Dynamic getDamage_dyn();

};

} // end namespace weapons

#endif /* INCLUDED_weapons_Bullet */ 

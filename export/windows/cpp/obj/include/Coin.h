#ifndef INCLUDED_Coin
#define INCLUDED_Coin

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxSprite.h>
HX_DECLARE_CLASS0(Coin)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,tweens,FlxTween)


class HXCPP_CLASS_ATTRIBUTES  Coin_obj : public ::flixel::FlxSprite_obj{
	public:
		typedef ::flixel::FlxSprite_obj super;
		typedef Coin_obj OBJ_;
		Coin_obj();
		Void __construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Coin_obj > __new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Coin_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Coin"); }

		virtual Void kill( );

		virtual Void finishKill( ::flixel::tweens::FlxTween _);
		Dynamic finishKill_dyn();

};


#endif /* INCLUDED_Coin */ 

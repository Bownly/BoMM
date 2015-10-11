#ifndef INCLUDED_Spike
#define INCLUDED_Spike

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxSprite.h>
HX_DECLARE_CLASS0(Spike)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)


class HXCPP_CLASS_ATTRIBUTES  Spike_obj : public ::flixel::FlxSprite_obj{
	public:
		typedef ::flixel::FlxSprite_obj super;
		typedef Spike_obj OBJ_;
		Spike_obj();
		Void __construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,int Damage);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Spike_obj > __new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,int Damage);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Spike_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Spike"); }

		int dmg;
};


#endif /* INCLUDED_Spike */ 

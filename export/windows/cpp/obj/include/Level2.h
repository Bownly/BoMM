#ifndef INCLUDED_Level2
#define INCLUDED_Level2

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <PlayState.h>
HX_DECLARE_CLASS0(Level2)
HX_DECLARE_CLASS0(PlayState)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)


class HXCPP_CLASS_ATTRIBUTES  Level2_obj : public ::PlayState_obj{
	public:
		typedef ::PlayState_obj super;
		typedef Level2_obj OBJ_;
		Level2_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Level2_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Level2_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Level2"); }

};


#endif /* INCLUDED_Level2 */ 

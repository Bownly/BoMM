#ifndef INCLUDED_Level1
#define INCLUDED_Level1

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <PlayState.h>
HX_DECLARE_CLASS0(Level1)
HX_DECLARE_CLASS0(PlayState)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)


class HXCPP_CLASS_ATTRIBUTES  Level1_obj : public ::PlayState_obj{
	public:
		typedef ::PlayState_obj super;
		typedef Level1_obj OBJ_;
		Level1_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Level1_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Level1_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Level1"); }

};


#endif /* INCLUDED_Level1 */ 

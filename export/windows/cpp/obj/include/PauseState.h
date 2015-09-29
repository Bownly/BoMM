#ifndef INCLUDED_PauseState
#define INCLUDED_PauseState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxSubState.h>
HX_DECLARE_CLASS0(PauseState)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS1(flixel,FlxSubState)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)


class HXCPP_CLASS_ATTRIBUTES  PauseState_obj : public ::flixel::FlxSubState_obj{
	public:
		typedef ::flixel::FlxSubState_obj super;
		typedef PauseState_obj OBJ_;
		PauseState_obj();
		Void __construct(hx::Null< int >  __o_BGColor);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< PauseState_obj > __new(hx::Null< int >  __o_BGColor);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PauseState_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("PauseState"); }

		virtual Void update( );

};


#endif /* INCLUDED_PauseState */ 

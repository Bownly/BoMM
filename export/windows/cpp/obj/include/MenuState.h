#ifndef INCLUDED_MenuState
#define INCLUDED_MenuState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxState.h>
HX_DECLARE_CLASS0(MenuState)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,text,FlxText)


class HXCPP_CLASS_ATTRIBUTES  MenuState_obj : public ::flixel::FlxState_obj{
	public:
		typedef ::flixel::FlxState_obj super;
		typedef MenuState_obj OBJ_;
		MenuState_obj();
		Void __construct(Dynamic MaxSize);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MenuState_obj > __new(Dynamic MaxSize);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MenuState_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MenuState"); }

		int colorDefault;
		int colorSelected;
		int selectedLevel;
		::flixel::text::FlxText txtLevel1;
		::flixel::text::FlxText txtLevel2;
		::flixel::text::FlxText txtLevel3;
		::flixel::group::FlxTypedGroup grpLevel;
		virtual Void create( );

		virtual Void update( );

		virtual Void colorize( );
		Dynamic colorize_dyn();

		virtual Void gotoLevel1( );
		Dynamic gotoLevel1_dyn();

		virtual Void gotoLevel2( );
		Dynamic gotoLevel2_dyn();

		virtual Void gotoLevel3( );
		Dynamic gotoLevel3_dyn();

		virtual Void gotoNextState( );
		Dynamic gotoNextState_dyn();

		virtual Void destroy( );

};


#endif /* INCLUDED_MenuState */ 

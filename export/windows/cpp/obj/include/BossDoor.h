#ifndef INCLUDED_BossDoor
#define INCLUDED_BossDoor

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxSprite.h>
HX_DECLARE_CLASS0(BossDoor)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)


class HXCPP_CLASS_ATTRIBUTES  BossDoor_obj : public ::flixel::FlxSprite_obj{
	public:
		typedef ::flixel::FlxSprite_obj super;
		typedef BossDoor_obj OBJ_;
		BossDoor_obj();
		Void __construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BossDoor_obj > __new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BossDoor_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("BossDoor"); }

		int status;
		virtual Void update( );

		virtual Void open( );
		Dynamic open_dyn();

		virtual Void shut( );
		Dynamic shut_dyn();

};


#endif /* INCLUDED_BossDoor */ 

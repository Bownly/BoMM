#ifndef INCLUDED_flixel_addons_effects_FlxGlitchSprite
#define INCLUDED_flixel_addons_effects_FlxGlitchSprite

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxSprite.h>
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS3(flixel,addons,effects,FlxGlitchSprite)
HX_DECLARE_CLASS3(flixel,addons,effects,GlitchDirection)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
namespace flixel{
namespace addons{
namespace effects{


class HXCPP_CLASS_ATTRIBUTES  FlxGlitchSprite_obj : public ::flixel::FlxSprite_obj{
	public:
		typedef ::flixel::FlxSprite_obj super;
		typedef FlxGlitchSprite_obj OBJ_;
		FlxGlitchSprite_obj();
		Void __construct(::flixel::FlxSprite Target,hx::Null< int >  __o_Strength,hx::Null< int >  __o_Size,hx::Null< Float >  __o_Delay,::flixel::addons::effects::GlitchDirection Direction);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FlxGlitchSprite_obj > __new(::flixel::FlxSprite Target,hx::Null< int >  __o_Strength,hx::Null< int >  __o_Size,hx::Null< Float >  __o_Delay,::flixel::addons::effects::GlitchDirection Direction);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FlxGlitchSprite_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FlxGlitchSprite"); }

		int size;
		Float delay;
		::flixel::FlxSprite target;
		::flixel::addons::effects::GlitchDirection direction;
		int strength;
		Float _time;
		virtual Void draw( );

		virtual Void initPixels( );
		Dynamic initPixels_dyn();

		virtual ::flixel::addons::effects::GlitchDirection set_direction( ::flixel::addons::effects::GlitchDirection Value);
		Dynamic set_direction_dyn();

		virtual int set_strength( int Value);
		Dynamic set_strength_dyn();

};

} // end namespace flixel
} // end namespace addons
} // end namespace effects

#endif /* INCLUDED_flixel_addons_effects_FlxGlitchSprite */ 

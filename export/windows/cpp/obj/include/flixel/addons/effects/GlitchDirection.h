#ifndef INCLUDED_flixel_addons_effects_GlitchDirection
#define INCLUDED_flixel_addons_effects_GlitchDirection

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(flixel,addons,effects,GlitchDirection)
namespace flixel{
namespace addons{
namespace effects{


class GlitchDirection_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef GlitchDirection_obj OBJ_;

	public:
		GlitchDirection_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("flixel.addons.effects.GlitchDirection"); }
		::String __ToString() const { return HX_CSTRING("GlitchDirection.") + tag; }

		static ::flixel::addons::effects::GlitchDirection HORIZONTAL;
		static inline ::flixel::addons::effects::GlitchDirection HORIZONTAL_dyn() { return HORIZONTAL; }
		static ::flixel::addons::effects::GlitchDirection VERTICAL;
		static inline ::flixel::addons::effects::GlitchDirection VERTICAL_dyn() { return VERTICAL; }
};

} // end namespace flixel
} // end namespace addons
} // end namespace effects

#endif /* INCLUDED_flixel_addons_effects_GlitchDirection */ 

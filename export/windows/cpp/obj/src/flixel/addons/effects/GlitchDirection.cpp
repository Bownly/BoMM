#include <hxcpp.h>

#ifndef INCLUDED_flixel_addons_effects_GlitchDirection
#include <flixel/addons/effects/GlitchDirection.h>
#endif
namespace flixel{
namespace addons{
namespace effects{

::flixel::addons::effects::GlitchDirection GlitchDirection_obj::HORIZONTAL;

::flixel::addons::effects::GlitchDirection GlitchDirection_obj::VERTICAL;

HX_DEFINE_CREATE_ENUM(GlitchDirection_obj)

int GlitchDirection_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("HORIZONTAL")) return 0;
	if (inName==HX_CSTRING("VERTICAL")) return 1;
	return super::__FindIndex(inName);
}

int GlitchDirection_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("HORIZONTAL")) return 0;
	if (inName==HX_CSTRING("VERTICAL")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic GlitchDirection_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("HORIZONTAL")) return HORIZONTAL;
	if (inName==HX_CSTRING("VERTICAL")) return VERTICAL;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("HORIZONTAL"),
	HX_CSTRING("VERTICAL"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GlitchDirection_obj::HORIZONTAL,"HORIZONTAL");
	HX_MARK_MEMBER_NAME(GlitchDirection_obj::VERTICAL,"VERTICAL");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GlitchDirection_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(GlitchDirection_obj::HORIZONTAL,"HORIZONTAL");
	HX_VISIT_MEMBER_NAME(GlitchDirection_obj::VERTICAL,"VERTICAL");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class GlitchDirection_obj::__mClass;

Dynamic __Create_GlitchDirection_obj() { return new GlitchDirection_obj; }

void GlitchDirection_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.addons.effects.GlitchDirection"), hx::TCanCast< GlitchDirection_obj >,sStaticFields,sMemberFields,
	&__Create_GlitchDirection_obj, &__Create,
	&super::__SGetClass(), &CreateGlitchDirection_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void GlitchDirection_obj::__boot()
{
hx::Static(HORIZONTAL) = hx::CreateEnum< GlitchDirection_obj >(HX_CSTRING("HORIZONTAL"),0);
hx::Static(VERTICAL) = hx::CreateEnum< GlitchDirection_obj >(HX_CSTRING("VERTICAL"),1);
}


} // end namespace flixel
} // end namespace addons
} // end namespace effects

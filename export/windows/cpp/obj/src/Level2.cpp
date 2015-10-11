#include <hxcpp.h>

#ifndef INCLUDED_Level2
#include <Level2.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif

Void Level2_obj::__construct()
{
HX_STACK_FRAME("Level2","new",0x2be21240,"Level2.new","Level2.hx",11,0x0df8f530)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(12)
	super::__construct(null());
	HX_STACK_LINE(14)
	this->levelId = HX_CSTRING("1");
	HX_STACK_LINE(15)
	this->tileName = HX_CSTRING("assets/images/wood_tiles3.png");
}
;
	return null();
}

//Level2_obj::~Level2_obj() { }

Dynamic Level2_obj::__CreateEmpty() { return  new Level2_obj; }
hx::ObjectPtr< Level2_obj > Level2_obj::__new()
{  hx::ObjectPtr< Level2_obj > result = new Level2_obj();
	result->__construct();
	return result;}

Dynamic Level2_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Level2_obj > result = new Level2_obj();
	result->__construct();
	return result;}


Level2_obj::Level2_obj()
{
}

Dynamic Level2_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic Level2_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Level2_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Level2_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Level2_obj::__mClass,"__mClass");
};

#endif

Class Level2_obj::__mClass;

void Level2_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Level2"), hx::TCanCast< Level2_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void Level2_obj::__boot()
{
}


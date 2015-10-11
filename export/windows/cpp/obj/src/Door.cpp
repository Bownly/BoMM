#include <hxcpp.h>

#ifndef INCLUDED_Door
#include <Door.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif

Void Door_obj::__construct(hx::Null< int >  __o_inX,hx::Null< int >  __o_inY)
{
HX_STACK_FRAME("Door","new",0x5d3b9d80,"Door.new","Door.hx",12,0xa24891f0)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_inX,"inX")
HX_STACK_ARG(__o_inY,"inY")
int inX = __o_inX.Default(0);
int inY = __o_inY.Default(0);
{
	HX_STACK_LINE(13)
	super::__construct(inX,inY,null());
	HX_STACK_LINE(14)
	this->loadGraphic(HX_CSTRING("assets/images/burdsmall.png"),true,(int)8,(int)8,null(),null());
}
;
	return null();
}

//Door_obj::~Door_obj() { }

Dynamic Door_obj::__CreateEmpty() { return  new Door_obj; }
hx::ObjectPtr< Door_obj > Door_obj::__new(hx::Null< int >  __o_inX,hx::Null< int >  __o_inY)
{  hx::ObjectPtr< Door_obj > result = new Door_obj();
	result->__construct(__o_inX,__o_inY);
	return result;}

Dynamic Door_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Door_obj > result = new Door_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


Door_obj::Door_obj()
{
}

Dynamic Door_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic Door_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Door_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(Door_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Door_obj::__mClass,"__mClass");
};

#endif

Class Door_obj::__mClass;

void Door_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Door"), hx::TCanCast< Door_obj> ,sStaticFields,sMemberFields,
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

void Door_obj::__boot()
{
}


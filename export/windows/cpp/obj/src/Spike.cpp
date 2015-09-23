#include <hxcpp.h>

#ifndef INCLUDED_Spike
#include <Spike.h>
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
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif

Void Spike_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,int Damage)
{
HX_STACK_FRAME("Spike","new",0x87088198,"Spike.new","Spike.hx",10,0x96fdb8d8)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_X,"X")
HX_STACK_ARG(__o_Y,"Y")
HX_STACK_ARG(Damage,"Damage")
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
{
	HX_STACK_LINE(13)
	this->dmg = (int)1;
	HX_STACK_LINE(17)
	super::__construct(X,Y,null());
	HX_STACK_LINE(19)
	this->loadGraphic(HX_CSTRING("assets/images/spike.png"),false,(int)16,(int)16,null(),null());
	HX_STACK_LINE(20)
	this->set_width((int)16);
	HX_STACK_LINE(21)
	this->set_height((int)15);
	HX_STACK_LINE(22)
	::flixel::util::FlxPoint _g = ::flixel::util::FlxPoint_obj::__new((int)0,(int)1);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(22)
	this->offset = _g;
	HX_STACK_LINE(25)
	this->dmg = Damage;
}
;
	return null();
}

//Spike_obj::~Spike_obj() { }

Dynamic Spike_obj::__CreateEmpty() { return  new Spike_obj; }
hx::ObjectPtr< Spike_obj > Spike_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,int Damage)
{  hx::ObjectPtr< Spike_obj > result = new Spike_obj();
	result->__construct(__o_X,__o_Y,Damage);
	return result;}

Dynamic Spike_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Spike_obj > result = new Spike_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}


Spike_obj::Spike_obj()
{
}

Dynamic Spike_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"dmg") ) { return dmg; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Spike_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"dmg") ) { dmg=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Spike_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("dmg"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Spike_obj,dmg),HX_CSTRING("dmg")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("dmg"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Spike_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Spike_obj::__mClass,"__mClass");
};

#endif

Class Spike_obj::__mClass;

void Spike_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Spike"), hx::TCanCast< Spike_obj> ,sStaticFields,sMemberFields,
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

void Spike_obj::__boot()
{
}


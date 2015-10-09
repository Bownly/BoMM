#include <hxcpp.h>

#ifndef INCLUDED_BossDoor
#include <BossDoor.h>
#endif
#ifndef INCLUDED_IMap
#include <IMap.h>
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
#ifndef INCLUDED_flixel_animation_FlxAnimation
#include <flixel/animation/FlxAnimation.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxBaseAnimation
#include <flixel/animation/FlxBaseAnimation.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif

Void BossDoor_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y)
{
HX_STACK_FRAME("BossDoor","new",0x54ec664d,"BossDoor.new","BossDoor.hx",9,0xb005a1c3)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_X,"X")
HX_STACK_ARG(__o_Y,"Y")
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
{
	HX_STACK_LINE(11)
	this->status = (int)0;
	HX_STACK_LINE(15)
	super::__construct(X,Y,null());
	HX_STACK_LINE(16)
	this->loadGraphic(HX_CSTRING("assets/images/bossdoor.png"),false,(int)16,(int)32,null(),null());
	HX_STACK_LINE(18)
	this->animation->add(HX_CSTRING("open"),Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)3).Add((int)4).Add((int)3).Add((int)2).Add((int)1).Add((int)0),(int)15,false);
	HX_STACK_LINE(19)
	this->animation->add(HX_CSTRING("shut"),Array_obj< int >::__new().Add((int)4).Add((int)3).Add((int)2).Add((int)1).Add((int)0),(int)5,false);
}
;
	return null();
}

//BossDoor_obj::~BossDoor_obj() { }

Dynamic BossDoor_obj::__CreateEmpty() { return  new BossDoor_obj; }
hx::ObjectPtr< BossDoor_obj > BossDoor_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y)
{  hx::ObjectPtr< BossDoor_obj > result = new BossDoor_obj();
	result->__construct(__o_X,__o_Y);
	return result;}

Dynamic BossDoor_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BossDoor_obj > result = new BossDoor_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void BossDoor_obj::update( ){
{
		HX_STACK_FRAME("BossDoor","update",0x3adfa23c,"BossDoor.update","BossDoor.hx",24,0xb005a1c3)
		HX_STACK_THIS(this)
		HX_STACK_LINE(25)
		if (((this->status == (int)1))){
			HX_STACK_LINE(27)
			this->animation->play(HX_CSTRING("open"),null(),null());
			HX_STACK_LINE(28)
			this->status = (int)2;
		}
		HX_STACK_LINE(31)
		if ((this->animation->_animations->get(HX_CSTRING("open"))->__Field(HX_CSTRING("finished"),true))){
			HX_STACK_LINE(32)
			this->status = (int)0;
		}
		HX_STACK_LINE(33)
		this->super::update();
	}
return null();
}


Void BossDoor_obj::open( ){
{
		HX_STACK_FRAME("BossDoor","open",0xfa9e9d3d,"BossDoor.open","BossDoor.hx",38,0xb005a1c3)
		HX_STACK_THIS(this)
		HX_STACK_LINE(38)
		this->status = (int)1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BossDoor_obj,open,(void))

Void BossDoor_obj::shut( ){
{
		HX_STACK_FRAME("BossDoor","shut",0xfd3d73a7,"BossDoor.shut","BossDoor.hx",42,0xb005a1c3)
		HX_STACK_THIS(this)
		HX_STACK_LINE(42)
		this->status = (int)2;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BossDoor_obj,shut,(void))


BossDoor_obj::BossDoor_obj()
{
}

Dynamic BossDoor_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"open") ) { return open_dyn(); }
		if (HX_FIELD_EQ(inName,"shut") ) { return shut_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { return status; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BossDoor_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { status=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BossDoor_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("status"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(BossDoor_obj,status),HX_CSTRING("status")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("status"),
	HX_CSTRING("update"),
	HX_CSTRING("open"),
	HX_CSTRING("shut"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BossDoor_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BossDoor_obj::__mClass,"__mClass");
};

#endif

Class BossDoor_obj::__mClass;

void BossDoor_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("BossDoor"), hx::TCanCast< BossDoor_obj> ,sStaticFields,sMemberFields,
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

void BossDoor_obj::__boot()
{
}


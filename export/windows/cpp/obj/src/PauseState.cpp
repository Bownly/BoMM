#include <hxcpp.h>

#ifndef INCLUDED_PauseState
#include <PauseState.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_FlxSubState
#include <flixel/FlxSubState.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyboard
#include <flixel/input/keyboard/FlxKeyboard.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxInput
#include <flixel/interfaces/IFlxInput.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif

Void PauseState_obj::__construct(hx::Null< int >  __o_BGColor)
{
HX_STACK_FRAME("PauseState","new",0xca3f01cd,"PauseState.new","PauseState.hx",16,0x6f1cf643)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_BGColor,"BGColor")
int BGColor = __o_BGColor.Default(0);
{
	HX_STACK_LINE(17)
	super::__construct(BGColor);
	HX_STACK_LINE(18)
	::flixel::text::FlxText text = ::flixel::text::FlxText_obj::__new((int)175,(int)120,(int)0,HX_CSTRING("PAUSED"),(int)16,null());		HX_STACK_VAR(text,"text");
	HX_STACK_LINE(20)
	text->scrollFactor->set((int)0,(int)0);
	HX_STACK_LINE(22)
	this->add(text);
}
;
	return null();
}

//PauseState_obj::~PauseState_obj() { }

Dynamic PauseState_obj::__CreateEmpty() { return  new PauseState_obj; }
hx::ObjectPtr< PauseState_obj > PauseState_obj::__new(hx::Null< int >  __o_BGColor)
{  hx::ObjectPtr< PauseState_obj > result = new PauseState_obj();
	result->__construct(__o_BGColor);
	return result;}

Dynamic PauseState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PauseState_obj > result = new PauseState_obj();
	result->__construct(inArgs[0]);
	return result;}

Void PauseState_obj::update( ){
{
		HX_STACK_FRAME("PauseState","update",0x2d7b36bc,"PauseState.update","PauseState.hx",26,0x6f1cf643)
		HX_STACK_THIS(this)
		HX_STACK_LINE(27)
		if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("P")),(int)-1))){
			HX_STACK_LINE(30)
			this->close();
		}
		HX_STACK_LINE(32)
		this->super::update();
	}
return null();
}



PauseState_obj::PauseState_obj()
{
}

Dynamic PauseState_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PauseState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void PauseState_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PauseState_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PauseState_obj::__mClass,"__mClass");
};

#endif

Class PauseState_obj::__mClass;

void PauseState_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("PauseState"), hx::TCanCast< PauseState_obj> ,sStaticFields,sMemberFields,
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

void PauseState_obj::__boot()
{
}


#include <hxcpp.h>

#ifndef INCLUDED_MenuState
#include <MenuState.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
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
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_ui_FlxButton
#include <flixel/ui/FlxButton.h>
#endif
#ifndef INCLUDED_flixel_ui_FlxTypedButton
#include <flixel/ui/FlxTypedButton.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_DisplayObject
#include <openfl/_legacy/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_DisplayObjectContainer
#include <openfl/_legacy/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_IBitmapDrawable
#include <openfl/_legacy/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_InteractiveObject
#include <openfl/_legacy/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_Sprite
#include <openfl/_legacy/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl__legacy_events_EventDispatcher
#include <openfl/_legacy/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__legacy_events_IEventDispatcher
#include <openfl/_legacy/events/IEventDispatcher.h>
#endif

Void MenuState_obj::__construct(Dynamic MaxSize)
{
HX_STACK_FRAME("MenuState","new",0xe563b1c4,"MenuState.new","MenuState.hx",13,0xdfbcb22c)
HX_STACK_THIS(this)
HX_STACK_ARG(MaxSize,"MaxSize")
{
	HX_STACK_LINE(13)
	super::__construct(MaxSize);
}
;
	return null();
}

//MenuState_obj::~MenuState_obj() { }

Dynamic MenuState_obj::__CreateEmpty() { return  new MenuState_obj; }
hx::ObjectPtr< MenuState_obj > MenuState_obj::__new(Dynamic MaxSize)
{  hx::ObjectPtr< MenuState_obj > result = new MenuState_obj();
	result->__construct(MaxSize);
	return result;}

Dynamic MenuState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MenuState_obj > result = new MenuState_obj();
	result->__construct(inArgs[0]);
	return result;}

Void MenuState_obj::create( ){
{
		HX_STACK_FRAME("MenuState","create",0xe57b7c18,"MenuState.create","MenuState.hx",19,0xdfbcb22c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(20)
		this->super::create();
		HX_STACK_LINE(21)
		::flixel::text::FlxText _g = ::flixel::text::FlxText_obj::__new((int)6,(int)9,(int)200,HX_CSTRING("Hello, HaxeFlixel!"),null(),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(21)
		this->add(_g);
		HX_STACK_LINE(22)
		::flixel::FlxG_obj::camera->bgColor = (int)-4531627;
		HX_STACK_LINE(24)
		::flixel::ui::FlxButton _g1 = ::flixel::ui::FlxButton_obj::__new((int)0,(int)25,HX_CSTRING("Start"),this->gotoNextStates_dyn());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(24)
		this->add(_g1);
	}
return null();
}


Void MenuState_obj::gotoNextStates( ){
{
		HX_STACK_FRAME("MenuState","gotoNextStates",0x84b04334,"MenuState.gotoNextStates","MenuState.hx",29,0xdfbcb22c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(29)
		::flixel::FlxState State = ::PlayState_obj::__new(null());		HX_STACK_VAR(State,"State");
		HX_STACK_LINE(29)
		::flixel::FlxG_obj::game->_requestedState = State;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MenuState_obj,gotoNextStates,(void))

Void MenuState_obj::destroy( ){
{
		HX_STACK_FRAME("MenuState","destroy",0xf9ac905e,"MenuState.destroy","MenuState.hx",38,0xdfbcb22c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(38)
		this->super::destroy();
	}
return null();
}


Void MenuState_obj::update( ){
{
		HX_STACK_FRAME("MenuState","update",0xf0719b25,"MenuState.update","MenuState.hx",46,0xdfbcb22c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(46)
		this->super::update();
	}
return null();
}



MenuState_obj::MenuState_obj()
{
}

Dynamic MenuState_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"gotoNextStates") ) { return gotoNextStates_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MenuState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void MenuState_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("create"),
	HX_CSTRING("gotoNextStates"),
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MenuState_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MenuState_obj::__mClass,"__mClass");
};

#endif

Class MenuState_obj::__mClass;

void MenuState_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("MenuState"), hx::TCanCast< MenuState_obj> ,sStaticFields,sMemberFields,
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

void MenuState_obj::__boot()
{
}


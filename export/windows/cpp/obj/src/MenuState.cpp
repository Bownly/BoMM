#include <hxcpp.h>

#ifndef INCLUDED_Level1
#include <Level1.h>
#endif
#ifndef INCLUDED_Level2
#include <Level2.h>
#endif
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
#ifndef INCLUDED_flixel_group_FlxTypedGroupIterator
#include <flixel/group/FlxTypedGroupIterator.h>
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
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
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
HX_STACK_FRAME("MenuState","new",0xe563b1c4,"MenuState.new","MenuState.hx",15,0xdfbcb22c)
HX_STACK_THIS(this)
HX_STACK_ARG(MaxSize,"MaxSize")
{
	HX_STACK_LINE(20)
	this->selectedLevel = (int)1;
	HX_STACK_LINE(19)
	this->colorSelected = (int)10156463;
	HX_STACK_LINE(18)
	this->colorDefault = (int)16424873;
	HX_STACK_LINE(15)
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
		HX_STACK_FRAME("MenuState","create",0xe57b7c18,"MenuState.create","MenuState.hx",31,0xdfbcb22c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(32)
		this->super::create();
		HX_STACK_LINE(33)
		::flixel::text::FlxText _g = ::flixel::text::FlxText_obj::__new((int)6,(int)9,(int)200,HX_CSTRING("Level Select (lol)"),null(),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(33)
		this->add(_g);
		HX_STACK_LINE(35)
		::flixel::FlxG_obj::camera->bgColor = (int)16424873;
		HX_STACK_LINE(41)
		::flixel::group::FlxTypedGroup _g1 = ::flixel::group::FlxTypedGroup_obj::__new(null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(41)
		this->grpLevel = _g1;
		HX_STACK_LINE(42)
		::flixel::text::FlxText _g2 = ::flixel::text::FlxText_obj::__new((int)100,(int)50,(int)0,HX_CSTRING("Level1"),(int)8,null());		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(42)
		this->txtLevel1 = _g2;
		HX_STACK_LINE(43)
		::flixel::text::FlxText _g3 = ::flixel::text::FlxText_obj::__new((int)100,(int)75,(int)0,HX_CSTRING("Level2"),(int)8,null());		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(43)
		this->txtLevel2 = _g3;
		HX_STACK_LINE(44)
		::flixel::text::FlxText _g4 = ::flixel::text::FlxText_obj::__new((int)100,(int)100,(int)0,HX_CSTRING("Level3"),(int)8,null());		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(44)
		this->txtLevel3 = _g4;
		HX_STACK_LINE(48)
		this->add(this->grpLevel);
		HX_STACK_LINE(49)
		this->grpLevel->add(this->txtLevel1);
		HX_STACK_LINE(50)
		this->grpLevel->add(this->txtLevel2);
		HX_STACK_LINE(51)
		this->grpLevel->add(this->txtLevel3);
	}
return null();
}


Void MenuState_obj::update( ){
{
		HX_STACK_FRAME("MenuState","update",0xf0719b25,"MenuState.update","MenuState.hx",57,0xdfbcb22c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(58)
		this->colorize();
		HX_STACK_LINE(60)
		if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("DOWN")).Add(HX_CSTRING("S")),(int)2))){
			HX_STACK_LINE(62)
			(this->selectedLevel)++;
		}
		else{
			HX_STACK_LINE(64)
			if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("UP")).Add(HX_CSTRING("W")),(int)2))){
				HX_STACK_LINE(66)
				(this->selectedLevel)--;
			}
		}
		HX_STACK_LINE(68)
		if (((this->selectedLevel >= (int)4))){
			HX_STACK_LINE(69)
			this->selectedLevel = (int)1;
		}
		else{
			HX_STACK_LINE(70)
			if (((this->selectedLevel <= (int)0))){
				HX_STACK_LINE(71)
				this->selectedLevel = (int)3;
			}
		}
		HX_STACK_LINE(73)
		if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("ENTER")).Add(HX_CSTRING("J")),(int)2))){
			HX_STACK_LINE(75)
			int _g = this->selectedLevel;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(75)
			switch( (int)(_g)){
				case (int)1: {
					HX_STACK_LINE(78)
					this->gotoLevel1();
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(80)
					this->gotoLevel2();
				}
				;break;
				case (int)3: {
					HX_STACK_LINE(82)
					this->gotoLevel3();
				}
				;break;
			}
		}
		HX_STACK_LINE(87)
		if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("SPACE")),(int)1))){
			HX_STACK_LINE(89)
			this->gotoNextState();
		}
		HX_STACK_LINE(91)
		this->super::update();
	}
return null();
}


Void MenuState_obj::colorize( ){
{
		HX_STACK_FRAME("MenuState","colorize",0x3670f9ed,"MenuState.colorize","MenuState.hx",96,0xdfbcb22c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(97)
		for(::cpp::FastIterator_obj< ::flixel::text::FlxText > *__it = ::cpp::CreateFastIterator< ::flixel::text::FlxText >(::flixel::group::FlxTypedGroupIterator_obj::__new(this->grpLevel->members,null()));  __it->hasNext(); ){
			::flixel::text::FlxText level = __it->next();
			level->setFormat(null(),(int)8,(int)10156463,null(),null(),null(),null());
		}
		HX_STACK_LINE(99)
		{
			HX_STACK_LINE(99)
			int _g = this->selectedLevel;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(99)
			switch( (int)(_g)){
				case (int)1: {
					HX_STACK_LINE(102)
					this->txtLevel1->setFormat(null(),(int)8,(int)16424873,null(),null(),null(),null());
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(104)
					this->txtLevel2->setFormat(null(),(int)8,(int)16424873,null(),null(),null(),null());
				}
				;break;
				case (int)3: {
					HX_STACK_LINE(106)
					this->txtLevel3->setFormat(null(),(int)8,(int)16424873,null(),null(),null(),null());
				}
				;break;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MenuState_obj,colorize,(void))

Void MenuState_obj::gotoLevel1( ){
{
		HX_STACK_FRAME("MenuState","gotoLevel1",0xb903fb4c,"MenuState.gotoLevel1","MenuState.hx",112,0xdfbcb22c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(112)
		::flixel::FlxState State = ::Level1_obj::__new();		HX_STACK_VAR(State,"State");
		HX_STACK_LINE(112)
		::flixel::FlxG_obj::game->_requestedState = State;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MenuState_obj,gotoLevel1,(void))

Void MenuState_obj::gotoLevel2( ){
{
		HX_STACK_FRAME("MenuState","gotoLevel2",0xb903fb4d,"MenuState.gotoLevel2","MenuState.hx",116,0xdfbcb22c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(116)
		::flixel::FlxState State = ::Level2_obj::__new();		HX_STACK_VAR(State,"State");
		HX_STACK_LINE(116)
		::flixel::FlxG_obj::game->_requestedState = State;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MenuState_obj,gotoLevel2,(void))

Void MenuState_obj::gotoLevel3( ){
{
		HX_STACK_FRAME("MenuState","gotoLevel3",0xb903fb4e,"MenuState.gotoLevel3","MenuState.hx",120,0xdfbcb22c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(120)
		::flixel::FlxState State = ::PlayState_obj::__new(null());		HX_STACK_VAR(State,"State");
		HX_STACK_LINE(120)
		::flixel::FlxG_obj::game->_requestedState = State;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MenuState_obj,gotoLevel3,(void))

Void MenuState_obj::gotoNextState( ){
{
		HX_STACK_FRAME("MenuState","gotoNextState",0x659e105f,"MenuState.gotoNextState","MenuState.hx",127,0xdfbcb22c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(127)
		::flixel::FlxState State = ::PlayState_obj::__new(null());		HX_STACK_VAR(State,"State");
		HX_STACK_LINE(127)
		::flixel::FlxG_obj::game->_requestedState = State;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MenuState_obj,gotoNextState,(void))

Void MenuState_obj::destroy( ){
{
		HX_STACK_FRAME("MenuState","destroy",0xf9ac905e,"MenuState.destroy","MenuState.hx",137,0xdfbcb22c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(137)
		this->super::destroy();
	}
return null();
}



MenuState_obj::MenuState_obj()
{
}

void MenuState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MenuState);
	HX_MARK_MEMBER_NAME(colorDefault,"colorDefault");
	HX_MARK_MEMBER_NAME(colorSelected,"colorSelected");
	HX_MARK_MEMBER_NAME(selectedLevel,"selectedLevel");
	HX_MARK_MEMBER_NAME(txtLevel1,"txtLevel1");
	HX_MARK_MEMBER_NAME(txtLevel2,"txtLevel2");
	HX_MARK_MEMBER_NAME(txtLevel3,"txtLevel3");
	HX_MARK_MEMBER_NAME(grpLevel,"grpLevel");
	::flixel::FlxState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void MenuState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(colorDefault,"colorDefault");
	HX_VISIT_MEMBER_NAME(colorSelected,"colorSelected");
	HX_VISIT_MEMBER_NAME(selectedLevel,"selectedLevel");
	HX_VISIT_MEMBER_NAME(txtLevel1,"txtLevel1");
	HX_VISIT_MEMBER_NAME(txtLevel2,"txtLevel2");
	HX_VISIT_MEMBER_NAME(txtLevel3,"txtLevel3");
	HX_VISIT_MEMBER_NAME(grpLevel,"grpLevel");
	::flixel::FlxState_obj::__Visit(HX_VISIT_ARG);
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
	case 8:
		if (HX_FIELD_EQ(inName,"grpLevel") ) { return grpLevel; }
		if (HX_FIELD_EQ(inName,"colorize") ) { return colorize_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"txtLevel1") ) { return txtLevel1; }
		if (HX_FIELD_EQ(inName,"txtLevel2") ) { return txtLevel2; }
		if (HX_FIELD_EQ(inName,"txtLevel3") ) { return txtLevel3; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"gotoLevel1") ) { return gotoLevel1_dyn(); }
		if (HX_FIELD_EQ(inName,"gotoLevel2") ) { return gotoLevel2_dyn(); }
		if (HX_FIELD_EQ(inName,"gotoLevel3") ) { return gotoLevel3_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"colorDefault") ) { return colorDefault; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"colorSelected") ) { return colorSelected; }
		if (HX_FIELD_EQ(inName,"selectedLevel") ) { return selectedLevel; }
		if (HX_FIELD_EQ(inName,"gotoNextState") ) { return gotoNextState_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MenuState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"grpLevel") ) { grpLevel=inValue.Cast< ::flixel::group::FlxTypedGroup >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"txtLevel1") ) { txtLevel1=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"txtLevel2") ) { txtLevel2=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"txtLevel3") ) { txtLevel3=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"colorDefault") ) { colorDefault=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"colorSelected") ) { colorSelected=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"selectedLevel") ) { selectedLevel=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MenuState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("colorDefault"));
	outFields->push(HX_CSTRING("colorSelected"));
	outFields->push(HX_CSTRING("selectedLevel"));
	outFields->push(HX_CSTRING("txtLevel1"));
	outFields->push(HX_CSTRING("txtLevel2"));
	outFields->push(HX_CSTRING("txtLevel3"));
	outFields->push(HX_CSTRING("grpLevel"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(MenuState_obj,colorDefault),HX_CSTRING("colorDefault")},
	{hx::fsInt,(int)offsetof(MenuState_obj,colorSelected),HX_CSTRING("colorSelected")},
	{hx::fsInt,(int)offsetof(MenuState_obj,selectedLevel),HX_CSTRING("selectedLevel")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(MenuState_obj,txtLevel1),HX_CSTRING("txtLevel1")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(MenuState_obj,txtLevel2),HX_CSTRING("txtLevel2")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(MenuState_obj,txtLevel3),HX_CSTRING("txtLevel3")},
	{hx::fsObject /*::flixel::group::FlxTypedGroup*/ ,(int)offsetof(MenuState_obj,grpLevel),HX_CSTRING("grpLevel")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("colorDefault"),
	HX_CSTRING("colorSelected"),
	HX_CSTRING("selectedLevel"),
	HX_CSTRING("txtLevel1"),
	HX_CSTRING("txtLevel2"),
	HX_CSTRING("txtLevel3"),
	HX_CSTRING("grpLevel"),
	HX_CSTRING("create"),
	HX_CSTRING("update"),
	HX_CSTRING("colorize"),
	HX_CSTRING("gotoLevel1"),
	HX_CSTRING("gotoLevel2"),
	HX_CSTRING("gotoLevel3"),
	HX_CSTRING("gotoNextState"),
	HX_CSTRING("destroy"),
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


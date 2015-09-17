#include <hxcpp.h>

#ifndef INCLUDED_Player
#include <Player.h>
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
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
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
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif

Void Player_obj::__construct(hx::Null< int >  __o_inX,hx::Null< int >  __o_inY)
{
HX_STACK_FRAME("Player","new",0x8d5554f3,"Player.new","Player.hx",11,0xa27fc9dd)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_inX,"inX")
HX_STACK_ARG(__o_inY,"inY")
int inX = __o_inX.Default(0);
int inY = __o_inY.Default(0);
{
	HX_STACK_LINE(13)
	this->jumpPower = (int)200;
	HX_STACK_LINE(17)
	super::__construct(inX,inY,null());
	HX_STACK_LINE(19)
	this->loadGraphic(HX_CSTRING("assets/images/mc.png"),true,(int)16,(int)16,null(),null());
	HX_STACK_LINE(20)
	this->set_width((int)10);
	HX_STACK_LINE(21)
	this->set_height((int)14);
	HX_STACK_LINE(22)
	::flixel::util::FlxPoint _g = ::flixel::util::FlxPoint_obj::__new((int)4,(int)-1);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(22)
	this->offset = _g;
	HX_STACK_LINE(24)
	this->acceleration->set_y((int)420);
	HX_STACK_LINE(25)
	this->maxVelocity->set((int)200,(int)200);
	HX_STACK_LINE(26)
	this->drag->set((int)1600,(int)1600);
	HX_STACK_LINE(28)
	this->animation->add(HX_CSTRING("walk"),Array_obj< int >::__new().Add((int)29).Add((int)30).Add((int)31),(int)10,true);
	HX_STACK_LINE(29)
	this->animation->add(HX_CSTRING("idle"),Array_obj< int >::__new().Add((int)15).Add((int)16).Add((int)17),(int)3,true);
	HX_STACK_LINE(30)
	this->animation->add(HX_CSTRING("jump"),Array_obj< int >::__new().Add((int)32),(int)15,true);
	HX_STACK_LINE(31)
	this->animation->add(HX_CSTRING("fall"),Array_obj< int >::__new().Add((int)33),(int)15,true);
}
;
	return null();
}

//Player_obj::~Player_obj() { }

Dynamic Player_obj::__CreateEmpty() { return  new Player_obj; }
hx::ObjectPtr< Player_obj > Player_obj::__new(hx::Null< int >  __o_inX,hx::Null< int >  __o_inY)
{  hx::ObjectPtr< Player_obj > result = new Player_obj();
	result->__construct(__o_inX,__o_inY);
	return result;}

Dynamic Player_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Player_obj > result = new Player_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Player_obj::update( ){
{
		HX_STACK_FRAME("Player","update",0xf1f8df56,"Player.update","Player.hx",36,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(37)
		this->acceleration->set_x((int)0);
		HX_STACK_LINE(39)
		if (((this->velocity->x == (int)0))){
			HX_STACK_LINE(40)
			this->animation->play(HX_CSTRING("idle"),null(),null());
		}
		HX_STACK_LINE(43)
		if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("LEFT")).Add(HX_CSTRING("A")),(int)1))){
			HX_STACK_LINE(44)
			this->acceleration->set_x((int)-800);
			HX_STACK_LINE(45)
			this->animation->play(HX_CSTRING("walk"),null(),null());
			HX_STACK_LINE(46)
			this->set_flipX(true);
		}
		else{
			HX_STACK_LINE(47)
			if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("RIGHT")).Add(HX_CSTRING("D")),(int)1))){
				HX_STACK_LINE(48)
				this->acceleration->set_x((int)800);
				HX_STACK_LINE(49)
				this->animation->play(HX_CSTRING("walk"),null(),null());
				HX_STACK_LINE(50)
				this->set_flipX(false);
			}
		}
		HX_STACK_LINE(54)
		if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("UP")).Add(HX_CSTRING("W")),(int)2))){
			HX_STACK_LINE(56)
			this->velocity->set_y(-(this->jumpPower));
			HX_STACK_LINE(57)
			this->animation->play(HX_CSTRING("jump"),null(),null());
		}
		HX_STACK_LINE(60)
		if (((this->velocity->y < (int)0))){
			HX_STACK_LINE(61)
			this->animation->play(HX_CSTRING("jump"),null(),null());
		}
		else{
			HX_STACK_LINE(62)
			if (((this->velocity->y > (int)0))){
				HX_STACK_LINE(63)
				this->animation->play(HX_CSTRING("fall"),null(),null());
			}
		}
		HX_STACK_LINE(66)
		this->super::update();
	}
return null();
}



Player_obj::Player_obj()
{
}

Dynamic Player_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"jumpPower") ) { return jumpPower; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Player_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"jumpPower") ) { jumpPower=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Player_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("jumpPower"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Player_obj,jumpPower),HX_CSTRING("jumpPower")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("jumpPower"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Player_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Player_obj::__mClass,"__mClass");
};

#endif

Class Player_obj::__mClass;

void Player_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Player"), hx::TCanCast< Player_obj> ,sStaticFields,sMemberFields,
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

void Player_obj::__boot()
{
}


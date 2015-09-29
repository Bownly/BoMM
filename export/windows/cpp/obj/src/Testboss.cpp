#include <hxcpp.h>

#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_Testboss
#include <Testboss.h>
#endif
#ifndef INCLUDED_enemies_EnemyTemplate
#include <enemies/EnemyTemplate.h>
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
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif

Void Testboss_obj::__construct(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup Bullets,::PlayState Playstate)
{
HX_STACK_FRAME("Testboss","new",0x9f60b991,"Testboss.new","Testboss.hx",14,0xa3ba62ff)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
HX_STACK_ARG(ThePlayer,"ThePlayer")
HX_STACK_ARG(DropsGrp,"DropsGrp")
HX_STACK_ARG(Bullets,"Bullets")
HX_STACK_ARG(Playstate,"Playstate")
{
	HX_STACK_LINE(28)
	this->_HP = (int)10;
	HX_STACK_LINE(27)
	this->BULLET_SPEED = (int)100;
	HX_STACK_LINE(26)
	this->GUN_DELAY = 1.5;
	HX_STACK_LINE(25)
	this->GRAVITY = (int)9800;
	HX_STACK_LINE(24)
	this->XSPEED = (int)0;
	HX_STACK_LINE(37)
	super::__construct(X,Y,ThePlayer,this->_HP,DropsGrp);
	HX_STACK_LINE(38)
	this->loadGraphic(HX_CSTRING("assets/images/mcbeck.png"),true,(int)34,(int)32,null(),null());
	HX_STACK_LINE(39)
	this->set_width((int)16);
	HX_STACK_LINE(40)
	this->set_height((int)16);
	HX_STACK_LINE(42)
	this->playstate = Playstate;
}
;
	return null();
}

//Testboss_obj::~Testboss_obj() { }

Dynamic Testboss_obj::__CreateEmpty() { return  new Testboss_obj; }
hx::ObjectPtr< Testboss_obj > Testboss_obj::__new(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup Bullets,::PlayState Playstate)
{  hx::ObjectPtr< Testboss_obj > result = new Testboss_obj();
	result->__construct(X,Y,ThePlayer,DropsGrp,Bullets,Playstate);
	return result;}

Dynamic Testboss_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Testboss_obj > result = new Testboss_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

Void Testboss_obj::finishKill( ::flixel::tweens::FlxTween _){
{
		HX_STACK_FRAME("Testboss","finishKill",0x4a3e8080,"Testboss.finishKill","Testboss.hx",46,0xa3ba62ff)
		HX_STACK_THIS(this)
		HX_STACK_ARG(_,"_")
		HX_STACK_LINE(47)
		this->super::finishKill(_);
		HX_STACK_LINE(48)
		this->playstate->gotoNextLevel();
	}
return null();
}



Testboss_obj::Testboss_obj()
{
}

void Testboss_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Testboss);
	HX_MARK_MEMBER_NAME(XSPEED,"XSPEED");
	HX_MARK_MEMBER_NAME(GRAVITY,"GRAVITY");
	HX_MARK_MEMBER_NAME(GUN_DELAY,"GUN_DELAY");
	HX_MARK_MEMBER_NAME(BULLET_SPEED,"BULLET_SPEED");
	HX_MARK_MEMBER_NAME(_HP,"_HP");
	HX_MARK_MEMBER_NAME(_bullets,"_bullets");
	HX_MARK_MEMBER_NAME(_cooldown,"_cooldown");
	HX_MARK_MEMBER_NAME(playstate,"playstate");
	::enemies::EnemyTemplate_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Testboss_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(XSPEED,"XSPEED");
	HX_VISIT_MEMBER_NAME(GRAVITY,"GRAVITY");
	HX_VISIT_MEMBER_NAME(GUN_DELAY,"GUN_DELAY");
	HX_VISIT_MEMBER_NAME(BULLET_SPEED,"BULLET_SPEED");
	HX_VISIT_MEMBER_NAME(_HP,"_HP");
	HX_VISIT_MEMBER_NAME(_bullets,"_bullets");
	HX_VISIT_MEMBER_NAME(_cooldown,"_cooldown");
	HX_VISIT_MEMBER_NAME(playstate,"playstate");
	::enemies::EnemyTemplate_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Testboss_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_HP") ) { return _HP; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"XSPEED") ) { return XSPEED; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"GRAVITY") ) { return GRAVITY; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_bullets") ) { return _bullets; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"GUN_DELAY") ) { return GUN_DELAY; }
		if (HX_FIELD_EQ(inName,"_cooldown") ) { return _cooldown; }
		if (HX_FIELD_EQ(inName,"playstate") ) { return playstate; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"finishKill") ) { return finishKill_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"BULLET_SPEED") ) { return BULLET_SPEED; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Testboss_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_HP") ) { _HP=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"XSPEED") ) { XSPEED=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"GRAVITY") ) { GRAVITY=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_bullets") ) { _bullets=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"GUN_DELAY") ) { GUN_DELAY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_cooldown") ) { _cooldown=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"playstate") ) { playstate=inValue.Cast< ::PlayState >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"BULLET_SPEED") ) { BULLET_SPEED=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Testboss_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("XSPEED"));
	outFields->push(HX_CSTRING("GRAVITY"));
	outFields->push(HX_CSTRING("GUN_DELAY"));
	outFields->push(HX_CSTRING("BULLET_SPEED"));
	outFields->push(HX_CSTRING("_HP"));
	outFields->push(HX_CSTRING("_bullets"));
	outFields->push(HX_CSTRING("_cooldown"));
	outFields->push(HX_CSTRING("playstate"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Testboss_obj,XSPEED),HX_CSTRING("XSPEED")},
	{hx::fsInt,(int)offsetof(Testboss_obj,GRAVITY),HX_CSTRING("GRAVITY")},
	{hx::fsFloat,(int)offsetof(Testboss_obj,GUN_DELAY),HX_CSTRING("GUN_DELAY")},
	{hx::fsInt,(int)offsetof(Testboss_obj,BULLET_SPEED),HX_CSTRING("BULLET_SPEED")},
	{hx::fsInt,(int)offsetof(Testboss_obj,_HP),HX_CSTRING("_HP")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(Testboss_obj,_bullets),HX_CSTRING("_bullets")},
	{hx::fsFloat,(int)offsetof(Testboss_obj,_cooldown),HX_CSTRING("_cooldown")},
	{hx::fsObject /*::PlayState*/ ,(int)offsetof(Testboss_obj,playstate),HX_CSTRING("playstate")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("XSPEED"),
	HX_CSTRING("GRAVITY"),
	HX_CSTRING("GUN_DELAY"),
	HX_CSTRING("BULLET_SPEED"),
	HX_CSTRING("_HP"),
	HX_CSTRING("_bullets"),
	HX_CSTRING("_cooldown"),
	HX_CSTRING("playstate"),
	HX_CSTRING("finishKill"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Testboss_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Testboss_obj::__mClass,"__mClass");
};

#endif

Class Testboss_obj::__mClass;

void Testboss_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Testboss"), hx::TCanCast< Testboss_obj> ,sStaticFields,sMemberFields,
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

void Testboss_obj::__boot()
{
}


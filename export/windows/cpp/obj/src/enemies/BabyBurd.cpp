#include <hxcpp.h>

#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_enemies_BabyBurd
#include <enemies/BabyBurd.h>
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
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
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
#ifndef INCLUDED_flixel_util_FlxRandom
#include <flixel/util/FlxRandom.h>
#endif
namespace enemies{

Void BabyBurd_obj::__construct(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp)
{
HX_STACK_FRAME("enemies.BabyBurd","new",0x2b161815,"enemies.BabyBurd.new","enemies/BabyBurd.hx",13,0xf506ae9a)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
HX_STACK_ARG(ThePlayer,"ThePlayer")
HX_STACK_ARG(DropsGrp,"DropsGrp")
{
	HX_STACK_LINE(17)
	this->_HP = (int)1;
	HX_STACK_LINE(16)
	this->YSPEED = (int)25;
	HX_STACK_LINE(15)
	this->XSPEED = (int)50;
	HX_STACK_LINE(21)
	super::__construct(X,Y,ThePlayer,this->_HP,DropsGrp);
	HX_STACK_LINE(22)
	int _g = ::flixel::util::FlxRandom_obj::intRanged((int)-10,(int)10,null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(22)
	this->YSPEED = _g;
	HX_STACK_LINE(23)
	this->velocity->set_y(this->YSPEED);
	HX_STACK_LINE(25)
	this->loadGraphic(HX_CSTRING("assets/images/burdsmall.png"),true,(int)8,(int)8,null(),null());
	HX_STACK_LINE(26)
	this->set_width((int)8);
	HX_STACK_LINE(27)
	this->set_height((int)8);
	HX_STACK_LINE(31)
	this->animation->add(HX_CSTRING("flap"),Array_obj< int >::__new().Add((int)0).Add((int)1),(int)10,true);
	HX_STACK_LINE(33)
	if (((this->_player->x < this->x))){
		HX_STACK_LINE(36)
		this->set_facing((int)16);
		HX_STACK_LINE(37)
		this->set_flipX(false);
		HX_STACK_LINE(38)
		this->velocity->set_x(-(this->XSPEED));
	}
	else{
		HX_STACK_LINE(40)
		if (((this->_player->x > this->x))){
			HX_STACK_LINE(42)
			this->set_facing((int)1);
			HX_STACK_LINE(43)
			this->set_flipX(true);
			HX_STACK_LINE(44)
			this->velocity->set_x(this->XSPEED);
		}
	}
}
;
	return null();
}

//BabyBurd_obj::~BabyBurd_obj() { }

Dynamic BabyBurd_obj::__CreateEmpty() { return  new BabyBurd_obj; }
hx::ObjectPtr< BabyBurd_obj > BabyBurd_obj::__new(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp)
{  hx::ObjectPtr< BabyBurd_obj > result = new BabyBurd_obj();
	result->__construct(X,Y,ThePlayer,DropsGrp);
	return result;}

Dynamic BabyBurd_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BabyBurd_obj > result = new BabyBurd_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void BabyBurd_obj::update( ){
{
		HX_STACK_FRAME("enemies.BabyBurd","update",0x674d3d74,"enemies.BabyBurd.update","enemies/BabyBurd.hx",49,0xf506ae9a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(50)
		this->animation->play(HX_CSTRING("flap"),null(),null());
		HX_STACK_LINE(52)
		this->super::update();
	}
return null();
}



BabyBurd_obj::BabyBurd_obj()
{
}

Dynamic BabyBurd_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_HP") ) { return _HP; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"XSPEED") ) { return XSPEED; }
		if (HX_FIELD_EQ(inName,"YSPEED") ) { return YSPEED; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BabyBurd_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_HP") ) { _HP=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"XSPEED") ) { XSPEED=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"YSPEED") ) { YSPEED=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BabyBurd_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("XSPEED"));
	outFields->push(HX_CSTRING("YSPEED"));
	outFields->push(HX_CSTRING("_HP"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(BabyBurd_obj,XSPEED),HX_CSTRING("XSPEED")},
	{hx::fsInt,(int)offsetof(BabyBurd_obj,YSPEED),HX_CSTRING("YSPEED")},
	{hx::fsInt,(int)offsetof(BabyBurd_obj,_HP),HX_CSTRING("_HP")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("XSPEED"),
	HX_CSTRING("YSPEED"),
	HX_CSTRING("_HP"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BabyBurd_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BabyBurd_obj::__mClass,"__mClass");
};

#endif

Class BabyBurd_obj::__mClass;

void BabyBurd_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("enemies.BabyBurd"), hx::TCanCast< BabyBurd_obj> ,sStaticFields,sMemberFields,
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

void BabyBurd_obj::__boot()
{
}

} // end namespace enemies

#include <hxcpp.h>

#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_enemies_EnemyTemplate
#include <enemies/EnemyTemplate.h>
#endif
#ifndef INCLUDED_enemies_Snobal
#include <enemies/Snobal.h>
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
namespace enemies{

Void Snobal_obj::__construct(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp)
{
HX_STACK_FRAME("enemies.Snobal","new",0x64ea2733,"enemies.Snobal.new","enemies/Snobal.hx",13,0xfa24777c)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
HX_STACK_ARG(ThePlayer,"ThePlayer")
HX_STACK_ARG(DropsGrp,"DropsGrp")
{
	HX_STACK_LINE(17)
	this->_HP = (int)1;
	HX_STACK_LINE(16)
	this->GRAVITY = (int)9800;
	HX_STACK_LINE(15)
	this->XSPEED = (int)25;
	HX_STACK_LINE(22)
	super::__construct(X,Y,ThePlayer,this->_HP,DropsGrp);
	HX_STACK_LINE(23)
	this->loadGraphic(HX_CSTRING("assets/images/snobal.png"),true,(int)16,(int)16,null(),null());
	HX_STACK_LINE(24)
	this->set_width((int)16);
	HX_STACK_LINE(25)
	this->set_height((int)16);
	HX_STACK_LINE(28)
	this->animation->add(HX_CSTRING("idle"),Array_obj< int >::__new().Add((int)0),(int)10,true);
	HX_STACK_LINE(29)
	this->animation->add(HX_CSTRING("roll"),Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)3),(int)15,true);
}
;
	return null();
}

//Snobal_obj::~Snobal_obj() { }

Dynamic Snobal_obj::__CreateEmpty() { return  new Snobal_obj; }
hx::ObjectPtr< Snobal_obj > Snobal_obj::__new(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp)
{  hx::ObjectPtr< Snobal_obj > result = new Snobal_obj();
	result->__construct(X,Y,ThePlayer,DropsGrp);
	return result;}

Dynamic Snobal_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Snobal_obj > result = new Snobal_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void Snobal_obj::update( ){
{
		HX_STACK_FRAME("enemies.Snobal","update",0x0800f516,"enemies.Snobal.update","enemies/Snobal.hx",34,0xfa24777c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(35)
		Float _g = this->velocity->set_y((int)0);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(35)
		this->velocity->set_x(_g);
		HX_STACK_LINE(37)
		Float xdistance = (this->_player->x - this->x);		HX_STACK_VAR(xdistance,"xdistance");
		HX_STACK_LINE(38)
		Float ydistance = (this->_player->y - this->y);		HX_STACK_VAR(ydistance,"ydistance");
		HX_STACK_LINE(39)
		Float distancesquared = ((xdistance * xdistance) + (ydistance * ydistance));		HX_STACK_VAR(distancesquared,"distancesquared");
		HX_STACK_LINE(40)
		this->acceleration->set_y(this->GRAVITY);
		HX_STACK_LINE(43)
		if (((distancesquared < (int)32000))){
			HX_STACK_LINE(45)
			if (((this->_player->x < this->x))){
				HX_STACK_LINE(48)
				this->set_facing((int)16);
				HX_STACK_LINE(49)
				this->set_flipX(false);
				HX_STACK_LINE(50)
				this->velocity->set_x(-(this->XSPEED));
			}
			else{
				HX_STACK_LINE(52)
				if (((this->_player->x > this->x))){
					HX_STACK_LINE(54)
					this->set_facing((int)1);
					HX_STACK_LINE(55)
					this->set_flipX(true);
					HX_STACK_LINE(56)
					this->velocity->set_x(this->XSPEED);
				}
			}
		}
		HX_STACK_LINE(61)
		if (((bool((this->velocity->x == (int)0)) && bool((this->velocity->y == (int)0))))){
			HX_STACK_LINE(63)
			this->animation->play(HX_CSTRING("idle"),null(),null());
		}
		else{
			HX_STACK_LINE(67)
			this->animation->play(HX_CSTRING("roll"),null(),null());
		}
		HX_STACK_LINE(70)
		this->super::update();
	}
return null();
}



Snobal_obj::Snobal_obj()
{
}

Dynamic Snobal_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_HP") ) { return _HP; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"XSPEED") ) { return XSPEED; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"GRAVITY") ) { return GRAVITY; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Snobal_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Snobal_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("XSPEED"));
	outFields->push(HX_CSTRING("GRAVITY"));
	outFields->push(HX_CSTRING("_HP"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Snobal_obj,XSPEED),HX_CSTRING("XSPEED")},
	{hx::fsInt,(int)offsetof(Snobal_obj,GRAVITY),HX_CSTRING("GRAVITY")},
	{hx::fsInt,(int)offsetof(Snobal_obj,_HP),HX_CSTRING("_HP")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("XSPEED"),
	HX_CSTRING("GRAVITY"),
	HX_CSTRING("_HP"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Snobal_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Snobal_obj::__mClass,"__mClass");
};

#endif

Class Snobal_obj::__mClass;

void Snobal_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("enemies.Snobal"), hx::TCanCast< Snobal_obj> ,sStaticFields,sMemberFields,
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

void Snobal_obj::__boot()
{
}

} // end namespace enemies

#include <hxcpp.h>

#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_enemies_EnemyTemplate
#include <enemies/EnemyTemplate.h>
#endif
#ifndef INCLUDED_enemies_Notey
#include <enemies/Notey.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
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

Void Notey_obj::__construct(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp)
{
HX_STACK_FRAME("enemies.Notey","new",0x00260ad1,"enemies.Notey.new","enemies/Notey.hx",11,0x54aa62c0)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
HX_STACK_ARG(ThePlayer,"ThePlayer")
HX_STACK_ARG(DropsGrp,"DropsGrp")
{
	HX_STACK_LINE(15)
	this->_HP = (int)1;
	HX_STACK_LINE(14)
	this->GRAVITY = (int)9800;
	HX_STACK_LINE(13)
	this->XSPEED = (int)-75;
	HX_STACK_LINE(19)
	super::__construct(X,Y,ThePlayer,this->_HP,DropsGrp);
	HX_STACK_LINE(20)
	this->loadGraphic(HX_CSTRING("assets/images/notey.png"),true,(int)16,(int)16,null(),null());
	HX_STACK_LINE(22)
	this->set_width((int)16);
	HX_STACK_LINE(23)
	this->set_height((int)16);
	HX_STACK_LINE(25)
	this->set_facing((int)16);
	HX_STACK_LINE(26)
	this->set_flipX(true);
	HX_STACK_LINE(28)
	this->animation->add(HX_CSTRING("walk"),Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)0).Add((int)2),(int)3,true);
}
;
	return null();
}

//Notey_obj::~Notey_obj() { }

Dynamic Notey_obj::__CreateEmpty() { return  new Notey_obj; }
hx::ObjectPtr< Notey_obj > Notey_obj::__new(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp)
{  hx::ObjectPtr< Notey_obj > result = new Notey_obj();
	result->__construct(X,Y,ThePlayer,DropsGrp);
	return result;}

Dynamic Notey_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Notey_obj > result = new Notey_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void Notey_obj::update( ){
{
		HX_STACK_FRAME("enemies.Notey","update",0x5784a838,"enemies.Notey.update","enemies/Notey.hx",34,0x54aa62c0)
		HX_STACK_THIS(this)
		HX_STACK_LINE(34)
		if ((this->isOnScreen(null()))){
			HX_STACK_LINE(36)
			this->velocity->set_x(this->XSPEED);
			HX_STACK_LINE(38)
			this->animation->play(HX_CSTRING("walk"),null(),null());
			HX_STACK_LINE(39)
			this->acceleration->set_y(this->GRAVITY);
			HX_STACK_LINE(41)
			if (((((int(this->touching) & int((int)17))) > (int)0))){
				HX_STACK_LINE(42)
				this->turnAround();
			}
			HX_STACK_LINE(44)
			this->super::update();
		}
	}
return null();
}


Void Notey_obj::turnAround( ){
{
		HX_STACK_FRAME("enemies.Notey","turnAround",0xf6e8f959,"enemies.Notey.turnAround","enemies/Notey.hx",49,0x54aa62c0)
		HX_STACK_THIS(this)
		HX_STACK_LINE(50)
		this->XSPEED = -(this->XSPEED);
		HX_STACK_LINE(52)
		if (((this->facing == (int)1))){
			HX_STACK_LINE(54)
			this->set_facing((int)16);
			HX_STACK_LINE(55)
			this->set_flipX(true);
			HX_STACK_LINE(56)
			{
				HX_STACK_LINE(56)
				::enemies::Notey _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(56)
				_g->set_x((_g->x - (int)2));
			}
		}
		else{
			HX_STACK_LINE(60)
			this->set_facing((int)1);
			HX_STACK_LINE(61)
			this->set_flipX(false);
			HX_STACK_LINE(62)
			{
				HX_STACK_LINE(62)
				::enemies::Notey _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(62)
				_g->set_x((_g->x + (int)2));
			}
		}
		HX_STACK_LINE(64)
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Notey_obj,turnAround,(void))


Notey_obj::Notey_obj()
{
}

Dynamic Notey_obj::__Field(const ::String &inName,bool inCallProp)
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
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"turnAround") ) { return turnAround_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Notey_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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

void Notey_obj::__GetFields(Array< ::String> &outFields)
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
	{hx::fsInt,(int)offsetof(Notey_obj,XSPEED),HX_CSTRING("XSPEED")},
	{hx::fsInt,(int)offsetof(Notey_obj,GRAVITY),HX_CSTRING("GRAVITY")},
	{hx::fsInt,(int)offsetof(Notey_obj,_HP),HX_CSTRING("_HP")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("XSPEED"),
	HX_CSTRING("GRAVITY"),
	HX_CSTRING("_HP"),
	HX_CSTRING("update"),
	HX_CSTRING("turnAround"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Notey_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Notey_obj::__mClass,"__mClass");
};

#endif

Class Notey_obj::__mClass;

void Notey_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("enemies.Notey"), hx::TCanCast< Notey_obj> ,sStaticFields,sMemberFields,
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

void Notey_obj::__boot()
{
}

} // end namespace enemies

#include <hxcpp.h>

#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_enemies_EnemyTemplate
#include <enemies/EnemyTemplate.h>
#endif
#ifndef INCLUDED_enemies_Snaake
#include <enemies/Snaake.h>
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

Void Snaake_obj::__construct(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp)
{
HX_STACK_FRAME("enemies.Snaake","new",0x1255feef,"enemies.Snaake.new","enemies/Snaake.hx",15,0x0afdeb40)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
HX_STACK_ARG(ThePlayer,"ThePlayer")
HX_STACK_ARG(DropsGrp,"DropsGrp")
{
	HX_STACK_LINE(21)
	this->_HP = (int)1;
	HX_STACK_LINE(20)
	this->GRAVITY = (int)9800;
	HX_STACK_LINE(19)
	this->XSPEED2 = (int)100;
	HX_STACK_LINE(18)
	this->XSPEED = (int)50;
	HX_STACK_LINE(25)
	super::__construct(X,Y,ThePlayer,this->_HP,DropsGrp);
	HX_STACK_LINE(27)
	this->loadGraphic(HX_CSTRING("assets/images/crawler.png"),true,(int)16,(int)8,null(),null());
	HX_STACK_LINE(28)
	this->set_width((int)16);
	HX_STACK_LINE(29)
	this->set_height((int)8);
	HX_STACK_LINE(31)
	this->set_facing((int)1);
	HX_STACK_LINE(34)
	this->animation->add(HX_CSTRING("walk"),Array_obj< int >::__new().Add((int)0).Add((int)1),(int)8,true);
}
;
	return null();
}

//Snaake_obj::~Snaake_obj() { }

Dynamic Snaake_obj::__CreateEmpty() { return  new Snaake_obj; }
hx::ObjectPtr< Snaake_obj > Snaake_obj::__new(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp)
{  hx::ObjectPtr< Snaake_obj > result = new Snaake_obj();
	result->__construct(X,Y,ThePlayer,DropsGrp);
	return result;}

Dynamic Snaake_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Snaake_obj > result = new Snaake_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void Snaake_obj::update( ){
{
		HX_STACK_FRAME("enemies.Snaake","update",0xe8999ada,"enemies.Snaake.update","enemies/Snaake.hx",40,0x0afdeb40)
		HX_STACK_THIS(this)
		HX_STACK_LINE(40)
		if ((this->isOnScreen(null()))){
			HX_STACK_LINE(42)
			this->velocity->set_x(this->XSPEED);
			HX_STACK_LINE(44)
			this->animation->play(HX_CSTRING("walk"),null(),null());
			HX_STACK_LINE(45)
			this->acceleration->set_y(this->GRAVITY);
			HX_STACK_LINE(47)
			if (((((int(this->touching) & int((int)17))) > (int)0))){
				HX_STACK_LINE(48)
				this->turnAround();
			}
			HX_STACK_LINE(50)
			Float _g = this->_player->get_height();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(50)
			Float _g1 = (this->_player->y + _g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(50)
			Float _g2 = this->get_height();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(50)
			Float _g3 = (this->y + _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(50)
			if (((_g1 == _g3))){
				HX_STACK_LINE(51)
				this->XSPEED = (int)150;
			}
			else{
				HX_STACK_LINE(53)
				this->XSPEED = (int)50;
			}
			HX_STACK_LINE(55)
			if (((this->flipX == true))){
				HX_STACK_LINE(56)
				hx::MultEq(this->XSPEED,(int)-1);
			}
			HX_STACK_LINE(58)
			this->super::update();
		}
	}
return null();
}


Void Snaake_obj::turnAround( ){
{
		HX_STACK_FRAME("enemies.Snaake","turnAround",0xe148e4fb,"enemies.Snaake.turnAround","enemies/Snaake.hx",63,0x0afdeb40)
		HX_STACK_THIS(this)
		HX_STACK_LINE(64)
		this->XSPEED = -(this->XSPEED);
		HX_STACK_LINE(66)
		if (((this->facing == (int)16))){
			HX_STACK_LINE(68)
			this->set_facing((int)1);
			HX_STACK_LINE(69)
			this->set_flipX(true);
			HX_STACK_LINE(70)
			{
				HX_STACK_LINE(70)
				::enemies::Snaake _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(70)
				_g->set_x((_g->x + (Float(this->XSPEED) / Float((int)25))));
			}
		}
		else{
			HX_STACK_LINE(74)
			this->set_facing((int)16);
			HX_STACK_LINE(75)
			this->set_flipX(false);
			HX_STACK_LINE(76)
			{
				HX_STACK_LINE(76)
				::enemies::Snaake _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(76)
				_g->set_x((_g->x + (Float(this->XSPEED) / Float((int)25))));
			}
		}
		HX_STACK_LINE(78)
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Snaake_obj,turnAround,(void))


Snaake_obj::Snaake_obj()
{
}

Dynamic Snaake_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"XSPEED2") ) { return XSPEED2; }
		if (HX_FIELD_EQ(inName,"GRAVITY") ) { return GRAVITY; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"turnAround") ) { return turnAround_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Snaake_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_HP") ) { _HP=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"XSPEED") ) { XSPEED=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"XSPEED2") ) { XSPEED2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"GRAVITY") ) { GRAVITY=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Snaake_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("XSPEED"));
	outFields->push(HX_CSTRING("XSPEED2"));
	outFields->push(HX_CSTRING("GRAVITY"));
	outFields->push(HX_CSTRING("_HP"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Snaake_obj,XSPEED),HX_CSTRING("XSPEED")},
	{hx::fsInt,(int)offsetof(Snaake_obj,XSPEED2),HX_CSTRING("XSPEED2")},
	{hx::fsInt,(int)offsetof(Snaake_obj,GRAVITY),HX_CSTRING("GRAVITY")},
	{hx::fsInt,(int)offsetof(Snaake_obj,_HP),HX_CSTRING("_HP")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("XSPEED"),
	HX_CSTRING("XSPEED2"),
	HX_CSTRING("GRAVITY"),
	HX_CSTRING("_HP"),
	HX_CSTRING("update"),
	HX_CSTRING("turnAround"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Snaake_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Snaake_obj::__mClass,"__mClass");
};

#endif

Class Snaake_obj::__mClass;

void Snaake_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("enemies.Snaake"), hx::TCanCast< Snaake_obj> ,sStaticFields,sMemberFields,
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

void Snaake_obj::__boot()
{
}

} // end namespace enemies

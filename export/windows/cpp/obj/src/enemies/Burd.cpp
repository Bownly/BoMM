#include <hxcpp.h>

#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_enemies_Burd
#include <enemies/Burd.h>
#endif
#ifndef INCLUDED_enemies_Egg
#include <enemies/Egg.h>
#endif
#ifndef INCLUDED_enemies_EnemyTemplate
#include <enemies/EnemyTemplate.h>
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
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
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

Void Burd_obj::__construct(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup Enemies)
{
HX_STACK_FRAME("enemies.Burd","new",0x3b5ca89f,"enemies.Burd.new","enemies/Burd.hx",11,0x52b801d0)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
HX_STACK_ARG(ThePlayer,"ThePlayer")
HX_STACK_ARG(DropsGrp,"DropsGrp")
HX_STACK_ARG(Enemies,"Enemies")
{
	HX_STACK_LINE(18)
	this->haveEgg = false;
	HX_STACK_LINE(16)
	this->_HP = (int)1;
	HX_STACK_LINE(15)
	this->GRAVITY = (int)9800;
	HX_STACK_LINE(14)
	this->XSPEED = (int)-75;
	HX_STACK_LINE(23)
	super::__construct(X,Y,ThePlayer,this->_HP,DropsGrp);
	HX_STACK_LINE(24)
	this->loadGraphic(HX_CSTRING("assets/images/burd.png"),true,(int)16,(int)16,null(),null());
	HX_STACK_LINE(25)
	this->set_width((int)16);
	HX_STACK_LINE(26)
	this->set_height((int)16);
	HX_STACK_LINE(28)
	this->animation->add(HX_CSTRING("flap"),Array_obj< int >::__new().Add((int)0).Add((int)1),(int)5,true);
	HX_STACK_LINE(30)
	Float _g = this->get_height();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(30)
	Float _g1 = (this->y + _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(30)
	::enemies::Egg _g2 = ::enemies::Egg_obj::__new(this->x,_g1,ThePlayer,this->_drops,this->XSPEED,Enemies);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(30)
	this->egg = _g2;
	HX_STACK_LINE(31)
	Enemies->add(this->egg);
	HX_STACK_LINE(32)
	this->haveEgg = true;
}
;
	return null();
}

//Burd_obj::~Burd_obj() { }

Dynamic Burd_obj::__CreateEmpty() { return  new Burd_obj; }
hx::ObjectPtr< Burd_obj > Burd_obj::__new(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup Enemies)
{  hx::ObjectPtr< Burd_obj > result = new Burd_obj();
	result->__construct(X,Y,ThePlayer,DropsGrp,Enemies);
	return result;}

Dynamic Burd_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Burd_obj > result = new Burd_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

Void Burd_obj::update( ){
{
		HX_STACK_FRAME("enemies.Burd","update",0xd0b81f2a,"enemies.Burd.update","enemies/Burd.hx",37,0x52b801d0)
		HX_STACK_THIS(this)
		HX_STACK_LINE(37)
		if ((this->isOnScreen(null()))){
			HX_STACK_LINE(39)
			this->velocity->set_x(this->XSPEED);
			HX_STACK_LINE(40)
			this->velocity->set_y((int)0);
			HX_STACK_LINE(42)
			this->animation->play(HX_CSTRING("flap"),null(),null());
			HX_STACK_LINE(44)
			Float xdistance = (this->_player->x - this->x);		HX_STACK_VAR(xdistance,"xdistance");
			HX_STACK_LINE(45)
			Float ydistance = (this->_player->y - this->y);		HX_STACK_VAR(ydistance,"ydistance");
			HX_STACK_LINE(46)
			Float distancesquared = ((xdistance * xdistance) + (ydistance * ydistance));		HX_STACK_VAR(distancesquared,"distancesquared");
			HX_STACK_LINE(48)
			if (((bool((distancesquared < (int)24000)) && bool(this->haveEgg)))){
				HX_STACK_LINE(50)
				this->dropEgg();
			}
			HX_STACK_LINE(52)
			this->super::update();
		}
	}
return null();
}


Void Burd_obj::dropEgg( ){
{
		HX_STACK_FRAME("enemies.Burd","dropEgg",0x395be895,"enemies.Burd.dropEgg","enemies/Burd.hx",57,0x52b801d0)
		HX_STACK_THIS(this)
		HX_STACK_LINE(58)
		this->haveEgg = false;
		HX_STACK_LINE(59)
		this->egg->dropped();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Burd_obj,dropEgg,(void))


Burd_obj::Burd_obj()
{
}

void Burd_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Burd);
	HX_MARK_MEMBER_NAME(XSPEED,"XSPEED");
	HX_MARK_MEMBER_NAME(GRAVITY,"GRAVITY");
	HX_MARK_MEMBER_NAME(_HP,"_HP");
	HX_MARK_MEMBER_NAME(haveEgg,"haveEgg");
	HX_MARK_MEMBER_NAME(egg,"egg");
	::enemies::EnemyTemplate_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Burd_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(XSPEED,"XSPEED");
	HX_VISIT_MEMBER_NAME(GRAVITY,"GRAVITY");
	HX_VISIT_MEMBER_NAME(_HP,"_HP");
	HX_VISIT_MEMBER_NAME(haveEgg,"haveEgg");
	HX_VISIT_MEMBER_NAME(egg,"egg");
	::enemies::EnemyTemplate_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Burd_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_HP") ) { return _HP; }
		if (HX_FIELD_EQ(inName,"egg") ) { return egg; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"XSPEED") ) { return XSPEED; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"GRAVITY") ) { return GRAVITY; }
		if (HX_FIELD_EQ(inName,"haveEgg") ) { return haveEgg; }
		if (HX_FIELD_EQ(inName,"dropEgg") ) { return dropEgg_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Burd_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_HP") ) { _HP=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"egg") ) { egg=inValue.Cast< ::enemies::Egg >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"XSPEED") ) { XSPEED=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"GRAVITY") ) { GRAVITY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"haveEgg") ) { haveEgg=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Burd_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("XSPEED"));
	outFields->push(HX_CSTRING("GRAVITY"));
	outFields->push(HX_CSTRING("_HP"));
	outFields->push(HX_CSTRING("haveEgg"));
	outFields->push(HX_CSTRING("egg"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Burd_obj,XSPEED),HX_CSTRING("XSPEED")},
	{hx::fsInt,(int)offsetof(Burd_obj,GRAVITY),HX_CSTRING("GRAVITY")},
	{hx::fsInt,(int)offsetof(Burd_obj,_HP),HX_CSTRING("_HP")},
	{hx::fsBool,(int)offsetof(Burd_obj,haveEgg),HX_CSTRING("haveEgg")},
	{hx::fsObject /*::enemies::Egg*/ ,(int)offsetof(Burd_obj,egg),HX_CSTRING("egg")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("XSPEED"),
	HX_CSTRING("GRAVITY"),
	HX_CSTRING("_HP"),
	HX_CSTRING("haveEgg"),
	HX_CSTRING("egg"),
	HX_CSTRING("update"),
	HX_CSTRING("dropEgg"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Burd_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Burd_obj::__mClass,"__mClass");
};

#endif

Class Burd_obj::__mClass;

void Burd_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("enemies.Burd"), hx::TCanCast< Burd_obj> ,sStaticFields,sMemberFields,
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

void Burd_obj::__boot()
{
}

} // end namespace enemies

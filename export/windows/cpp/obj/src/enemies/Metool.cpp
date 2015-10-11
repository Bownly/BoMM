#include <hxcpp.h>

#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_enemies_EnemyTemplate
#include <enemies/EnemyTemplate.h>
#endif
#ifndef INCLUDED_enemies_Metool
#include <enemies/Metool.h>
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
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_weapons_Bullet
#include <weapons/Bullet.h>
#endif
namespace enemies{

Void Metool_obj::__construct(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup Bullets)
{
HX_STACK_FRAME("enemies.Metool","new",0x4c40f68a,"enemies.Metool.new","enemies/Metool.hx",14,0x17e12005)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
HX_STACK_ARG(ThePlayer,"ThePlayer")
HX_STACK_ARG(DropsGrp,"DropsGrp")
HX_STACK_ARG(Bullets,"Bullets")
{
	HX_STACK_LINE(21)
	this->_HP = (int)2;
	HX_STACK_LINE(20)
	this->BULLET_SPEED = (int)100;
	HX_STACK_LINE(19)
	this->GUN_DELAY = 1.5;
	HX_STACK_LINE(18)
	this->GRAVITY = (int)9800;
	HX_STACK_LINE(17)
	this->XSPEED = (int)0;
	HX_STACK_LINE(28)
	super::__construct(X,Y,ThePlayer,this->_HP,DropsGrp);
	HX_STACK_LINE(29)
	this->loadGraphic(HX_CSTRING("assets/images/metool.png"),true,(int)16,(int)16,null(),null());
	HX_STACK_LINE(30)
	this->set_width((int)16);
	HX_STACK_LINE(31)
	this->set_height((int)16);
	HX_STACK_LINE(33)
	this->_bullets = Bullets;
	HX_STACK_LINE(34)
	this->_cooldown = (int)0;
	HX_STACK_LINE(36)
	this->animation->add(HX_CSTRING("hide"),Array_obj< int >::__new().Add((int)0),null(),null());
	HX_STACK_LINE(37)
	this->animation->add(HX_CSTRING("open"),Array_obj< int >::__new().Add((int)1),null(),null());
}
;
	return null();
}

//Metool_obj::~Metool_obj() { }

Dynamic Metool_obj::__CreateEmpty() { return  new Metool_obj; }
hx::ObjectPtr< Metool_obj > Metool_obj::__new(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup Bullets)
{  hx::ObjectPtr< Metool_obj > result = new Metool_obj();
	result->__construct(X,Y,ThePlayer,DropsGrp,Bullets);
	return result;}

Dynamic Metool_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Metool_obj > result = new Metool_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

Void Metool_obj::update( ){
{
		HX_STACK_FRAME("enemies.Metool","update",0xe717161f,"enemies.Metool.update","enemies/Metool.hx",42,0x17e12005)
		HX_STACK_THIS(this)
		HX_STACK_LINE(42)
		if ((this->isOnScreen(null()))){
			HX_STACK_LINE(44)
			Float _g = this->velocity->set_y((int)0);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(44)
			this->velocity->set_x(_g);
			HX_STACK_LINE(46)
			Float xdistance = (this->_player->x - this->x);		HX_STACK_VAR(xdistance,"xdistance");
			HX_STACK_LINE(47)
			Float ydistance = (this->_player->y - this->y);		HX_STACK_VAR(ydistance,"ydistance");
			HX_STACK_LINE(48)
			Float distancesquared = ((xdistance * xdistance) + (ydistance * ydistance));		HX_STACK_VAR(distancesquared,"distancesquared");
			HX_STACK_LINE(49)
			this->acceleration->set_y(this->GRAVITY);
			HX_STACK_LINE(51)
			if (((distancesquared < (int)16000))){
				HX_STACK_LINE(53)
				if (((this->_player->x < this->x))){
					HX_STACK_LINE(57)
					this->set_facing((int)16);
					HX_STACK_LINE(58)
					this->set_flipX(false);
					HX_STACK_LINE(59)
					this->velocity->set_x(-(this->XSPEED));
				}
				else{
					HX_STACK_LINE(61)
					if (((this->_player->x > this->x))){
						HX_STACK_LINE(63)
						this->set_facing((int)1);
						HX_STACK_LINE(64)
						this->set_flipX(true);
						HX_STACK_LINE(65)
						this->velocity->set_x(this->XSPEED);
					}
				}
				HX_STACK_LINE(67)
				if (((this->_player->facing == (int)16))){
					HX_STACK_LINE(68)
					this->animation->play(HX_CSTRING("hide"),null(),null());
				}
				else{
					HX_STACK_LINE(70)
					this->animation->play(HX_CSTRING("open"),null(),null());
				}
			}
			else{
				HX_STACK_LINE(74)
				this->animation->play(HX_CSTRING("open"),null(),null());
				HX_STACK_LINE(75)
				this->shoot(this->_player);
			}
			HX_STACK_LINE(77)
			hx::AddEq(this->_cooldown,::flixel::FlxG_obj::elapsed);
			HX_STACK_LINE(78)
			this->super::update();
		}
	}
return null();
}


Void Metool_obj::shoot( ::Player P){
{
		HX_STACK_FRAME("enemies.Metool","shoot",0x7a4a0689,"enemies.Metool.shoot","enemies/Metool.hx",83,0x17e12005)
		HX_STACK_THIS(this)
		HX_STACK_ARG(P,"P")
		HX_STACK_LINE(85)
		int bulletX = ::Math_obj::floor(this->x);		HX_STACK_VAR(bulletX,"bulletX");
		HX_STACK_LINE(86)
		int bulletY = ::Math_obj::floor((this->y + (int)4));		HX_STACK_VAR(bulletY,"bulletY");
		HX_STACK_LINE(88)
		if (((this->_cooldown > this->GUN_DELAY))){
			HX_STACK_LINE(90)
			::weapons::Bullet bullet = ::weapons::Bullet_obj::__new((this->x - (int)8),(this->y + (int)8),(int)500,(int)1,(int)1,(int)256);		HX_STACK_VAR(bullet,"bullet");
			HX_STACK_LINE(91)
			this->_bullets->add(bullet);
			HX_STACK_LINE(95)
			this->_cooldown = (int)0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Metool_obj,shoot,(void))

Void Metool_obj::takeDamage( int damage){
{
		HX_STACK_FRAME("enemies.Metool","takeDamage",0x4ca7ff2c,"enemies.Metool.takeDamage","enemies/Metool.hx",100,0x17e12005)
		HX_STACK_THIS(this)
		HX_STACK_ARG(damage,"damage")
		HX_STACK_LINE(101)
		::String _g = this->animation->get_name();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(101)
		if (((_g == HX_CSTRING("open")))){
			HX_STACK_LINE(105)
			hx::SubEq(this->_health,damage);
			HX_STACK_LINE(107)
			if (((this->_health <= (int)0))){
				HX_STACK_LINE(108)
				this->kill();
			}
		}
	}
return null();
}



Metool_obj::Metool_obj()
{
}

void Metool_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Metool);
	HX_MARK_MEMBER_NAME(XSPEED,"XSPEED");
	HX_MARK_MEMBER_NAME(GRAVITY,"GRAVITY");
	HX_MARK_MEMBER_NAME(GUN_DELAY,"GUN_DELAY");
	HX_MARK_MEMBER_NAME(BULLET_SPEED,"BULLET_SPEED");
	HX_MARK_MEMBER_NAME(_HP,"_HP");
	HX_MARK_MEMBER_NAME(_bullets,"_bullets");
	HX_MARK_MEMBER_NAME(_cooldown,"_cooldown");
	::enemies::EnemyTemplate_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Metool_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(XSPEED,"XSPEED");
	HX_VISIT_MEMBER_NAME(GRAVITY,"GRAVITY");
	HX_VISIT_MEMBER_NAME(GUN_DELAY,"GUN_DELAY");
	HX_VISIT_MEMBER_NAME(BULLET_SPEED,"BULLET_SPEED");
	HX_VISIT_MEMBER_NAME(_HP,"_HP");
	HX_VISIT_MEMBER_NAME(_bullets,"_bullets");
	HX_VISIT_MEMBER_NAME(_cooldown,"_cooldown");
	::enemies::EnemyTemplate_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Metool_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_HP") ) { return _HP; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"shoot") ) { return shoot_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"XSPEED") ) { return XSPEED; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
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
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"takeDamage") ) { return takeDamage_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"BULLET_SPEED") ) { return BULLET_SPEED; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Metool_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"BULLET_SPEED") ) { BULLET_SPEED=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Metool_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("XSPEED"));
	outFields->push(HX_CSTRING("GRAVITY"));
	outFields->push(HX_CSTRING("GUN_DELAY"));
	outFields->push(HX_CSTRING("BULLET_SPEED"));
	outFields->push(HX_CSTRING("_HP"));
	outFields->push(HX_CSTRING("_bullets"));
	outFields->push(HX_CSTRING("_cooldown"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Metool_obj,XSPEED),HX_CSTRING("XSPEED")},
	{hx::fsInt,(int)offsetof(Metool_obj,GRAVITY),HX_CSTRING("GRAVITY")},
	{hx::fsFloat,(int)offsetof(Metool_obj,GUN_DELAY),HX_CSTRING("GUN_DELAY")},
	{hx::fsInt,(int)offsetof(Metool_obj,BULLET_SPEED),HX_CSTRING("BULLET_SPEED")},
	{hx::fsInt,(int)offsetof(Metool_obj,_HP),HX_CSTRING("_HP")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(Metool_obj,_bullets),HX_CSTRING("_bullets")},
	{hx::fsFloat,(int)offsetof(Metool_obj,_cooldown),HX_CSTRING("_cooldown")},
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
	HX_CSTRING("update"),
	HX_CSTRING("shoot"),
	HX_CSTRING("takeDamage"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Metool_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Metool_obj::__mClass,"__mClass");
};

#endif

Class Metool_obj::__mClass;

void Metool_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("enemies.Metool"), hx::TCanCast< Metool_obj> ,sStaticFields,sMemberFields,
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

void Metool_obj::__boot()
{
}

} // end namespace enemies

#include <hxcpp.h>

#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_enemies_EnemyTemplate
#include <enemies/EnemyTemplate.h>
#endif
#ifndef INCLUDED_enemies_Mush
#include <enemies/Mush.h>
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
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_weapons_Bullet
#include <weapons/Bullet.h>
#endif
#ifndef INCLUDED_weapons_Spore
#include <weapons/Spore.h>
#endif
namespace enemies{

Void Mush_obj::__construct(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup Bullets,int Palette)
{
HX_STACK_FRAME("enemies.Mush","new",0x647d3e57,"enemies.Mush.new","enemies/Mush.hx",17,0xb22f8b18)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
HX_STACK_ARG(ThePlayer,"ThePlayer")
HX_STACK_ARG(DropsGrp,"DropsGrp")
HX_STACK_ARG(Bullets,"Bullets")
HX_STACK_ARG(Palette,"Palette")
{
	HX_STACK_LINE(30)
	this->sporeSpeed = (int)40;
	HX_STACK_LINE(29)
	this->palette = (int)0;
	HX_STACK_LINE(28)
	this->postShotTimer = (int)0;
	HX_STACK_LINE(26)
	this->rangeX = (int)64;
	HX_STACK_LINE(23)
	this->_HP = (int)2;
	HX_STACK_LINE(22)
	this->BULLET_SPEED = (int)100;
	HX_STACK_LINE(21)
	this->GUN_DELAY = (int)3;
	HX_STACK_LINE(20)
	this->GRAVITY = (int)9800;
	HX_STACK_LINE(19)
	this->XSPEED = (int)-30;
	HX_STACK_LINE(34)
	super::__construct(X,Y,ThePlayer,this->_HP,DropsGrp);
	HX_STACK_LINE(35)
	this->loadGraphic(HX_CSTRING("assets/images/mush.png"),true,(int)16,(int)16,null(),null());
	HX_STACK_LINE(36)
	this->set_width((int)16);
	HX_STACK_LINE(37)
	this->set_height((int)16);
	HX_STACK_LINE(39)
	this->palette = Palette;
	HX_STACK_LINE(41)
	this->ogX = X;
	HX_STACK_LINE(42)
	this->_bullets = Bullets;
	HX_STACK_LINE(43)
	this->_cooldown = (int)0;
	HX_STACK_LINE(45)
	this->set_facing((int)1);
	HX_STACK_LINE(46)
	this->set_flipX(true);
	HX_STACK_LINE(48)
	this->animation->add(HX_CSTRING("walk0"),Array_obj< int >::__new().Add((int)1).Add((int)0).Add((int)1).Add((int)2),(int)3,true);
	HX_STACK_LINE(49)
	this->animation->add(HX_CSTRING("walk1"),Array_obj< int >::__new().Add((int)5).Add((int)4).Add((int)5).Add((int)6),(int)3,true);
	HX_STACK_LINE(50)
	this->animation->add(HX_CSTRING("walk2"),Array_obj< int >::__new().Add((int)9).Add((int)8).Add((int)9).Add((int)10),(int)3,true);
	HX_STACK_LINE(51)
	this->animation->add(HX_CSTRING("walk3"),Array_obj< int >::__new().Add((int)13).Add((int)12).Add((int)13).Add((int)14),(int)3,true);
	HX_STACK_LINE(52)
	this->animation->add(HX_CSTRING("spore0"),Array_obj< int >::__new().Add((int)1).Add((int)3).Add((int)3).Add((int)3).Add((int)3),(int)6,false);
	HX_STACK_LINE(53)
	this->animation->add(HX_CSTRING("spore1"),Array_obj< int >::__new().Add((int)5).Add((int)7).Add((int)7).Add((int)7).Add((int)7),(int)6,false);
	HX_STACK_LINE(54)
	this->animation->add(HX_CSTRING("spore2"),Array_obj< int >::__new().Add((int)9).Add((int)11).Add((int)11).Add((int)11).Add((int)11),(int)6,false);
	HX_STACK_LINE(55)
	this->animation->add(HX_CSTRING("spore3"),Array_obj< int >::__new().Add((int)13).Add((int)15).Add((int)15).Add((int)15).Add((int)15),(int)6,false);
}
;
	return null();
}

//Mush_obj::~Mush_obj() { }

Dynamic Mush_obj::__CreateEmpty() { return  new Mush_obj; }
hx::ObjectPtr< Mush_obj > Mush_obj::__new(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup Bullets,int Palette)
{  hx::ObjectPtr< Mush_obj > result = new Mush_obj();
	result->__construct(X,Y,ThePlayer,DropsGrp,Bullets,Palette);
	return result;}

Dynamic Mush_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Mush_obj > result = new Mush_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

Void Mush_obj::update( ){
{
		HX_STACK_FRAME("enemies.Mush","update",0x1201ec72,"enemies.Mush.update","enemies/Mush.hx",61,0xb22f8b18)
		HX_STACK_THIS(this)
		HX_STACK_LINE(61)
		if ((this->isOnScreen(null()))){
			HX_STACK_LINE(63)
			if (((this->postShotTimer <= (int)0))){
				HX_STACK_LINE(65)
				this->velocity->set_x(this->XSPEED);
				HX_STACK_LINE(66)
				this->animation->play((HX_CSTRING("walk") + this->palette),null(),null());
				struct _Function_3_1{
					inline static bool Block( hx::ObjectPtr< ::enemies::Mush_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","enemies/Mush.hx",67,0xb22f8b18)
						{
							HX_STACK_LINE(67)
							Float _g = ::Math_obj::abs((__this->ogX - __this->x));		HX_STACK_VAR(_g,"_g");
							HX_STACK_LINE(67)
							return (_g >= __this->rangeX);
						}
						return null();
					}
				};
				HX_STACK_LINE(67)
				if (((  ((!(((((int(this->touching) & int((int)17))) > (int)0))))) ? bool(_Function_3_1::Block(this)) : bool(true) ))){
					HX_STACK_LINE(68)
					this->turnAround();
				}
			}
			HX_STACK_LINE(70)
			this->shoot();
			HX_STACK_LINE(72)
			this->changeColor();
			HX_STACK_LINE(74)
			if (((this->palette == (int)3))){
				HX_STACK_LINE(75)
				this->GUN_DELAY = .67;
			}
			else{
				HX_STACK_LINE(77)
				this->GUN_DELAY = (int)3;
			}
			HX_STACK_LINE(78)
			this->super::update();
		}
	}
return null();
}


Void Mush_obj::changeColor( ){
{
		HX_STACK_FRAME("enemies.Mush","changeColor",0xf5ecd6ca,"enemies.Mush.changeColor","enemies/Mush.hx",86,0xb22f8b18)
		HX_STACK_THIS(this)
		HX_STACK_LINE(86)
		if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("C")),(int)2))){
			HX_STACK_LINE(88)
			hx::AddEq(this->palette,(int)1);
			HX_STACK_LINE(89)
			if (((this->palette > (int)3))){
				HX_STACK_LINE(90)
				this->palette = (int)0;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Mush_obj,changeColor,(void))

Void Mush_obj::shoot( ){
{
		HX_STACK_FRAME("enemies.Mush","shoot",0x50019b96,"enemies.Mush.shoot","enemies/Mush.hx",96,0xb22f8b18)
		HX_STACK_THIS(this)
		HX_STACK_LINE(97)
		if (((this->_cooldown > this->GUN_DELAY))){
			HX_STACK_LINE(99)
			{
				HX_STACK_LINE(99)
				int _g = this->palette;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(99)
				switch( (int)(_g)){
					case (int)0: {
						HX_STACK_LINE(104)
						this->velocity->set_x((int)0);
						HX_STACK_LINE(105)
						this->animation->play((HX_CSTRING("spore") + this->palette),null(),null());
						HX_STACK_LINE(106)
						::weapons::Spore bullet = ::weapons::Spore_obj::__new(this->x,(this->y + (int)8),this->sporeSpeed,(int)256,(int)1,(int)256,(int)0);		HX_STACK_VAR(bullet,"bullet");
						HX_STACK_LINE(107)
						this->_bullets->add(bullet);
					}
					;break;
					case (int)1: {
						HX_STACK_LINE(112)
						this->velocity->set_x((int)0);
						HX_STACK_LINE(113)
						this->animation->play((HX_CSTRING("spore") + this->palette),null(),null());
						HX_STACK_LINE(114)
						::weapons::Spore bullet = ::weapons::Spore_obj::__new(this->x,this->y,(this->sporeSpeed * 0.5),((int)256 + this->facing),(int)1,(int)256,(int)1);		HX_STACK_VAR(bullet,"bullet");
						HX_STACK_LINE(115)
						::weapons::Spore bullet2 = ::weapons::Spore_obj::__new(this->x,this->y,(this->sporeSpeed * 0.75),((int)256 + this->facing),(int)1,(int)256,(int)1);		HX_STACK_VAR(bullet2,"bullet2");
						HX_STACK_LINE(116)
						::weapons::Spore bullet3 = ::weapons::Spore_obj::__new(this->x,this->y,this->sporeSpeed,((int)256 + this->facing),(int)1,(int)256,(int)1);		HX_STACK_VAR(bullet3,"bullet3");
						HX_STACK_LINE(117)
						this->_bullets->add(bullet);
						HX_STACK_LINE(118)
						this->_bullets->add(bullet2);
						HX_STACK_LINE(119)
						this->_bullets->add(bullet3);
					}
					;break;
					case (int)2: {
						HX_STACK_LINE(124)
						this->velocity->set_x((int)0);
						HX_STACK_LINE(125)
						this->animation->play((HX_CSTRING("spore") + this->palette),null(),null());
						HX_STACK_LINE(126)
						::weapons::Spore bullet = ::weapons::Spore_obj::__new(this->x,this->y,this->sporeSpeed,(int)257,(int)1,(int)256,(int)2);		HX_STACK_VAR(bullet,"bullet");
						HX_STACK_LINE(127)
						::weapons::Spore bullet2 = ::weapons::Spore_obj::__new(this->x,this->y,this->sporeSpeed,(int)272,(int)1,(int)256,(int)2);		HX_STACK_VAR(bullet2,"bullet2");
						HX_STACK_LINE(128)
						::weapons::Spore bullet3 = ::weapons::Spore_obj::__new(this->x,(this->y + (int)8),this->sporeSpeed,(int)256,(int)1,(int)256,(int)2);		HX_STACK_VAR(bullet3,"bullet3");
						HX_STACK_LINE(129)
						this->_bullets->add(bullet);
						HX_STACK_LINE(130)
						this->_bullets->add(bullet2);
						HX_STACK_LINE(131)
						this->_bullets->add(bullet3);
					}
					;break;
					case (int)3: {
						HX_STACK_LINE(136)
						int direction;		HX_STACK_VAR(direction,"direction");
						HX_STACK_LINE(137)
						if (((this->facing == (int)16))){
							HX_STACK_LINE(138)
							direction = (int)1;
						}
						else{
							HX_STACK_LINE(140)
							direction = (int)16;
						}
						HX_STACK_LINE(141)
						::weapons::Spore bullet = ::weapons::Spore_obj::__new((this->x - (int)8),this->y,this->sporeSpeed,((int)256 + direction),(int)1,(int)256,(int)3);		HX_STACK_VAR(bullet,"bullet");
						HX_STACK_LINE(142)
						this->_bullets->add(bullet);
					}
					;break;
				}
			}
			HX_STACK_LINE(147)
			this->_cooldown = (int)0;
			HX_STACK_LINE(148)
			if (((this->palette != (int)3))){
				HX_STACK_LINE(149)
				this->postShotTimer = .67;
			}
		}
		HX_STACK_LINE(151)
		hx::AddEq(this->_cooldown,::flixel::FlxG_obj::elapsed);
		HX_STACK_LINE(152)
		hx::SubEq(this->postShotTimer,::flixel::FlxG_obj::elapsed);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Mush_obj,shoot,(void))

Void Mush_obj::turnAround( ){
{
		HX_STACK_FRAME("enemies.Mush","turnAround",0xd895e293,"enemies.Mush.turnAround","enemies/Mush.hx",156,0xb22f8b18)
		HX_STACK_THIS(this)
		HX_STACK_LINE(157)
		this->XSPEED = -(this->XSPEED);
		HX_STACK_LINE(159)
		if (((this->facing == (int)16))){
			HX_STACK_LINE(161)
			this->set_facing((int)1);
			HX_STACK_LINE(162)
			this->set_flipX(true);
			HX_STACK_LINE(163)
			{
				HX_STACK_LINE(163)
				::enemies::Mush _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(163)
				_g->set_x((_g->x - (int)2));
			}
		}
		else{
			HX_STACK_LINE(167)
			this->set_facing((int)16);
			HX_STACK_LINE(168)
			this->set_flipX(false);
			HX_STACK_LINE(169)
			{
				HX_STACK_LINE(169)
				::enemies::Mush _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(169)
				_g->set_x((_g->x + (int)2));
			}
		}
		HX_STACK_LINE(171)
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Mush_obj,turnAround,(void))


Mush_obj::Mush_obj()
{
}

void Mush_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Mush);
	HX_MARK_MEMBER_NAME(XSPEED,"XSPEED");
	HX_MARK_MEMBER_NAME(GRAVITY,"GRAVITY");
	HX_MARK_MEMBER_NAME(GUN_DELAY,"GUN_DELAY");
	HX_MARK_MEMBER_NAME(BULLET_SPEED,"BULLET_SPEED");
	HX_MARK_MEMBER_NAME(_HP,"_HP");
	HX_MARK_MEMBER_NAME(_bullets,"_bullets");
	HX_MARK_MEMBER_NAME(_cooldown,"_cooldown");
	HX_MARK_MEMBER_NAME(rangeX,"rangeX");
	HX_MARK_MEMBER_NAME(ogX,"ogX");
	HX_MARK_MEMBER_NAME(postShotTimer,"postShotTimer");
	HX_MARK_MEMBER_NAME(palette,"palette");
	HX_MARK_MEMBER_NAME(sporeSpeed,"sporeSpeed");
	::enemies::EnemyTemplate_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Mush_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(XSPEED,"XSPEED");
	HX_VISIT_MEMBER_NAME(GRAVITY,"GRAVITY");
	HX_VISIT_MEMBER_NAME(GUN_DELAY,"GUN_DELAY");
	HX_VISIT_MEMBER_NAME(BULLET_SPEED,"BULLET_SPEED");
	HX_VISIT_MEMBER_NAME(_HP,"_HP");
	HX_VISIT_MEMBER_NAME(_bullets,"_bullets");
	HX_VISIT_MEMBER_NAME(_cooldown,"_cooldown");
	HX_VISIT_MEMBER_NAME(rangeX,"rangeX");
	HX_VISIT_MEMBER_NAME(ogX,"ogX");
	HX_VISIT_MEMBER_NAME(postShotTimer,"postShotTimer");
	HX_VISIT_MEMBER_NAME(palette,"palette");
	HX_VISIT_MEMBER_NAME(sporeSpeed,"sporeSpeed");
	::enemies::EnemyTemplate_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Mush_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_HP") ) { return _HP; }
		if (HX_FIELD_EQ(inName,"ogX") ) { return ogX; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"shoot") ) { return shoot_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"XSPEED") ) { return XSPEED; }
		if (HX_FIELD_EQ(inName,"rangeX") ) { return rangeX; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"GRAVITY") ) { return GRAVITY; }
		if (HX_FIELD_EQ(inName,"palette") ) { return palette; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_bullets") ) { return _bullets; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"GUN_DELAY") ) { return GUN_DELAY; }
		if (HX_FIELD_EQ(inName,"_cooldown") ) { return _cooldown; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sporeSpeed") ) { return sporeSpeed; }
		if (HX_FIELD_EQ(inName,"turnAround") ) { return turnAround_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"changeColor") ) { return changeColor_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"BULLET_SPEED") ) { return BULLET_SPEED; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"postShotTimer") ) { return postShotTimer; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Mush_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_HP") ) { _HP=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ogX") ) { ogX=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"XSPEED") ) { XSPEED=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rangeX") ) { rangeX=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"GRAVITY") ) { GRAVITY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"palette") ) { palette=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_bullets") ) { _bullets=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"GUN_DELAY") ) { GUN_DELAY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_cooldown") ) { _cooldown=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sporeSpeed") ) { sporeSpeed=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"BULLET_SPEED") ) { BULLET_SPEED=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"postShotTimer") ) { postShotTimer=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Mush_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("XSPEED"));
	outFields->push(HX_CSTRING("GRAVITY"));
	outFields->push(HX_CSTRING("GUN_DELAY"));
	outFields->push(HX_CSTRING("BULLET_SPEED"));
	outFields->push(HX_CSTRING("_HP"));
	outFields->push(HX_CSTRING("_bullets"));
	outFields->push(HX_CSTRING("_cooldown"));
	outFields->push(HX_CSTRING("rangeX"));
	outFields->push(HX_CSTRING("ogX"));
	outFields->push(HX_CSTRING("postShotTimer"));
	outFields->push(HX_CSTRING("palette"));
	outFields->push(HX_CSTRING("sporeSpeed"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Mush_obj,XSPEED),HX_CSTRING("XSPEED")},
	{hx::fsInt,(int)offsetof(Mush_obj,GRAVITY),HX_CSTRING("GRAVITY")},
	{hx::fsFloat,(int)offsetof(Mush_obj,GUN_DELAY),HX_CSTRING("GUN_DELAY")},
	{hx::fsInt,(int)offsetof(Mush_obj,BULLET_SPEED),HX_CSTRING("BULLET_SPEED")},
	{hx::fsInt,(int)offsetof(Mush_obj,_HP),HX_CSTRING("_HP")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(Mush_obj,_bullets),HX_CSTRING("_bullets")},
	{hx::fsFloat,(int)offsetof(Mush_obj,_cooldown),HX_CSTRING("_cooldown")},
	{hx::fsInt,(int)offsetof(Mush_obj,rangeX),HX_CSTRING("rangeX")},
	{hx::fsFloat,(int)offsetof(Mush_obj,ogX),HX_CSTRING("ogX")},
	{hx::fsFloat,(int)offsetof(Mush_obj,postShotTimer),HX_CSTRING("postShotTimer")},
	{hx::fsInt,(int)offsetof(Mush_obj,palette),HX_CSTRING("palette")},
	{hx::fsInt,(int)offsetof(Mush_obj,sporeSpeed),HX_CSTRING("sporeSpeed")},
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
	HX_CSTRING("rangeX"),
	HX_CSTRING("ogX"),
	HX_CSTRING("postShotTimer"),
	HX_CSTRING("palette"),
	HX_CSTRING("sporeSpeed"),
	HX_CSTRING("update"),
	HX_CSTRING("changeColor"),
	HX_CSTRING("shoot"),
	HX_CSTRING("turnAround"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Mush_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Mush_obj::__mClass,"__mClass");
};

#endif

Class Mush_obj::__mClass;

void Mush_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("enemies.Mush"), hx::TCanCast< Mush_obj> ,sStaticFields,sMemberFields,
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

void Mush_obj::__boot()
{
}

} // end namespace enemies

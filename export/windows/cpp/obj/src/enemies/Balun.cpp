#include <hxcpp.h>

#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_enemies_Balun
#include <enemies/Balun.h>
#endif
#ifndef INCLUDED_enemies_BalunString
#include <enemies/BalunString.h>
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
namespace enemies{

Void Balun_obj::__construct(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup Enemies,::flixel::group::FlxGroup Bullets,int Color)
{
HX_STACK_FRAME("enemies.Balun","new",0xbfb48f70,"enemies.Balun.new","enemies/Balun.hx",13,0x5c699701)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
HX_STACK_ARG(ThePlayer,"ThePlayer")
HX_STACK_ARG(DropsGrp,"DropsGrp")
HX_STACK_ARG(Enemies,"Enemies")
HX_STACK_ARG(Bullets,"Bullets")
HX_STACK_ARG(Color,"Color")
{
	HX_STACK_LINE(36)
	this->_cooldown = (int)0;
	HX_STACK_LINE(34)
	this->BULLET_SPEED = (int)100;
	HX_STACK_LINE(33)
	this->GUN_DELAY = 1.5;
	HX_STACK_LINE(31)
	this->_HP = (int)20;
	HX_STACK_LINE(30)
	this->GRAVITY = (int)0;
	HX_STACK_LINE(29)
	this->XSPEED = (int)35;
	HX_STACK_LINE(26)
	this->colorString = HX_CSTRING("grey");
	HX_STACK_LINE(25)
	this->palette = (int)0;
	HX_STACK_LINE(42)
	super::__construct(X,Y,ThePlayer,this->_HP,DropsGrp);
	HX_STACK_LINE(44)
	this->palette = Color;
	HX_STACK_LINE(45)
	::enemies::BalunString _g = ::enemies::BalunString_obj::__new(this->x,(this->y + (int)16),ThePlayer,DropsGrp);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(45)
	this->tail = _g;
	HX_STACK_LINE(46)
	Enemies->add(this->tail);
	HX_STACK_LINE(48)
	this->loadGraphic(HX_CSTRING("assets/images/balun.png"),true,(int)16,(int)16,null(),null());
	HX_STACK_LINE(49)
	this->set_width((int)16);
	HX_STACK_LINE(50)
	this->set_height((int)16);
	HX_STACK_LINE(52)
	this->_bullets = Bullets;
	HX_STACK_LINE(54)
	{
		HX_STACK_LINE(54)
		int _g1 = this->palette;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(54)
		switch( (int)(_g1)){
			case (int)0: {
				HX_STACK_LINE(57)
				this->colorString = HX_CSTRING("grey");
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(59)
				this->colorString = HX_CSTRING("yellow");
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(61)
				this->colorString = HX_CSTRING("cyan");
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(63)
				this->colorString = HX_CSTRING("magenta");
			}
			;break;
		}
	}
	HX_STACK_LINE(67)
	this->animation->add(HX_CSTRING("grey"),Array_obj< int >::__new().Add((int)0),null(),null());
	HX_STACK_LINE(68)
	this->animation->add(HX_CSTRING("grey2"),Array_obj< int >::__new().Add((int)1),null(),null());
	HX_STACK_LINE(69)
	this->animation->add(HX_CSTRING("yellow"),Array_obj< int >::__new().Add((int)2),null(),null());
	HX_STACK_LINE(70)
	this->animation->add(HX_CSTRING("yellow2"),Array_obj< int >::__new().Add((int)3),null(),null());
	HX_STACK_LINE(71)
	this->animation->add(HX_CSTRING("cyan"),Array_obj< int >::__new().Add((int)4),null(),null());
	HX_STACK_LINE(72)
	this->animation->add(HX_CSTRING("cyan2"),Array_obj< int >::__new().Add((int)5),null(),null());
	HX_STACK_LINE(73)
	this->animation->add(HX_CSTRING("magenta"),Array_obj< int >::__new().Add((int)6),null(),null());
	HX_STACK_LINE(74)
	this->animation->add(HX_CSTRING("magenta2"),Array_obj< int >::__new().Add((int)7),null(),null());
}
;
	return null();
}

//Balun_obj::~Balun_obj() { }

Dynamic Balun_obj::__CreateEmpty() { return  new Balun_obj; }
hx::ObjectPtr< Balun_obj > Balun_obj::__new(Float X,Float Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup Enemies,::flixel::group::FlxGroup Bullets,int Color)
{  hx::ObjectPtr< Balun_obj > result = new Balun_obj();
	result->__construct(X,Y,ThePlayer,DropsGrp,Enemies,Bullets,Color);
	return result;}

Dynamic Balun_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Balun_obj > result = new Balun_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6]);
	return result;}

Void Balun_obj::update( ){
{
		HX_STACK_FRAME("enemies.Balun","update",0xedf990f9,"enemies.Balun.update","enemies/Balun.hx",79,0x5c699701)
		HX_STACK_THIS(this)
		HX_STACK_LINE(79)
		if ((this->isOnScreen(null()))){
			HX_STACK_LINE(85)
			if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("C")),(int)2))){
				HX_STACK_LINE(87)
				hx::AddEq(this->palette,(int)1);
				HX_STACK_LINE(88)
				if (((this->palette > (int)3))){
					HX_STACK_LINE(89)
					this->palette = (int)0;
				}
				HX_STACK_LINE(90)
				{
					HX_STACK_LINE(90)
					int _g = this->palette;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(90)
					switch( (int)(_g)){
						case (int)0: {
							HX_STACK_LINE(93)
							this->colorString = HX_CSTRING("grey");
						}
						;break;
						case (int)1: {
							HX_STACK_LINE(95)
							this->colorString = HX_CSTRING("yellow");
						}
						;break;
						case (int)2: {
							HX_STACK_LINE(97)
							this->colorString = HX_CSTRING("cyan");
						}
						;break;
						case (int)3: {
							HX_STACK_LINE(99)
							this->colorString = HX_CSTRING("magenta");
						}
						;break;
					}
				}
			}
			HX_STACK_LINE(111)
			Float _g = this->velocity->set_y((int)0);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(111)
			this->velocity->set_x(_g);
			HX_STACK_LINE(113)
			Float xdistance = (this->_player->x - this->x);		HX_STACK_VAR(xdistance,"xdistance");
			HX_STACK_LINE(114)
			Float ydistance = (this->_player->y - this->y);		HX_STACK_VAR(ydistance,"ydistance");
			HX_STACK_LINE(115)
			Float distancesquared = ((xdistance * xdistance) + (ydistance * ydistance));		HX_STACK_VAR(distancesquared,"distancesquared");
			HX_STACK_LINE(116)
			this->acceleration->set_y(this->GRAVITY);
			HX_STACK_LINE(119)
			if (((distancesquared < (int)24000))){
				HX_STACK_LINE(122)
				int _g1 = ::Math_obj::floor(this->_player->x);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(122)
				if (((_g1 < this->x))){
					HX_STACK_LINE(125)
					this->set_facing((int)16);
					HX_STACK_LINE(126)
					this->set_flipX(false);
					HX_STACK_LINE(127)
					{
						HX_STACK_LINE(127)
						::String _g2 = this->colorString;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(127)
						::String _switch_1 = (_g2);
						if (  ( _switch_1==HX_CSTRING("grey"))){
							HX_STACK_LINE(131)
							{
								HX_STACK_LINE(131)
								::enemies::Balun _g11 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g11,"_g11");
								HX_STACK_LINE(131)
								_g11->set_x((_g11->x - (int)1));
							}
							HX_STACK_LINE(132)
							this->tail->_moving = (int)16;
						}
						else if (  ( _switch_1==HX_CSTRING("yellow"))){
							HX_STACK_LINE(136)
							{
								HX_STACK_LINE(136)
								::enemies::Balun _g11 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g11,"_g11");
								HX_STACK_LINE(136)
								_g11->set_x((_g11->x - (int)1));
							}
							HX_STACK_LINE(137)
							this->tail->_moving = (int)16;
						}
						else if (  ( _switch_1==HX_CSTRING("cyan"))){
							HX_STACK_LINE(141)
							{
								HX_STACK_LINE(141)
								::enemies::Balun _g11 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g11,"_g11");
								HX_STACK_LINE(141)
								_g11->set_x((_g11->x + (int)1));
							}
							HX_STACK_LINE(142)
							this->tail->_moving = (int)1;
							HX_STACK_LINE(143)
							this->shoot(this->_player);
						}
						else if (  ( _switch_1==HX_CSTRING("magenta"))){
							HX_STACK_LINE(147)
							{
								HX_STACK_LINE(147)
								::enemies::Balun _g11 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g11,"_g11");
								HX_STACK_LINE(147)
								_g11->set_x((_g11->x - (int)1));
							}
							HX_STACK_LINE(148)
							this->tail->_moving = (int)16;
							HX_STACK_LINE(149)
							this->shoot(this->_player);
						}
					}
				}
				else{
					HX_STACK_LINE(153)
					int _g2 = ::Math_obj::floor(this->_player->x);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(153)
					if (((_g2 > this->x))){
						HX_STACK_LINE(155)
						this->set_facing((int)1);
						HX_STACK_LINE(156)
						this->set_flipX(true);
						HX_STACK_LINE(157)
						{
							HX_STACK_LINE(157)
							::String _g3 = this->colorString;		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(157)
							::String _switch_2 = (_g3);
							if (  ( _switch_2==HX_CSTRING("grey"))){
								HX_STACK_LINE(161)
								{
									HX_STACK_LINE(161)
									::enemies::Balun _g11 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g11,"_g11");
									HX_STACK_LINE(161)
									_g11->set_x((_g11->x + (int)1));
								}
								HX_STACK_LINE(162)
								this->tail->_moving = (int)1;
							}
							else if (  ( _switch_2==HX_CSTRING("yellow"))){
								HX_STACK_LINE(166)
								{
									HX_STACK_LINE(166)
									::enemies::Balun _g11 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g11,"_g11");
									HX_STACK_LINE(166)
									_g11->set_x((_g11->x + (int)1));
								}
								HX_STACK_LINE(167)
								this->tail->_moving = (int)1;
							}
							else if (  ( _switch_2==HX_CSTRING("cyan"))){
								HX_STACK_LINE(171)
								{
									HX_STACK_LINE(171)
									::enemies::Balun _g11 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g11,"_g11");
									HX_STACK_LINE(171)
									_g11->set_x((_g11->x - (int)1));
								}
								HX_STACK_LINE(172)
								this->tail->_moving = (int)16;
								HX_STACK_LINE(173)
								this->shoot(this->_player);
							}
							else if (  ( _switch_2==HX_CSTRING("magenta"))){
								HX_STACK_LINE(177)
								{
									HX_STACK_LINE(177)
									::enemies::Balun _g11 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g11,"_g11");
									HX_STACK_LINE(177)
									_g11->set_x((_g11->x + (int)1));
								}
								HX_STACK_LINE(178)
								this->tail->_moving = (int)1;
							}
						}
					}
					else{
						HX_STACK_LINE(183)
						this->tail->_moving = (int)0;
					}
				}
				HX_STACK_LINE(186)
				this->idealY = (this->_player->y - (int)8);
				HX_STACK_LINE(187)
				if (((this->colorString == HX_CSTRING("magenta")))){
					HX_STACK_LINE(188)
					this->idealY = (this->_player->y - (int)40);
				}
				HX_STACK_LINE(190)
				if (((this->y > this->idealY))){
					HX_STACK_LINE(191)
					::enemies::Balun _g2 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(191)
					_g2->set_y((_g2->y - (int)1));
				}
				else{
					HX_STACK_LINE(192)
					if (((this->y < this->idealY))){
						HX_STACK_LINE(193)
						::enemies::Balun _g2 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(193)
						_g2->set_y((_g2->y + (int)1));
					}
				}
			}
			HX_STACK_LINE(204)
			this->resolveAnims();
			HX_STACK_LINE(206)
			hx::AddEq(this->_cooldown,::flixel::FlxG_obj::elapsed);
			HX_STACK_LINE(208)
			if ((this->tail->alive)){
				HX_STACK_LINE(210)
				this->tail->set_x(this->x);
				HX_STACK_LINE(211)
				this->tail->set_y((this->y + (int)16));
			}
			HX_STACK_LINE(214)
			this->super::update();
		}
	}
return null();
}


Void Balun_obj::shoot( ::Player P){
{
		HX_STACK_FRAME("enemies.Balun","shoot",0x648224ef,"enemies.Balun.shoot","enemies/Balun.hx",219,0x5c699701)
		HX_STACK_THIS(this)
		HX_STACK_ARG(P,"P")
		HX_STACK_LINE(221)
		int bulletX = ::Math_obj::floor(this->x);		HX_STACK_VAR(bulletX,"bulletX");
		HX_STACK_LINE(222)
		int bulletY = ::Math_obj::floor((this->y + (int)4));		HX_STACK_VAR(bulletY,"bulletY");
		HX_STACK_LINE(224)
		if (((this->_cooldown > this->GUN_DELAY))){
			HX_STACK_LINE(227)
			if (((this->colorString == HX_CSTRING("cyan")))){
				HX_STACK_LINE(229)
				if (((P->x < this->x))){
					HX_STACK_LINE(231)
					::weapons::Bullet bullet = ::weapons::Bullet_obj::__new((this->x + (int)8),(this->y + (int)8),(int)500,(int)1,(int)1,(int)256);		HX_STACK_VAR(bullet,"bullet");
					HX_STACK_LINE(232)
					this->_bullets->add(bullet);
				}
				else{
					HX_STACK_LINE(236)
					::weapons::Bullet bullet = ::weapons::Bullet_obj::__new((this->x + (int)8),(this->y + (int)8),(int)500,(int)16,(int)1,(int)256);		HX_STACK_VAR(bullet,"bullet");
					HX_STACK_LINE(237)
					this->_bullets->add(bullet);
				}
			}
			else{
				HX_STACK_LINE(240)
				if (((this->colorString == HX_CSTRING("magenta")))){
					HX_STACK_LINE(242)
					::weapons::Bullet bullet = ::weapons::Bullet_obj::__new((this->x + (int)8),(this->y + (int)8),(int)500,(int)4096,(int)1,(int)256);		HX_STACK_VAR(bullet,"bullet");
					HX_STACK_LINE(243)
					this->_bullets->add(bullet);
				}
			}
			HX_STACK_LINE(247)
			this->_cooldown = (int)0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Balun_obj,shoot,(void))

Void Balun_obj::resolveAnims( ){
{
		HX_STACK_FRAME("enemies.Balun","resolveAnims",0x441feda6,"enemies.Balun.resolveAnims","enemies/Balun.hx",256,0x5c699701)
		HX_STACK_THIS(this)
		HX_STACK_LINE(256)
		if (((bool((this->velocity->x == (int)0)) && bool((this->velocity->y == (int)0))))){
			HX_STACK_LINE(258)
			this->animation->play(this->colorString,null(),null());
		}
		else{
			HX_STACK_LINE(262)
			this->animation->play((this->colorString + HX_CSTRING("2")),null(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Balun_obj,resolveAnims,(void))

Void Balun_obj::kill( ){
{
		HX_STACK_FRAME("enemies.Balun","kill",0xfc504e8e,"enemies.Balun.kill","enemies/Balun.hx",267,0x5c699701)
		HX_STACK_THIS(this)
		HX_STACK_LINE(268)
		this->tail->set_alive(false);
		HX_STACK_LINE(269)
		this->tail->set_exists(false);
		HX_STACK_LINE(270)
		this->super::kill();
	}
return null();
}



Balun_obj::Balun_obj()
{
}

void Balun_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Balun);
	HX_MARK_MEMBER_NAME(palette,"palette");
	HX_MARK_MEMBER_NAME(colorString,"colorString");
	HX_MARK_MEMBER_NAME(idealY,"idealY");
	HX_MARK_MEMBER_NAME(XSPEED,"XSPEED");
	HX_MARK_MEMBER_NAME(GRAVITY,"GRAVITY");
	HX_MARK_MEMBER_NAME(_HP,"_HP");
	HX_MARK_MEMBER_NAME(GUN_DELAY,"GUN_DELAY");
	HX_MARK_MEMBER_NAME(BULLET_SPEED,"BULLET_SPEED");
	HX_MARK_MEMBER_NAME(_bullets,"_bullets");
	HX_MARK_MEMBER_NAME(_cooldown,"_cooldown");
	HX_MARK_MEMBER_NAME(tail,"tail");
	::enemies::EnemyTemplate_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Balun_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(palette,"palette");
	HX_VISIT_MEMBER_NAME(colorString,"colorString");
	HX_VISIT_MEMBER_NAME(idealY,"idealY");
	HX_VISIT_MEMBER_NAME(XSPEED,"XSPEED");
	HX_VISIT_MEMBER_NAME(GRAVITY,"GRAVITY");
	HX_VISIT_MEMBER_NAME(_HP,"_HP");
	HX_VISIT_MEMBER_NAME(GUN_DELAY,"GUN_DELAY");
	HX_VISIT_MEMBER_NAME(BULLET_SPEED,"BULLET_SPEED");
	HX_VISIT_MEMBER_NAME(_bullets,"_bullets");
	HX_VISIT_MEMBER_NAME(_cooldown,"_cooldown");
	HX_VISIT_MEMBER_NAME(tail,"tail");
	::enemies::EnemyTemplate_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Balun_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_HP") ) { return _HP; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"tail") ) { return tail; }
		if (HX_FIELD_EQ(inName,"kill") ) { return kill_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"shoot") ) { return shoot_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"idealY") ) { return idealY; }
		if (HX_FIELD_EQ(inName,"XSPEED") ) { return XSPEED; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"palette") ) { return palette; }
		if (HX_FIELD_EQ(inName,"GRAVITY") ) { return GRAVITY; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_bullets") ) { return _bullets; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"GUN_DELAY") ) { return GUN_DELAY; }
		if (HX_FIELD_EQ(inName,"_cooldown") ) { return _cooldown; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"colorString") ) { return colorString; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"BULLET_SPEED") ) { return BULLET_SPEED; }
		if (HX_FIELD_EQ(inName,"resolveAnims") ) { return resolveAnims_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Balun_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_HP") ) { _HP=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"tail") ) { tail=inValue.Cast< ::enemies::BalunString >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"idealY") ) { idealY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"XSPEED") ) { XSPEED=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"palette") ) { palette=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"GRAVITY") ) { GRAVITY=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_bullets") ) { _bullets=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"GUN_DELAY") ) { GUN_DELAY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_cooldown") ) { _cooldown=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"colorString") ) { colorString=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"BULLET_SPEED") ) { BULLET_SPEED=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Balun_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("palette"));
	outFields->push(HX_CSTRING("colorString"));
	outFields->push(HX_CSTRING("idealY"));
	outFields->push(HX_CSTRING("XSPEED"));
	outFields->push(HX_CSTRING("GRAVITY"));
	outFields->push(HX_CSTRING("_HP"));
	outFields->push(HX_CSTRING("GUN_DELAY"));
	outFields->push(HX_CSTRING("BULLET_SPEED"));
	outFields->push(HX_CSTRING("_bullets"));
	outFields->push(HX_CSTRING("_cooldown"));
	outFields->push(HX_CSTRING("tail"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Balun_obj,palette),HX_CSTRING("palette")},
	{hx::fsString,(int)offsetof(Balun_obj,colorString),HX_CSTRING("colorString")},
	{hx::fsFloat,(int)offsetof(Balun_obj,idealY),HX_CSTRING("idealY")},
	{hx::fsInt,(int)offsetof(Balun_obj,XSPEED),HX_CSTRING("XSPEED")},
	{hx::fsInt,(int)offsetof(Balun_obj,GRAVITY),HX_CSTRING("GRAVITY")},
	{hx::fsInt,(int)offsetof(Balun_obj,_HP),HX_CSTRING("_HP")},
	{hx::fsFloat,(int)offsetof(Balun_obj,GUN_DELAY),HX_CSTRING("GUN_DELAY")},
	{hx::fsInt,(int)offsetof(Balun_obj,BULLET_SPEED),HX_CSTRING("BULLET_SPEED")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(Balun_obj,_bullets),HX_CSTRING("_bullets")},
	{hx::fsFloat,(int)offsetof(Balun_obj,_cooldown),HX_CSTRING("_cooldown")},
	{hx::fsObject /*::enemies::BalunString*/ ,(int)offsetof(Balun_obj,tail),HX_CSTRING("tail")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("palette"),
	HX_CSTRING("colorString"),
	HX_CSTRING("idealY"),
	HX_CSTRING("XSPEED"),
	HX_CSTRING("GRAVITY"),
	HX_CSTRING("_HP"),
	HX_CSTRING("GUN_DELAY"),
	HX_CSTRING("BULLET_SPEED"),
	HX_CSTRING("_bullets"),
	HX_CSTRING("_cooldown"),
	HX_CSTRING("tail"),
	HX_CSTRING("update"),
	HX_CSTRING("shoot"),
	HX_CSTRING("resolveAnims"),
	HX_CSTRING("kill"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Balun_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Balun_obj::__mClass,"__mClass");
};

#endif

Class Balun_obj::__mClass;

void Balun_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("enemies.Balun"), hx::TCanCast< Balun_obj> ,sStaticFields,sMemberFields,
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

void Balun_obj::__boot()
{
}

} // end namespace enemies

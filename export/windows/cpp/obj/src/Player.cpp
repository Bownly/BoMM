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
#ifndef INCLUDED_flixel_tweens_FlxEase
#include <flixel/tweens/FlxEase.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_VarTween
#include <flixel/tweens/misc/VarTween.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_weapons_EightWayWeapon
#include <weapons/EightWayWeapon.h>
#endif
#ifndef INCLUDED_weapons_MagentaWeapon
#include <weapons/MagentaWeapon.h>
#endif
#ifndef INCLUDED_weapons_WeaponTemplate
#include <weapons/WeaponTemplate.h>
#endif
#ifndef INCLUDED_weapons_YellowWeapon
#include <weapons/YellowWeapon.h>
#endif

Void Player_obj::__construct(hx::Null< int >  __o_inX,hx::Null< int >  __o_inY,::flixel::group::FlxTypedGroup Bullets)
{
HX_STACK_FRAME("Player","new",0x8d5554f3,"Player.new","Player.hx",21,0xa27fc9dd)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_inX,"inX")
HX_STACK_ARG(__o_inY,"inY")
HX_STACK_ARG(Bullets,"Bullets")
int inX = __o_inX.Default(0);
int inY = __o_inY.Default(0);
{
	HX_STACK_LINE(61)
	this->canMove = true;
	HX_STACK_LINE(59)
	this->hurtTimer = (int)0;
	HX_STACK_LINE(57)
	this->climbing = false;
	HX_STACK_LINE(56)
	this->touchingLadder = false;
	HX_STACK_LINE(52)
	this->postShotTimer = (int)0;
	HX_STACK_LINE(51)
	this->shootingString = HX_CSTRING("");
	HX_STACK_LINE(39)
	this->bulletCount = (int)0;
	HX_STACK_LINE(38)
	this->maxBullets = (int)3;
	HX_STACK_LINE(35)
	this->luck = (int)5;
	HX_STACK_LINE(34)
	this->damage = (int)1;
	HX_STACK_LINE(33)
	this->shotRange = (int)10;
	HX_STACK_LINE(32)
	this->maxJumps = (int)2;
	HX_STACK_LINE(31)
	this->maxHP = (int)3;
	HX_STACK_LINE(28)
	this->isSliding = false;
	HX_STACK_LINE(27)
	this->hp = (int)3;
	HX_STACK_LINE(26)
	this->remainingJumps = (int)2;
	HX_STACK_LINE(25)
	this->xSpeed = (int)150;
	HX_STACK_LINE(24)
	this->GRAVITY = (int)690;
	HX_STACK_LINE(23)
	this->jumpPower = (int)2250;
	HX_STACK_LINE(66)
	super::__construct(inX,inY,null());
	HX_STACK_LINE(68)
	::weapons::WeaponTemplate _g = ::weapons::WeaponTemplate_obj::__new(HX_CSTRING("pea"),this->bulletArray);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(68)
	this->weapon1 = _g;
	HX_STACK_LINE(69)
	::weapons::EightWayWeapon _g1 = ::weapons::EightWayWeapon_obj::__new(HX_CSTRING("cyan"),this->bulletArray);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(69)
	this->weapon2 = _g1;
	HX_STACK_LINE(70)
	::weapons::YellowWeapon _g2 = ::weapons::YellowWeapon_obj::__new(HX_CSTRING("yellow"),this->bulletArray);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(70)
	this->weapon3 = _g2;
	HX_STACK_LINE(71)
	::weapons::MagentaWeapon _g3 = ::weapons::MagentaWeapon_obj::__new(HX_CSTRING("magenta"),this->bulletArray);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(71)
	this->weapon4 = _g3;
	HX_STACK_LINE(73)
	this->weaponArray = Array_obj< ::Dynamic >::__new().Add(this->weapon1).Add(this->weapon2).Add(this->weapon3).Add(this->weapon4);
	HX_STACK_LINE(74)
	this->curWeaponLoc = (int)0;
	HX_STACK_LINE(75)
	this->curWeapon = this->weaponArray->__get(this->curWeaponLoc).StaticCast< ::weapons::WeaponTemplate >();
	HX_STACK_LINE(78)
	this->loadGraphic(HX_CSTRING("assets/images/mm.png"),true,(int)32,(int)32,null(),null());
	HX_STACK_LINE(79)
	this->set_width((int)16);
	HX_STACK_LINE(80)
	this->set_height((int)22);
	HX_STACK_LINE(81)
	::flixel::util::FlxPoint _g4 = ::flixel::util::FlxPoint_obj::__new((int)8,(int)4);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(81)
	this->offset = _g4;
	HX_STACK_LINE(83)
	this->bulletArray = Bullets;
	HX_STACK_LINE(85)
	this->velocity->set_y(this->GRAVITY);
	HX_STACK_LINE(87)
	this->maxVelocity->set((int)200,(int)200);
	HX_STACK_LINE(88)
	this->drag->set((int)1600,(int)1600);
	HX_STACK_LINE(90)
	this->animation->add(HX_CSTRING("walk"),Array_obj< int >::__new().Add((int)3).Add((int)2).Add((int)3).Add((int)4),(int)10,true);
	HX_STACK_LINE(91)
	this->animation->add(HX_CSTRING("idle"),Array_obj< int >::__new().Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)1),(int)3,true);
	HX_STACK_LINE(92)
	this->animation->add(HX_CSTRING("jump"),Array_obj< int >::__new().Add((int)5),(int)15,true);
	HX_STACK_LINE(93)
	this->animation->add(HX_CSTRING("fall"),Array_obj< int >::__new().Add((int)6),(int)15,true);
	HX_STACK_LINE(94)
	this->animation->add(HX_CSTRING("hurt"),Array_obj< int >::__new().Add((int)5),(int)15,true);
	HX_STACK_LINE(96)
	this->animation->add(HX_CSTRING("walk_shoot"),Array_obj< int >::__new().Add((int)10).Add((int)9).Add((int)10).Add((int)11),(int)10,true);
	HX_STACK_LINE(97)
	this->animation->add(HX_CSTRING("idle_shoot"),Array_obj< int >::__new().Add((int)8),(int)3,true);
	HX_STACK_LINE(98)
	this->animation->add(HX_CSTRING("jump_shoot"),Array_obj< int >::__new().Add((int)13),(int)15,true);
	HX_STACK_LINE(99)
	this->animation->add(HX_CSTRING("fall_shoot"),Array_obj< int >::__new().Add((int)13),(int)15,true);
}
;
	return null();
}

//Player_obj::~Player_obj() { }

Dynamic Player_obj::__CreateEmpty() { return  new Player_obj; }
hx::ObjectPtr< Player_obj > Player_obj::__new(hx::Null< int >  __o_inX,hx::Null< int >  __o_inY,::flixel::group::FlxTypedGroup Bullets)
{  hx::ObjectPtr< Player_obj > result = new Player_obj();
	result->__construct(__o_inX,__o_inY,Bullets);
	return result;}

Dynamic Player_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Player_obj > result = new Player_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Player_obj::update( ){
{
		HX_STACK_FRAME("Player","update",0xf1f8df56,"Player.update","Player.hx",159,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(161)
		this->velocity->set_x((int)0);
		HX_STACK_LINE(163)
		if (((this->canMove == true))){
			HX_STACK_LINE(165)
			if (((this->hp <= (int)0))){
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",166,0xa27fc9dd)
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("alpha") , (int)0,false);
							return __result;
						}
						return null();
					}
				};
				struct _Function_3_2{
					inline static Dynamic Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",166,0xa27fc9dd)
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("ease") , ::flixel::tweens::FlxEase_obj::circOut_dyn(),false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(166)
				::flixel::tweens::FlxTween_obj::tween(hx::ObjectPtr<OBJ_>(this),_Function_3_1::Block(),.33,_Function_3_2::Block());
			}
			HX_STACK_LINE(168)
			if (((this->hurtTimer > (int)0))){
				HX_STACK_LINE(169)
				hx::SubEq(this->hurtTimer,::flixel::FlxG_obj::elapsed);
			}
			HX_STACK_LINE(171)
			if ((this->climbing)){
				HX_STACK_LINE(172)
				this->acceleration->set_y((int)0);
			}
			else{
				HX_STACK_LINE(174)
				this->acceleration->set_y(this->GRAVITY);
			}
			HX_STACK_LINE(176)
			if (((((int(this->touching) & int((int)4096))) > (int)0))){
				HX_STACK_LINE(177)
				this->remainingJumps = this->maxJumps;
			}
			HX_STACK_LINE(179)
			if (((this->isSliding == true))){
				HX_STACK_LINE(181)
				{
					HX_STACK_LINE(181)
					::Player _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(181)
					_g->set_x((_g->x + (int)100));
				}
				HX_STACK_LINE(182)
				this->isSliding = false;
			}
			HX_STACK_LINE(185)
			this->playerInputs();
			HX_STACK_LINE(186)
			this->resolveAnimations();
		}
		HX_STACK_LINE(189)
		this->super::update();
	}
return null();
}


Void Player_obj::enterBossDoor( ){
{
		HX_STACK_FRAME("Player","enterBossDoor",0x04599b46,"Player.enterBossDoor","Player.hx",193,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(194)
		this->canMove = false;
		HX_STACK_LINE(195)
		{
			HX_STACK_LINE(195)
			::Player _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(195)
			_g->set_x((_g->x + (int)32));
		}
		HX_STACK_LINE(196)
		this->canMove = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Player_obj,enterBossDoor,(void))

Void Player_obj::playerInputs( ){
{
		HX_STACK_FRAME("Player","playerInputs",0xb3503477,"Player.playerInputs","Player.hx",200,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(201)
		if (((  ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("RIGHT")).Add(HX_CSTRING("D")),(int)1))) ? bool((this->climbing == false)) : bool(false) ))){
			HX_STACK_LINE(203)
			this->velocity->set_x(this->xSpeed);
			HX_STACK_LINE(204)
			this->set_flipX(false);
			HX_STACK_LINE(205)
			this->set_facing((int)16);
			HX_STACK_LINE(206)
			this->climbing = false;
		}
		else{
			HX_STACK_LINE(208)
			if (((  ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("LEFT")).Add(HX_CSTRING("A")),(int)1))) ? bool((this->climbing == false)) : bool(false) ))){
				HX_STACK_LINE(210)
				this->velocity->set_x(-(this->xSpeed));
				HX_STACK_LINE(211)
				this->set_flipX(true);
				HX_STACK_LINE(212)
				this->set_facing((int)1);
				HX_STACK_LINE(213)
				this->climbing = false;
			}
		}
		HX_STACK_LINE(216)
		if (((  ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("UP")).Add(HX_CSTRING("W")),(int)1))) ? bool((this->touchingLadder == true)) : bool(false) ))){
			HX_STACK_LINE(218)
			this->velocity->set_y((int)-100);
			HX_STACK_LINE(219)
			this->climbing = true;
			HX_STACK_LINE(220)
			this->remainingJumps = this->maxJumps;
		}
		HX_STACK_LINE(223)
		if (((  ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("DOWN")).Add(HX_CSTRING("S")),(int)1))) ? bool((this->touchingLadder == true)) : bool(false) ))){
			HX_STACK_LINE(225)
			this->velocity->set_y((int)100);
			HX_STACK_LINE(226)
			this->climbing = true;
			HX_STACK_LINE(227)
			this->remainingJumps = this->maxJumps;
		}
		HX_STACK_LINE(230)
		if (((  (((  ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("DOWN")).Add(HX_CSTRING("S")),(int)1))) ? bool(::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("J")),(int)2)) : bool(false) ))) ? bool((((int(this->touching) & int((int)4096))) > (int)0)) : bool(false) ))){
			HX_STACK_LINE(232)
			this->isSliding = true;
		}
		HX_STACK_LINE(235)
		if (((  (((  ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("UP")).Add(HX_CSTRING("J")).Add(HX_CSTRING("W")),(int)2))) ? bool((this->remainingJumps > (int)0)) : bool(false) ))) ? bool((this->isSliding == false)) : bool(false) ))){
			HX_STACK_LINE(237)
			this->velocity->set_y(-(this->jumpPower));
			HX_STACK_LINE(238)
			(this->remainingJumps)--;
			HX_STACK_LINE(239)
			this->climbing = false;
		}
		HX_STACK_LINE(241)
		if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("SPACE")).Add(HX_CSTRING("K")),(int)2))){
			HX_STACK_LINE(242)
			this->shoot();
		}
		HX_STACK_LINE(244)
		if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("L")),(int)2))){
			HX_STACK_LINE(245)
			this->switchWeapon();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Player_obj,playerInputs,(void))

Void Player_obj::resolveAnimations( ){
{
		HX_STACK_FRAME("Player","resolveAnimations",0x815feace,"Player.resolveAnimations","Player.hx",249,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(250)
		if (((this->postShotTimer > (int)0))){
			HX_STACK_LINE(252)
			this->shootingString = HX_CSTRING("_shoot");
			HX_STACK_LINE(253)
			hx::SubEq(this->postShotTimer,::flixel::FlxG_obj::elapsed);
		}
		else{
			HX_STACK_LINE(256)
			this->shootingString = HX_CSTRING("");
		}
		HX_STACK_LINE(258)
		if (((bool((this->velocity->x == (int)0)) && bool((this->hurtTimer <= (int)0))))){
			HX_STACK_LINE(259)
			this->animation->play((HX_CSTRING("idle") + this->shootingString),null(),null());
		}
		HX_STACK_LINE(261)
		if (((this->velocity->x != (int)0))){
			HX_STACK_LINE(262)
			this->animation->play((HX_CSTRING("walk") + this->shootingString),null(),null());
		}
		HX_STACK_LINE(264)
		if (((this->velocity->y < (int)0))){
			HX_STACK_LINE(265)
			this->animation->play((HX_CSTRING("jump") + this->shootingString),null(),null());
		}
		else{
			HX_STACK_LINE(266)
			if (((this->velocity->y > (int)0))){
				HX_STACK_LINE(268)
				this->animation->play((HX_CSTRING("fall") + this->shootingString),null(),null());
				HX_STACK_LINE(270)
				if (((this->remainingJumps == this->maxJumps))){
					HX_STACK_LINE(271)
					(this->remainingJumps)--;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Player_obj,resolveAnimations,(void))

Void Player_obj::setTouchingLadder( bool _bool){
{
		HX_STACK_FRAME("Player","setTouchingLadder",0x967762da,"Player.setTouchingLadder","Player.hx",278,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_ARG(_bool,"bool")
		HX_STACK_LINE(278)
		this->touchingLadder = _bool;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Player_obj,setTouchingLadder,(void))

Void Player_obj::shoot( ){
{
		HX_STACK_FRAME("Player","shoot",0x70019132,"Player.shoot","Player.hx",283,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(283)
		this->curWeapon->shoot(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Player_obj,shoot,(void))

Void Player_obj::switchWeapon( ){
{
		HX_STACK_FRAME("Player","switchWeapon",0x33f414fd,"Player.switchWeapon","Player.hx",288,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(289)
		while((true)){
			HX_STACK_LINE(291)
			(this->curWeaponLoc)++;
			HX_STACK_LINE(292)
			if (((this->curWeaponLoc == this->weaponArray->length))){
				HX_STACK_LINE(293)
				this->curWeaponLoc = (int)0;
			}
			HX_STACK_LINE(289)
			if ((!(((this->weaponArray->__get(this->curWeaponLoc).StaticCast< ::weapons::WeaponTemplate >()->unlocked == false))))){
				HX_STACK_LINE(289)
				break;
			}
		}
		HX_STACK_LINE(298)
		this->curWeapon = this->weaponArray->__get(this->curWeaponLoc).StaticCast< ::weapons::WeaponTemplate >();
		HX_STACK_LINE(300)
		if (((this->curWeaponLoc == (int)0))){
			HX_STACK_LINE(302)
			this->animation->add(HX_CSTRING("walk"),Array_obj< int >::__new().Add((int)3).Add((int)2).Add((int)3).Add((int)4),(int)10,true);
			HX_STACK_LINE(303)
			this->animation->add(HX_CSTRING("idle"),Array_obj< int >::__new().Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)1),(int)3,true);
			HX_STACK_LINE(304)
			this->animation->add(HX_CSTRING("jump"),Array_obj< int >::__new().Add((int)5),(int)15,true);
			HX_STACK_LINE(305)
			this->animation->add(HX_CSTRING("fall"),Array_obj< int >::__new().Add((int)6),(int)15,true);
			HX_STACK_LINE(306)
			this->animation->add(HX_CSTRING("hurt"),Array_obj< int >::__new().Add((int)5),(int)15,true);
			HX_STACK_LINE(308)
			this->animation->add(HX_CSTRING("walk_shoot"),Array_obj< int >::__new().Add((int)10).Add((int)9).Add((int)10).Add((int)11),(int)10,true);
			HX_STACK_LINE(309)
			this->animation->add(HX_CSTRING("idle_shoot"),Array_obj< int >::__new().Add((int)8),(int)3,true);
			HX_STACK_LINE(310)
			this->animation->add(HX_CSTRING("jump_shoot"),Array_obj< int >::__new().Add((int)13),(int)15,true);
			HX_STACK_LINE(311)
			this->animation->add(HX_CSTRING("fall_shoot"),Array_obj< int >::__new().Add((int)13),(int)15,true);
		}
		else{
			HX_STACK_LINE(313)
			if (((this->curWeaponLoc == (int)1))){
				HX_STACK_LINE(315)
				this->animation->add(HX_CSTRING("walk"),Array_obj< int >::__new().Add((int)31).Add((int)30).Add((int)31).Add((int)32),(int)10,true);
				HX_STACK_LINE(316)
				this->animation->add(HX_CSTRING("idle"),Array_obj< int >::__new().Add((int)28).Add((int)28).Add((int)28).Add((int)28).Add((int)28).Add((int)29),(int)3,true);
				HX_STACK_LINE(317)
				this->animation->add(HX_CSTRING("jump"),Array_obj< int >::__new().Add((int)33),(int)15,true);
				HX_STACK_LINE(318)
				this->animation->add(HX_CSTRING("fall"),Array_obj< int >::__new().Add((int)34),(int)15,true);
				HX_STACK_LINE(319)
				this->animation->add(HX_CSTRING("hurt"),Array_obj< int >::__new().Add((int)33),(int)15,true);
				HX_STACK_LINE(321)
				this->animation->add(HX_CSTRING("walk_shoot"),Array_obj< int >::__new().Add((int)38).Add((int)37).Add((int)38).Add((int)39),(int)10,true);
				HX_STACK_LINE(322)
				this->animation->add(HX_CSTRING("idle_shoot"),Array_obj< int >::__new().Add((int)35),(int)3,true);
				HX_STACK_LINE(323)
				this->animation->add(HX_CSTRING("jump_shoot"),Array_obj< int >::__new().Add((int)40),(int)15,true);
				HX_STACK_LINE(324)
				this->animation->add(HX_CSTRING("fall_shoot"),Array_obj< int >::__new().Add((int)40),(int)15,true);
			}
			else{
				HX_STACK_LINE(326)
				if (((this->curWeaponLoc == (int)2))){
					HX_STACK_LINE(328)
					this->animation->add(HX_CSTRING("walk"),Array_obj< int >::__new().Add((int)17).Add((int)16).Add((int)17).Add((int)18),(int)10,true);
					HX_STACK_LINE(329)
					this->animation->add(HX_CSTRING("idle"),Array_obj< int >::__new().Add((int)14).Add((int)14).Add((int)14).Add((int)14).Add((int)14).Add((int)15),(int)3,true);
					HX_STACK_LINE(330)
					this->animation->add(HX_CSTRING("jump"),Array_obj< int >::__new().Add((int)19),(int)15,true);
					HX_STACK_LINE(331)
					this->animation->add(HX_CSTRING("fall"),Array_obj< int >::__new().Add((int)20),(int)15,true);
					HX_STACK_LINE(332)
					this->animation->add(HX_CSTRING("hurt"),Array_obj< int >::__new().Add((int)19),(int)15,true);
					HX_STACK_LINE(334)
					this->animation->add(HX_CSTRING("walk_shoot"),Array_obj< int >::__new().Add((int)24).Add((int)23).Add((int)24).Add((int)25),(int)10,true);
					HX_STACK_LINE(335)
					this->animation->add(HX_CSTRING("idle_shoot"),Array_obj< int >::__new().Add((int)21),(int)3,true);
					HX_STACK_LINE(336)
					this->animation->add(HX_CSTRING("jump_shoot"),Array_obj< int >::__new().Add((int)26),(int)15,true);
					HX_STACK_LINE(337)
					this->animation->add(HX_CSTRING("fall_shoot"),Array_obj< int >::__new().Add((int)26),(int)15,true);
				}
				else{
					HX_STACK_LINE(339)
					if (((this->curWeaponLoc == (int)3))){
						HX_STACK_LINE(341)
						this->animation->add(HX_CSTRING("walk"),Array_obj< int >::__new().Add((int)45).Add((int)44).Add((int)45).Add((int)46),(int)10,true);
						HX_STACK_LINE(342)
						this->animation->add(HX_CSTRING("idle"),Array_obj< int >::__new().Add((int)42).Add((int)42).Add((int)42).Add((int)42).Add((int)42).Add((int)43),(int)3,true);
						HX_STACK_LINE(343)
						this->animation->add(HX_CSTRING("jump"),Array_obj< int >::__new().Add((int)47),(int)15,true);
						HX_STACK_LINE(344)
						this->animation->add(HX_CSTRING("fall"),Array_obj< int >::__new().Add((int)48),(int)15,true);
						HX_STACK_LINE(345)
						this->animation->add(HX_CSTRING("hurt"),Array_obj< int >::__new().Add((int)47),(int)15,true);
						HX_STACK_LINE(347)
						this->animation->add(HX_CSTRING("walk_shoot"),Array_obj< int >::__new().Add((int)52).Add((int)51).Add((int)52).Add((int)53),(int)10,true);
						HX_STACK_LINE(348)
						this->animation->add(HX_CSTRING("idle_shoot"),Array_obj< int >::__new().Add((int)49),(int)3,true);
						HX_STACK_LINE(349)
						this->animation->add(HX_CSTRING("jump_shoot"),Array_obj< int >::__new().Add((int)54),(int)15,true);
						HX_STACK_LINE(350)
						this->animation->add(HX_CSTRING("fall_shoot"),Array_obj< int >::__new().Add((int)54),(int)15,true);
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Player_obj,switchWeapon,(void))

Void Player_obj::takeDamage( int dmg){
{
		HX_STACK_FRAME("Player","takeDamage",0x11ac2fe3,"Player.takeDamage","Player.hx",356,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_ARG(dmg,"dmg")
		HX_STACK_LINE(356)
		if (((this->hurtTimer <= (int)0))){
			HX_STACK_LINE(358)
			this->hurtTimer = (int)1;
			HX_STACK_LINE(359)
			hx::SubEq(this->hp,dmg);
			HX_STACK_LINE(360)
			this->animation->play(HX_CSTRING("hurt"),null(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Player_obj,takeDamage,(void))


Player_obj::Player_obj()
{
}

void Player_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Player);
	HX_MARK_MEMBER_NAME(jumpPower,"jumpPower");
	HX_MARK_MEMBER_NAME(GRAVITY,"GRAVITY");
	HX_MARK_MEMBER_NAME(xSpeed,"xSpeed");
	HX_MARK_MEMBER_NAME(remainingJumps,"remainingJumps");
	HX_MARK_MEMBER_NAME(hp,"hp");
	HX_MARK_MEMBER_NAME(isSliding,"isSliding");
	HX_MARK_MEMBER_NAME(maxHP,"maxHP");
	HX_MARK_MEMBER_NAME(maxJumps,"maxJumps");
	HX_MARK_MEMBER_NAME(shotRange,"shotRange");
	HX_MARK_MEMBER_NAME(damage,"damage");
	HX_MARK_MEMBER_NAME(luck,"luck");
	HX_MARK_MEMBER_NAME(bulletArray,"bulletArray");
	HX_MARK_MEMBER_NAME(maxBullets,"maxBullets");
	HX_MARK_MEMBER_NAME(bulletCount,"bulletCount");
	HX_MARK_MEMBER_NAME(curWeaponLoc,"curWeaponLoc");
	HX_MARK_MEMBER_NAME(curWeapon,"curWeapon");
	HX_MARK_MEMBER_NAME(weapon1,"weapon1");
	HX_MARK_MEMBER_NAME(weapon2,"weapon2");
	HX_MARK_MEMBER_NAME(weapon3,"weapon3");
	HX_MARK_MEMBER_NAME(weapon4,"weapon4");
	HX_MARK_MEMBER_NAME(weaponArray,"weaponArray");
	HX_MARK_MEMBER_NAME(shootingString,"shootingString");
	HX_MARK_MEMBER_NAME(postShotTimer,"postShotTimer");
	HX_MARK_MEMBER_NAME(cooldown,"cooldown");
	HX_MARK_MEMBER_NAME(touchingLadder,"touchingLadder");
	HX_MARK_MEMBER_NAME(climbing,"climbing");
	HX_MARK_MEMBER_NAME(hurtTimer,"hurtTimer");
	HX_MARK_MEMBER_NAME(canMove,"canMove");
	::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Player_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(jumpPower,"jumpPower");
	HX_VISIT_MEMBER_NAME(GRAVITY,"GRAVITY");
	HX_VISIT_MEMBER_NAME(xSpeed,"xSpeed");
	HX_VISIT_MEMBER_NAME(remainingJumps,"remainingJumps");
	HX_VISIT_MEMBER_NAME(hp,"hp");
	HX_VISIT_MEMBER_NAME(isSliding,"isSliding");
	HX_VISIT_MEMBER_NAME(maxHP,"maxHP");
	HX_VISIT_MEMBER_NAME(maxJumps,"maxJumps");
	HX_VISIT_MEMBER_NAME(shotRange,"shotRange");
	HX_VISIT_MEMBER_NAME(damage,"damage");
	HX_VISIT_MEMBER_NAME(luck,"luck");
	HX_VISIT_MEMBER_NAME(bulletArray,"bulletArray");
	HX_VISIT_MEMBER_NAME(maxBullets,"maxBullets");
	HX_VISIT_MEMBER_NAME(bulletCount,"bulletCount");
	HX_VISIT_MEMBER_NAME(curWeaponLoc,"curWeaponLoc");
	HX_VISIT_MEMBER_NAME(curWeapon,"curWeapon");
	HX_VISIT_MEMBER_NAME(weapon1,"weapon1");
	HX_VISIT_MEMBER_NAME(weapon2,"weapon2");
	HX_VISIT_MEMBER_NAME(weapon3,"weapon3");
	HX_VISIT_MEMBER_NAME(weapon4,"weapon4");
	HX_VISIT_MEMBER_NAME(weaponArray,"weaponArray");
	HX_VISIT_MEMBER_NAME(shootingString,"shootingString");
	HX_VISIT_MEMBER_NAME(postShotTimer,"postShotTimer");
	HX_VISIT_MEMBER_NAME(cooldown,"cooldown");
	HX_VISIT_MEMBER_NAME(touchingLadder,"touchingLadder");
	HX_VISIT_MEMBER_NAME(climbing,"climbing");
	HX_VISIT_MEMBER_NAME(hurtTimer,"hurtTimer");
	HX_VISIT_MEMBER_NAME(canMove,"canMove");
	::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Player_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"hp") ) { return hp; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"luck") ) { return luck; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"maxHP") ) { return maxHP; }
		if (HX_FIELD_EQ(inName,"shoot") ) { return shoot_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"xSpeed") ) { return xSpeed; }
		if (HX_FIELD_EQ(inName,"damage") ) { return damage; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"GRAVITY") ) { return GRAVITY; }
		if (HX_FIELD_EQ(inName,"weapon1") ) { return weapon1; }
		if (HX_FIELD_EQ(inName,"weapon2") ) { return weapon2; }
		if (HX_FIELD_EQ(inName,"weapon3") ) { return weapon3; }
		if (HX_FIELD_EQ(inName,"weapon4") ) { return weapon4; }
		if (HX_FIELD_EQ(inName,"canMove") ) { return canMove; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxJumps") ) { return maxJumps; }
		if (HX_FIELD_EQ(inName,"cooldown") ) { return cooldown; }
		if (HX_FIELD_EQ(inName,"climbing") ) { return climbing; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"jumpPower") ) { return jumpPower; }
		if (HX_FIELD_EQ(inName,"isSliding") ) { return isSliding; }
		if (HX_FIELD_EQ(inName,"shotRange") ) { return shotRange; }
		if (HX_FIELD_EQ(inName,"curWeapon") ) { return curWeapon; }
		if (HX_FIELD_EQ(inName,"hurtTimer") ) { return hurtTimer; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"maxBullets") ) { return maxBullets; }
		if (HX_FIELD_EQ(inName,"takeDamage") ) { return takeDamage_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bulletArray") ) { return bulletArray; }
		if (HX_FIELD_EQ(inName,"bulletCount") ) { return bulletCount; }
		if (HX_FIELD_EQ(inName,"weaponArray") ) { return weaponArray; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"curWeaponLoc") ) { return curWeaponLoc; }
		if (HX_FIELD_EQ(inName,"playerInputs") ) { return playerInputs_dyn(); }
		if (HX_FIELD_EQ(inName,"switchWeapon") ) { return switchWeapon_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"postShotTimer") ) { return postShotTimer; }
		if (HX_FIELD_EQ(inName,"enterBossDoor") ) { return enterBossDoor_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"remainingJumps") ) { return remainingJumps; }
		if (HX_FIELD_EQ(inName,"shootingString") ) { return shootingString; }
		if (HX_FIELD_EQ(inName,"touchingLadder") ) { return touchingLadder; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"resolveAnimations") ) { return resolveAnimations_dyn(); }
		if (HX_FIELD_EQ(inName,"setTouchingLadder") ) { return setTouchingLadder_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Player_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"hp") ) { hp=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"luck") ) { luck=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"maxHP") ) { maxHP=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"xSpeed") ) { xSpeed=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"damage") ) { damage=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"GRAVITY") ) { GRAVITY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"weapon1") ) { weapon1=inValue.Cast< ::weapons::WeaponTemplate >(); return inValue; }
		if (HX_FIELD_EQ(inName,"weapon2") ) { weapon2=inValue.Cast< ::weapons::WeaponTemplate >(); return inValue; }
		if (HX_FIELD_EQ(inName,"weapon3") ) { weapon3=inValue.Cast< ::weapons::WeaponTemplate >(); return inValue; }
		if (HX_FIELD_EQ(inName,"weapon4") ) { weapon4=inValue.Cast< ::weapons::WeaponTemplate >(); return inValue; }
		if (HX_FIELD_EQ(inName,"canMove") ) { canMove=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxJumps") ) { maxJumps=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cooldown") ) { cooldown=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"climbing") ) { climbing=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"jumpPower") ) { jumpPower=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isSliding") ) { isSliding=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"shotRange") ) { shotRange=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"curWeapon") ) { curWeapon=inValue.Cast< ::weapons::WeaponTemplate >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hurtTimer") ) { hurtTimer=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"maxBullets") ) { maxBullets=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bulletArray") ) { bulletArray=inValue.Cast< ::flixel::group::FlxTypedGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bulletCount") ) { bulletCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"weaponArray") ) { weaponArray=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"curWeaponLoc") ) { curWeaponLoc=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"postShotTimer") ) { postShotTimer=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"remainingJumps") ) { remainingJumps=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"shootingString") ) { shootingString=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touchingLadder") ) { touchingLadder=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Player_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("jumpPower"));
	outFields->push(HX_CSTRING("GRAVITY"));
	outFields->push(HX_CSTRING("xSpeed"));
	outFields->push(HX_CSTRING("remainingJumps"));
	outFields->push(HX_CSTRING("hp"));
	outFields->push(HX_CSTRING("isSliding"));
	outFields->push(HX_CSTRING("maxHP"));
	outFields->push(HX_CSTRING("maxJumps"));
	outFields->push(HX_CSTRING("shotRange"));
	outFields->push(HX_CSTRING("damage"));
	outFields->push(HX_CSTRING("luck"));
	outFields->push(HX_CSTRING("bulletArray"));
	outFields->push(HX_CSTRING("maxBullets"));
	outFields->push(HX_CSTRING("bulletCount"));
	outFields->push(HX_CSTRING("curWeaponLoc"));
	outFields->push(HX_CSTRING("curWeapon"));
	outFields->push(HX_CSTRING("weapon1"));
	outFields->push(HX_CSTRING("weapon2"));
	outFields->push(HX_CSTRING("weapon3"));
	outFields->push(HX_CSTRING("weapon4"));
	outFields->push(HX_CSTRING("weaponArray"));
	outFields->push(HX_CSTRING("shootingString"));
	outFields->push(HX_CSTRING("postShotTimer"));
	outFields->push(HX_CSTRING("cooldown"));
	outFields->push(HX_CSTRING("touchingLadder"));
	outFields->push(HX_CSTRING("climbing"));
	outFields->push(HX_CSTRING("hurtTimer"));
	outFields->push(HX_CSTRING("canMove"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Player_obj,jumpPower),HX_CSTRING("jumpPower")},
	{hx::fsInt,(int)offsetof(Player_obj,GRAVITY),HX_CSTRING("GRAVITY")},
	{hx::fsInt,(int)offsetof(Player_obj,xSpeed),HX_CSTRING("xSpeed")},
	{hx::fsInt,(int)offsetof(Player_obj,remainingJumps),HX_CSTRING("remainingJumps")},
	{hx::fsInt,(int)offsetof(Player_obj,hp),HX_CSTRING("hp")},
	{hx::fsBool,(int)offsetof(Player_obj,isSliding),HX_CSTRING("isSliding")},
	{hx::fsInt,(int)offsetof(Player_obj,maxHP),HX_CSTRING("maxHP")},
	{hx::fsInt,(int)offsetof(Player_obj,maxJumps),HX_CSTRING("maxJumps")},
	{hx::fsInt,(int)offsetof(Player_obj,shotRange),HX_CSTRING("shotRange")},
	{hx::fsInt,(int)offsetof(Player_obj,damage),HX_CSTRING("damage")},
	{hx::fsInt,(int)offsetof(Player_obj,luck),HX_CSTRING("luck")},
	{hx::fsObject /*::flixel::group::FlxTypedGroup*/ ,(int)offsetof(Player_obj,bulletArray),HX_CSTRING("bulletArray")},
	{hx::fsInt,(int)offsetof(Player_obj,maxBullets),HX_CSTRING("maxBullets")},
	{hx::fsInt,(int)offsetof(Player_obj,bulletCount),HX_CSTRING("bulletCount")},
	{hx::fsInt,(int)offsetof(Player_obj,curWeaponLoc),HX_CSTRING("curWeaponLoc")},
	{hx::fsObject /*::weapons::WeaponTemplate*/ ,(int)offsetof(Player_obj,curWeapon),HX_CSTRING("curWeapon")},
	{hx::fsObject /*::weapons::WeaponTemplate*/ ,(int)offsetof(Player_obj,weapon1),HX_CSTRING("weapon1")},
	{hx::fsObject /*::weapons::WeaponTemplate*/ ,(int)offsetof(Player_obj,weapon2),HX_CSTRING("weapon2")},
	{hx::fsObject /*::weapons::WeaponTemplate*/ ,(int)offsetof(Player_obj,weapon3),HX_CSTRING("weapon3")},
	{hx::fsObject /*::weapons::WeaponTemplate*/ ,(int)offsetof(Player_obj,weapon4),HX_CSTRING("weapon4")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Player_obj,weaponArray),HX_CSTRING("weaponArray")},
	{hx::fsString,(int)offsetof(Player_obj,shootingString),HX_CSTRING("shootingString")},
	{hx::fsFloat,(int)offsetof(Player_obj,postShotTimer),HX_CSTRING("postShotTimer")},
	{hx::fsFloat,(int)offsetof(Player_obj,cooldown),HX_CSTRING("cooldown")},
	{hx::fsBool,(int)offsetof(Player_obj,touchingLadder),HX_CSTRING("touchingLadder")},
	{hx::fsBool,(int)offsetof(Player_obj,climbing),HX_CSTRING("climbing")},
	{hx::fsFloat,(int)offsetof(Player_obj,hurtTimer),HX_CSTRING("hurtTimer")},
	{hx::fsBool,(int)offsetof(Player_obj,canMove),HX_CSTRING("canMove")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("jumpPower"),
	HX_CSTRING("GRAVITY"),
	HX_CSTRING("xSpeed"),
	HX_CSTRING("remainingJumps"),
	HX_CSTRING("hp"),
	HX_CSTRING("isSliding"),
	HX_CSTRING("maxHP"),
	HX_CSTRING("maxJumps"),
	HX_CSTRING("shotRange"),
	HX_CSTRING("damage"),
	HX_CSTRING("luck"),
	HX_CSTRING("bulletArray"),
	HX_CSTRING("maxBullets"),
	HX_CSTRING("bulletCount"),
	HX_CSTRING("curWeaponLoc"),
	HX_CSTRING("curWeapon"),
	HX_CSTRING("weapon1"),
	HX_CSTRING("weapon2"),
	HX_CSTRING("weapon3"),
	HX_CSTRING("weapon4"),
	HX_CSTRING("weaponArray"),
	HX_CSTRING("shootingString"),
	HX_CSTRING("postShotTimer"),
	HX_CSTRING("cooldown"),
	HX_CSTRING("touchingLadder"),
	HX_CSTRING("climbing"),
	HX_CSTRING("hurtTimer"),
	HX_CSTRING("canMove"),
	HX_CSTRING("update"),
	HX_CSTRING("enterBossDoor"),
	HX_CSTRING("playerInputs"),
	HX_CSTRING("resolveAnimations"),
	HX_CSTRING("setTouchingLadder"),
	HX_CSTRING("shoot"),
	HX_CSTRING("switchWeapon"),
	HX_CSTRING("takeDamage"),
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


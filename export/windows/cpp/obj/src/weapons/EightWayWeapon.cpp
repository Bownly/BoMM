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
#ifndef INCLUDED_weapons_Bullet
#include <weapons/Bullet.h>
#endif
#ifndef INCLUDED_weapons_EightWayWeapon
#include <weapons/EightWayWeapon.h>
#endif
#ifndef INCLUDED_weapons_WeaponTemplate
#include <weapons/WeaponTemplate.h>
#endif
namespace weapons{

Void EightWayWeapon_obj::__construct(::String Name,::flixel::group::FlxTypedGroup Bullets)
{
HX_STACK_FRAME("weapons.EightWayWeapon","new",0xfe70bd25,"weapons.EightWayWeapon.new","weapons/EightWayWeapon.hx",15,0x7767dcca)
HX_STACK_THIS(this)
HX_STACK_ARG(Name,"Name")
HX_STACK_ARG(Bullets,"Bullets")
{
	HX_STACK_LINE(16)
	super::__construct(Name,Bullets);
	HX_STACK_LINE(18)
	this->damage = (int)5;
	HX_STACK_LINE(19)
	this->juice = (int)9;
	HX_STACK_LINE(20)
	this->juiceMax = (int)9;
	HX_STACK_LINE(21)
	this->juiceCost = (int)1;
	HX_STACK_LINE(22)
	this->palette = (int)1;
}
;
	return null();
}

//EightWayWeapon_obj::~EightWayWeapon_obj() { }

Dynamic EightWayWeapon_obj::__CreateEmpty() { return  new EightWayWeapon_obj; }
hx::ObjectPtr< EightWayWeapon_obj > EightWayWeapon_obj::__new(::String Name,::flixel::group::FlxTypedGroup Bullets)
{  hx::ObjectPtr< EightWayWeapon_obj > result = new EightWayWeapon_obj();
	result->__construct(Name,Bullets);
	return result;}

Dynamic EightWayWeapon_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EightWayWeapon_obj > result = new EightWayWeapon_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void EightWayWeapon_obj::shoot( ::Player _player){
{
		HX_STACK_FRAME("weapons.EightWayWeapon","shoot",0xecece9e4,"weapons.EightWayWeapon.shoot","weapons/EightWayWeapon.hx",26,0x7767dcca)
		HX_STACK_THIS(this)
		HX_STACK_ARG(_player,"_player")
		HX_STACK_LINE(27)
		int _g = _player->bulletArray->countLiving();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(27)
		if (((  (((_g < _player->maxBullets))) ? bool((this->juice >= this->juiceCost)) : bool(false) ))){
			HX_STACK_LINE(29)
			_player->postShotTimer = .33;
			HX_STACK_LINE(31)
			int direction = (int)0;		HX_STACK_VAR(direction,"direction");
			HX_STACK_LINE(33)
			if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("LEFT")).Add(HX_CSTRING("A")),(int)1))){
				HX_STACK_LINE(34)
				hx::AddEq(direction,(int)1);
			}
			else{
				HX_STACK_LINE(35)
				if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("RIGHT")).Add(HX_CSTRING("D")),(int)1))){
					HX_STACK_LINE(36)
					hx::AddEq(direction,(int)16);
				}
			}
			HX_STACK_LINE(37)
			if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("UP")).Add(HX_CSTRING("W")),(int)1))){
				HX_STACK_LINE(38)
				hx::AddEq(direction,(int)256);
			}
			else{
				HX_STACK_LINE(39)
				if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("DOWN")).Add(HX_CSTRING("S")),(int)1))){
					HX_STACK_LINE(40)
					hx::AddEq(direction,(int)4096);
				}
			}
			HX_STACK_LINE(42)
			if (((direction == (int)0))){
				HX_STACK_LINE(44)
				direction = _player->facing;
			}
			HX_STACK_LINE(46)
			::weapons::Bullet newBullet = ::weapons::Bullet_obj::__new((_player->x + (int)8),(_player->y + (int)8),(int)500,direction,(_player->damage + this->damage),(int)256);		HX_STACK_VAR(newBullet,"newBullet");
			HX_STACK_LINE(47)
			_player->bulletArray->add(newBullet);
			HX_STACK_LINE(55)
			hx::SubEq(this->juice,this->juiceCost);
		}
	}
return null();
}



EightWayWeapon_obj::EightWayWeapon_obj()
{
}

Dynamic EightWayWeapon_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"shoot") ) { return shoot_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EightWayWeapon_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void EightWayWeapon_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("shoot"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EightWayWeapon_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EightWayWeapon_obj::__mClass,"__mClass");
};

#endif

Class EightWayWeapon_obj::__mClass;

void EightWayWeapon_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("weapons.EightWayWeapon"), hx::TCanCast< EightWayWeapon_obj> ,sStaticFields,sMemberFields,
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

void EightWayWeapon_obj::__boot()
{
}

} // end namespace weapons

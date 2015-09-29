#include <hxcpp.h>

#ifndef INCLUDED_Player
#include <Player.h>
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
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_weapons_Bullet
#include <weapons/Bullet.h>
#endif
#ifndef INCLUDED_weapons_MagentaWeapon
#include <weapons/MagentaWeapon.h>
#endif
#ifndef INCLUDED_weapons_WeaponTemplate
#include <weapons/WeaponTemplate.h>
#endif
namespace weapons{

Void MagentaWeapon_obj::__construct(::String Name,::flixel::group::FlxTypedGroup Bullets)
{
HX_STACK_FRAME("weapons.MagentaWeapon","new",0x31aea920,"weapons.MagentaWeapon.new","weapons/MagentaWeapon.hx",14,0xd388ac51)
HX_STACK_THIS(this)
HX_STACK_ARG(Name,"Name")
HX_STACK_ARG(Bullets,"Bullets")
{
	HX_STACK_LINE(15)
	super::__construct(Name,Bullets);
	HX_STACK_LINE(17)
	this->damage = (int)5;
	HX_STACK_LINE(18)
	this->juice = (int)9;
	HX_STACK_LINE(19)
	this->juiceMax = (int)9;
	HX_STACK_LINE(20)
	this->juiceCost = (int)1;
}
;
	return null();
}

//MagentaWeapon_obj::~MagentaWeapon_obj() { }

Dynamic MagentaWeapon_obj::__CreateEmpty() { return  new MagentaWeapon_obj; }
hx::ObjectPtr< MagentaWeapon_obj > MagentaWeapon_obj::__new(::String Name,::flixel::group::FlxTypedGroup Bullets)
{  hx::ObjectPtr< MagentaWeapon_obj > result = new MagentaWeapon_obj();
	result->__construct(Name,Bullets);
	return result;}

Dynamic MagentaWeapon_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MagentaWeapon_obj > result = new MagentaWeapon_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void MagentaWeapon_obj::shoot( ::Player _player){
{
		HX_STACK_FRAME("weapons.MagentaWeapon","shoot",0xdc7a0a9f,"weapons.MagentaWeapon.shoot","weapons/MagentaWeapon.hx",24,0xd388ac51)
		HX_STACK_THIS(this)
		HX_STACK_ARG(_player,"_player")
		HX_STACK_LINE(25)
		int _g = _player->bulletArray->countLiving();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(25)
		if (((  (((_g < _player->maxBullets))) ? bool((this->juice >= this->juiceCost)) : bool(false) ))){
			HX_STACK_LINE(27)
			_player->postShotTimer = .33;
			HX_STACK_LINE(29)
			if ((_player->flipX)){
				HX_STACK_LINE(31)
				::weapons::Bullet newBullet = ::weapons::Bullet_obj::__new((_player->x - (int)8),(_player->y + (int)8),(int)500,(int)1,(_player->damage + this->damage),(int)256);		HX_STACK_VAR(newBullet,"newBullet");
				HX_STACK_LINE(32)
				::weapons::Bullet newBullet2 = ::weapons::Bullet_obj::__new((_player->x - (int)8),(_player->y + (int)16),(int)500,(int)256,(_player->damage + this->damage),(int)256);		HX_STACK_VAR(newBullet2,"newBullet2");
				HX_STACK_LINE(33)
				_player->bulletArray->add(newBullet);
				HX_STACK_LINE(34)
				_player->bulletArray->add(newBullet2);
			}
			else{
				HX_STACK_LINE(38)
				::weapons::Bullet newBullet = ::weapons::Bullet_obj::__new((_player->x + (int)8),(_player->y + (int)8),(int)500,(int)256,(_player->damage + this->damage),(int)256);		HX_STACK_VAR(newBullet,"newBullet");
				HX_STACK_LINE(39)
				::weapons::Bullet newBullet2 = ::weapons::Bullet_obj::__new((_player->x + (int)8),(_player->y + (int)16),(int)500,(int)16,(_player->damage + this->damage),(int)256);		HX_STACK_VAR(newBullet2,"newBullet2");
				HX_STACK_LINE(40)
				_player->bulletArray->add(newBullet);
				HX_STACK_LINE(41)
				_player->bulletArray->add(newBullet2);
			}
			HX_STACK_LINE(43)
			hx::SubEq(this->juice,this->juiceCost);
		}
	}
return null();
}



MagentaWeapon_obj::MagentaWeapon_obj()
{
}

Dynamic MagentaWeapon_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"shoot") ) { return shoot_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MagentaWeapon_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void MagentaWeapon_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(MagentaWeapon_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MagentaWeapon_obj::__mClass,"__mClass");
};

#endif

Class MagentaWeapon_obj::__mClass;

void MagentaWeapon_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("weapons.MagentaWeapon"), hx::TCanCast< MagentaWeapon_obj> ,sStaticFields,sMemberFields,
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

void MagentaWeapon_obj::__boot()
{
}

} // end namespace weapons

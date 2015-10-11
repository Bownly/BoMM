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
#ifndef INCLUDED_weapons_CyanWeapon
#include <weapons/CyanWeapon.h>
#endif
#ifndef INCLUDED_weapons_WeaponTemplate
#include <weapons/WeaponTemplate.h>
#endif
namespace weapons{

Void CyanWeapon_obj::__construct(::String Name,::flixel::group::FlxTypedGroup Bullets)
{
HX_STACK_FRAME("weapons.CyanWeapon","new",0x53bed968,"weapons.CyanWeapon.new","weapons/CyanWeapon.hx",14,0x41549e67)
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
	this->juiceCost = (int)2;
}
;
	return null();
}

//CyanWeapon_obj::~CyanWeapon_obj() { }

Dynamic CyanWeapon_obj::__CreateEmpty() { return  new CyanWeapon_obj; }
hx::ObjectPtr< CyanWeapon_obj > CyanWeapon_obj::__new(::String Name,::flixel::group::FlxTypedGroup Bullets)
{  hx::ObjectPtr< CyanWeapon_obj > result = new CyanWeapon_obj();
	result->__construct(Name,Bullets);
	return result;}

Dynamic CyanWeapon_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CyanWeapon_obj > result = new CyanWeapon_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void CyanWeapon_obj::shoot( ::Player _player){
{
		HX_STACK_FRAME("weapons.CyanWeapon","shoot",0xc72cdce7,"weapons.CyanWeapon.shoot","weapons/CyanWeapon.hx",24,0x41549e67)
		HX_STACK_THIS(this)
		HX_STACK_ARG(_player,"_player")
		HX_STACK_LINE(25)
		int _g = _player->bulletArray->countLiving();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(25)
		if (((  (((_g < _player->_maxBullets))) ? bool((this->juice >= this->juiceCost)) : bool(false) ))){
			HX_STACK_LINE(27)
			_player->postShotTimer = .33;
			HX_STACK_LINE(29)
			::weapons::Bullet newBullet = ::weapons::Bullet_obj::__new((_player->x - (int)8),(_player->y + (int)8),(int)500,(int)1,(_player->_DAMAGE + this->damage),(int)256);		HX_STACK_VAR(newBullet,"newBullet");
			HX_STACK_LINE(30)
			::weapons::Bullet newBullet2 = ::weapons::Bullet_obj::__new((_player->x + (int)8),(_player->y + (int)8),(int)500,(int)16,(_player->_DAMAGE + this->damage),(int)256);		HX_STACK_VAR(newBullet2,"newBullet2");
			HX_STACK_LINE(31)
			_player->bulletArray->add(newBullet);
			HX_STACK_LINE(32)
			_player->bulletArray->add(newBullet2);
			HX_STACK_LINE(34)
			hx::SubEq(this->juice,this->juiceCost);
		}
	}
return null();
}



CyanWeapon_obj::CyanWeapon_obj()
{
}

Dynamic CyanWeapon_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"shoot") ) { return shoot_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CyanWeapon_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void CyanWeapon_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(CyanWeapon_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CyanWeapon_obj::__mClass,"__mClass");
};

#endif

Class CyanWeapon_obj::__mClass;

void CyanWeapon_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("weapons.CyanWeapon"), hx::TCanCast< CyanWeapon_obj> ,sStaticFields,sMemberFields,
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

void CyanWeapon_obj::__boot()
{
}

} // end namespace weapons

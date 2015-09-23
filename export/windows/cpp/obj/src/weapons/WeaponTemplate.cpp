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
#ifndef INCLUDED_weapons_WeaponTemplate
#include <weapons/WeaponTemplate.h>
#endif
namespace weapons{

Void WeaponTemplate_obj::__construct(::String Name,::flixel::group::FlxTypedGroup Bullets)
{
HX_STACK_FRAME("weapons.WeaponTemplate","new",0xb690533f,"weapons.WeaponTemplate.new","weapons/WeaponTemplate.hx",11,0x5cae07f0)
HX_STACK_THIS(this)
HX_STACK_ARG(Name,"Name")
HX_STACK_ARG(Bullets,"Bullets")
{
	HX_STACK_LINE(21)
	this->unlocked = true;
	HX_STACK_LINE(19)
	this->juiceCost = (int)0;
	HX_STACK_LINE(18)
	this->juiceMax = (int)9;
	HX_STACK_LINE(17)
	this->juice = (int)9;
	HX_STACK_LINE(15)
	this->damage = (int)1;
	HX_STACK_LINE(25)
	this->name = Name;
	HX_STACK_LINE(26)
	this->bulletArray = Bullets;
}
;
	return null();
}

//WeaponTemplate_obj::~WeaponTemplate_obj() { }

Dynamic WeaponTemplate_obj::__CreateEmpty() { return  new WeaponTemplate_obj; }
hx::ObjectPtr< WeaponTemplate_obj > WeaponTemplate_obj::__new(::String Name,::flixel::group::FlxTypedGroup Bullets)
{  hx::ObjectPtr< WeaponTemplate_obj > result = new WeaponTemplate_obj();
	result->__construct(Name,Bullets);
	return result;}

Dynamic WeaponTemplate_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< WeaponTemplate_obj > result = new WeaponTemplate_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void WeaponTemplate_obj::shoot( ::Player _player){
{
		HX_STACK_FRAME("weapons.WeaponTemplate","shoot",0x9cb1ba7e,"weapons.WeaponTemplate.shoot","weapons/WeaponTemplate.hx",30,0x5cae07f0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(_player,"_player")
		HX_STACK_LINE(31)
		int _g = _player->bulletArray->countLiving();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(31)
		if (((  (((_g < _player->_maxBullets))) ? bool((this->juice > (int)0)) : bool(false) ))){
			HX_STACK_LINE(33)
			_player->postShotTimer = .33;
			HX_STACK_LINE(35)
			if ((_player->flipX)){
				HX_STACK_LINE(37)
				::weapons::Bullet newBullet = ::weapons::Bullet_obj::__new((_player->x - (int)8),(_player->y + (int)8),(int)500,(int)1,(_player->_DAMAGE + this->damage),(int)256);		HX_STACK_VAR(newBullet,"newBullet");
				HX_STACK_LINE(38)
				_player->bulletArray->add(newBullet);
			}
			else{
				HX_STACK_LINE(42)
				::weapons::Bullet newBullet = ::weapons::Bullet_obj::__new((_player->x + (int)8),(_player->y + (int)8),(int)500,(int)16,(_player->_DAMAGE + this->damage),(int)256);		HX_STACK_VAR(newBullet,"newBullet");
				HX_STACK_LINE(43)
				_player->bulletArray->add(newBullet);
			}
			HX_STACK_LINE(45)
			hx::SubEq(this->juice,this->juiceCost);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(WeaponTemplate_obj,shoot,(void))


WeaponTemplate_obj::WeaponTemplate_obj()
{
}

void WeaponTemplate_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(WeaponTemplate);
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(bulletArray,"bulletArray");
	HX_MARK_MEMBER_NAME(damage,"damage");
	HX_MARK_MEMBER_NAME(juice,"juice");
	HX_MARK_MEMBER_NAME(juiceMax,"juiceMax");
	HX_MARK_MEMBER_NAME(juiceCost,"juiceCost");
	HX_MARK_MEMBER_NAME(unlocked,"unlocked");
	HX_MARK_END_CLASS();
}

void WeaponTemplate_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(bulletArray,"bulletArray");
	HX_VISIT_MEMBER_NAME(damage,"damage");
	HX_VISIT_MEMBER_NAME(juice,"juice");
	HX_VISIT_MEMBER_NAME(juiceMax,"juiceMax");
	HX_VISIT_MEMBER_NAME(juiceCost,"juiceCost");
	HX_VISIT_MEMBER_NAME(unlocked,"unlocked");
}

Dynamic WeaponTemplate_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"juice") ) { return juice; }
		if (HX_FIELD_EQ(inName,"shoot") ) { return shoot_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"damage") ) { return damage; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"juiceMax") ) { return juiceMax; }
		if (HX_FIELD_EQ(inName,"unlocked") ) { return unlocked; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"juiceCost") ) { return juiceCost; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bulletArray") ) { return bulletArray; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic WeaponTemplate_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"juice") ) { juice=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"damage") ) { damage=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"juiceMax") ) { juiceMax=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"unlocked") ) { unlocked=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"juiceCost") ) { juiceCost=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bulletArray") ) { bulletArray=inValue.Cast< ::flixel::group::FlxTypedGroup >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void WeaponTemplate_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("bulletArray"));
	outFields->push(HX_CSTRING("damage"));
	outFields->push(HX_CSTRING("juice"));
	outFields->push(HX_CSTRING("juiceMax"));
	outFields->push(HX_CSTRING("juiceCost"));
	outFields->push(HX_CSTRING("unlocked"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(WeaponTemplate_obj,name),HX_CSTRING("name")},
	{hx::fsObject /*::flixel::group::FlxTypedGroup*/ ,(int)offsetof(WeaponTemplate_obj,bulletArray),HX_CSTRING("bulletArray")},
	{hx::fsInt,(int)offsetof(WeaponTemplate_obj,damage),HX_CSTRING("damage")},
	{hx::fsInt,(int)offsetof(WeaponTemplate_obj,juice),HX_CSTRING("juice")},
	{hx::fsInt,(int)offsetof(WeaponTemplate_obj,juiceMax),HX_CSTRING("juiceMax")},
	{hx::fsInt,(int)offsetof(WeaponTemplate_obj,juiceCost),HX_CSTRING("juiceCost")},
	{hx::fsBool,(int)offsetof(WeaponTemplate_obj,unlocked),HX_CSTRING("unlocked")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("name"),
	HX_CSTRING("bulletArray"),
	HX_CSTRING("damage"),
	HX_CSTRING("juice"),
	HX_CSTRING("juiceMax"),
	HX_CSTRING("juiceCost"),
	HX_CSTRING("unlocked"),
	HX_CSTRING("shoot"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(WeaponTemplate_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(WeaponTemplate_obj::__mClass,"__mClass");
};

#endif

Class WeaponTemplate_obj::__mClass;

void WeaponTemplate_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("weapons.WeaponTemplate"), hx::TCanCast< WeaponTemplate_obj> ,sStaticFields,sMemberFields,
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

void WeaponTemplate_obj::__boot()
{
}

} // end namespace weapons

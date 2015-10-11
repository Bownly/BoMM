#include <hxcpp.h>

#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
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
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_weapons_Bullet
#include <weapons/Bullet.h>
#endif
#ifndef INCLUDED_weapons_Spore
#include <weapons/Spore.h>
#endif
namespace weapons{

Void Spore_obj::__construct(Float X,Float Y,Float Speed,int Direction,int Damage,int Range,int Palette)
{
HX_STACK_FRAME("weapons.Spore","new",0x518ee7a0,"weapons.Spore.new","weapons/Spore.hx",7,0xa8d554d1)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
HX_STACK_ARG(Speed,"Speed")
HX_STACK_ARG(Direction,"Direction")
HX_STACK_ARG(Damage,"Damage")
HX_STACK_ARG(Range,"Range")
HX_STACK_ARG(Palette,"Palette")
{
	HX_STACK_LINE(9)
	this->gravity = (int)-30;
	HX_STACK_LINE(13)
	super::__construct(X,Y,Speed,Direction,Damage,Range);
	HX_STACK_LINE(14)
	this->loadGraphic(HX_CSTRING("assets/images/spore.png"),true,(int)16,(int)16,true,null());
	HX_STACK_LINE(15)
	this->acceleration->set_y(-(this->gravity));
	HX_STACK_LINE(17)
	int clrBfr = (Palette * (int)4);		HX_STACK_VAR(clrBfr,"clrBfr");
	HX_STACK_LINE(19)
	this->animation->add(HX_CSTRING("spore"),Array_obj< int >::__new().Add(clrBfr).Add(((int)1 + clrBfr)).Add(((int)2 + clrBfr)).Add(((int)3 + clrBfr)).Add(((int)2 + clrBfr)).Add(((int)3 + clrBfr)).Add(((int)2 + clrBfr)).Add(((int)3 + clrBfr)).Add(((int)2 + clrBfr)).Add(((int)3 + clrBfr)),(int)2,true);
}
;
	return null();
}

//Spore_obj::~Spore_obj() { }

Dynamic Spore_obj::__CreateEmpty() { return  new Spore_obj; }
hx::ObjectPtr< Spore_obj > Spore_obj::__new(Float X,Float Y,Float Speed,int Direction,int Damage,int Range,int Palette)
{  hx::ObjectPtr< Spore_obj > result = new Spore_obj();
	result->__construct(X,Y,Speed,Direction,Damage,Range,Palette);
	return result;}

Dynamic Spore_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Spore_obj > result = new Spore_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6]);
	return result;}

Void Spore_obj::update( ){
{
		HX_STACK_FRAME("weapons.Spore","update",0xcae076c9,"weapons.Spore.update","weapons/Spore.hx",26,0xa8d554d1)
		HX_STACK_THIS(this)
		HX_STACK_LINE(27)
		this->animation->play(HX_CSTRING("spore"),null(),null());
		HX_STACK_LINE(28)
		this->super::update();
	}
return null();
}



Spore_obj::Spore_obj()
{
}

Dynamic Spore_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"gravity") ) { return gravity; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Spore_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"gravity") ) { gravity=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Spore_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("gravity"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Spore_obj,gravity),HX_CSTRING("gravity")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("gravity"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Spore_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Spore_obj::__mClass,"__mClass");
};

#endif

Class Spore_obj::__mClass;

void Spore_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("weapons.Spore"), hx::TCanCast< Spore_obj> ,sStaticFields,sMemberFields,
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

void Spore_obj::__boot()
{
}

} // end namespace weapons

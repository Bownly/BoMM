#include <hxcpp.h>

#ifndef INCLUDED_Player
#include <Player.h>
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
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
namespace enemies{

Void BalunString_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp)
{
HX_STACK_FRAME("enemies.BalunString","new",0xf37feb61,"enemies.BalunString.new","enemies/BalunString.hx",11,0x2b4ffaf0)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_X,"X")
HX_STACK_ARG(__o_Y,"Y")
HX_STACK_ARG(ThePlayer,"ThePlayer")
HX_STACK_ARG(DropsGrp,"DropsGrp")
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
{
	HX_STACK_LINE(15)
	this->_HP = (int)9999;
	HX_STACK_LINE(19)
	super::__construct(X,Y,ThePlayer,this->_HP,DropsGrp);
	HX_STACK_LINE(20)
	this->loadGraphic(HX_CSTRING("assets/images/balun.png"),true,(int)16,(int)16,null(),null());
	HX_STACK_LINE(21)
	this->set_width((int)0);
	HX_STACK_LINE(22)
	this->set_height((int)0);
	HX_STACK_LINE(24)
	this->_moving = (int)0;
	HX_STACK_LINE(26)
	this->animation->add(HX_CSTRING("idle"),Array_obj< int >::__new().Add((int)8).Add((int)9),(int)3,true);
	HX_STACK_LINE(27)
	this->animation->add(HX_CSTRING("left"),Array_obj< int >::__new().Add((int)10).Add((int)11),(int)6,true);
	HX_STACK_LINE(28)
	this->animation->add(HX_CSTRING("right"),Array_obj< int >::__new().Add((int)12).Add((int)13),(int)6,true);
}
;
	return null();
}

//BalunString_obj::~BalunString_obj() { }

Dynamic BalunString_obj::__CreateEmpty() { return  new BalunString_obj; }
hx::ObjectPtr< BalunString_obj > BalunString_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp)
{  hx::ObjectPtr< BalunString_obj > result = new BalunString_obj();
	result->__construct(__o_X,__o_Y,ThePlayer,DropsGrp);
	return result;}

Dynamic BalunString_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BalunString_obj > result = new BalunString_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void BalunString_obj::update( ){
{
		HX_STACK_FRAME("enemies.BalunString","update",0xb0c581a8,"enemies.BalunString.update","enemies/BalunString.hx",33,0x2b4ffaf0)
		HX_STACK_THIS(this)
		HX_STACK_LINE(33)
		if (((this->alive == true))){
			HX_STACK_LINE(35)
			if (((this->_moving == (int)0))){
				HX_STACK_LINE(36)
				this->animation->play(HX_CSTRING("idle"),null(),null());
			}
			else{
				HX_STACK_LINE(37)
				if (((this->_moving == (int)1))){
					HX_STACK_LINE(39)
					this->animation->play(HX_CSTRING("left"),null(),null());
				}
				else{
					HX_STACK_LINE(41)
					if (((this->_moving == (int)16))){
						HX_STACK_LINE(43)
						this->animation->play(HX_CSTRING("right"),null(),null());
					}
				}
			}
			HX_STACK_LINE(45)
			this->super::update();
		}
	}
return null();
}



BalunString_obj::BalunString_obj()
{
}

Dynamic BalunString_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_HP") ) { return _HP; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_moving") ) { return _moving; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BalunString_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_HP") ) { _HP=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_moving") ) { _moving=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BalunString_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_moving"));
	outFields->push(HX_CSTRING("_HP"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(BalunString_obj,_moving),HX_CSTRING("_moving")},
	{hx::fsInt,(int)offsetof(BalunString_obj,_HP),HX_CSTRING("_HP")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_moving"),
	HX_CSTRING("_HP"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BalunString_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BalunString_obj::__mClass,"__mClass");
};

#endif

Class BalunString_obj::__mClass;

void BalunString_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("enemies.BalunString"), hx::TCanCast< BalunString_obj> ,sStaticFields,sMemberFields,
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

void BalunString_obj::__boot()
{
}

} // end namespace enemies

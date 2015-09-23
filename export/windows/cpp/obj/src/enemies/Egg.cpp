#include <hxcpp.h>

#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_enemies_BabyBurd
#include <enemies/BabyBurd.h>
#endif
#ifndef INCLUDED_enemies_Egg
#include <enemies/Egg.h>
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
namespace enemies{

Void Egg_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,int XVel,::flixel::group::FlxGroup Enemies)
{
HX_STACK_FRAME("enemies.Egg","new",0x845d8d4f,"enemies.Egg.new","enemies/Egg.hx",17,0x2b5347c2)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_X,"X")
HX_STACK_ARG(__o_Y,"Y")
HX_STACK_ARG(ThePlayer,"ThePlayer")
HX_STACK_ARG(DropsGrp,"DropsGrp")
HX_STACK_ARG(XVel,"XVel")
HX_STACK_ARG(Enemies,"Enemies")
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
{
	HX_STACK_LINE(23)
	this->_cracked = false;
	HX_STACK_LINE(21)
	this->_HP = (int)1;
	HX_STACK_LINE(20)
	this->GRAVITY = (int)9800;
	HX_STACK_LINE(33)
	super::__construct(X,Y,ThePlayer,this->_HP,DropsGrp);
	HX_STACK_LINE(34)
	this->XSPEED = XVel;
	HX_STACK_LINE(36)
	this->loadGraphic(HX_CSTRING("assets/images/burdegg.png"),true,(int)16,(int)8,null(),null());
	HX_STACK_LINE(37)
	this->set_width((int)16);
	HX_STACK_LINE(38)
	this->set_height((int)8);
	HX_STACK_LINE(40)
	this->enemArray = Enemies;
	HX_STACK_LINE(41)
	::flixel::group::FlxTypedGroup _g = ::flixel::group::FlxTypedGroup_obj::__new(null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(41)
	this->burdArray = _g;
	HX_STACK_LINE(43)
	this->animation->add(HX_CSTRING("idle"),Array_obj< int >::__new().Add((int)0),null(),null());
	HX_STACK_LINE(44)
	this->animation->add(HX_CSTRING("open"),Array_obj< int >::__new().Add((int)1),null(),null());
}
;
	return null();
}

//Egg_obj::~Egg_obj() { }

Dynamic Egg_obj::__CreateEmpty() { return  new Egg_obj; }
hx::ObjectPtr< Egg_obj > Egg_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,int XVel,::flixel::group::FlxGroup Enemies)
{  hx::ObjectPtr< Egg_obj > result = new Egg_obj();
	result->__construct(__o_X,__o_Y,ThePlayer,DropsGrp,XVel,Enemies);
	return result;}

Dynamic Egg_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Egg_obj > result = new Egg_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

Void Egg_obj::update( ){
{
		HX_STACK_FRAME("enemies.Egg","update",0x50b3487a,"enemies.Egg.update","enemies/Egg.hx",49,0x2b5347c2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(49)
		if ((this->isOnScreen(null()))){
			HX_STACK_LINE(51)
			this->velocity->set_x(this->XSPEED);
			HX_STACK_LINE(52)
			this->velocity->set_y((int)0);
			HX_STACK_LINE(53)
			if (((this->_cracked == false))){
				HX_STACK_LINE(54)
				this->animation->play(HX_CSTRING("idle"),null(),null());
			}
			else{
				HX_STACK_LINE(56)
				this->animation->play(HX_CSTRING("open"),null(),null());
			}
			HX_STACK_LINE(58)
			if (((((int(this->touching) & int((int)4096))) > (int)0))){
				HX_STACK_LINE(60)
				this->spawnBirds();
				HX_STACK_LINE(61)
				this->_cracked = true;
				HX_STACK_LINE(62)
				this->animation->play(HX_CSTRING("open"),null(),null());
				HX_STACK_LINE(63)
				this->kill();
			}
			HX_STACK_LINE(65)
			this->super::update();
		}
	}
return null();
}


Void Egg_obj::dropped( ){
{
		HX_STACK_FRAME("enemies.Egg","dropped",0xb545846f,"enemies.Egg.dropped","enemies/Egg.hx",71,0x2b5347c2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(71)
		this->acceleration->set_y(this->GRAVITY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Egg_obj,dropped,(void))

Void Egg_obj::spawnBirds( ){
{
		HX_STACK_FRAME("enemies.Egg","spawnBirds",0x5e19c3d0,"enemies.Egg.spawnBirds","enemies/Egg.hx",75,0x2b5347c2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(76)
		::enemies::BabyBurd _g = ::enemies::BabyBurd_obj::__new(this->x,this->y,this->_player,this->_drops);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(76)
		this->babby = _g;
		HX_STACK_LINE(77)
		::enemies::BabyBurd _g1 = ::enemies::BabyBurd_obj::__new(this->x,(this->y - (int)10),this->_player,this->_drops);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(77)
		this->babby2 = _g1;
		HX_STACK_LINE(78)
		Float _g2 = this->get_height();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(78)
		Float _g3 = ((this->y - (int)10) + _g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(78)
		::enemies::BabyBurd _g4 = ::enemies::BabyBurd_obj::__new((this->x + (int)10),_g3,this->_player,this->_drops);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(78)
		this->babby3 = _g4;
		HX_STACK_LINE(79)
		Float _g5 = this->get_height();		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(79)
		Float _g6 = ((this->y - (int)10) + _g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(79)
		::enemies::BabyBurd _g7 = ::enemies::BabyBurd_obj::__new((this->x - (int)10),_g6,this->_player,this->_drops);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(79)
		this->babby4 = _g7;
		HX_STACK_LINE(81)
		this->burdArray->add(this->babby);
		HX_STACK_LINE(82)
		this->burdArray->add(this->babby2);
		HX_STACK_LINE(83)
		this->burdArray->add(this->babby3);
		HX_STACK_LINE(84)
		this->burdArray->add(this->babby4);
		HX_STACK_LINE(86)
		this->enemArray->add(this->burdArray);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Egg_obj,spawnBirds,(void))


Egg_obj::Egg_obj()
{
}

void Egg_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Egg);
	HX_MARK_MEMBER_NAME(XSPEED,"XSPEED");
	HX_MARK_MEMBER_NAME(GRAVITY,"GRAVITY");
	HX_MARK_MEMBER_NAME(_HP,"_HP");
	HX_MARK_MEMBER_NAME(_cracked,"_cracked");
	HX_MARK_MEMBER_NAME(babby,"babby");
	HX_MARK_MEMBER_NAME(babby2,"babby2");
	HX_MARK_MEMBER_NAME(babby3,"babby3");
	HX_MARK_MEMBER_NAME(babby4,"babby4");
	HX_MARK_MEMBER_NAME(burdArray,"burdArray");
	HX_MARK_MEMBER_NAME(enemArray,"enemArray");
	::enemies::EnemyTemplate_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Egg_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(XSPEED,"XSPEED");
	HX_VISIT_MEMBER_NAME(GRAVITY,"GRAVITY");
	HX_VISIT_MEMBER_NAME(_HP,"_HP");
	HX_VISIT_MEMBER_NAME(_cracked,"_cracked");
	HX_VISIT_MEMBER_NAME(babby,"babby");
	HX_VISIT_MEMBER_NAME(babby2,"babby2");
	HX_VISIT_MEMBER_NAME(babby3,"babby3");
	HX_VISIT_MEMBER_NAME(babby4,"babby4");
	HX_VISIT_MEMBER_NAME(burdArray,"burdArray");
	HX_VISIT_MEMBER_NAME(enemArray,"enemArray");
	::enemies::EnemyTemplate_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Egg_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_HP") ) { return _HP; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"babby") ) { return babby; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"XSPEED") ) { return XSPEED; }
		if (HX_FIELD_EQ(inName,"babby2") ) { return babby2; }
		if (HX_FIELD_EQ(inName,"babby3") ) { return babby3; }
		if (HX_FIELD_EQ(inName,"babby4") ) { return babby4; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"GRAVITY") ) { return GRAVITY; }
		if (HX_FIELD_EQ(inName,"dropped") ) { return dropped_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_cracked") ) { return _cracked; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"burdArray") ) { return burdArray; }
		if (HX_FIELD_EQ(inName,"enemArray") ) { return enemArray; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"spawnBirds") ) { return spawnBirds_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Egg_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_HP") ) { _HP=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"babby") ) { babby=inValue.Cast< ::enemies::BabyBurd >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"XSPEED") ) { XSPEED=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"babby2") ) { babby2=inValue.Cast< ::enemies::BabyBurd >(); return inValue; }
		if (HX_FIELD_EQ(inName,"babby3") ) { babby3=inValue.Cast< ::enemies::BabyBurd >(); return inValue; }
		if (HX_FIELD_EQ(inName,"babby4") ) { babby4=inValue.Cast< ::enemies::BabyBurd >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"GRAVITY") ) { GRAVITY=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_cracked") ) { _cracked=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"burdArray") ) { burdArray=inValue.Cast< ::flixel::group::FlxTypedGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"enemArray") ) { enemArray=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Egg_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("XSPEED"));
	outFields->push(HX_CSTRING("GRAVITY"));
	outFields->push(HX_CSTRING("_HP"));
	outFields->push(HX_CSTRING("_cracked"));
	outFields->push(HX_CSTRING("babby"));
	outFields->push(HX_CSTRING("babby2"));
	outFields->push(HX_CSTRING("babby3"));
	outFields->push(HX_CSTRING("babby4"));
	outFields->push(HX_CSTRING("burdArray"));
	outFields->push(HX_CSTRING("enemArray"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Egg_obj,XSPEED),HX_CSTRING("XSPEED")},
	{hx::fsInt,(int)offsetof(Egg_obj,GRAVITY),HX_CSTRING("GRAVITY")},
	{hx::fsInt,(int)offsetof(Egg_obj,_HP),HX_CSTRING("_HP")},
	{hx::fsBool,(int)offsetof(Egg_obj,_cracked),HX_CSTRING("_cracked")},
	{hx::fsObject /*::enemies::BabyBurd*/ ,(int)offsetof(Egg_obj,babby),HX_CSTRING("babby")},
	{hx::fsObject /*::enemies::BabyBurd*/ ,(int)offsetof(Egg_obj,babby2),HX_CSTRING("babby2")},
	{hx::fsObject /*::enemies::BabyBurd*/ ,(int)offsetof(Egg_obj,babby3),HX_CSTRING("babby3")},
	{hx::fsObject /*::enemies::BabyBurd*/ ,(int)offsetof(Egg_obj,babby4),HX_CSTRING("babby4")},
	{hx::fsObject /*::flixel::group::FlxTypedGroup*/ ,(int)offsetof(Egg_obj,burdArray),HX_CSTRING("burdArray")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(Egg_obj,enemArray),HX_CSTRING("enemArray")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("XSPEED"),
	HX_CSTRING("GRAVITY"),
	HX_CSTRING("_HP"),
	HX_CSTRING("_cracked"),
	HX_CSTRING("babby"),
	HX_CSTRING("babby2"),
	HX_CSTRING("babby3"),
	HX_CSTRING("babby4"),
	HX_CSTRING("burdArray"),
	HX_CSTRING("enemArray"),
	HX_CSTRING("update"),
	HX_CSTRING("dropped"),
	HX_CSTRING("spawnBirds"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Egg_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Egg_obj::__mClass,"__mClass");
};

#endif

Class Egg_obj::__mClass;

void Egg_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("enemies.Egg"), hx::TCanCast< Egg_obj> ,sStaticFields,sMemberFields,
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

void Egg_obj::__boot()
{
}

} // end namespace enemies

#include <hxcpp.h>

#ifndef INCLUDED_Drops
#include <Drops.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
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
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
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
#ifndef INCLUDED_flixel_util_FlxRandom
#include <flixel/util/FlxRandom.h>
#endif
namespace enemies{

Void EnemyTemplate_obj::__construct(Float X,Float Y,::Player ThePlayer,int Health,::flixel::group::FlxTypedGroup DropsGrp)
{
HX_STACK_FRAME("enemies.EnemyTemplate","new",0x37170eac,"enemies.EnemyTemplate.new","enemies/EnemyTemplate.hx",25,0x14fe3c45)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
HX_STACK_ARG(ThePlayer,"ThePlayer")
HX_STACK_ARG(Health,"Health")
HX_STACK_ARG(DropsGrp,"DropsGrp")
{
	HX_STACK_LINE(36)
	this->YELLOW = (int)3;
	HX_STACK_LINE(35)
	this->MAGENTA = (int)2;
	HX_STACK_LINE(34)
	this->CYAN = (int)1;
	HX_STACK_LINE(33)
	this->GREY = (int)0;
	HX_STACK_LINE(30)
	this->_health = (int)2;
	HX_STACK_LINE(41)
	super::__construct(X,Y,null());
	HX_STACK_LINE(42)
	this->_startx = X;
	HX_STACK_LINE(43)
	this->_starty = Y;
	HX_STACK_LINE(44)
	this->_player = ThePlayer;
	HX_STACK_LINE(45)
	this->_health = Health;
	HX_STACK_LINE(46)
	this->_drops = DropsGrp;
}
;
	return null();
}

//EnemyTemplate_obj::~EnemyTemplate_obj() { }

Dynamic EnemyTemplate_obj::__CreateEmpty() { return  new EnemyTemplate_obj; }
hx::ObjectPtr< EnemyTemplate_obj > EnemyTemplate_obj::__new(Float X,Float Y,::Player ThePlayer,int Health,::flixel::group::FlxTypedGroup DropsGrp)
{  hx::ObjectPtr< EnemyTemplate_obj > result = new EnemyTemplate_obj();
	result->__construct(X,Y,ThePlayer,Health,DropsGrp);
	return result;}

Dynamic EnemyTemplate_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EnemyTemplate_obj > result = new EnemyTemplate_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

Void EnemyTemplate_obj::takeDamage( int damage){
{
		HX_STACK_FRAME("enemies.EnemyTemplate","takeDamage",0x5bf80f4a,"enemies.EnemyTemplate.takeDamage","enemies/EnemyTemplate.hx",50,0x14fe3c45)
		HX_STACK_THIS(this)
		HX_STACK_ARG(damage,"damage")
		HX_STACK_LINE(53)
		hx::SubEq(this->_health,damage);
		HX_STACK_LINE(55)
		if (((this->_health <= (int)0))){
			HX_STACK_LINE(56)
			this->kill();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(EnemyTemplate_obj,takeDamage,(void))

Void EnemyTemplate_obj::kill( ){
{
		HX_STACK_FRAME("enemies.EnemyTemplate","kill",0xfb1d23d2,"enemies.EnemyTemplate.kill","enemies/EnemyTemplate.hx",60,0x14fe3c45)
		HX_STACK_THIS(this)
		HX_STACK_LINE(61)
		int dropChance = ::flixel::util::FlxRandom_obj::intRanged((int)0,(int)1,null());		HX_STACK_VAR(dropChance,"dropChance");
		HX_STACK_LINE(62)
		int dropChance1 = (int)1;		HX_STACK_VAR(dropChance1,"dropChance1");
		HX_STACK_LINE(63)
		int _g = ::flixel::util::FlxRandom_obj::intRanged((int)0,(int)3,null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(63)
		int dropID = (_g * (int)2);		HX_STACK_VAR(dropID,"dropID");
		HX_STACK_LINE(65)
		::Drops newDrop = ::Drops_obj::__new(this->x,this->y,dropID,this->_player,true);		HX_STACK_VAR(newDrop,"newDrop");
		HX_STACK_LINE(66)
		this->_drops->add(newDrop);
		HX_STACK_LINE(68)
		this->set_alive(false);
		struct _Function_1_1{
			inline static Dynamic Block( hx::ObjectPtr< ::enemies::EnemyTemplate_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","enemies/EnemyTemplate.hx",69,0x14fe3c45)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("alpha") , (int)0,false);
					__result->Add(HX_CSTRING("y") , (__this->y - (int)16),false);
					return __result;
				}
				return null();
			}
		};
		struct _Function_1_2{
			inline static Dynamic Block( hx::ObjectPtr< ::enemies::EnemyTemplate_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","enemies/EnemyTemplate.hx",69,0x14fe3c45)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("ease") , ::flixel::tweens::FlxEase_obj::circOut_dyn(),false);
					__result->Add(HX_CSTRING("complete") , __this->finishKill_dyn(),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(69)
		::flixel::tweens::FlxTween_obj::tween(hx::ObjectPtr<OBJ_>(this),_Function_1_1::Block(this),.33,_Function_1_2::Block(this));
	}
return null();
}


Void EnemyTemplate_obj::finishKill( ::flixel::tweens::FlxTween _){
{
		HX_STACK_FRAME("enemies.EnemyTemplate","finishKill",0x7d7ed4c5,"enemies.EnemyTemplate.finishKill","enemies/EnemyTemplate.hx",76,0x14fe3c45)
		HX_STACK_THIS(this)
		HX_STACK_ARG(_,"_")
		HX_STACK_LINE(76)
		this->set_exists(false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(EnemyTemplate_obj,finishKill,(void))


EnemyTemplate_obj::EnemyTemplate_obj()
{
}

void EnemyTemplate_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EnemyTemplate);
	HX_MARK_MEMBER_NAME(_startx,"_startx");
	HX_MARK_MEMBER_NAME(_starty,"_starty");
	HX_MARK_MEMBER_NAME(_player,"_player");
	HX_MARK_MEMBER_NAME(_health,"_health");
	HX_MARK_MEMBER_NAME(_drops,"_drops");
	HX_MARK_MEMBER_NAME(GREY,"GREY");
	HX_MARK_MEMBER_NAME(CYAN,"CYAN");
	HX_MARK_MEMBER_NAME(MAGENTA,"MAGENTA");
	HX_MARK_MEMBER_NAME(YELLOW,"YELLOW");
	::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void EnemyTemplate_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_startx,"_startx");
	HX_VISIT_MEMBER_NAME(_starty,"_starty");
	HX_VISIT_MEMBER_NAME(_player,"_player");
	HX_VISIT_MEMBER_NAME(_health,"_health");
	HX_VISIT_MEMBER_NAME(_drops,"_drops");
	HX_VISIT_MEMBER_NAME(GREY,"GREY");
	HX_VISIT_MEMBER_NAME(CYAN,"CYAN");
	HX_VISIT_MEMBER_NAME(MAGENTA,"MAGENTA");
	HX_VISIT_MEMBER_NAME(YELLOW,"YELLOW");
	::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic EnemyTemplate_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"GREY") ) { return GREY; }
		if (HX_FIELD_EQ(inName,"CYAN") ) { return CYAN; }
		if (HX_FIELD_EQ(inName,"kill") ) { return kill_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_drops") ) { return _drops; }
		if (HX_FIELD_EQ(inName,"YELLOW") ) { return YELLOW; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_startx") ) { return _startx; }
		if (HX_FIELD_EQ(inName,"_starty") ) { return _starty; }
		if (HX_FIELD_EQ(inName,"_player") ) { return _player; }
		if (HX_FIELD_EQ(inName,"_health") ) { return _health; }
		if (HX_FIELD_EQ(inName,"MAGENTA") ) { return MAGENTA; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"takeDamage") ) { return takeDamage_dyn(); }
		if (HX_FIELD_EQ(inName,"finishKill") ) { return finishKill_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EnemyTemplate_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"GREY") ) { GREY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CYAN") ) { CYAN=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_drops") ) { _drops=inValue.Cast< ::flixel::group::FlxTypedGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"YELLOW") ) { YELLOW=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_startx") ) { _startx=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_starty") ) { _starty=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_player") ) { _player=inValue.Cast< ::Player >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_health") ) { _health=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MAGENTA") ) { MAGENTA=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EnemyTemplate_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_startx"));
	outFields->push(HX_CSTRING("_starty"));
	outFields->push(HX_CSTRING("_player"));
	outFields->push(HX_CSTRING("_health"));
	outFields->push(HX_CSTRING("_drops"));
	outFields->push(HX_CSTRING("GREY"));
	outFields->push(HX_CSTRING("CYAN"));
	outFields->push(HX_CSTRING("MAGENTA"));
	outFields->push(HX_CSTRING("YELLOW"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(EnemyTemplate_obj,_startx),HX_CSTRING("_startx")},
	{hx::fsFloat,(int)offsetof(EnemyTemplate_obj,_starty),HX_CSTRING("_starty")},
	{hx::fsObject /*::Player*/ ,(int)offsetof(EnemyTemplate_obj,_player),HX_CSTRING("_player")},
	{hx::fsInt,(int)offsetof(EnemyTemplate_obj,_health),HX_CSTRING("_health")},
	{hx::fsObject /*::flixel::group::FlxTypedGroup*/ ,(int)offsetof(EnemyTemplate_obj,_drops),HX_CSTRING("_drops")},
	{hx::fsInt,(int)offsetof(EnemyTemplate_obj,GREY),HX_CSTRING("GREY")},
	{hx::fsInt,(int)offsetof(EnemyTemplate_obj,CYAN),HX_CSTRING("CYAN")},
	{hx::fsInt,(int)offsetof(EnemyTemplate_obj,MAGENTA),HX_CSTRING("MAGENTA")},
	{hx::fsInt,(int)offsetof(EnemyTemplate_obj,YELLOW),HX_CSTRING("YELLOW")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_startx"),
	HX_CSTRING("_starty"),
	HX_CSTRING("_player"),
	HX_CSTRING("_health"),
	HX_CSTRING("_drops"),
	HX_CSTRING("GREY"),
	HX_CSTRING("CYAN"),
	HX_CSTRING("MAGENTA"),
	HX_CSTRING("YELLOW"),
	HX_CSTRING("takeDamage"),
	HX_CSTRING("kill"),
	HX_CSTRING("finishKill"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EnemyTemplate_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EnemyTemplate_obj::__mClass,"__mClass");
};

#endif

Class EnemyTemplate_obj::__mClass;

void EnemyTemplate_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("enemies.EnemyTemplate"), hx::TCanCast< EnemyTemplate_obj> ,sStaticFields,sMemberFields,
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

void EnemyTemplate_obj::__boot()
{
}

} // end namespace enemies

#include <hxcpp.h>

#ifndef INCLUDED_Drops
#include <Drops.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
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
#ifndef INCLUDED_weapons_WeaponTemplate
#include <weapons/WeaponTemplate.h>
#endif

Void Drops_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,int Index,::Player ThePlayer)
{
HX_STACK_FRAME("Drops","new",0xa62df436,"Drops.new","Drops.hx",11,0xe09a03fa)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_X,"X")
HX_STACK_ARG(__o_Y,"Y")
HX_STACK_ARG(Index,"Index")
HX_STACK_ARG(ThePlayer,"ThePlayer")
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
{
	HX_STACK_LINE(15)
	this->i = (int)0;
	HX_STACK_LINE(26)
	super::__construct(X,Y,null());
	HX_STACK_LINE(27)
	this->loadGraphic(HX_CSTRING("assets/images/drops.png"),false,(int)8,(int)8,null(),null());
	HX_STACK_LINE(28)
	this->set_width((int)8);
	HX_STACK_LINE(29)
	this->set_height((int)8);
	HX_STACK_LINE(31)
	this->_player = ThePlayer;
	HX_STACK_LINE(32)
	this->i = Index;
	HX_STACK_LINE(34)
	this->animation->add(HX_CSTRING("idle"),Array_obj< int >::__new().Add(this->i).Add((this->i + (int)1)),(int)5,true);
}
;
	return null();
}

//Drops_obj::~Drops_obj() { }

Dynamic Drops_obj::__CreateEmpty() { return  new Drops_obj; }
hx::ObjectPtr< Drops_obj > Drops_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,int Index,::Player ThePlayer)
{  hx::ObjectPtr< Drops_obj > result = new Drops_obj();
	result->__construct(__o_X,__o_Y,Index,ThePlayer);
	return result;}

Dynamic Drops_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Drops_obj > result = new Drops_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void Drops_obj::update( ){
{
		HX_STACK_FRAME("Drops","update",0x3556ebf3,"Drops.update","Drops.hx",40,0xe09a03fa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(40)
		if ((this->isOnScreen(null()))){
			HX_STACK_LINE(42)
			this->animation->play(HX_CSTRING("idle"),null(),null());
			HX_STACK_LINE(43)
			this->super::update();
		}
	}
return null();
}


Void Drops_obj::playerHeal( int Val){
{
		HX_STACK_FRAME("Drops","playerHeal",0x86f8a813,"Drops.playerHeal","Drops.hx",49,0xe09a03fa)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Val,"Val")
		HX_STACK_LINE(49)
		hx::AddEq(this->_player->hp,Val);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Drops_obj,playerHeal,(void))

Void Drops_obj::playerJuiceRestore( int Val){
{
		HX_STACK_FRAME("Drops","playerJuiceRestore",0x45f0a5b9,"Drops.playerJuiceRestore","Drops.hx",54,0xe09a03fa)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Val,"Val")
		HX_STACK_LINE(54)
		if ((((this->_player->curWeapon->juice + Val) > this->_player->curWeapon->juiceMax))){
			HX_STACK_LINE(55)
			this->_player->curWeapon->juice = this->_player->curWeapon->juiceMax;
		}
		else{
			HX_STACK_LINE(57)
			hx::AddEq(this->_player->curWeapon->juice,Val);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Drops_obj,playerJuiceRestore,(void))

Void Drops_obj::weaponStrengthUp( int Val){
{
		HX_STACK_FRAME("Drops","weaponStrengthUp",0x95c973a2,"Drops.weaponStrengthUp","Drops.hx",62,0xe09a03fa)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Val,"Val")
		HX_STACK_LINE(62)
		hx::AddEq(this->_player->curWeapon->damage,Val);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Drops_obj,weaponStrengthUp,(void))

Void Drops_obj::doStuff( ){
{
		HX_STACK_FRAME("Drops","doStuff",0x902f3e3f,"Drops.doStuff","Drops.hx",68,0xe09a03fa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(68)
		int _g = this->i;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(68)
		switch( (int)(_g)){
			case (int)0: {
				HX_STACK_LINE(72)
				this->playerHeal((int)10);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(75)
				this->playerHeal((int)20);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(78)
				this->playerJuiceRestore((int)5);
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(81)
				this->weaponStrengthUp((int)1);
			}
			;break;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Drops_obj,doStuff,(void))

Void Drops_obj::kill( ){
{
		HX_STACK_FRAME("Drops","kill",0xc00f1708,"Drops.kill","Drops.hx",86,0xe09a03fa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(87)
		this->set_alive(false);
		struct _Function_1_1{
			inline static Dynamic Block( hx::ObjectPtr< ::Drops_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Drops.hx",88,0xe09a03fa)
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
			inline static Dynamic Block( hx::ObjectPtr< ::Drops_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Drops.hx",88,0xe09a03fa)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("ease") , ::flixel::tweens::FlxEase_obj::circOut_dyn(),false);
					__result->Add(HX_CSTRING("complete") , __this->finishKill_dyn(),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(88)
		::flixel::tweens::FlxTween_obj::tween(hx::ObjectPtr<OBJ_>(this),_Function_1_1::Block(this),.33,_Function_1_2::Block(this));
	}
return null();
}


Void Drops_obj::finishKill( ::flixel::tweens::FlxTween _){
{
		HX_STACK_FRAME("Drops","finishKill",0xb270147b,"Drops.finishKill","Drops.hx",93,0xe09a03fa)
		HX_STACK_THIS(this)
		HX_STACK_ARG(_,"_")
		HX_STACK_LINE(93)
		this->set_exists(false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Drops_obj,finishKill,(void))


Drops_obj::Drops_obj()
{
}

void Drops_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Drops);
	HX_MARK_MEMBER_NAME(_player,"_player");
	HX_MARK_MEMBER_NAME(i,"i");
	::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Drops_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_player,"_player");
	HX_VISIT_MEMBER_NAME(i,"i");
	::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Drops_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"i") ) { return i; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"kill") ) { return kill_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_player") ) { return _player; }
		if (HX_FIELD_EQ(inName,"doStuff") ) { return doStuff_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"playerHeal") ) { return playerHeal_dyn(); }
		if (HX_FIELD_EQ(inName,"finishKill") ) { return finishKill_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"weaponStrengthUp") ) { return weaponStrengthUp_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"playerJuiceRestore") ) { return playerJuiceRestore_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Drops_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"i") ) { i=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_player") ) { _player=inValue.Cast< ::Player >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Drops_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_player"));
	outFields->push(HX_CSTRING("i"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::Player*/ ,(int)offsetof(Drops_obj,_player),HX_CSTRING("_player")},
	{hx::fsInt,(int)offsetof(Drops_obj,i),HX_CSTRING("i")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_player"),
	HX_CSTRING("i"),
	HX_CSTRING("update"),
	HX_CSTRING("playerHeal"),
	HX_CSTRING("playerJuiceRestore"),
	HX_CSTRING("weaponStrengthUp"),
	HX_CSTRING("doStuff"),
	HX_CSTRING("kill"),
	HX_CSTRING("finishKill"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Drops_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Drops_obj::__mClass,"__mClass");
};

#endif

Class Drops_obj::__mClass;

void Drops_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Drops"), hx::TCanCast< Drops_obj> ,sStaticFields,sMemberFields,
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

void Drops_obj::__boot()
{
}


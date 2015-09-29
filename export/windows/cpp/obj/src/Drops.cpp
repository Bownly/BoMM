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

Void Drops_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,int Index,::Player ThePlayer,bool Free)
{
HX_STACK_FRAME("Drops","new",0xa62df436,"Drops.new","Drops.hx",11,0xe09a03fa)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_X,"X")
HX_STACK_ARG(__o_Y,"Y")
HX_STACK_ARG(Index,"Index")
HX_STACK_ARG(ThePlayer,"ThePlayer")
HX_STACK_ARG(Free,"Free")
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
{
	HX_STACK_LINE(17)
	this->free = true;
	HX_STACK_LINE(16)
	this->price = (int)0;
	HX_STACK_LINE(15)
	this->id = (int)0;
	HX_STACK_LINE(28)
	super::__construct(X,Y,null());
	HX_STACK_LINE(29)
	this->loadGraphic(HX_CSTRING("assets/images/drops.png"),false,(int)8,(int)8,null(),null());
	HX_STACK_LINE(30)
	this->set_width((int)8);
	HX_STACK_LINE(31)
	this->set_height((int)8);
	HX_STACK_LINE(33)
	this->free = Free;
	HX_STACK_LINE(35)
	this->_player = ThePlayer;
	HX_STACK_LINE(36)
	this->id = Index;
	HX_STACK_LINE(38)
	this->animation->add(HX_CSTRING("idle"),Array_obj< int >::__new().Add(this->id).Add((this->id + (int)1)),(int)5,true);
	HX_STACK_LINE(40)
	int _g = this->allocatePrices();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(40)
	this->price = _g;
}
;
	return null();
}

//Drops_obj::~Drops_obj() { }

Dynamic Drops_obj::__CreateEmpty() { return  new Drops_obj; }
hx::ObjectPtr< Drops_obj > Drops_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,int Index,::Player ThePlayer,bool Free)
{  hx::ObjectPtr< Drops_obj > result = new Drops_obj();
	result->__construct(__o_X,__o_Y,Index,ThePlayer,Free);
	return result;}

Dynamic Drops_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Drops_obj > result = new Drops_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

Void Drops_obj::update( ){
{
		HX_STACK_FRAME("Drops","update",0x3556ebf3,"Drops.update","Drops.hx",46,0xe09a03fa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(46)
		if ((this->isOnScreen(null()))){
			HX_STACK_LINE(48)
			this->animation->play(HX_CSTRING("idle"),null(),null());
			HX_STACK_LINE(49)
			this->super::update();
		}
	}
return null();
}


Void Drops_obj::kill( ){
{
		HX_STACK_FRAME("Drops","kill",0xc00f1708,"Drops.kill","Drops.hx",54,0xe09a03fa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(55)
		this->set_alive(false);
		struct _Function_1_1{
			inline static Dynamic Block( hx::ObjectPtr< ::Drops_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Drops.hx",56,0xe09a03fa)
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
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Drops.hx",56,0xe09a03fa)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("ease") , ::flixel::tweens::FlxEase_obj::circOut_dyn(),false);
					__result->Add(HX_CSTRING("complete") , __this->finishKill_dyn(),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(56)
		::flixel::tweens::FlxTween_obj::tween(hx::ObjectPtr<OBJ_>(this),_Function_1_1::Block(this),.33,_Function_1_2::Block(this));
	}
return null();
}


Void Drops_obj::finishKill( ::flixel::tweens::FlxTween _){
{
		HX_STACK_FRAME("Drops","finishKill",0xb270147b,"Drops.finishKill","Drops.hx",61,0xe09a03fa)
		HX_STACK_THIS(this)
		HX_STACK_ARG(_,"_")
		HX_STACK_LINE(61)
		this->set_exists(false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Drops_obj,finishKill,(void))

int Drops_obj::allocatePrices( ){
	HX_STACK_FRAME("Drops","allocatePrices",0x47833c51,"Drops.allocatePrices","Drops.hx",66,0xe09a03fa)
	HX_STACK_THIS(this)
	HX_STACK_LINE(67)
	{
		HX_STACK_LINE(67)
		int _g = this->id;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(67)
		switch( (int)(_g)){
			case (int)0: {
				HX_STACK_LINE(70)
				return (int)10;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(72)
				return (int)20;
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(74)
				return (int)10;
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(76)
				return (int)30;
			}
			;break;
		}
	}
	HX_STACK_LINE(78)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(Drops_obj,allocatePrices,return )

int Drops_obj::doStuff( int score){
	HX_STACK_FRAME("Drops","doStuff",0x902f3e3f,"Drops.doStuff","Drops.hx",82,0xe09a03fa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(score,"score")
	HX_STACK_LINE(83)
	if (((bool((this->price <= score)) || bool((this->free == true))))){
		HX_STACK_LINE(85)
		{
			HX_STACK_LINE(85)
			int _g = this->id;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(85)
			switch( (int)(_g)){
				case (int)0: {
					HX_STACK_LINE(88)
					this->playerHeal((int)10);
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(90)
					this->playerHeal((int)20);
				}
				;break;
				case (int)4: {
					HX_STACK_LINE(92)
					this->playerJuiceRestore((int)5);
				}
				;break;
				case (int)6: {
					HX_STACK_LINE(94)
					this->weaponStrengthUp((int)1);
				}
				;break;
			}
		}
		HX_STACK_LINE(96)
		if (((this->free == true))){
			HX_STACK_LINE(98)
			this->kill();
			HX_STACK_LINE(99)
			return (int)0;
		}
		else{
			HX_STACK_LINE(103)
			this->kill();
			HX_STACK_LINE(104)
			return this->price;
		}
	}
	HX_STACK_LINE(107)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC1(Drops_obj,doStuff,return )

Void Drops_obj::playerHeal( int Val){
{
		HX_STACK_FRAME("Drops","playerHeal",0x86f8a813,"Drops.playerHeal","Drops.hx",112,0xe09a03fa)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Val,"Val")
		HX_STACK_LINE(112)
		hx::AddEq(this->_player->hp,Val);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Drops_obj,playerHeal,(void))

Void Drops_obj::playerJuiceRestore( int Val){
{
		HX_STACK_FRAME("Drops","playerJuiceRestore",0x45f0a5b9,"Drops.playerJuiceRestore","Drops.hx",117,0xe09a03fa)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Val,"Val")
		HX_STACK_LINE(117)
		if ((((this->_player->curWeapon->juice + Val) > this->_player->curWeapon->juiceMax))){
			HX_STACK_LINE(118)
			this->_player->curWeapon->juice = this->_player->curWeapon->juiceMax;
		}
		else{
			HX_STACK_LINE(120)
			hx::AddEq(this->_player->curWeapon->juice,Val);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Drops_obj,playerJuiceRestore,(void))

Void Drops_obj::weaponStrengthUp( int Val){
{
		HX_STACK_FRAME("Drops","weaponStrengthUp",0x95c973a2,"Drops.weaponStrengthUp","Drops.hx",125,0xe09a03fa)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Val,"Val")
		HX_STACK_LINE(125)
		hx::AddEq(this->_player->curWeapon->damage,Val);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Drops_obj,weaponStrengthUp,(void))


Drops_obj::Drops_obj()
{
}

void Drops_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Drops);
	HX_MARK_MEMBER_NAME(_player,"_player");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(price,"price");
	HX_MARK_MEMBER_NAME(free,"free");
	::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Drops_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_player,"_player");
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(price,"price");
	HX_VISIT_MEMBER_NAME(free,"free");
	::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Drops_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"free") ) { return free; }
		if (HX_FIELD_EQ(inName,"kill") ) { return kill_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"price") ) { return price; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_player") ) { return _player; }
		if (HX_FIELD_EQ(inName,"doStuff") ) { return doStuff_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"finishKill") ) { return finishKill_dyn(); }
		if (HX_FIELD_EQ(inName,"playerHeal") ) { return playerHeal_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"allocatePrices") ) { return allocatePrices_dyn(); }
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
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"free") ) { free=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"price") ) { price=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_player") ) { _player=inValue.Cast< ::Player >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Drops_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_player"));
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("price"));
	outFields->push(HX_CSTRING("free"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::Player*/ ,(int)offsetof(Drops_obj,_player),HX_CSTRING("_player")},
	{hx::fsInt,(int)offsetof(Drops_obj,id),HX_CSTRING("id")},
	{hx::fsInt,(int)offsetof(Drops_obj,price),HX_CSTRING("price")},
	{hx::fsBool,(int)offsetof(Drops_obj,free),HX_CSTRING("free")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_player"),
	HX_CSTRING("id"),
	HX_CSTRING("price"),
	HX_CSTRING("free"),
	HX_CSTRING("update"),
	HX_CSTRING("kill"),
	HX_CSTRING("finishKill"),
	HX_CSTRING("allocatePrices"),
	HX_CSTRING("doStuff"),
	HX_CSTRING("playerHeal"),
	HX_CSTRING("playerJuiceRestore"),
	HX_CSTRING("weaponStrengthUp"),
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


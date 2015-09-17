#include <hxcpp.h>

#ifndef INCLUDED_Coin
#include <Coin.h>
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

Void Coin_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y)
{
HX_STACK_FRAME("Coin","new",0x704aaf23,"Coin.new","Coin.hx",14,0x01a6c5ad)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_X,"X")
HX_STACK_ARG(__o_Y,"Y")
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
{
	HX_STACK_LINE(15)
	super::__construct(X,Y,null());
	HX_STACK_LINE(16)
	this->loadGraphic(HX_CSTRING("assets/images/coin.png"),false,(int)8,(int)8,null(),null());
}
;
	return null();
}

//Coin_obj::~Coin_obj() { }

Dynamic Coin_obj::__CreateEmpty() { return  new Coin_obj; }
hx::ObjectPtr< Coin_obj > Coin_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y)
{  hx::ObjectPtr< Coin_obj > result = new Coin_obj();
	result->__construct(__o_X,__o_Y);
	return result;}

Dynamic Coin_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Coin_obj > result = new Coin_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Coin_obj::kill( ){
{
		HX_STACK_FRAME("Coin","kill",0xcf15eb7b,"Coin.kill","Coin.hx",21,0x01a6c5ad)
		HX_STACK_THIS(this)
		HX_STACK_LINE(22)
		this->set_alive(false);
		struct _Function_1_1{
			inline static Dynamic Block( hx::ObjectPtr< ::Coin_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Coin.hx",23,0x01a6c5ad)
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
			inline static Dynamic Block( hx::ObjectPtr< ::Coin_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Coin.hx",23,0x01a6c5ad)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("ease") , ::flixel::tweens::FlxEase_obj::circOut_dyn(),false);
					__result->Add(HX_CSTRING("complete") , __this->finishKill_dyn(),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(23)
		::flixel::tweens::FlxTween_obj::tween(hx::ObjectPtr<OBJ_>(this),_Function_1_1::Block(this),.33,_Function_1_2::Block(this));
	}
return null();
}


Void Coin_obj::finishKill( ::flixel::tweens::FlxTween _){
{
		HX_STACK_FRAME("Coin","finishKill",0x3e72412e,"Coin.finishKill","Coin.hx",29,0x01a6c5ad)
		HX_STACK_THIS(this)
		HX_STACK_ARG(_,"_")
		HX_STACK_LINE(29)
		this->set_exists(false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Coin_obj,finishKill,(void))


Coin_obj::Coin_obj()
{
}

Dynamic Coin_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"kill") ) { return kill_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"finishKill") ) { return finishKill_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Coin_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Coin_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("kill"),
	HX_CSTRING("finishKill"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Coin_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Coin_obj::__mClass,"__mClass");
};

#endif

Class Coin_obj::__mClass;

void Coin_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Coin"), hx::TCanCast< Coin_obj> ,sStaticFields,sMemberFields,
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

void Coin_obj::__boot()
{
}


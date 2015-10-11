#include <hxcpp.h>

#ifndef INCLUDED_Ladder
#include <Ladder.h>
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

Void Ladder_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,bool Top)
{
HX_STACK_FRAME("Ladder","new",0xbe208af4,"Ladder.new","Ladder.hx",11,0xf8d10efc)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_X,"X")
HX_STACK_ARG(__o_Y,"Y")
HX_STACK_ARG(Top,"Top")
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
{
	HX_STACK_LINE(25)
	this->top = false;
	HX_STACK_LINE(29)
	super::__construct(X,Y,null());
	HX_STACK_LINE(30)
	this->loadGraphic(HX_CSTRING("assets/images/ladder.png"),false,(int)16,(int)16,null(),null());
	HX_STACK_LINE(32)
	this->top = Top;
	HX_STACK_LINE(34)
	this->allowCollisions = (int)256;
}
;
	return null();
}

//Ladder_obj::~Ladder_obj() { }

Dynamic Ladder_obj::__CreateEmpty() { return  new Ladder_obj; }
hx::ObjectPtr< Ladder_obj > Ladder_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,bool Top)
{  hx::ObjectPtr< Ladder_obj > result = new Ladder_obj();
	result->__construct(__o_X,__o_Y,Top);
	return result;}

Dynamic Ladder_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Ladder_obj > result = new Ladder_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Ladder_obj::kill( ){
{
		HX_STACK_FRAME("Ladder","kill",0x9c60668a,"Ladder.kill","Ladder.hx",39,0xf8d10efc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(40)
		this->set_alive(false);
		struct _Function_1_1{
			inline static Dynamic Block( hx::ObjectPtr< ::Ladder_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Ladder.hx",41,0xf8d10efc)
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
			inline static Dynamic Block( hx::ObjectPtr< ::Ladder_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Ladder.hx",41,0xf8d10efc)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("ease") , ::flixel::tweens::FlxEase_obj::circOut_dyn(),false);
					__result->Add(HX_CSTRING("complete") , __this->finishKill_dyn(),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(41)
		::flixel::tweens::FlxTween_obj::tween(hx::ObjectPtr<OBJ_>(this),_Function_1_1::Block(this),.33,_Function_1_2::Block(this));
	}
return null();
}


Void Ladder_obj::finishKill( ::flixel::tweens::FlxTween _){
{
		HX_STACK_FRAME("Ladder","finishKill",0x5f0cf17d,"Ladder.finishKill","Ladder.hx",47,0xf8d10efc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(_,"_")
		HX_STACK_LINE(47)
		this->set_exists(false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Ladder_obj,finishKill,(void))


Ladder_obj::Ladder_obj()
{
}

Dynamic Ladder_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return top; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"kill") ) { return kill_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"finishKill") ) { return finishKill_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Ladder_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { top=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Ladder_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("top"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(Ladder_obj,top),HX_CSTRING("top")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("top"),
	HX_CSTRING("kill"),
	HX_CSTRING("finishKill"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Ladder_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Ladder_obj::__mClass,"__mClass");
};

#endif

Class Ladder_obj::__mClass;

void Ladder_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Ladder"), hx::TCanCast< Ladder_obj> ,sStaticFields,sMemberFields,
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

void Ladder_obj::__boot()
{
}


#include <hxcpp.h>

#ifndef INCLUDED_Drops
#include <Drops.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_ShopPodium
#include <ShopPodium.h>
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
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_util_FlxRandom
#include <flixel/util/FlxRandom.h>
#endif

Void ShopPodium_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup MiscGrp)
{
HX_STACK_FRAME("ShopPodium","new",0xf4d2d244,"ShopPodium.new","ShopPodium.hx",29,0xec6f21ac)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_X,"X")
HX_STACK_ARG(__o_Y,"Y")
HX_STACK_ARG(ThePlayer,"ThePlayer")
HX_STACK_ARG(DropsGrp,"DropsGrp")
HX_STACK_ARG(MiscGrp,"MiscGrp")
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
{
	HX_STACK_LINE(30)
	super::__construct(X,Y,null());
	HX_STACK_LINE(32)
	this->set_visible(false);
	HX_STACK_LINE(35)
	int _g = ::flixel::util::FlxRandom_obj::intRanged((int)0,(int)3,null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(35)
	int dropID = (_g * (int)2);		HX_STACK_VAR(dropID,"dropID");
	HX_STACK_LINE(37)
	::Drops newDrop = ::Drops_obj::__new(this->x,this->y,dropID,ThePlayer,false);		HX_STACK_VAR(newDrop,"newDrop");
	HX_STACK_LINE(38)
	this->price = newDrop->price;
	HX_STACK_LINE(39)
	DropsGrp->add(newDrop);
	HX_STACK_LINE(41)
	::flixel::text::FlxText _g1 = ::flixel::text::FlxText_obj::__new(this->x,(this->y + (int)16),(int)0,(HX_CSTRING("") + this->price),(int)8,null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(41)
	this->_txtMoney = _g1;
	HX_STACK_LINE(42)
	{
		HX_STACK_LINE(42)
		::flixel::text::FlxText _this = this->_txtMoney;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(42)
		_this->set_borderStyle((int)1);
		HX_STACK_LINE(42)
		_this->set_borderColor((int)-8355712);
		HX_STACK_LINE(42)
		_this->set_borderSize((int)1);
		HX_STACK_LINE(42)
		_this->set_borderQuality((int)1);
	}
	HX_STACK_LINE(43)
	Float _g2 = this->_txtMoney->get_width();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(43)
	Float _g3 = (this->_txtMoney->x + _g2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(43)
	::flixel::FlxSprite _g4 = ::flixel::FlxSprite_obj::__new(_g3,(this->_txtMoney->y + (int)4),HX_CSTRING("assets/images/coin.png"));		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(43)
	this->_sprMoney = _g4;
	HX_STACK_LINE(44)
	this->_txtMoney->set_alignment(HX_CSTRING("right"));
	HX_STACK_LINE(46)
	MiscGrp->add(this->_txtMoney);
	HX_STACK_LINE(47)
	MiscGrp->add(this->_sprMoney);
}
;
	return null();
}

//ShopPodium_obj::~ShopPodium_obj() { }

Dynamic ShopPodium_obj::__CreateEmpty() { return  new ShopPodium_obj; }
hx::ObjectPtr< ShopPodium_obj > ShopPodium_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::Player ThePlayer,::flixel::group::FlxTypedGroup DropsGrp,::flixel::group::FlxGroup MiscGrp)
{  hx::ObjectPtr< ShopPodium_obj > result = new ShopPodium_obj();
	result->__construct(__o_X,__o_Y,ThePlayer,DropsGrp,MiscGrp);
	return result;}

Dynamic ShopPodium_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ShopPodium_obj > result = new ShopPodium_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}


ShopPodium_obj::ShopPodium_obj()
{
}

void ShopPodium_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ShopPodium);
	HX_MARK_MEMBER_NAME(_txtMoney,"_txtMoney");
	HX_MARK_MEMBER_NAME(_sprMoney,"_sprMoney");
	HX_MARK_MEMBER_NAME(price,"price");
	::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ShopPodium_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_txtMoney,"_txtMoney");
	HX_VISIT_MEMBER_NAME(_sprMoney,"_sprMoney");
	HX_VISIT_MEMBER_NAME(price,"price");
	::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic ShopPodium_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"price") ) { return price; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_txtMoney") ) { return _txtMoney; }
		if (HX_FIELD_EQ(inName,"_sprMoney") ) { return _sprMoney; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ShopPodium_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"price") ) { price=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_txtMoney") ) { _txtMoney=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_sprMoney") ) { _sprMoney=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ShopPodium_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_txtMoney"));
	outFields->push(HX_CSTRING("_sprMoney"));
	outFields->push(HX_CSTRING("price"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(ShopPodium_obj,_txtMoney),HX_CSTRING("_txtMoney")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(ShopPodium_obj,_sprMoney),HX_CSTRING("_sprMoney")},
	{hx::fsInt,(int)offsetof(ShopPodium_obj,price),HX_CSTRING("price")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_txtMoney"),
	HX_CSTRING("_sprMoney"),
	HX_CSTRING("price"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ShopPodium_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ShopPodium_obj::__mClass,"__mClass");
};

#endif

Class ShopPodium_obj::__mClass;

void ShopPodium_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("ShopPodium"), hx::TCanCast< ShopPodium_obj> ,sStaticFields,sMemberFields,
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

void ShopPodium_obj::__boot()
{
}


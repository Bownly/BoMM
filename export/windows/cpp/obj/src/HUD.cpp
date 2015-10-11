#include <hxcpp.h>

#ifndef INCLUDED_HUD
#include <HUD.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
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
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSpriteUtil
#include <flixel/util/FlxSpriteUtil.h>
#endif

Void HUD_obj::__construct()
{
HX_STACK_FRAME("HUD","new",0xf45a2509,"HUD.new","HUD.hx",30,0xe7d70e87)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(31)
	super::__construct(null());
	HX_STACK_LINE(32)
	::flixel::FlxSprite _g = ::flixel::FlxSprite_obj::__new(null(),null(),null())->makeGraphic(::flixel::FlxG_obj::width,(int)20,(int)-16777216,null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(32)
	this->_sprBack = _g;
	HX_STACK_LINE(33)
	::flixel::util::FlxSpriteUtil_obj::drawRect(this->_sprBack,(int)0,(int)19,::flixel::FlxG_obj::width,(int)1,(int)-1,null(),null(),null());
	HX_STACK_LINE(35)
	::flixel::text::FlxText _g1 = ::flixel::text::FlxText_obj::__new((int)16,(int)2,(int)0,HX_CSTRING("3 / 3"),(int)8,null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(35)
	this->_txtHealth = _g1;
	HX_STACK_LINE(36)
	{
		HX_STACK_LINE(36)
		::flixel::text::FlxText _this = this->_txtHealth;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(36)
		_this->set_borderStyle((int)1);
		HX_STACK_LINE(36)
		_this->set_borderColor((int)-8355712);
		HX_STACK_LINE(36)
		_this->set_borderSize((int)1);
		HX_STACK_LINE(36)
		_this->set_borderQuality((int)1);
	}
	HX_STACK_LINE(37)
	Float _g2 = this->_txtHealth->get_height();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(37)
	Float _g3 = (Float(_g2) / Float((int)2));		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(37)
	Float _g4 = (this->_txtHealth->y + _g3);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(37)
	Float _g5 = (_g4 - (int)8);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(37)
	::flixel::FlxSprite _g6 = ::flixel::FlxSprite_obj::__new((int)0,_g5,HX_CSTRING("assets/images/heart.png"));		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(37)
	this->_sprHealth = _g6;
	HX_STACK_LINE(39)
	::flixel::text::FlxText _g7 = ::flixel::text::FlxText_obj::__new((int)64,(int)2,(int)0,HX_CSTRING("6 / 9"),(int)8,null());		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(39)
	this->_txtJuice = _g7;
	HX_STACK_LINE(40)
	{
		HX_STACK_LINE(40)
		::flixel::text::FlxText _this = this->_txtJuice;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(40)
		_this->set_borderStyle((int)1);
		HX_STACK_LINE(40)
		_this->set_borderColor((int)-8355712);
		HX_STACK_LINE(40)
		_this->set_borderSize((int)1);
		HX_STACK_LINE(40)
		_this->set_borderQuality((int)1);
	}
	HX_STACK_LINE(41)
	Float _g8 = this->_txtHealth->get_width();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(41)
	Float _g9 = (this->_txtHealth->x + _g8);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(41)
	Float _g10 = this->_txtJuice->get_height();		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(41)
	Float _g11 = (Float(_g10) / Float((int)2));		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(41)
	Float _g12 = (this->_txtJuice->y + _g11);		HX_STACK_VAR(_g12,"_g12");
	HX_STACK_LINE(41)
	Float _g13 = (_g12 - (int)8);		HX_STACK_VAR(_g13,"_g13");
	HX_STACK_LINE(41)
	::flixel::FlxSprite _g14 = ::flixel::FlxSprite_obj::__new(_g9,_g13,HX_CSTRING("assets/images/juice.png"));		HX_STACK_VAR(_g14,"_g14");
	HX_STACK_LINE(41)
	this->_sprJuice = _g14;
	HX_STACK_LINE(43)
	Float _g15 = this->_txtJuice->get_width();		HX_STACK_VAR(_g15,"_g15");
	HX_STACK_LINE(43)
	Float _g16 = (this->_txtJuice->x + _g15);		HX_STACK_VAR(_g16,"_g16");
	HX_STACK_LINE(43)
	::flixel::text::FlxText _g17 = ::flixel::text::FlxText_obj::__new(_g16,(int)2,(int)0,HX_CSTRING("Cur Weapon: "),(int)8,null());		HX_STACK_VAR(_g17,"_g17");
	HX_STACK_LINE(43)
	this->_txtWeapon = _g17;
	HX_STACK_LINE(44)
	{
		HX_STACK_LINE(44)
		::flixel::text::FlxText _this = this->_txtWeapon;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(44)
		_this->set_borderStyle((int)1);
		HX_STACK_LINE(44)
		_this->set_borderColor((int)-8355712);
		HX_STACK_LINE(44)
		_this->set_borderSize((int)1);
		HX_STACK_LINE(44)
		_this->set_borderQuality((int)1);
	}
	HX_STACK_LINE(45)
	Float _g18 = this->_txtWeapon->get_width();		HX_STACK_VAR(_g18,"_g18");
	HX_STACK_LINE(45)
	Float _g19 = (this->_txtWeapon->x + _g18);		HX_STACK_VAR(_g19,"_g19");
	HX_STACK_LINE(45)
	Float _g20 = this->_txtWeapon->get_height();		HX_STACK_VAR(_g20,"_g20");
	HX_STACK_LINE(45)
	Float _g21 = (Float(_g20) / Float((int)2));		HX_STACK_VAR(_g21,"_g21");
	HX_STACK_LINE(45)
	Float _g22 = (_g21 - (int)4);		HX_STACK_VAR(_g22,"_g22");
	HX_STACK_LINE(45)
	Float _g23 = (this->_txtWeapon->y + _g22);		HX_STACK_VAR(_g23,"_g23");
	HX_STACK_LINE(45)
	::flixel::FlxSprite _g24 = ::flixel::FlxSprite_obj::__new(_g19,_g23,HX_CSTRING("assets/images/coin.png"));		HX_STACK_VAR(_g24,"_g24");
	HX_STACK_LINE(45)
	this->_sprWeapon = _g24;
	HX_STACK_LINE(47)
	::flixel::text::FlxText _g25 = ::flixel::text::FlxText_obj::__new((int)0,(int)2,(int)0,HX_CSTRING("0"),(int)8,null());		HX_STACK_VAR(_g25,"_g25");
	HX_STACK_LINE(47)
	this->_txtMoney = _g25;
	HX_STACK_LINE(48)
	{
		HX_STACK_LINE(48)
		::flixel::text::FlxText _this = this->_txtMoney;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(48)
		_this->set_borderStyle((int)1);
		HX_STACK_LINE(48)
		_this->set_borderColor((int)-8355712);
		HX_STACK_LINE(48)
		_this->set_borderSize((int)1);
		HX_STACK_LINE(48)
		_this->set_borderQuality((int)1);
	}
	HX_STACK_LINE(49)
	Float _g26 = this->_txtMoney->get_height();		HX_STACK_VAR(_g26,"_g26");
	HX_STACK_LINE(49)
	Float _g27 = (Float(_g26) / Float((int)2));		HX_STACK_VAR(_g27,"_g27");
	HX_STACK_LINE(49)
	Float _g28 = (this->_txtMoney->y + _g27);		HX_STACK_VAR(_g28,"_g28");
	HX_STACK_LINE(49)
	Float _g29 = (_g28 - (int)4);		HX_STACK_VAR(_g29,"_g29");
	HX_STACK_LINE(49)
	::flixel::FlxSprite _g30 = ::flixel::FlxSprite_obj::__new((::flixel::FlxG_obj::width - (int)12),_g29,HX_CSTRING("assets/images/coin.png"));		HX_STACK_VAR(_g30,"_g30");
	HX_STACK_LINE(49)
	this->_sprMoney = _g30;
	HX_STACK_LINE(50)
	this->_txtMoney->set_alignment(HX_CSTRING("right"));
	HX_STACK_LINE(51)
	Float _g31 = this->_txtMoney->get_width();		HX_STACK_VAR(_g31,"_g31");
	HX_STACK_LINE(51)
	Float _g32 = (this->_sprMoney->x - _g31);		HX_STACK_VAR(_g32,"_g32");
	HX_STACK_LINE(51)
	Float _g33 = (_g32 - (int)4);		HX_STACK_VAR(_g33,"_g33");
	HX_STACK_LINE(51)
	this->_txtMoney->set_x(_g33);
	HX_STACK_LINE(53)
	this->add(this->_sprBack);
	HX_STACK_LINE(54)
	this->add(this->_sprHealth);
	HX_STACK_LINE(55)
	this->add(this->_sprMoney);
	HX_STACK_LINE(56)
	this->add(this->_sprJuice);
	HX_STACK_LINE(58)
	this->add(this->_txtHealth);
	HX_STACK_LINE(59)
	this->add(this->_txtMoney);
	HX_STACK_LINE(60)
	this->add(this->_txtJuice);
	HX_STACK_LINE(61)
	this->add(this->_txtWeapon);

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
	Void run(::flixel::FlxSprite spr){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","HUD.hx",64,0xe7d70e87)
		HX_STACK_ARG(spr,"spr")
		{
			HX_STACK_LINE(64)
			spr->scrollFactor->set(null(),null());
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(63)
	this->forEach( Dynamic(new _Function_1_1()));
}
;
	return null();
}

//HUD_obj::~HUD_obj() { }

Dynamic HUD_obj::__CreateEmpty() { return  new HUD_obj; }
hx::ObjectPtr< HUD_obj > HUD_obj::__new()
{  hx::ObjectPtr< HUD_obj > result = new HUD_obj();
	result->__construct();
	return result;}

Dynamic HUD_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HUD_obj > result = new HUD_obj();
	result->__construct();
	return result;}

Void HUD_obj::updateHUD( hx::Null< int >  __o_Health,hx::Null< int >  __o_Juice,hx::Null< int >  __o_Money,::String Weapon){
int Health = __o_Health.Default(0);
int Juice = __o_Juice.Default(0);
int Money = __o_Money.Default(0);
	HX_STACK_FRAME("HUD","updateHUD",0xbe04cb97,"HUD.updateHUD","HUD.hx",70,0xe7d70e87)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Health,"Health")
	HX_STACK_ARG(Juice,"Juice")
	HX_STACK_ARG(Money,"Money")
	HX_STACK_ARG(Weapon,"Weapon")
{
		HX_STACK_LINE(71)
		::String _g = ::Std_obj::string(Health);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(71)
		::String _g1 = (_g + HX_CSTRING(" / 3"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(71)
		this->_txtHealth->set_text(_g1);
		HX_STACK_LINE(72)
		::String _g2 = ::Std_obj::string(Money);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(72)
		this->_txtMoney->set_text(_g2);
		HX_STACK_LINE(73)
		Float _g3 = this->_txtMoney->get_width();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(73)
		Float _g4 = (this->_sprMoney->x - _g3);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(73)
		Float _g5 = (_g4 - (int)4);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(73)
		this->_txtMoney->set_x(_g5);
		HX_STACK_LINE(75)
		::String _g6 = ::Std_obj::string(Juice);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(75)
		::String _g7 = (_g6 + HX_CSTRING(" / 9"));		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(75)
		this->_txtJuice->set_text(_g7);
		HX_STACK_LINE(76)
		this->_txtWeapon->set_text((HX_CSTRING("Cur Weapon: ") + Weapon));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(HUD_obj,updateHUD,(void))


HUD_obj::HUD_obj()
{
}

void HUD_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HUD);
	HX_MARK_MEMBER_NAME(_sprBack,"_sprBack");
	HX_MARK_MEMBER_NAME(_txtHealth,"_txtHealth");
	HX_MARK_MEMBER_NAME(_txtJuice,"_txtJuice");
	HX_MARK_MEMBER_NAME(_txtWeapon,"_txtWeapon");
	HX_MARK_MEMBER_NAME(_txtMoney,"_txtMoney");
	HX_MARK_MEMBER_NAME(_sprHealth,"_sprHealth");
	HX_MARK_MEMBER_NAME(_sprJuice,"_sprJuice");
	HX_MARK_MEMBER_NAME(_sprWeapon,"_sprWeapon");
	HX_MARK_MEMBER_NAME(_sprMoney,"_sprMoney");
	::flixel::group::FlxTypedGroup_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HUD_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_sprBack,"_sprBack");
	HX_VISIT_MEMBER_NAME(_txtHealth,"_txtHealth");
	HX_VISIT_MEMBER_NAME(_txtJuice,"_txtJuice");
	HX_VISIT_MEMBER_NAME(_txtWeapon,"_txtWeapon");
	HX_VISIT_MEMBER_NAME(_txtMoney,"_txtMoney");
	HX_VISIT_MEMBER_NAME(_sprHealth,"_sprHealth");
	HX_VISIT_MEMBER_NAME(_sprJuice,"_sprJuice");
	HX_VISIT_MEMBER_NAME(_sprWeapon,"_sprWeapon");
	HX_VISIT_MEMBER_NAME(_sprMoney,"_sprMoney");
	::flixel::group::FlxTypedGroup_obj::__Visit(HX_VISIT_ARG);
}

Dynamic HUD_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"_sprBack") ) { return _sprBack; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_txtJuice") ) { return _txtJuice; }
		if (HX_FIELD_EQ(inName,"_txtMoney") ) { return _txtMoney; }
		if (HX_FIELD_EQ(inName,"_sprJuice") ) { return _sprJuice; }
		if (HX_FIELD_EQ(inName,"_sprMoney") ) { return _sprMoney; }
		if (HX_FIELD_EQ(inName,"updateHUD") ) { return updateHUD_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_txtHealth") ) { return _txtHealth; }
		if (HX_FIELD_EQ(inName,"_txtWeapon") ) { return _txtWeapon; }
		if (HX_FIELD_EQ(inName,"_sprHealth") ) { return _sprHealth; }
		if (HX_FIELD_EQ(inName,"_sprWeapon") ) { return _sprWeapon; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HUD_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"_sprBack") ) { _sprBack=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_txtJuice") ) { _txtJuice=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_txtMoney") ) { _txtMoney=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_sprJuice") ) { _sprJuice=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_sprMoney") ) { _sprMoney=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_txtHealth") ) { _txtHealth=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_txtWeapon") ) { _txtWeapon=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_sprHealth") ) { _sprHealth=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_sprWeapon") ) { _sprWeapon=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HUD_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_sprBack"));
	outFields->push(HX_CSTRING("_txtHealth"));
	outFields->push(HX_CSTRING("_txtJuice"));
	outFields->push(HX_CSTRING("_txtWeapon"));
	outFields->push(HX_CSTRING("_txtMoney"));
	outFields->push(HX_CSTRING("_sprHealth"));
	outFields->push(HX_CSTRING("_sprJuice"));
	outFields->push(HX_CSTRING("_sprWeapon"));
	outFields->push(HX_CSTRING("_sprMoney"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(HUD_obj,_sprBack),HX_CSTRING("_sprBack")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(HUD_obj,_txtHealth),HX_CSTRING("_txtHealth")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(HUD_obj,_txtJuice),HX_CSTRING("_txtJuice")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(HUD_obj,_txtWeapon),HX_CSTRING("_txtWeapon")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(HUD_obj,_txtMoney),HX_CSTRING("_txtMoney")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(HUD_obj,_sprHealth),HX_CSTRING("_sprHealth")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(HUD_obj,_sprJuice),HX_CSTRING("_sprJuice")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(HUD_obj,_sprWeapon),HX_CSTRING("_sprWeapon")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(HUD_obj,_sprMoney),HX_CSTRING("_sprMoney")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_sprBack"),
	HX_CSTRING("_txtHealth"),
	HX_CSTRING("_txtJuice"),
	HX_CSTRING("_txtWeapon"),
	HX_CSTRING("_txtMoney"),
	HX_CSTRING("_sprHealth"),
	HX_CSTRING("_sprJuice"),
	HX_CSTRING("_sprWeapon"),
	HX_CSTRING("_sprMoney"),
	HX_CSTRING("updateHUD"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HUD_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HUD_obj::__mClass,"__mClass");
};

#endif

Class HUD_obj::__mClass;

void HUD_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("HUD"), hx::TCanCast< HUD_obj> ,sStaticFields,sMemberFields,
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

void HUD_obj::__boot()
{
}


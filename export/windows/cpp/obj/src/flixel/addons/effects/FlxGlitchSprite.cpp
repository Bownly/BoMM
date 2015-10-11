#include <hxcpp.h>

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
#ifndef INCLUDED_flixel_addons_effects_FlxGlitchSprite
#include <flixel/addons/effects/FlxGlitchSprite.h>
#endif
#ifndef INCLUDED_flixel_addons_effects_GlitchDirection
#include <flixel/addons/effects/GlitchDirection.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_system_layer_TileSheetData
#include <flixel/system/layer/TileSheetData.h>
#endif
#ifndef INCLUDED_flixel_util_FlxRandom
#include <flixel/util/FlxRandom.h>
#endif
#ifndef INCLUDED_flixel_util_loaders_CachedGraphics
#include <flixel/util/loaders/CachedGraphics.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_BitmapData
#include <openfl/_legacy/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_IBitmapDrawable
#include <openfl/_legacy/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__legacy_geom_Point
#include <openfl/_legacy/geom/Point.h>
#endif
#ifndef INCLUDED_openfl__legacy_geom_Rectangle
#include <openfl/_legacy/geom/Rectangle.h>
#endif
namespace flixel{
namespace addons{
namespace effects{

Void FlxGlitchSprite_obj::__construct(::flixel::FlxSprite Target,hx::Null< int >  __o_Strength,hx::Null< int >  __o_Size,hx::Null< Float >  __o_Delay,::flixel::addons::effects::GlitchDirection Direction)
{
HX_STACK_FRAME("flixel.addons.effects.FlxGlitchSprite","new",0xcb361169,"flixel.addons.effects.FlxGlitchSprite.new","flixel/addons/effects/FlxGlitchSprite.hx",15,0x61e07c88)
HX_STACK_THIS(this)
HX_STACK_ARG(Target,"Target")
HX_STACK_ARG(__o_Strength,"Strength")
HX_STACK_ARG(__o_Size,"Size")
HX_STACK_ARG(__o_Delay,"Delay")
HX_STACK_ARG(Direction,"Direction")
int Strength = __o_Strength.Default(4);
int Size = __o_Size.Default(1);
Float Delay = __o_Delay.Default(0.05);
{
	HX_STACK_LINE(38)
	this->_time = (int)0;
	HX_STACK_LINE(36)
	this->strength = (int)2;
	HX_STACK_LINE(24)
	this->delay = 0.05;
	HX_STACK_LINE(20)
	this->size = (int)1;
	HX_STACK_LINE(52)
	super::__construct(null(),null(),null());
	HX_STACK_LINE(53)
	this->target = Target;
	HX_STACK_LINE(54)
	this->set_strength(Strength);
	HX_STACK_LINE(55)
	this->size = Size;
	HX_STACK_LINE(56)
	if (((Direction != null()))){
		HX_STACK_LINE(57)
		this->set_direction(Direction);
	}
	else{
		HX_STACK_LINE(59)
		this->set_direction(::flixel::addons::effects::GlitchDirection_obj::HORIZONTAL);
	}
	HX_STACK_LINE(60)
	this->initPixels();
}
;
	return null();
}

//FlxGlitchSprite_obj::~FlxGlitchSprite_obj() { }

Dynamic FlxGlitchSprite_obj::__CreateEmpty() { return  new FlxGlitchSprite_obj; }
hx::ObjectPtr< FlxGlitchSprite_obj > FlxGlitchSprite_obj::__new(::flixel::FlxSprite Target,hx::Null< int >  __o_Strength,hx::Null< int >  __o_Size,hx::Null< Float >  __o_Delay,::flixel::addons::effects::GlitchDirection Direction)
{  hx::ObjectPtr< FlxGlitchSprite_obj > result = new FlxGlitchSprite_obj();
	result->__construct(Target,__o_Strength,__o_Size,__o_Delay,Direction);
	return result;}

Dynamic FlxGlitchSprite_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxGlitchSprite_obj > result = new FlxGlitchSprite_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

Void FlxGlitchSprite_obj::draw( ){
{
		HX_STACK_FRAME("flixel.addons.effects.FlxGlitchSprite","draw",0xfd86d2db,"flixel.addons.effects.FlxGlitchSprite.draw","flixel/addons/effects/FlxGlitchSprite.hx",64,0x61e07c88)
		HX_STACK_THIS(this)
		HX_STACK_LINE(65)
		if (((bool((this->alpha == (int)0)) || bool((this->target == null()))))){
			HX_STACK_LINE(66)
			return null();
		}
		HX_STACK_LINE(68)
		if (((this->_time > this->delay))){
			HX_STACK_LINE(70)
			this->_time = (int)0;
			HX_STACK_LINE(71)
			this->get_pixels()->lock();
			HX_STACK_LINE(72)
			::openfl::_legacy::geom::Rectangle _g = this->get_pixels()->get_rect();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(72)
			this->get_pixels()->fillRect(_g,(int)0);
			HX_STACK_LINE(73)
			int p = (int)0;		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(74)
			if (((this->direction == ::flixel::addons::effects::GlitchDirection_obj::HORIZONTAL))){
				HX_STACK_LINE(77)
				while((true)){
					HX_STACK_LINE(77)
					if ((!(((p < this->target->frameHeight))))){
						HX_STACK_LINE(77)
						break;
					}
					HX_STACK_LINE(79)
					this->_flashRect2->setTo((int)0,p,this->target->frameWidth,this->size);
					HX_STACK_LINE(80)
					Float _g1 = this->_flashRect2->get_bottom();		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(80)
					if (((_g1 > this->target->frameHeight))){
						HX_STACK_LINE(81)
						this->_flashRect2->set_bottom(this->target->frameHeight);
					}
					HX_STACK_LINE(82)
					int _g2 = ::flixel::util::FlxRandom_obj::intRanged(-(this->strength),this->strength,null());		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(82)
					int _g3 = (_g2 + this->strength);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(82)
					this->_flashPoint->setTo(_g3,p);
					HX_STACK_LINE(83)
					int _g4 = ::Std_obj::_int(this->_flashRect2->height);		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(83)
					hx::AddEq(p,_g4);
					HX_STACK_LINE(84)
					this->get_pixels()->copyPixels(this->target->framePixels,this->_flashRect2,this->_flashPoint,null(),null(),null());
				}
			}
			else{
				HX_STACK_LINE(89)
				while((true)){
					HX_STACK_LINE(89)
					if ((!(((p < this->target->frameWidth))))){
						HX_STACK_LINE(89)
						break;
					}
					HX_STACK_LINE(91)
					this->_flashRect2->setTo(p,(int)0,this->size,this->target->frameHeight);
					HX_STACK_LINE(92)
					Float _g5 = this->_flashRect2->get_right();		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(92)
					if (((_g5 > this->target->frameWidth))){
						HX_STACK_LINE(93)
						this->_flashRect2->set_right(this->target->frameWidth);
					}
					HX_STACK_LINE(94)
					int _g6 = ::flixel::util::FlxRandom_obj::intRanged(-(this->strength),this->strength,null());		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(94)
					int _g7 = (_g6 + this->strength);		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(94)
					this->_flashPoint->setTo(p,_g7);
					HX_STACK_LINE(95)
					int _g8 = ::Std_obj::_int(this->_flashRect2->width);		HX_STACK_VAR(_g8,"_g8");
					HX_STACK_LINE(95)
					hx::AddEq(p,_g8);
					HX_STACK_LINE(96)
					this->get_pixels()->copyPixels(this->target->framePixels,this->_flashRect2,this->_flashPoint,null(),null(),null());
				}
			}
			HX_STACK_LINE(100)
			this->cachedGraphics->get_tilesheet()->destroyFrameBitmapDatas();
			HX_STACK_LINE(101)
			this->get_pixels()->unlock(null());
			HX_STACK_LINE(102)
			this->dirty = true;
		}
		else{
			HX_STACK_LINE(105)
			hx::AddEq(this->_time,::flixel::FlxG_obj::elapsed);
		}
		HX_STACK_LINE(106)
		this->super::draw();
	}
return null();
}


Void FlxGlitchSprite_obj::initPixels( ){
{
		HX_STACK_FRAME("flixel.addons.effects.FlxGlitchSprite","initPixels",0x980d2c74,"flixel.addons.effects.FlxGlitchSprite.initPixels","flixel/addons/effects/FlxGlitchSprite.hx",110,0x61e07c88)
		HX_STACK_THIS(this)
		HX_STACK_LINE(111)
		{
			HX_STACK_LINE(111)
			bool Force = false;		HX_STACK_VAR(Force,"Force");
			HX_STACK_LINE(111)
			this->target->calcFrame(true);
		}
		HX_STACK_LINE(112)
		this->setPosition((this->target->x - ((  (((this->direction == ::flixel::addons::effects::GlitchDirection_obj::HORIZONTAL))) ? int(this->strength) : int((int)0) ))),(this->target->y - ((  (((this->direction == ::flixel::addons::effects::GlitchDirection_obj::VERTICAL))) ? int(this->strength) : int((int)0) ))));
		HX_STACK_LINE(113)
		int _g = ::Std_obj::_int((this->target->frameWidth + ((  (((this->direction == ::flixel::addons::effects::GlitchDirection_obj::HORIZONTAL))) ? int((this->strength * (int)2)) : int((int)0) ))));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(113)
		int _g1 = ::Std_obj::_int((this->target->frameHeight + ((  (((this->direction == ::flixel::addons::effects::GlitchDirection_obj::VERTICAL))) ? int((this->strength * (int)2)) : int((int)0) ))));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(113)
		this->makeGraphic(_g,_g1,(int)0,true,null());
		HX_STACK_LINE(114)
		this->_flashPoint->setTo((  (((this->direction == ::flixel::addons::effects::GlitchDirection_obj::HORIZONTAL))) ? Float(this->strength) : Float((int)0) ),(  (((this->direction == ::flixel::addons::effects::GlitchDirection_obj::VERTICAL))) ? Float(this->strength) : Float((int)0) ));
		HX_STACK_LINE(115)
		::openfl::_legacy::display::BitmapData _g2 = this->target->get_pixels();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(115)
		::openfl::_legacy::geom::Rectangle _g3 = this->target->get_pixels()->get_rect();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(115)
		this->get_pixels()->copyPixels(_g2,_g3,this->_flashPoint,null(),null(),null());
		HX_STACK_LINE(116)
		this->dirty = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGlitchSprite_obj,initPixels,(void))

::flixel::addons::effects::GlitchDirection FlxGlitchSprite_obj::set_direction( ::flixel::addons::effects::GlitchDirection Value){
	HX_STACK_FRAME("flixel.addons.effects.FlxGlitchSprite","set_direction",0x11195e6b,"flixel.addons.effects.FlxGlitchSprite.set_direction","flixel/addons/effects/FlxGlitchSprite.hx",120,0x61e07c88)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(121)
	if (((this->direction != Value))){
		HX_STACK_LINE(123)
		this->direction = Value;
		HX_STACK_LINE(124)
		this->initPixels();
	}
	HX_STACK_LINE(126)
	return this->direction;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGlitchSprite_obj,set_direction,return )

int FlxGlitchSprite_obj::set_strength( int Value){
	HX_STACK_FRAME("flixel.addons.effects.FlxGlitchSprite","set_strength",0xcc8d7fd5,"flixel.addons.effects.FlxGlitchSprite.set_strength","flixel/addons/effects/FlxGlitchSprite.hx",130,0x61e07c88)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(131)
	if (((this->strength != Value))){
		HX_STACK_LINE(133)
		this->strength = Value;
		HX_STACK_LINE(134)
		this->initPixels();
	}
	HX_STACK_LINE(136)
	return this->strength;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGlitchSprite_obj,set_strength,return )


FlxGlitchSprite_obj::FlxGlitchSprite_obj()
{
}

void FlxGlitchSprite_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxGlitchSprite);
	HX_MARK_MEMBER_NAME(size,"size");
	HX_MARK_MEMBER_NAME(delay,"delay");
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(direction,"direction");
	HX_MARK_MEMBER_NAME(strength,"strength");
	HX_MARK_MEMBER_NAME(_time,"_time");
	::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxGlitchSprite_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(size,"size");
	HX_VISIT_MEMBER_NAME(delay,"delay");
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(direction,"direction");
	HX_VISIT_MEMBER_NAME(strength,"strength");
	HX_VISIT_MEMBER_NAME(_time,"_time");
	::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic FlxGlitchSprite_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { return size; }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"delay") ) { return delay; }
		if (HX_FIELD_EQ(inName,"_time") ) { return _time; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"strength") ) { return strength; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"direction") ) { return direction; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initPixels") ) { return initPixels_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_strength") ) { return set_strength_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_direction") ) { return set_direction_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxGlitchSprite_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { size=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"delay") ) { delay=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_time") ) { _time=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"strength") ) { if (inCallProp) return set_strength(inValue);strength=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"direction") ) { if (inCallProp) return set_direction(inValue);direction=inValue.Cast< ::flixel::addons::effects::GlitchDirection >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxGlitchSprite_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("size"));
	outFields->push(HX_CSTRING("delay"));
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("direction"));
	outFields->push(HX_CSTRING("strength"));
	outFields->push(HX_CSTRING("_time"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(FlxGlitchSprite_obj,size),HX_CSTRING("size")},
	{hx::fsFloat,(int)offsetof(FlxGlitchSprite_obj,delay),HX_CSTRING("delay")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(FlxGlitchSprite_obj,target),HX_CSTRING("target")},
	{hx::fsObject /*::flixel::addons::effects::GlitchDirection*/ ,(int)offsetof(FlxGlitchSprite_obj,direction),HX_CSTRING("direction")},
	{hx::fsInt,(int)offsetof(FlxGlitchSprite_obj,strength),HX_CSTRING("strength")},
	{hx::fsFloat,(int)offsetof(FlxGlitchSprite_obj,_time),HX_CSTRING("_time")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("size"),
	HX_CSTRING("delay"),
	HX_CSTRING("target"),
	HX_CSTRING("direction"),
	HX_CSTRING("strength"),
	HX_CSTRING("_time"),
	HX_CSTRING("draw"),
	HX_CSTRING("initPixels"),
	HX_CSTRING("set_direction"),
	HX_CSTRING("set_strength"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxGlitchSprite_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxGlitchSprite_obj::__mClass,"__mClass");
};

#endif

Class FlxGlitchSprite_obj::__mClass;

void FlxGlitchSprite_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.addons.effects.FlxGlitchSprite"), hx::TCanCast< FlxGlitchSprite_obj> ,sStaticFields,sMemberFields,
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

void FlxGlitchSprite_obj::__boot()
{
}

} // end namespace flixel
} // end namespace addons
} // end namespace effects

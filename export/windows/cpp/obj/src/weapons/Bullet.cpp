#include <hxcpp.h>

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
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_weapons_Bullet
#include <weapons/Bullet.h>
#endif
namespace weapons{

Void Bullet_obj::__construct(Float X,Float Y,Float Speed,int Direction,int Damage,int Range)
{
HX_STACK_FRAME("weapons.Bullet","new",0xe3ee754b,"weapons.Bullet.new","weapons/Bullet.hx",14,0x78fd7464)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
HX_STACK_ARG(Speed,"Speed")
HX_STACK_ARG(Direction,"Direction")
HX_STACK_ARG(Damage,"Damage")
HX_STACK_ARG(Range,"Range")
{
	HX_STACK_LINE(21)
	this->RANGE = (int)128;
	HX_STACK_LINE(25)
	super::__construct(X,Y,null());
	HX_STACK_LINE(26)
	this->ogX = X;
	HX_STACK_LINE(27)
	this->ogY = Y;
	HX_STACK_LINE(28)
	this->speed = Speed;
	HX_STACK_LINE(29)
	this->direction = Direction;
	HX_STACK_LINE(30)
	this->damage = Damage;
	HX_STACK_LINE(31)
	this->RANGE = Range;
	HX_STACK_LINE(32)
	this->loadGraphic(HX_CSTRING("assets/images/coin.png"),true,(int)6,(int)6,true,HX_CSTRING("bullet"));
}
;
	return null();
}

//Bullet_obj::~Bullet_obj() { }

Dynamic Bullet_obj::__CreateEmpty() { return  new Bullet_obj; }
hx::ObjectPtr< Bullet_obj > Bullet_obj::__new(Float X,Float Y,Float Speed,int Direction,int Damage,int Range)
{  hx::ObjectPtr< Bullet_obj > result = new Bullet_obj();
	result->__construct(X,Y,Speed,Direction,Damage,Range);
	return result;}

Dynamic Bullet_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bullet_obj > result = new Bullet_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

Void Bullet_obj::update( ){
{
		HX_STACK_FRAME("weapons.Bullet","update",0x61fe85fe,"weapons.Bullet.update","weapons/Bullet.hx",39,0x78fd7464)
		HX_STACK_THIS(this)
		HX_STACK_LINE(40)
		this->super::update();
		HX_STACK_LINE(41)
		if (((this->direction == (int)1))){
			HX_STACK_LINE(42)
			this->velocity->set_x(-(this->speed));
		}
		HX_STACK_LINE(44)
		if (((this->direction == (int)16))){
			HX_STACK_LINE(45)
			this->velocity->set_x(this->speed);
		}
		HX_STACK_LINE(47)
		if (((this->direction == (int)4096))){
			HX_STACK_LINE(48)
			this->velocity->set_y(this->speed);
		}
		HX_STACK_LINE(50)
		if (((this->direction == (int)256))){
			HX_STACK_LINE(51)
			this->velocity->set_y(-(this->speed));
		}
		HX_STACK_LINE(58)
		Float _g = ::Math_obj::abs((this->x - this->ogX));		HX_STACK_VAR(_g,"_g");
		struct _Function_1_1{
			inline static bool Block( hx::ObjectPtr< ::weapons::Bullet_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","weapons/Bullet.hx",58,0x78fd7464)
				{
					HX_STACK_LINE(58)
					Float _g1 = ::Math_obj::abs((__this->y - __this->ogY));		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(58)
					return (_g1 > __this->RANGE);
				}
				return null();
			}
		};
		HX_STACK_LINE(58)
		if (((  ((!(((_g > this->RANGE))))) ? bool(_Function_1_1::Block(this)) : bool(true) ))){
			HX_STACK_LINE(60)
			this->kill();
		}
		else{
			HX_STACK_LINE(62)
			if (((this->touching != (int)0))){
				HX_STACK_LINE(65)
				this->kill();
			}
		}
	}
return null();
}


Void Bullet_obj::destroy( ){
{
		HX_STACK_FRAME("weapons.Bullet","destroy",0xe36d2365,"weapons.Bullet.destroy","weapons/Bullet.hx",71,0x78fd7464)
		HX_STACK_THIS(this)
		HX_STACK_LINE(72)
		this->set_alive(false);
		HX_STACK_LINE(74)
		this->super::destroy();
	}
return null();
}


int Bullet_obj::getDamage( ){
	HX_STACK_FRAME("weapons.Bullet","getDamage",0x199cc0d0,"weapons.Bullet.getDamage","weapons/Bullet.hx",79,0x78fd7464)
	HX_STACK_THIS(this)
	HX_STACK_LINE(79)
	return this->damage;
}


HX_DEFINE_DYNAMIC_FUNC0(Bullet_obj,getDamage,return )


Bullet_obj::Bullet_obj()
{
}

Dynamic Bullet_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"ogX") ) { return ogX; }
		if (HX_FIELD_EQ(inName,"ogY") ) { return ogY; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"speed") ) { return speed; }
		if (HX_FIELD_EQ(inName,"RANGE") ) { return RANGE; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"damage") ) { return damage; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"direction") ) { return direction; }
		if (HX_FIELD_EQ(inName,"getDamage") ) { return getDamage_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Bullet_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"ogX") ) { ogX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ogY") ) { ogY=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"speed") ) { speed=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RANGE") ) { RANGE=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"damage") ) { damage=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"direction") ) { direction=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bullet_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("speed"));
	outFields->push(HX_CSTRING("direction"));
	outFields->push(HX_CSTRING("damage"));
	outFields->push(HX_CSTRING("ogX"));
	outFields->push(HX_CSTRING("ogY"));
	outFields->push(HX_CSTRING("RANGE"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Bullet_obj,speed),HX_CSTRING("speed")},
	{hx::fsInt,(int)offsetof(Bullet_obj,direction),HX_CSTRING("direction")},
	{hx::fsInt,(int)offsetof(Bullet_obj,damage),HX_CSTRING("damage")},
	{hx::fsFloat,(int)offsetof(Bullet_obj,ogX),HX_CSTRING("ogX")},
	{hx::fsFloat,(int)offsetof(Bullet_obj,ogY),HX_CSTRING("ogY")},
	{hx::fsInt,(int)offsetof(Bullet_obj,RANGE),HX_CSTRING("RANGE")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("speed"),
	HX_CSTRING("direction"),
	HX_CSTRING("damage"),
	HX_CSTRING("ogX"),
	HX_CSTRING("ogY"),
	HX_CSTRING("RANGE"),
	HX_CSTRING("update"),
	HX_CSTRING("destroy"),
	HX_CSTRING("getDamage"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Bullet_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Bullet_obj::__mClass,"__mClass");
};

#endif

Class Bullet_obj::__mClass;

void Bullet_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("weapons.Bullet"), hx::TCanCast< Bullet_obj> ,sStaticFields,sMemberFields,
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

void Bullet_obj::__boot()
{
}

} // end namespace weapons

#include <hxcpp.h>

#ifndef INCLUDED_Coin
#include <Coin.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
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
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_addons_editors_ogmo_FlxOgmoLoader
#include <flixel/addons/editors/ogmo/FlxOgmoLoader.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_input_mouse_FlxMouse
#include <flixel/input/mouse/FlxMouse.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxInput
#include <flixel/interfaces/IFlxInput.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_tile_FlxTilemap
#include <flixel/tile/FlxTilemap.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif

Void PlayState_obj::__construct(Dynamic MaxSize)
{
HX_STACK_FRAME("PlayState","new",0xf8bf96cf,"PlayState.new","PlayState.hx",20,0xb30d7781)
HX_STACK_THIS(this)
HX_STACK_ARG(MaxSize,"MaxSize")
{
	HX_STACK_LINE(20)
	super::__construct(MaxSize);
}
;
	return null();
}

//PlayState_obj::~PlayState_obj() { }

Dynamic PlayState_obj::__CreateEmpty() { return  new PlayState_obj; }
hx::ObjectPtr< PlayState_obj > PlayState_obj::__new(Dynamic MaxSize)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct(MaxSize);
	return result;}

Dynamic PlayState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct(inArgs[0]);
	return result;}

Void PlayState_obj::create( ){
{
		HX_STACK_FRAME("PlayState","create",0x82220fed,"PlayState.create","PlayState.hx",44,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(45)
		this->super::create();
		HX_STACK_LINE(48)
		::flixel::addons::editors::ogmo::FlxOgmoLoader _g = ::flixel::addons::editors::ogmo::FlxOgmoLoader_obj::__new(HX_CSTRING("assets/data/room-002.oel"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(48)
		this->_map2 = _g;
		HX_STACK_LINE(51)
		::flixel::tile::FlxTilemap _g1 = this->_map2->loadTilemap(HX_CSTRING("assets/images/wood_tiles.png"),(int)16,(int)16,HX_CSTRING("walls"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(51)
		this->_mWalls2 = _g1;
		HX_STACK_LINE(53)
		{
			HX_STACK_LINE(53)
			int _g2 = (int)1;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(53)
			while((true)){
				HX_STACK_LINE(53)
				if ((!(((_g2 < (int)150))))){
					HX_STACK_LINE(53)
					break;
				}
				HX_STACK_LINE(53)
				int i = (_g2)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(54)
				this->_mWalls->setTileProperties(i,(int)4369,null(),null(),null());
				HX_STACK_LINE(55)
				this->_mWalls2->setTileProperties(i,(int)4369,null(),null(),null());
			}
		}
		HX_STACK_LINE(57)
		this->add(this->_mWalls2);
		HX_STACK_LINE(61)
		::flixel::group::FlxTypedGroup _g2 = ::flixel::group::FlxTypedGroup_obj::__new(null());		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(61)
		this->_grpCoins = _g2;
		HX_STACK_LINE(62)
		this->add(this->_grpCoins);
		HX_STACK_LINE(64)
		::flixel::FlxG_obj::mouse->set_visible(false);
		HX_STACK_LINE(66)
		this->score = (int)0;
		HX_STACK_LINE(67)
		::flixel::text::FlxText _g3 = ::flixel::text::FlxText_obj::__new((int)0,(int)0,(int)100,(HX_CSTRING("Score: ") + this->score),null(),null());		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(67)
		this->scoreText = _g3;
		HX_STACK_LINE(68)
		this->add(this->scoreText);
		HX_STACK_LINE(70)
		::Player _g4 = ::Player_obj::__new(null(),null());		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(70)
		this->_player = _g4;
		HX_STACK_LINE(71)
		this->_map2->loadEntities(this->placeEntities_dyn(),HX_CSTRING("entities"));
		HX_STACK_LINE(74)
		this->add(this->_player);
		HX_STACK_LINE(76)
		::flixel::FlxG_obj::camera->bgColor = (int)154743039;
		HX_STACK_LINE(86)
		::flixel::FlxG_obj::camera->follow(this->_player,(int)1,null(),null());
		HX_STACK_LINE(87)
		::flixel::FlxG_obj::camera->style = (int)1;
	}
return null();
}


Void PlayState_obj::destroy( ){
{
		HX_STACK_FRAME("PlayState","destroy",0x6ec756e9,"PlayState.destroy","PlayState.hx",97,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(97)
		this->super::destroy();
	}
return null();
}


Void PlayState_obj::update( ){
{
		HX_STACK_FRAME("PlayState","update",0x8d182efa,"PlayState.update","PlayState.hx",104,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(106)
		::flixel::FlxG_obj::overlap(this->_player,this->_mWalls2,null(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(107)
		::flixel::FlxG_obj::overlap(this->_player,this->_mWalls,null(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(108)
		::flixel::FlxG_obj::overlap(this->_player,this->_grpCoins,this->playerTouchCoin_dyn(),null());
		HX_STACK_LINE(109)
		this->super::update();
	}
return null();
}


Void PlayState_obj::playerTouchCoin( ::Player P,::Coin C){
{
		HX_STACK_FRAME("PlayState","playerTouchCoin",0x7f00763e,"PlayState.playerTouchCoin","PlayState.hx",114,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(P,"P")
		HX_STACK_ARG(C,"C")
		HX_STACK_LINE(114)
		if (((bool((bool((bool(P->alive) && bool(P->exists))) && bool(C->alive))) && bool(C->exists)))){
			HX_STACK_LINE(116)
			C->kill();
			HX_STACK_LINE(117)
			(this->score)++;
			HX_STACK_LINE(120)
			this->scoreText->set_text((HX_CSTRING("Score: ") + this->score));
			HX_STACK_LINE(121)
			this->add(this->scoreText);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,playerTouchCoin,(void))

Void PlayState_obj::placeEntities( ::String entityName,::Xml entityData){
{
		HX_STACK_FRAME("PlayState","placeEntities",0xcb21ad57,"PlayState.placeEntities","PlayState.hx",127,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(entityName,"entityName")
		HX_STACK_ARG(entityData,"entityData")
		HX_STACK_LINE(128)
		::String _g = entityData->get(HX_CSTRING("x"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(128)
		int x = ::Std_obj::parseInt(_g);		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(129)
		::String _g1 = entityData->get(HX_CSTRING("y"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(129)
		int y = ::Std_obj::parseInt(_g1);		HX_STACK_VAR(y,"y");
		HX_STACK_LINE(130)
		if (((entityName == HX_CSTRING("player")))){
			HX_STACK_LINE(132)
			this->_player->set_x(x);
			HX_STACK_LINE(133)
			this->_player->set_y(y);
		}
		else{
			HX_STACK_LINE(135)
			if (((entityName == HX_CSTRING("coin")))){
				HX_STACK_LINE(137)
				::Coin _g2 = ::Coin_obj::__new((x + (int)4),(y + (int)4));		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(137)
				this->_grpCoins->add(_g2);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,placeEntities,(void))


PlayState_obj::PlayState_obj()
{
}

void PlayState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PlayState);
	HX_MARK_MEMBER_NAME(_player,"_player");
	HX_MARK_MEMBER_NAME(_grpCoins,"_grpCoins");
	HX_MARK_MEMBER_NAME(_map,"_map");
	HX_MARK_MEMBER_NAME(_mWalls,"_mWalls");
	HX_MARK_MEMBER_NAME(floor,"floor");
	HX_MARK_MEMBER_NAME(_map2,"_map2");
	HX_MARK_MEMBER_NAME(_mWalls2,"_mWalls2");
	HX_MARK_MEMBER_NAME(loader,"loader");
	HX_MARK_MEMBER_NAME(midgroundMap,"midgroundMap");
	HX_MARK_MEMBER_NAME(coinGroup,"coinGroup");
	HX_MARK_MEMBER_NAME(score,"score");
	HX_MARK_MEMBER_NAME(scoreText,"scoreText");
	::flixel::FlxState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PlayState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_player,"_player");
	HX_VISIT_MEMBER_NAME(_grpCoins,"_grpCoins");
	HX_VISIT_MEMBER_NAME(_map,"_map");
	HX_VISIT_MEMBER_NAME(_mWalls,"_mWalls");
	HX_VISIT_MEMBER_NAME(floor,"floor");
	HX_VISIT_MEMBER_NAME(_map2,"_map2");
	HX_VISIT_MEMBER_NAME(_mWalls2,"_mWalls2");
	HX_VISIT_MEMBER_NAME(loader,"loader");
	HX_VISIT_MEMBER_NAME(midgroundMap,"midgroundMap");
	HX_VISIT_MEMBER_NAME(coinGroup,"coinGroup");
	HX_VISIT_MEMBER_NAME(score,"score");
	HX_VISIT_MEMBER_NAME(scoreText,"scoreText");
	::flixel::FlxState_obj::__Visit(HX_VISIT_ARG);
}

Dynamic PlayState_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_map") ) { return _map; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"floor") ) { return floor; }
		if (HX_FIELD_EQ(inName,"_map2") ) { return _map2; }
		if (HX_FIELD_EQ(inName,"score") ) { return score; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"loader") ) { return loader; }
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_player") ) { return _player; }
		if (HX_FIELD_EQ(inName,"_mWalls") ) { return _mWalls; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_mWalls2") ) { return _mWalls2; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_grpCoins") ) { return _grpCoins; }
		if (HX_FIELD_EQ(inName,"coinGroup") ) { return coinGroup; }
		if (HX_FIELD_EQ(inName,"scoreText") ) { return scoreText; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"midgroundMap") ) { return midgroundMap; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"placeEntities") ) { return placeEntities_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"playerTouchCoin") ) { return playerTouchCoin_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PlayState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_map") ) { _map=inValue.Cast< ::flixel::addons::editors::ogmo::FlxOgmoLoader >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"floor") ) { floor=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_map2") ) { _map2=inValue.Cast< ::flixel::addons::editors::ogmo::FlxOgmoLoader >(); return inValue; }
		if (HX_FIELD_EQ(inName,"score") ) { score=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"loader") ) { loader=inValue.Cast< ::flixel::addons::editors::ogmo::FlxOgmoLoader >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_player") ) { _player=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_mWalls") ) { _mWalls=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_mWalls2") ) { _mWalls2=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_grpCoins") ) { _grpCoins=inValue.Cast< ::flixel::group::FlxTypedGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"coinGroup") ) { coinGroup=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scoreText") ) { scoreText=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"midgroundMap") ) { midgroundMap=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PlayState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_player"));
	outFields->push(HX_CSTRING("_grpCoins"));
	outFields->push(HX_CSTRING("_map"));
	outFields->push(HX_CSTRING("_mWalls"));
	outFields->push(HX_CSTRING("floor"));
	outFields->push(HX_CSTRING("_map2"));
	outFields->push(HX_CSTRING("_mWalls2"));
	outFields->push(HX_CSTRING("loader"));
	outFields->push(HX_CSTRING("midgroundMap"));
	outFields->push(HX_CSTRING("coinGroup"));
	outFields->push(HX_CSTRING("score"));
	outFields->push(HX_CSTRING("scoreText"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,_player),HX_CSTRING("_player")},
	{hx::fsObject /*::flixel::group::FlxTypedGroup*/ ,(int)offsetof(PlayState_obj,_grpCoins),HX_CSTRING("_grpCoins")},
	{hx::fsObject /*::flixel::addons::editors::ogmo::FlxOgmoLoader*/ ,(int)offsetof(PlayState_obj,_map),HX_CSTRING("_map")},
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,_mWalls),HX_CSTRING("_mWalls")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,floor),HX_CSTRING("floor")},
	{hx::fsObject /*::flixel::addons::editors::ogmo::FlxOgmoLoader*/ ,(int)offsetof(PlayState_obj,_map2),HX_CSTRING("_map2")},
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,_mWalls2),HX_CSTRING("_mWalls2")},
	{hx::fsObject /*::flixel::addons::editors::ogmo::FlxOgmoLoader*/ ,(int)offsetof(PlayState_obj,loader),HX_CSTRING("loader")},
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,midgroundMap),HX_CSTRING("midgroundMap")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(PlayState_obj,coinGroup),HX_CSTRING("coinGroup")},
	{hx::fsInt,(int)offsetof(PlayState_obj,score),HX_CSTRING("score")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(PlayState_obj,scoreText),HX_CSTRING("scoreText")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_player"),
	HX_CSTRING("_grpCoins"),
	HX_CSTRING("_map"),
	HX_CSTRING("_mWalls"),
	HX_CSTRING("floor"),
	HX_CSTRING("_map2"),
	HX_CSTRING("_mWalls2"),
	HX_CSTRING("loader"),
	HX_CSTRING("midgroundMap"),
	HX_CSTRING("coinGroup"),
	HX_CSTRING("score"),
	HX_CSTRING("scoreText"),
	HX_CSTRING("create"),
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("playerTouchCoin"),
	HX_CSTRING("placeEntities"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
};

#endif

Class PlayState_obj::__mClass;

void PlayState_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("PlayState"), hx::TCanCast< PlayState_obj> ,sStaticFields,sMemberFields,
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

void PlayState_obj::__boot()
{
}


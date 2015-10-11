#include <hxcpp.h>

#ifndef INCLUDED_Coin
#include <Coin.h>
#endif
#ifndef INCLUDED_Door
#include <Door.h>
#endif
#ifndef INCLUDED_Drops
#include <Drops.h>
#endif
#ifndef INCLUDED_HUD
#include <HUD.h>
#endif
#ifndef INCLUDED_Ladder
#include <Ladder.h>
#endif
#ifndef INCLUDED_Level1
#include <Level1.h>
#endif
#ifndef INCLUDED_MenuState
#include <MenuState.h>
#endif
#ifndef INCLUDED_PauseState
#include <PauseState.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_Reg
#include <Reg.h>
#endif
#ifndef INCLUDED_ShopPodium
#include <ShopPodium.h>
#endif
#ifndef INCLUDED_Spike
#include <Spike.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Testboss
#include <Testboss.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_enemies_Balun
#include <enemies/Balun.h>
#endif
#ifndef INCLUDED_enemies_Burd
#include <enemies/Burd.h>
#endif
#ifndef INCLUDED_enemies_EnemyTemplate
#include <enemies/EnemyTemplate.h>
#endif
#ifndef INCLUDED_enemies_Metool
#include <enemies/Metool.h>
#endif
#ifndef INCLUDED_enemies_Mush
#include <enemies/Mush.h>
#endif
#ifndef INCLUDED_enemies_Notey
#include <enemies/Notey.h>
#endif
#ifndef INCLUDED_enemies_Snaake
#include <enemies/Snaake.h>
#endif
#ifndef INCLUDED_enemies_Snobal
#include <enemies/Snobal.h>
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
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
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
#ifndef INCLUDED_flixel_FlxSubState
#include <flixel/FlxSubState.h>
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
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyboard
#include <flixel/input/keyboard/FlxKeyboard.h>
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
#ifndef INCLUDED_flixel_tile_FlxTilemap
#include <flixel/tile/FlxTilemap.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxRandom
#include <flixel/util/FlxRandom.h>
#endif
#ifndef INCLUDED_flixel_util_FlxRect
#include <flixel/util/FlxRect.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_DisplayObject
#include <openfl/_legacy/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_DisplayObjectContainer
#include <openfl/_legacy/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_IBitmapDrawable
#include <openfl/_legacy/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_InteractiveObject
#include <openfl/_legacy/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_Sprite
#include <openfl/_legacy/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl__legacy_events_EventDispatcher
#include <openfl/_legacy/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__legacy_events_IEventDispatcher
#include <openfl/_legacy/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_weapons_Bullet
#include <weapons/Bullet.h>
#endif
#ifndef INCLUDED_weapons_WeaponTemplate
#include <weapons/WeaponTemplate.h>
#endif

Void PlayState_obj::__construct(Dynamic MaxSize)
{
HX_STACK_FRAME("PlayState","new",0xf8bf96cf,"PlayState.new","PlayState.hx",31,0xb30d7781)
HX_STACK_THIS(this)
HX_STACK_ARG(MaxSize,"MaxSize")
{
	HX_STACK_LINE(73)
	this->_score = (int)0;
	HX_STACK_LINE(70)
	this->_curMapY = (int)0;
	HX_STACK_LINE(69)
	this->_curMapX = (int)0;
	HX_STACK_LINE(56)
	this->tileName = HX_CSTRING("assets/images/wood_tiles.png");
	HX_STACK_LINE(55)
	this->levelId = HX_CSTRING("1");
	HX_STACK_LINE(31)
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
		HX_STACK_FRAME("PlayState","create",0x82220fed,"PlayState.create","PlayState.hx",79,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(81)
		Float _g = this->_levelWidth = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(81)
		this->_levelHeight = _g;
		HX_STACK_LINE(84)
		::flixel::group::FlxTypedGroup _g1 = ::flixel::group::FlxTypedGroup_obj::__new(null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(84)
		this->_grpWalls = _g1;
		HX_STACK_LINE(86)
		::flixel::group::FlxTypedGroup _g2 = ::flixel::group::FlxTypedGroup_obj::__new(null());		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(86)
		this->_grpLadders = _g2;
		HX_STACK_LINE(87)
		this->add(this->_grpLadders);
		HX_STACK_LINE(89)
		::flixel::group::FlxTypedGroup _g3 = ::flixel::group::FlxTypedGroup_obj::__new(null());		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(89)
		this->_grpHazards = _g3;
		HX_STACK_LINE(90)
		this->add(this->_grpHazards);
		HX_STACK_LINE(92)
		::flixel::group::FlxGroup _g4 = ::flixel::group::FlxGroup_obj::__new(null());		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(92)
		this->_grpEnemies = _g4;
		HX_STACK_LINE(93)
		this->add(this->_grpEnemies);
		HX_STACK_LINE(96)
		::Door _g5 = ::Door_obj::__new(null(),null());		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(96)
		this->_door = _g5;
		HX_STACK_LINE(97)
		this->add(this->_door);
		HX_STACK_LINE(99)
		::flixel::group::FlxTypedGroup _g6 = ::flixel::group::FlxTypedGroup_obj::__new(null());		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(99)
		this->_grpCoins = _g6;
		HX_STACK_LINE(100)
		this->add(this->_grpCoins);
		HX_STACK_LINE(102)
		::flixel::group::FlxTypedGroup _g7 = ::flixel::group::FlxTypedGroup_obj::__new(null());		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(102)
		this->playerBullets = _g7;
		HX_STACK_LINE(103)
		this->playerBullets = ::Reg_obj::bullets;
		HX_STACK_LINE(104)
		this->add(this->playerBullets);
		HX_STACK_LINE(106)
		::Player _g8 = ::Player_obj::__new((int)100,(int)100,this->playerBullets);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(106)
		this->_player = _g8;
		HX_STACK_LINE(124)
		::flixel::group::FlxTypedGroup _g9 = ::flixel::group::FlxTypedGroup_obj::__new(null());		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(124)
		this->dropsGroup = _g9;
		HX_STACK_LINE(125)
		this->add(this->dropsGroup);
		HX_STACK_LINE(127)
		::Drops drop = ::Drops_obj::__new((int)320,(int)320,(int)0,this->_player,true);		HX_STACK_VAR(drop,"drop");
		HX_STACK_LINE(128)
		::Drops drop2 = ::Drops_obj::__new((int)340,(int)320,(int)2,this->_player,true);		HX_STACK_VAR(drop2,"drop2");
		HX_STACK_LINE(129)
		::Drops drop4 = ::Drops_obj::__new((int)360,(int)320,(int)4,this->_player,true);		HX_STACK_VAR(drop4,"drop4");
		HX_STACK_LINE(130)
		::Drops drop6 = ::Drops_obj::__new((int)380,(int)320,(int)6,this->_player,true);		HX_STACK_VAR(drop6,"drop6");
		HX_STACK_LINE(132)
		this->dropsGroup->add(drop);
		HX_STACK_LINE(133)
		this->dropsGroup->add(drop2);
		HX_STACK_LINE(134)
		this->dropsGroup->add(drop4);
		HX_STACK_LINE(135)
		this->dropsGroup->add(drop6);
		HX_STACK_LINE(138)
		::flixel::group::FlxGroup _g10 = ::flixel::group::FlxGroup_obj::__new(null());		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(138)
		this->_grpBadBullets = _g10;
		HX_STACK_LINE(139)
		this->add(this->_grpBadBullets);
		HX_STACK_LINE(140)
		::flixel::group::FlxGroup _g11 = ::flixel::group::FlxGroup_obj::__new(null());		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(140)
		this->miscGroup = _g11;
		HX_STACK_LINE(141)
		this->add(this->miscGroup);
		HX_STACK_LINE(143)
		this->setUpLevel();
		HX_STACK_LINE(144)
		this->add(this->_grpWalls);
		HX_STACK_LINE(147)
		::flixel::group::FlxGroup _g12 = ::flixel::group::FlxGroup_obj::__new(null());		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(147)
		this->_grpPlayer = _g12;
		HX_STACK_LINE(148)
		this->add(this->_grpPlayer);
		HX_STACK_LINE(149)
		this->_grpPlayer->add(this->_player);
		HX_STACK_LINE(150)
		this->_grpPlayer->add(this->playerBullets);
		HX_STACK_LINE(153)
		::flixel::FlxG_obj::mouse->set_visible(false);
		HX_STACK_LINE(156)
		::flixel::FlxG_obj::camera->bgColor = (int)-11184811;
		HX_STACK_LINE(158)
		::flixel::FlxG_obj::camera->follow(this->_player,(int)1,null(),null());
		HX_STACK_LINE(159)
		::flixel::FlxG_obj::camera->style = (int)1;
		HX_STACK_LINE(160)
		::flixel::FlxG_obj::camera->setBounds((int)0,-(this->_levelHeight),this->_levelWidth,(this->_levelHeight * (int)2),null());
		HX_STACK_LINE(161)
		{
			HX_STACK_LINE(161)
			::flixel::util::FlxRect _this = ::flixel::FlxG_obj::worldBounds;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(161)
			_this->x = (int)0;
			HX_STACK_LINE(161)
			_this->y = -(this->_levelHeight);
			HX_STACK_LINE(161)
			_this->width = this->_levelWidth;
			HX_STACK_LINE(161)
			_this->height = (this->_levelHeight * (int)2);
			HX_STACK_LINE(161)
			_this;
		}
		HX_STACK_LINE(163)
		::HUD _g13 = ::HUD_obj::__new();		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(163)
		this->_hud = _g13;
		HX_STACK_LINE(164)
		this->add(this->_hud);
		HX_STACK_LINE(166)
		this->super::create();
	}
return null();
}


Void PlayState_obj::update( ){
{
		HX_STACK_FRAME("PlayState","update",0x8d182efa,"PlayState.update","PlayState.hx",170,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(172)
		::flixel::FlxG_obj::overlap(this->_grpWalls,this->_player,null(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(173)
		::flixel::FlxG_obj::overlap(this->_grpWalls,this->_grpEnemies,null(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(174)
		::flixel::FlxG_obj::overlap(this->_grpWalls,this->_grpBadBullets,null(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(175)
		::flixel::FlxG_obj::overlap(this->_grpWalls,this->playerBullets,null(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(177)
		::flixel::FlxG_obj::overlap(this->_player,this->_grpEnemies,this->touchEnemy_dyn(),null());
		HX_STACK_LINE(178)
		::flixel::FlxG_obj::overlap(this->_player,this->_grpBadBullets,this->playerGetHit_dyn(),null());
		HX_STACK_LINE(179)
		::flixel::FlxG_obj::overlap(this->playerBullets,this->_grpEnemies,this->bulletTouchEnemy_dyn(),null());
		HX_STACK_LINE(180)
		::flixel::FlxG_obj::overlap(this->_player,this->_grpCoins,this->playerTouchCoin_dyn(),null());
		HX_STACK_LINE(181)
		::flixel::FlxG_obj::overlap(this->_player,this->dropsGroup,this->playerTouchDrops_dyn(),null());
		HX_STACK_LINE(182)
		::flixel::FlxG_obj::overlap(this->_player,this->_grpHazards,this->playerTouchHazard_dyn(),null());
		HX_STACK_LINE(184)
		if ((!(::flixel::FlxG_obj::overlap(this->_player,this->_grpLadders,this->playerTouchLadder_dyn(),null())))){
			HX_STACK_LINE(186)
			this->_player->setTouchingLadder(false);
		}
		HX_STACK_LINE(190)
		if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("R")),(int)1))){
			HX_STACK_LINE(192)
			::flixel::FlxState State = ::PlayState_obj::__new(null());		HX_STACK_VAR(State,"State");
			HX_STACK_LINE(192)
			::flixel::FlxG_obj::game->_requestedState = State;
		}
		HX_STACK_LINE(194)
		if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("T")),(int)1))){
			HX_STACK_LINE(196)
			::flixel::FlxState State = ::MenuState_obj::__new(null());		HX_STACK_VAR(State,"State");
			HX_STACK_LINE(196)
			::flixel::FlxG_obj::game->_requestedState = State;
		}
		HX_STACK_LINE(199)
		if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("P")),(int)2))){
			HX_STACK_LINE(201)
			::PauseState sub = ::PauseState_obj::__new(null());		HX_STACK_VAR(sub,"sub");
			HX_STACK_LINE(203)
			{
				HX_STACK_LINE(203)
				this->_requestSubStateReset = true;
				HX_STACK_LINE(203)
				this->_requestedSubState = sub;
			}
		}
		HX_STACK_LINE(211)
		this->_hud->updateHUD(this->_player->hp,this->_player->curWeapon->juice,this->_score,this->_player->curWeapon->name);
		HX_STACK_LINE(213)
		this->super::update();
	}
return null();
}


Void PlayState_obj::destroy( ){
{
		HX_STACK_FRAME("PlayState","destroy",0x6ec756e9,"PlayState.destroy","PlayState.hx",222,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(222)
		this->super::destroy();
	}
return null();
}


Void PlayState_obj::gotoNextLevel( ){
{
		HX_STACK_FRAME("PlayState","gotoNextLevel",0xc690709d,"PlayState.gotoNextLevel","PlayState.hx",228,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(228)
		::flixel::FlxState State = ::Level1_obj::__new();		HX_STACK_VAR(State,"State");
		HX_STACK_LINE(228)
		::flixel::FlxG_obj::game->_requestedState = State;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,gotoNextLevel,(void))

Void PlayState_obj::setUpLevel( ){
{
		HX_STACK_FRAME("PlayState","setUpLevel",0xadcfcf18,"PlayState.setUpLevel","PlayState.hx",233,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(243)
		int _g = ::flixel::util::FlxRandom_obj::intRanged((int)1,(int)1,null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(243)
		this->_newEntrance = _g;
		HX_STACK_LINE(244)
		::flixel::addons::editors::ogmo::FlxOgmoLoader _g1 = ::flixel::addons::editors::ogmo::FlxOgmoLoader_obj::__new(((((HX_CSTRING("assets/levels/level_") + this->levelId) + HX_CSTRING("_start_")) + this->_newEntrance) + HX_CSTRING(".oel")));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(244)
		this->myOgmoLoader = _g1;
		HX_STACK_LINE(245)
		::flixel::tile::FlxTilemap _g2 = this->myOgmoLoader->loadTilemap(this->tileName,(int)16,(int)16,HX_CSTRING("walls"));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(245)
		this->mTileMap = _g2;
		HX_STACK_LINE(247)
		this->myOgmoLoader->loadEntities(this->placeEntities_dyn(),HX_CSTRING("entities"));
		HX_STACK_LINE(249)
		Float _g3 = this->mTileMap->get_height();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(249)
		hx::AddEq(this->_levelHeight,_g3);
		HX_STACK_LINE(250)
		Float _g4 = this->mTileMap->get_width();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(250)
		hx::AddEq(this->_levelWidth,_g4);
		HX_STACK_LINE(251)
		this->_grpWalls->add(this->mTileMap);
		HX_STACK_LINE(254)
		int itemRoomPos;		HX_STACK_VAR(itemRoomPos,"itemRoomPos");
		HX_STACK_LINE(255)
		int _g5 = ::flixel::util::FlxRandom_obj::intRanged((int)1,(int)3,null());		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(255)
		itemRoomPos = _g5;
		HX_STACK_LINE(259)
		{
			HX_STACK_LINE(259)
			int _g6 = (int)1;		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(259)
			while((true)){
				HX_STACK_LINE(259)
				if ((!(((_g6 < (int)4))))){
					HX_STACK_LINE(259)
					break;
				}
				HX_STACK_LINE(259)
				int i = (_g6)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(261)
				if (((i == itemRoomPos))){
					HX_STACK_LINE(264)
					::flixel::addons::editors::ogmo::FlxOgmoLoader myOgmoLoader = ::flixel::addons::editors::ogmo::FlxOgmoLoader_obj::__new(((((HX_CSTRING("assets/levels/level_") + this->levelId) + HX_CSTRING("_item_start_")) + this->_newEntrance) + HX_CSTRING(".oel")));		HX_STACK_VAR(myOgmoLoader,"myOgmoLoader");
					HX_STACK_LINE(265)
					::flixel::tile::FlxTilemap myTileMap = myOgmoLoader->loadTilemap(this->tileName,(int)16,(int)16,HX_CSTRING("walls"));		HX_STACK_VAR(myTileMap,"myTileMap");
					HX_STACK_LINE(266)
					this->setUpMaps(myOgmoLoader,myTileMap);
					HX_STACK_LINE(268)
					int endId = ::flixel::util::FlxRandom_obj::intRanged((int)1,(int)1,null());		HX_STACK_VAR(endId,"endId");
					HX_STACK_LINE(270)
					::flixel::addons::editors::ogmo::FlxOgmoLoader _g61 = ::flixel::addons::editors::ogmo::FlxOgmoLoader_obj::__new(((((HX_CSTRING("assets/levels/level_") + this->levelId) + HX_CSTRING("_shop_end_")) + endId) + HX_CSTRING(".oel")));		HX_STACK_VAR(_g61,"_g61");
					HX_STACK_LINE(270)
					myOgmoLoader = _g61;
					HX_STACK_LINE(271)
					::flixel::tile::FlxTilemap _g7 = myOgmoLoader->loadTilemap(this->tileName,(int)16,(int)16,HX_CSTRING("walls"));		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(271)
					myTileMap = _g7;
					HX_STACK_LINE(272)
					this->setUpMaps(myOgmoLoader,myTileMap);
				}
				HX_STACK_LINE(275)
				int id;		HX_STACK_VAR(id,"id");
				HX_STACK_LINE(276)
				int _g8 = ::flixel::util::FlxRandom_obj::intRanged((int)1,(int)1,null());		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(276)
				id = _g8;
				HX_STACK_LINE(278)
				::flixel::addons::editors::ogmo::FlxOgmoLoader myOgmoLoader = ::flixel::addons::editors::ogmo::FlxOgmoLoader_obj::__new(((((((HX_CSTRING("assets/levels/level_") + this->levelId) + HX_CSTRING("_")) + this->_newEntrance) + HX_CSTRING("_")) + id) + HX_CSTRING(".oel")));		HX_STACK_VAR(myOgmoLoader,"myOgmoLoader");
				HX_STACK_LINE(279)
				::flixel::tile::FlxTilemap myTileMap = myOgmoLoader->loadTilemap(this->tileName,(int)16,(int)16,HX_CSTRING("walls"));		HX_STACK_VAR(myTileMap,"myTileMap");
				HX_STACK_LINE(280)
				this->setUpMaps(myOgmoLoader,myTileMap);
			}
		}
		HX_STACK_LINE(284)
		::flixel::addons::editors::ogmo::FlxOgmoLoader myOgmoLoader = ::flixel::addons::editors::ogmo::FlxOgmoLoader_obj::__new(((((HX_CSTRING("assets/levels/level_") + this->levelId) + HX_CSTRING("_end_")) + this->_newEntrance) + HX_CSTRING(".oel")));		HX_STACK_VAR(myOgmoLoader,"myOgmoLoader");
		HX_STACK_LINE(285)
		::flixel::tile::FlxTilemap myTileMap = myOgmoLoader->loadTilemap(this->tileName,(int)16,(int)16,HX_CSTRING("walls"));		HX_STACK_VAR(myTileMap,"myTileMap");
		HX_STACK_LINE(286)
		this->setUpMaps(myOgmoLoader,myTileMap);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,setUpLevel,(void))

Void PlayState_obj::setUpMaps( ::flixel::addons::editors::ogmo::FlxOgmoLoader ogmo,::flixel::tile::FlxTilemap map){
{
		HX_STACK_FRAME("PlayState","setUpMaps",0x13cbd343,"PlayState.setUpMaps","PlayState.hx",290,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(ogmo,"ogmo")
		HX_STACK_ARG(map,"map")
		HX_STACK_LINE(292)
		::flixel::tile::FlxTilemap previousWall = this->_grpWalls->members->__GetItem((this->_grpWalls->length - (int)1));		HX_STACK_VAR(previousWall,"previousWall");
		HX_STACK_LINE(294)
		if (((bool((this->_newEntrance == (int)1)) || bool((this->_newEntrance == (int)2))))){
			HX_STACK_LINE(296)
			{
				HX_STACK_LINE(296)
				::flixel::tile::FlxTilemap _g = map;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(296)
				Float _g1 = previousWall->get_width();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(296)
				Float _g11 = (previousWall->x + _g1);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(296)
				Float _g2 = (_g->x + _g11);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(296)
				_g->set_x(_g2);
			}
			HX_STACK_LINE(297)
			{
				HX_STACK_LINE(297)
				::flixel::tile::FlxTilemap _g = map;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(297)
				_g->set_y((_g->y + previousWall->y));
			}
		}
		else{
			HX_STACK_LINE(299)
			if (((this->_newEntrance == (int)3))){
				HX_STACK_LINE(301)
				{
					HX_STACK_LINE(301)
					::flixel::tile::FlxTilemap _g = map;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(301)
					Float _g3 = previousWall->get_width();		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(301)
					Float _g4 = (previousWall->x + _g3);		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(301)
					Float _g5 = (_g4 - (int)96);		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(301)
					Float _g6 = (_g->x + _g5);		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(301)
					_g->set_x(_g6);
				}
				HX_STACK_LINE(302)
				{
					HX_STACK_LINE(302)
					::flixel::tile::FlxTilemap _g = map;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(302)
					Float _g7 = previousWall->get_height();		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(302)
					Float _g8 = (previousWall->y + _g7);		HX_STACK_VAR(_g8,"_g8");
					HX_STACK_LINE(302)
					Float _g9 = (_g->y + _g8);		HX_STACK_VAR(_g9,"_g9");
					HX_STACK_LINE(302)
					_g->set_y(_g9);
				}
			}
			else{
				HX_STACK_LINE(306)
				{
					HX_STACK_LINE(306)
					::flixel::tile::FlxTilemap _g = map;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(306)
					Float _g10 = previousWall->get_width();		HX_STACK_VAR(_g10,"_g10");
					HX_STACK_LINE(306)
					Float _g11 = (previousWall->x + _g10);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(306)
					Float _g12 = (_g11 - (int)96);		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(306)
					Float _g13 = (_g->x + _g12);		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(306)
					_g->set_x(_g13);
				}
				HX_STACK_LINE(307)
				{
					HX_STACK_LINE(307)
					::flixel::tile::FlxTilemap _g = map;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(307)
					Float _g14 = previousWall->get_height();		HX_STACK_VAR(_g14,"_g14");
					HX_STACK_LINE(307)
					Float _g15 = (previousWall->y - _g14);		HX_STACK_VAR(_g15,"_g15");
					HX_STACK_LINE(307)
					Float _g16 = (_g->y + _g15);		HX_STACK_VAR(_g16,"_g16");
					HX_STACK_LINE(307)
					_g->set_y(_g16);
				}
			}
		}
		HX_STACK_LINE(310)
		this->_curMapX = map->x;
		HX_STACK_LINE(311)
		this->_curMapY = map->y;
		HX_STACK_LINE(313)
		ogmo->loadEntities(this->placeEntities_dyn(),HX_CSTRING("entities"));
		HX_STACK_LINE(314)
		ogmo->loadEntities(this->getExit_dyn(),HX_CSTRING("entities"));
		HX_STACK_LINE(316)
		Float _g17 = map->get_height();		HX_STACK_VAR(_g17,"_g17");
		HX_STACK_LINE(316)
		hx::AddEq(this->_levelHeight,_g17);
		HX_STACK_LINE(317)
		Float _g18 = map->get_width();		HX_STACK_VAR(_g18,"_g18");
		HX_STACK_LINE(317)
		hx::AddEq(this->_levelWidth,_g18);
		HX_STACK_LINE(319)
		this->_grpWalls->add(map);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,setUpMaps,(void))

Void PlayState_obj::touchEnemy( ::Player P,::enemies::EnemyTemplate E){
{
		HX_STACK_FRAME("PlayState","touchEnemy",0xf6246b7a,"PlayState.touchEnemy","PlayState.hx",325,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(P,"P")
		HX_STACK_ARG(E,"E")
		HX_STACK_LINE(325)
		if (((E->alive == true))){
			HX_STACK_LINE(327)
			P->takeDamage((int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,touchEnemy,(void))

Void PlayState_obj::playerGetHit( ::Player P,::weapons::Bullet B){
{
		HX_STACK_FRAME("PlayState","playerGetHit",0xba45914f,"PlayState.playerGetHit","PlayState.hx",333,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(P,"P")
		HX_STACK_ARG(B,"B")
		HX_STACK_LINE(333)
		if (((B->alive == true))){
			HX_STACK_LINE(335)
			int _g = B->getDamage();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(335)
			P->takeDamage(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,playerGetHit,(void))

Void PlayState_obj::bulletTouchEnemy( ::weapons::Bullet B,::enemies::EnemyTemplate E){
{
		HX_STACK_FRAME("PlayState","bulletTouchEnemy",0xf427531c,"PlayState.bulletTouchEnemy","PlayState.hx",340,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(B,"B")
		HX_STACK_ARG(E,"E")
		HX_STACK_LINE(341)
		if (((bool((bool((bool(B->alive) && bool(B->exists))) && bool(E->alive))) && bool(E->exists)))){
			HX_STACK_LINE(343)
			int _g = B->getDamage();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(343)
			E->takeDamage(_g);
		}
		HX_STACK_LINE(346)
		if (((E->alive == false))){
			HX_STACK_LINE(348)
			(this->_score)++;
			HX_STACK_LINE(349)
			int health;		HX_STACK_VAR(health,"health");
			HX_STACK_LINE(350)
			health = this->_player->hp;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,bulletTouchEnemy,(void))

Void PlayState_obj::bulletTouchLadder( ::weapons::Bullet B,::Ladder L){
{
		HX_STACK_FRAME("PlayState","bulletTouchLadder",0xfddb458e,"PlayState.bulletTouchLadder","PlayState.hx",358,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(B,"B")
		HX_STACK_ARG(L,"L")
		HX_STACK_LINE(358)
		if (((bool((bool((bool(B->alive) && bool(B->exists))) && bool(L->alive))) && bool(L->exists)))){
			HX_STACK_LINE(360)
			L->kill();
			HX_STACK_LINE(361)
			(this->_score)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,bulletTouchLadder,(void))

Void PlayState_obj::playerTouchDrops( ::Player P,::Drops D){
{
		HX_STACK_FRAME("PlayState","playerTouchDrops",0x36cdc817,"PlayState.playerTouchDrops","PlayState.hx",371,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(P,"P")
		HX_STACK_ARG(D,"D")
		HX_STACK_LINE(371)
		if (((bool((bool((bool(P->alive) && bool(P->exists))) && bool(D->alive))) && bool(D->exists)))){
			HX_STACK_LINE(373)
			int cost = D->doStuff(this->_score);		HX_STACK_VAR(cost,"cost");
			HX_STACK_LINE(374)
			hx::SubEq(this->_score,cost);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,playerTouchDrops,(void))

Void PlayState_obj::playerTouchCoin( ::Player P,::Coin C){
{
		HX_STACK_FRAME("PlayState","playerTouchCoin",0x7f00763e,"PlayState.playerTouchCoin","PlayState.hx",381,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(P,"P")
		HX_STACK_ARG(C,"C")
		HX_STACK_LINE(381)
		if (((bool((bool((bool(P->alive) && bool(P->exists))) && bool(C->alive))) && bool(C->exists)))){
			HX_STACK_LINE(383)
			C->kill();
			HX_STACK_LINE(384)
			(this->_score)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,playerTouchCoin,(void))

Void PlayState_obj::playerTouchLadder( ::Player P,::Ladder L){
{
		HX_STACK_FRAME("PlayState","playerTouchLadder",0x1efdd2cf,"PlayState.playerTouchLadder","PlayState.hx",393,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(P,"P")
		HX_STACK_ARG(L,"L")
		HX_STACK_LINE(394)
		P->setTouchingLadder(true);
		struct _Function_1_1{
			inline static bool Block( ::Ladder &L,::Player &P){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","PlayState.hx",397,0xb30d7781)
				{
					HX_STACK_LINE(397)
					Float _g = P->get_height();		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(397)
					Float _g1 = (_g - (int)3);		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(397)
					Float _g2 = (L->y - _g1);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(397)
					return (P->y < _g2);
				}
				return null();
			}
		};
		HX_STACK_LINE(397)
		if (((  (((L->top == true))) ? bool(_Function_1_1::Block(L,P)) : bool(false) ))){
			HX_STACK_LINE(399)
			L->set_immovable(true);
			HX_STACK_LINE(400)
			::flixel::FlxG_obj::overlap(P,L,null(),::flixel::FlxObject_obj::separate_dyn());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,playerTouchLadder,(void))

Void PlayState_obj::playerTouchHazard( ::Player P,::Spike S){
{
		HX_STACK_FRAME("PlayState","playerTouchHazard",0x9418d77f,"PlayState.playerTouchHazard","PlayState.hx",406,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(P,"P")
		HX_STACK_ARG(S,"S")
		HX_STACK_LINE(406)
		P->takeDamage(S->dmg);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,playerTouchHazard,(void))

Void PlayState_obj::placeEntities( ::String entityName,::Xml entityData){
{
		HX_STACK_FRAME("PlayState","placeEntities",0xcb21ad57,"PlayState.placeEntities","PlayState.hx",411,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(entityName,"entityName")
		HX_STACK_ARG(entityData,"entityData")
		HX_STACK_LINE(412)
		::String _g = entityData->get(HX_CSTRING("x"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(412)
		Float x = ::Std_obj::parseFloat(_g);		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(413)
		::String _g1 = entityData->get(HX_CSTRING("y"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(413)
		Float y = ::Std_obj::parseFloat(_g1);		HX_STACK_VAR(y,"y");
		HX_STACK_LINE(414)
		hx::AddEq(x,this->_curMapX);
		HX_STACK_LINE(415)
		hx::AddEq(y,this->_curMapY);
		HX_STACK_LINE(417)
		if (((entityName == HX_CSTRING("player")))){
			HX_STACK_LINE(419)
			this->_player->set_x(x);
			HX_STACK_LINE(420)
			this->_player->set_y(y);
		}
		else{
			HX_STACK_LINE(422)
			if (((entityName == HX_CSTRING("coin")))){
				HX_STACK_LINE(424)
				::Coin _g2 = ::Coin_obj::__new((x + (int)4),(y + (int)4));		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(424)
				this->_grpCoins->add(_g2);
			}
			else{
				HX_STACK_LINE(426)
				if (((entityName == HX_CSTRING("ladder")))){
					HX_STACK_LINE(428)
					::String _g3 = entityData->get(HX_CSTRING("top"));		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(428)
					if (((_g3 == HX_CSTRING("True")))){
						HX_STACK_LINE(429)
						::Ladder _g4 = ::Ladder_obj::__new(x,y,true);		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(429)
						this->_grpLadders->add(_g4);
					}
					else{
						HX_STACK_LINE(431)
						::Ladder _g5 = ::Ladder_obj::__new(x,y,false);		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(431)
						this->_grpLadders->add(_g5);
					}
				}
				else{
					HX_STACK_LINE(433)
					if (((entityName == HX_CSTRING("door")))){
						HX_STACK_LINE(435)
						this->_door->set_x(x);
						HX_STACK_LINE(436)
						this->_door->set_y(y);
					}
					else{
						HX_STACK_LINE(438)
						if (((entityName == HX_CSTRING("spike")))){
							HX_STACK_LINE(440)
							::String _g6 = entityData->get(HX_CSTRING("damage"));		HX_STACK_VAR(_g6,"_g6");
							HX_STACK_LINE(440)
							int dmg = ::Std_obj::parseInt(_g6);		HX_STACK_VAR(dmg,"dmg");
							HX_STACK_LINE(441)
							::Spike _g7 = ::Spike_obj::__new(x,y,dmg);		HX_STACK_VAR(_g7,"_g7");
							HX_STACK_LINE(441)
							this->_grpHazards->add(_g7);
						}
						else{
							HX_STACK_LINE(443)
							if (((entityName == HX_CSTRING("StorePodium")))){
								HX_STACK_LINE(445)
								::ShopPodium _g8 = ::ShopPodium_obj::__new(x,y,this->_player,this->dropsGroup,this->miscGroup);		HX_STACK_VAR(_g8,"_g8");
								HX_STACK_LINE(445)
								this->add(_g8);
							}
							else{
								HX_STACK_LINE(447)
								if (((entityName == HX_CSTRING("enemy")))){
									HX_STACK_LINE(449)
									::String _g2 = entityData->get(HX_CSTRING("name"));		HX_STACK_VAR(_g2,"_g2");
									HX_STACK_LINE(449)
									::String _switch_1 = (_g2);
									if (  ( _switch_1==HX_CSTRING("snobal"))){
										HX_STACK_LINE(452)
										::enemies::Snobal _g9 = ::enemies::Snobal_obj::__new(x,y,this->_player,this->dropsGroup);		HX_STACK_VAR(_g9,"_g9");
										HX_STACK_LINE(452)
										this->_grpEnemies->add(_g9);
									}
									else if (  ( _switch_1==HX_CSTRING("snaake"))){
										HX_STACK_LINE(454)
										::enemies::Snaake _g10 = ::enemies::Snaake_obj::__new(x,y,this->_player,this->dropsGroup);		HX_STACK_VAR(_g10,"_g10");
										HX_STACK_LINE(454)
										this->_grpEnemies->add(_g10);
									}
									else if (  ( _switch_1==HX_CSTRING("metool"))){
										HX_STACK_LINE(456)
										::enemies::Metool _g11 = ::enemies::Metool_obj::__new(x,y,this->_player,this->dropsGroup,this->_grpBadBullets);		HX_STACK_VAR(_g11,"_g11");
										HX_STACK_LINE(456)
										this->_grpEnemies->add(_g11);
									}
									else if (  ( _switch_1==HX_CSTRING("burd"))){
										HX_STACK_LINE(458)
										::enemies::Burd _g12 = ::enemies::Burd_obj::__new(x,y,this->_player,this->dropsGroup,this->_grpEnemies);		HX_STACK_VAR(_g12,"_g12");
										HX_STACK_LINE(458)
										this->_grpEnemies->add(_g12);
									}
									else if (  ( _switch_1==HX_CSTRING("notey"))){
										HX_STACK_LINE(460)
										::enemies::Notey _g13 = ::enemies::Notey_obj::__new(x,y,this->_player,this->dropsGroup);		HX_STACK_VAR(_g13,"_g13");
										HX_STACK_LINE(460)
										this->_grpEnemies->add(_g13);
									}
									else if (  ( _switch_1==HX_CSTRING("testboss"))){
										HX_STACK_LINE(462)
										::Testboss _g14 = ::Testboss_obj::__new(x,y,this->_player,this->dropsGroup,this->_grpBadBullets,hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g14,"_g14");
										HX_STACK_LINE(462)
										this->_grpEnemies->add(_g14);
									}
									else if (  ( _switch_1==HX_CSTRING("balun"))){
										HX_STACK_LINE(464)
										::enemies::Balun _g15 = ::enemies::Balun_obj::__new(x,y,this->_player,this->dropsGroup,this->_grpEnemies,this->_grpBadBullets,(int)1);		HX_STACK_VAR(_g15,"_g15");
										HX_STACK_LINE(464)
										this->_grpEnemies->add(_g15);
									}
									else if (  ( _switch_1==HX_CSTRING("mush"))){
										HX_STACK_LINE(466)
										::enemies::Mush _g16 = ::enemies::Mush_obj::__new(x,y,this->_player,this->dropsGroup,this->_grpBadBullets,(int)1);		HX_STACK_VAR(_g16,"_g16");
										HX_STACK_LINE(466)
										this->_grpEnemies->add(_g16);
									}
								}
							}
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,placeEntities,(void))

Void PlayState_obj::getExit( ::String entityName,::Xml entityData){
{
		HX_STACK_FRAME("PlayState","getExit",0x5fe1d0c3,"PlayState.getExit","PlayState.hx",472,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(entityName,"entityName")
		HX_STACK_ARG(entityData,"entityData")
		HX_STACK_LINE(472)
		if (((entityName == HX_CSTRING("exit")))){
			HX_STACK_LINE(474)
			::String _g = entityData->get(HX_CSTRING("val"));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(474)
			Dynamic _g1 = ::Std_obj::parseInt(_g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(474)
			this->_newEntrance = _g1;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,getExit,(void))

Void PlayState_obj::getEntrance( ::String entityName,::Xml entityData){
{
		HX_STACK_FRAME("PlayState","getEntrance",0xe3e79a9b,"PlayState.getEntrance","PlayState.hx",480,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(entityName,"entityName")
		HX_STACK_ARG(entityData,"entityData")
		HX_STACK_LINE(480)
		if (((entityName == HX_CSTRING("entrance")))){
			HX_STACK_LINE(482)
			::String _g = entityData->get(HX_CSTRING("val"));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(482)
			Dynamic _g1 = ::Std_obj::parseInt(_g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(482)
			this->_newEntrance = _g1;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,getEntrance,(void))

::Player PlayState_obj::player;


PlayState_obj::PlayState_obj()
{
}

void PlayState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PlayState);
	HX_MARK_MEMBER_NAME(_grpPlayer,"_grpPlayer");
	HX_MARK_MEMBER_NAME(_player,"_player");
	HX_MARK_MEMBER_NAME(playerBullets,"playerBullets");
	HX_MARK_MEMBER_NAME(_grpEnemies,"_grpEnemies");
	HX_MARK_MEMBER_NAME(_grpBadBullets,"_grpBadBullets");
	HX_MARK_MEMBER_NAME(_grpCoins,"_grpCoins");
	HX_MARK_MEMBER_NAME(_grpLadders,"_grpLadders");
	HX_MARK_MEMBER_NAME(_grpHazards,"_grpHazards");
	HX_MARK_MEMBER_NAME(_door,"_door");
	HX_MARK_MEMBER_NAME(_grpWalls,"_grpWalls");
	HX_MARK_MEMBER_NAME(_levelWidth,"_levelWidth");
	HX_MARK_MEMBER_NAME(_levelHeight,"_levelHeight");
	HX_MARK_MEMBER_NAME(myOgmoLoader,"myOgmoLoader");
	HX_MARK_MEMBER_NAME(mTileMap,"mTileMap");
	HX_MARK_MEMBER_NAME(levelId,"levelId");
	HX_MARK_MEMBER_NAME(tileName,"tileName");
	HX_MARK_MEMBER_NAME(loader,"loader");
	HX_MARK_MEMBER_NAME(midgroundMap,"midgroundMap");
	HX_MARK_MEMBER_NAME(coinGroup,"coinGroup");
	HX_MARK_MEMBER_NAME(dropsGroup,"dropsGroup");
	HX_MARK_MEMBER_NAME(miscGroup,"miscGroup");
	HX_MARK_MEMBER_NAME(_newEntrance,"_newEntrance");
	HX_MARK_MEMBER_NAME(_curMapX,"_curMapX");
	HX_MARK_MEMBER_NAME(_curMapY,"_curMapY");
	HX_MARK_MEMBER_NAME(_hud,"_hud");
	HX_MARK_MEMBER_NAME(_score,"_score");
	::flixel::FlxState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PlayState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_grpPlayer,"_grpPlayer");
	HX_VISIT_MEMBER_NAME(_player,"_player");
	HX_VISIT_MEMBER_NAME(playerBullets,"playerBullets");
	HX_VISIT_MEMBER_NAME(_grpEnemies,"_grpEnemies");
	HX_VISIT_MEMBER_NAME(_grpBadBullets,"_grpBadBullets");
	HX_VISIT_MEMBER_NAME(_grpCoins,"_grpCoins");
	HX_VISIT_MEMBER_NAME(_grpLadders,"_grpLadders");
	HX_VISIT_MEMBER_NAME(_grpHazards,"_grpHazards");
	HX_VISIT_MEMBER_NAME(_door,"_door");
	HX_VISIT_MEMBER_NAME(_grpWalls,"_grpWalls");
	HX_VISIT_MEMBER_NAME(_levelWidth,"_levelWidth");
	HX_VISIT_MEMBER_NAME(_levelHeight,"_levelHeight");
	HX_VISIT_MEMBER_NAME(myOgmoLoader,"myOgmoLoader");
	HX_VISIT_MEMBER_NAME(mTileMap,"mTileMap");
	HX_VISIT_MEMBER_NAME(levelId,"levelId");
	HX_VISIT_MEMBER_NAME(tileName,"tileName");
	HX_VISIT_MEMBER_NAME(loader,"loader");
	HX_VISIT_MEMBER_NAME(midgroundMap,"midgroundMap");
	HX_VISIT_MEMBER_NAME(coinGroup,"coinGroup");
	HX_VISIT_MEMBER_NAME(dropsGroup,"dropsGroup");
	HX_VISIT_MEMBER_NAME(miscGroup,"miscGroup");
	HX_VISIT_MEMBER_NAME(_newEntrance,"_newEntrance");
	HX_VISIT_MEMBER_NAME(_curMapX,"_curMapX");
	HX_VISIT_MEMBER_NAME(_curMapY,"_curMapY");
	HX_VISIT_MEMBER_NAME(_hud,"_hud");
	HX_VISIT_MEMBER_NAME(_score,"_score");
	::flixel::FlxState_obj::__Visit(HX_VISIT_ARG);
}

Dynamic PlayState_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_hud") ) { return _hud; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_door") ) { return _door; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"player") ) { return player; }
		if (HX_FIELD_EQ(inName,"loader") ) { return loader; }
		if (HX_FIELD_EQ(inName,"_score") ) { return _score; }
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_player") ) { return _player; }
		if (HX_FIELD_EQ(inName,"levelId") ) { return levelId; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"getExit") ) { return getExit_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mTileMap") ) { return mTileMap; }
		if (HX_FIELD_EQ(inName,"tileName") ) { return tileName; }
		if (HX_FIELD_EQ(inName,"_curMapX") ) { return _curMapX; }
		if (HX_FIELD_EQ(inName,"_curMapY") ) { return _curMapY; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_grpCoins") ) { return _grpCoins; }
		if (HX_FIELD_EQ(inName,"_grpWalls") ) { return _grpWalls; }
		if (HX_FIELD_EQ(inName,"coinGroup") ) { return coinGroup; }
		if (HX_FIELD_EQ(inName,"miscGroup") ) { return miscGroup; }
		if (HX_FIELD_EQ(inName,"setUpMaps") ) { return setUpMaps_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_grpPlayer") ) { return _grpPlayer; }
		if (HX_FIELD_EQ(inName,"dropsGroup") ) { return dropsGroup; }
		if (HX_FIELD_EQ(inName,"setUpLevel") ) { return setUpLevel_dyn(); }
		if (HX_FIELD_EQ(inName,"touchEnemy") ) { return touchEnemy_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_grpEnemies") ) { return _grpEnemies; }
		if (HX_FIELD_EQ(inName,"_grpLadders") ) { return _grpLadders; }
		if (HX_FIELD_EQ(inName,"_grpHazards") ) { return _grpHazards; }
		if (HX_FIELD_EQ(inName,"_levelWidth") ) { return _levelWidth; }
		if (HX_FIELD_EQ(inName,"getEntrance") ) { return getEntrance_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_levelHeight") ) { return _levelHeight; }
		if (HX_FIELD_EQ(inName,"myOgmoLoader") ) { return myOgmoLoader; }
		if (HX_FIELD_EQ(inName,"midgroundMap") ) { return midgroundMap; }
		if (HX_FIELD_EQ(inName,"_newEntrance") ) { return _newEntrance; }
		if (HX_FIELD_EQ(inName,"playerGetHit") ) { return playerGetHit_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"playerBullets") ) { return playerBullets; }
		if (HX_FIELD_EQ(inName,"gotoNextLevel") ) { return gotoNextLevel_dyn(); }
		if (HX_FIELD_EQ(inName,"placeEntities") ) { return placeEntities_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_grpBadBullets") ) { return _grpBadBullets; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"playerTouchCoin") ) { return playerTouchCoin_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"bulletTouchEnemy") ) { return bulletTouchEnemy_dyn(); }
		if (HX_FIELD_EQ(inName,"playerTouchDrops") ) { return playerTouchDrops_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"bulletTouchLadder") ) { return bulletTouchLadder_dyn(); }
		if (HX_FIELD_EQ(inName,"playerTouchLadder") ) { return playerTouchLadder_dyn(); }
		if (HX_FIELD_EQ(inName,"playerTouchHazard") ) { return playerTouchHazard_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PlayState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_hud") ) { _hud=inValue.Cast< ::HUD >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_door") ) { _door=inValue.Cast< ::Door >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"player") ) { player=inValue.Cast< ::Player >(); return inValue; }
		if (HX_FIELD_EQ(inName,"loader") ) { loader=inValue.Cast< ::flixel::addons::editors::ogmo::FlxOgmoLoader >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_score") ) { _score=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_player") ) { _player=inValue.Cast< ::Player >(); return inValue; }
		if (HX_FIELD_EQ(inName,"levelId") ) { levelId=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mTileMap") ) { mTileMap=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tileName") ) { tileName=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_curMapX") ) { _curMapX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_curMapY") ) { _curMapY=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_grpCoins") ) { _grpCoins=inValue.Cast< ::flixel::group::FlxTypedGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_grpWalls") ) { _grpWalls=inValue.Cast< ::flixel::group::FlxTypedGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"coinGroup") ) { coinGroup=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"miscGroup") ) { miscGroup=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_grpPlayer") ) { _grpPlayer=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dropsGroup") ) { dropsGroup=inValue.Cast< ::flixel::group::FlxTypedGroup >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_grpEnemies") ) { _grpEnemies=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_grpLadders") ) { _grpLadders=inValue.Cast< ::flixel::group::FlxTypedGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_grpHazards") ) { _grpHazards=inValue.Cast< ::flixel::group::FlxTypedGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_levelWidth") ) { _levelWidth=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_levelHeight") ) { _levelHeight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"myOgmoLoader") ) { myOgmoLoader=inValue.Cast< ::flixel::addons::editors::ogmo::FlxOgmoLoader >(); return inValue; }
		if (HX_FIELD_EQ(inName,"midgroundMap") ) { midgroundMap=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_newEntrance") ) { _newEntrance=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"playerBullets") ) { playerBullets=inValue.Cast< ::flixel::group::FlxTypedGroup >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_grpBadBullets") ) { _grpBadBullets=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PlayState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_grpPlayer"));
	outFields->push(HX_CSTRING("_player"));
	outFields->push(HX_CSTRING("playerBullets"));
	outFields->push(HX_CSTRING("_grpEnemies"));
	outFields->push(HX_CSTRING("_grpBadBullets"));
	outFields->push(HX_CSTRING("_grpCoins"));
	outFields->push(HX_CSTRING("_grpLadders"));
	outFields->push(HX_CSTRING("_grpHazards"));
	outFields->push(HX_CSTRING("_door"));
	outFields->push(HX_CSTRING("_grpWalls"));
	outFields->push(HX_CSTRING("_levelWidth"));
	outFields->push(HX_CSTRING("_levelHeight"));
	outFields->push(HX_CSTRING("myOgmoLoader"));
	outFields->push(HX_CSTRING("mTileMap"));
	outFields->push(HX_CSTRING("levelId"));
	outFields->push(HX_CSTRING("tileName"));
	outFields->push(HX_CSTRING("loader"));
	outFields->push(HX_CSTRING("midgroundMap"));
	outFields->push(HX_CSTRING("coinGroup"));
	outFields->push(HX_CSTRING("dropsGroup"));
	outFields->push(HX_CSTRING("miscGroup"));
	outFields->push(HX_CSTRING("_newEntrance"));
	outFields->push(HX_CSTRING("_curMapX"));
	outFields->push(HX_CSTRING("_curMapY"));
	outFields->push(HX_CSTRING("_hud"));
	outFields->push(HX_CSTRING("_score"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("player"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(PlayState_obj,_grpPlayer),HX_CSTRING("_grpPlayer")},
	{hx::fsObject /*::Player*/ ,(int)offsetof(PlayState_obj,_player),HX_CSTRING("_player")},
	{hx::fsObject /*::flixel::group::FlxTypedGroup*/ ,(int)offsetof(PlayState_obj,playerBullets),HX_CSTRING("playerBullets")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(PlayState_obj,_grpEnemies),HX_CSTRING("_grpEnemies")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(PlayState_obj,_grpBadBullets),HX_CSTRING("_grpBadBullets")},
	{hx::fsObject /*::flixel::group::FlxTypedGroup*/ ,(int)offsetof(PlayState_obj,_grpCoins),HX_CSTRING("_grpCoins")},
	{hx::fsObject /*::flixel::group::FlxTypedGroup*/ ,(int)offsetof(PlayState_obj,_grpLadders),HX_CSTRING("_grpLadders")},
	{hx::fsObject /*::flixel::group::FlxTypedGroup*/ ,(int)offsetof(PlayState_obj,_grpHazards),HX_CSTRING("_grpHazards")},
	{hx::fsObject /*::Door*/ ,(int)offsetof(PlayState_obj,_door),HX_CSTRING("_door")},
	{hx::fsObject /*::flixel::group::FlxTypedGroup*/ ,(int)offsetof(PlayState_obj,_grpWalls),HX_CSTRING("_grpWalls")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,_levelWidth),HX_CSTRING("_levelWidth")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,_levelHeight),HX_CSTRING("_levelHeight")},
	{hx::fsObject /*::flixel::addons::editors::ogmo::FlxOgmoLoader*/ ,(int)offsetof(PlayState_obj,myOgmoLoader),HX_CSTRING("myOgmoLoader")},
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,mTileMap),HX_CSTRING("mTileMap")},
	{hx::fsString,(int)offsetof(PlayState_obj,levelId),HX_CSTRING("levelId")},
	{hx::fsString,(int)offsetof(PlayState_obj,tileName),HX_CSTRING("tileName")},
	{hx::fsObject /*::flixel::addons::editors::ogmo::FlxOgmoLoader*/ ,(int)offsetof(PlayState_obj,loader),HX_CSTRING("loader")},
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,midgroundMap),HX_CSTRING("midgroundMap")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(PlayState_obj,coinGroup),HX_CSTRING("coinGroup")},
	{hx::fsObject /*::flixel::group::FlxTypedGroup*/ ,(int)offsetof(PlayState_obj,dropsGroup),HX_CSTRING("dropsGroup")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(PlayState_obj,miscGroup),HX_CSTRING("miscGroup")},
	{hx::fsInt,(int)offsetof(PlayState_obj,_newEntrance),HX_CSTRING("_newEntrance")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,_curMapX),HX_CSTRING("_curMapX")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,_curMapY),HX_CSTRING("_curMapY")},
	{hx::fsObject /*::HUD*/ ,(int)offsetof(PlayState_obj,_hud),HX_CSTRING("_hud")},
	{hx::fsInt,(int)offsetof(PlayState_obj,_score),HX_CSTRING("_score")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_grpPlayer"),
	HX_CSTRING("_player"),
	HX_CSTRING("playerBullets"),
	HX_CSTRING("_grpEnemies"),
	HX_CSTRING("_grpBadBullets"),
	HX_CSTRING("_grpCoins"),
	HX_CSTRING("_grpLadders"),
	HX_CSTRING("_grpHazards"),
	HX_CSTRING("_door"),
	HX_CSTRING("_grpWalls"),
	HX_CSTRING("_levelWidth"),
	HX_CSTRING("_levelHeight"),
	HX_CSTRING("myOgmoLoader"),
	HX_CSTRING("mTileMap"),
	HX_CSTRING("levelId"),
	HX_CSTRING("tileName"),
	HX_CSTRING("loader"),
	HX_CSTRING("midgroundMap"),
	HX_CSTRING("coinGroup"),
	HX_CSTRING("dropsGroup"),
	HX_CSTRING("miscGroup"),
	HX_CSTRING("_newEntrance"),
	HX_CSTRING("_curMapX"),
	HX_CSTRING("_curMapY"),
	HX_CSTRING("_hud"),
	HX_CSTRING("_score"),
	HX_CSTRING("create"),
	HX_CSTRING("update"),
	HX_CSTRING("destroy"),
	HX_CSTRING("gotoNextLevel"),
	HX_CSTRING("setUpLevel"),
	HX_CSTRING("setUpMaps"),
	HX_CSTRING("touchEnemy"),
	HX_CSTRING("playerGetHit"),
	HX_CSTRING("bulletTouchEnemy"),
	HX_CSTRING("bulletTouchLadder"),
	HX_CSTRING("playerTouchDrops"),
	HX_CSTRING("playerTouchCoin"),
	HX_CSTRING("playerTouchLadder"),
	HX_CSTRING("playerTouchHazard"),
	HX_CSTRING("placeEntities"),
	HX_CSTRING("getExit"),
	HX_CSTRING("getEntrance"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(PlayState_obj::player,"player");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(PlayState_obj::player,"player");
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


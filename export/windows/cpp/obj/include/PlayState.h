#ifndef INCLUDED_PlayState
#define INCLUDED_PlayState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxState.h>
HX_DECLARE_CLASS0(Coin)
HX_DECLARE_CLASS0(Door)
HX_DECLARE_CLASS0(Drops)
HX_DECLARE_CLASS0(HUD)
HX_DECLARE_CLASS0(Ladder)
HX_DECLARE_CLASS0(PlayState)
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS0(Spike)
HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS1(enemies,EnemyTemplate)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS4(flixel,addons,editors,ogmo,FlxOgmoLoader)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,tile,FlxTilemap)
HX_DECLARE_CLASS1(weapons,Bullet)


class HXCPP_CLASS_ATTRIBUTES  PlayState_obj : public ::flixel::FlxState_obj{
	public:
		typedef ::flixel::FlxState_obj super;
		typedef PlayState_obj OBJ_;
		PlayState_obj();
		Void __construct(Dynamic MaxSize);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< PlayState_obj > __new(Dynamic MaxSize);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PlayState_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PlayState"); }

		::flixel::group::FlxGroup _grpPlayer;
		::Player _player;
		::flixel::group::FlxTypedGroup playerBullets;
		::flixel::group::FlxGroup _grpEnemies;
		::flixel::group::FlxGroup _grpBadBullets;
		::flixel::group::FlxTypedGroup _grpCoins;
		::flixel::group::FlxTypedGroup _grpLadders;
		::flixel::group::FlxTypedGroup _grpHazards;
		::Door _door;
		::flixel::group::FlxTypedGroup _grpWalls;
		Float _levelWidth;
		Float _levelHeight;
		::flixel::addons::editors::ogmo::FlxOgmoLoader myOgmoLoader;
		::flixel::tile::FlxTilemap mTileMap;
		::String levelId;
		::String tileName;
		::flixel::addons::editors::ogmo::FlxOgmoLoader loader;
		::flixel::tile::FlxTilemap midgroundMap;
		::flixel::group::FlxGroup coinGroup;
		::flixel::group::FlxTypedGroup dropsGroup;
		::flixel::group::FlxGroup miscGroup;
		int _newEntrance;
		Float _curMapX;
		Float _curMapY;
		::HUD _hud;
		int _score;
		virtual Void create( );

		virtual Void update( );

		virtual Void destroy( );

		virtual Void gotoNextLevel( );
		Dynamic gotoNextLevel_dyn();

		virtual Void setUpLevel( );
		Dynamic setUpLevel_dyn();

		virtual Void setUpMaps( ::flixel::addons::editors::ogmo::FlxOgmoLoader ogmo,::flixel::tile::FlxTilemap map);
		Dynamic setUpMaps_dyn();

		virtual Void touchEnemy( ::Player P,::enemies::EnemyTemplate E);
		Dynamic touchEnemy_dyn();

		virtual Void playerGetHit( ::Player P,::weapons::Bullet B);
		Dynamic playerGetHit_dyn();

		virtual Void bulletTouchEnemy( ::weapons::Bullet B,::enemies::EnemyTemplate E);
		Dynamic bulletTouchEnemy_dyn();

		virtual Void bulletTouchLadder( ::weapons::Bullet B,::Ladder L);
		Dynamic bulletTouchLadder_dyn();

		virtual Void playerTouchDrops( ::Player P,::Drops D);
		Dynamic playerTouchDrops_dyn();

		virtual Void playerTouchCoin( ::Player P,::Coin C);
		Dynamic playerTouchCoin_dyn();

		virtual Void playerTouchLadder( ::Player P,::Ladder L);
		Dynamic playerTouchLadder_dyn();

		virtual Void playerTouchHazard( ::Player P,::Spike S);
		Dynamic playerTouchHazard_dyn();

		virtual Void placeEntities( ::String entityName,::Xml entityData);
		Dynamic placeEntities_dyn();

		virtual Void getExit( ::String entityName,::Xml entityData);
		Dynamic getExit_dyn();

		virtual Void getEntrance( ::String entityName,::Xml entityData);
		Dynamic getEntrance_dyn();

		static ::Player player;
};


#endif /* INCLUDED_PlayState */ 

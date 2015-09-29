#ifndef INCLUDED_Drops
#define INCLUDED_Drops

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxSprite.h>
HX_DECLARE_CLASS0(Drops)
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,tweens,FlxTween)


class HXCPP_CLASS_ATTRIBUTES  Drops_obj : public ::flixel::FlxSprite_obj{
	public:
		typedef ::flixel::FlxSprite_obj super;
		typedef Drops_obj OBJ_;
		Drops_obj();
		Void __construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,int Index,::Player ThePlayer,bool Free);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Drops_obj > __new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,int Index,::Player ThePlayer,bool Free);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Drops_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Drops"); }

		::Player _player;
		int id;
		int price;
		bool free;
		virtual Void update( );

		virtual Void kill( );

		virtual Void finishKill( ::flixel::tweens::FlxTween _);
		Dynamic finishKill_dyn();

		virtual int allocatePrices( );
		Dynamic allocatePrices_dyn();

		virtual int doStuff( int score);
		Dynamic doStuff_dyn();

		virtual Void playerHeal( int Val);
		Dynamic playerHeal_dyn();

		virtual Void playerJuiceRestore( int Val);
		Dynamic playerJuiceRestore_dyn();

		virtual Void weaponStrengthUp( int Val);
		Dynamic weaponStrengthUp_dyn();

};


#endif /* INCLUDED_Drops */ 

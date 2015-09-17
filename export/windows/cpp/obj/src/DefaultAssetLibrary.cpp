#include <hxcpp.h>

#ifndef INCLUDED_Date
#include <Date.h>
#endif
#ifndef INCLUDED_DefaultAssetLibrary
#include <DefaultAssetLibrary.h>
#endif
#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED___ASSET__assets_fonts_arial_ttf
#include <__ASSET__assets_fonts_arial_ttf.h>
#endif
#ifndef INCLUDED___ASSET__assets_fonts_nokiafc22_ttf
#include <__ASSET__assets_fonts_nokiafc22_ttf.h>
#endif
#ifndef INCLUDED_cpp_vm_Deque
#include <cpp/vm/Deque.h>
#endif
#ifndef INCLUDED_cpp_vm_Thread
#include <cpp/vm/Thread.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_haxe_Unserializer
#include <haxe/Unserializer.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_openfl__legacy_AssetLibrary
#include <openfl/_legacy/AssetLibrary.h>
#endif
#ifndef INCLUDED_openfl__legacy_AssetType
#include <openfl/_legacy/AssetType.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_BitmapData
#include <openfl/_legacy/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_IBitmapDrawable
#include <openfl/_legacy/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__legacy_events_EventDispatcher
#include <openfl/_legacy/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__legacy_events_IEventDispatcher
#include <openfl/_legacy/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__legacy_media_Sound
#include <openfl/_legacy/media/Sound.h>
#endif
#ifndef INCLUDED_openfl__legacy_net_URLRequest
#include <openfl/_legacy/net/URLRequest.h>
#endif
#ifndef INCLUDED_openfl__legacy_text_Font
#include <openfl/_legacy/text/Font.h>
#endif
#ifndef INCLUDED_openfl__legacy_text_FontStyle
#include <openfl/_legacy/text/FontStyle.h>
#endif
#ifndef INCLUDED_openfl__legacy_text_FontType
#include <openfl/_legacy/text/FontType.h>
#endif
#ifndef INCLUDED_openfl__legacy_utils_ByteArray
#include <openfl/_legacy/utils/ByteArray.h>
#endif
#ifndef INCLUDED_openfl__legacy_utils_IDataInput
#include <openfl/_legacy/utils/IDataInput.h>
#endif
#ifndef INCLUDED_openfl__legacy_utils_IDataOutput
#include <openfl/_legacy/utils/IDataOutput.h>
#endif
#ifndef INCLUDED_openfl__legacy_utils_IMemoryRange
#include <openfl/_legacy/utils/IMemoryRange.h>
#endif
#ifndef INCLUDED_openfl_media_SoundLoaderContext
#include <openfl/media/SoundLoaderContext.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif

Void DefaultAssetLibrary_obj::__construct()
{
HX_STACK_FRAME("DefaultAssetLibrary","new",0xbc37e41e,"DefaultAssetLibrary.new","DefaultAssetLibrary.hx",37,0x0fc48912)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(48)
	this->type = ::haxe::ds::StringMap_obj::__new();
	HX_STACK_LINE(47)
	this->path = ::haxe::ds::StringMap_obj::__new();
	HX_STACK_LINE(46)
	this->className = ::haxe::ds::StringMap_obj::__new();
	HX_STACK_LINE(54)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(56)
	super::__construct();
	HX_STACK_LINE(72)
	::openfl::_legacy::text::Font_obj::registerFont(hx::ClassOf< ::__ASSET__assets_fonts_nokiafc22_ttf >());
	HX_STACK_LINE(73)
	::openfl::_legacy::text::Font_obj::registerFont(hx::ClassOf< ::__ASSET__assets_fonts_arial_ttf >());
	HX_STACK_LINE(78)
	bool useManifest = false;		HX_STACK_VAR(useManifest,"useManifest");
	HX_STACK_LINE(79)
	useManifest = true;
	HX_STACK_LINE(80)
	useManifest = true;
	HX_STACK_LINE(81)
	useManifest = true;
	HX_STACK_LINE(82)
	useManifest = true;
	HX_STACK_LINE(83)
	useManifest = true;
	HX_STACK_LINE(84)
	useManifest = true;
	HX_STACK_LINE(85)
	useManifest = true;
	HX_STACK_LINE(86)
	useManifest = true;
	HX_STACK_LINE(87)
	useManifest = true;
	HX_STACK_LINE(88)
	useManifest = true;
	HX_STACK_LINE(89)
	useManifest = true;
	HX_STACK_LINE(90)
	useManifest = true;
	HX_STACK_LINE(91)
	useManifest = true;
	HX_STACK_LINE(93)
	this->className->set(HX_CSTRING("assets/fonts/nokiafc22.ttf"),hx::ClassOf< ::__ASSET__assets_fonts_nokiafc22_ttf >());
	HX_STACK_LINE(94)
	this->type->set(HX_CSTRING("assets/fonts/nokiafc22.ttf"),::openfl::_legacy::AssetType_obj::FONT);
	HX_STACK_LINE(96)
	this->className->set(HX_CSTRING("assets/fonts/arial.ttf"),hx::ClassOf< ::__ASSET__assets_fonts_arial_ttf >());
	HX_STACK_LINE(97)
	this->type->set(HX_CSTRING("assets/fonts/arial.ttf"),::openfl::_legacy::AssetType_obj::FONT);
	HX_STACK_LINE(100)
	if ((useManifest)){
		HX_STACK_LINE(102)
		this->loadManifest();
		HX_STACK_LINE(104)
		int _g1 = ::Sys_obj::args()->indexOf(HX_CSTRING("-livereload"),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(104)
		if (((_g1 > (int)-1))){
			HX_STACK_LINE(106)
			Array< ::String > path = Array_obj< ::String >::__new().Add(::sys::FileSystem_obj::fullPath(HX_CSTRING("manifest")));		HX_STACK_VAR(path,"path");
			HX_STACK_LINE(107)
			Float _g11 = ::sys::FileSystem_obj::stat(path->__get((int)0))->__Field(HX_CSTRING("mtime"),true)->__Field(HX_CSTRING("getTime"),true)();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(107)
			this->lastModified = _g11;
			HX_STACK_LINE(109)
			::haxe::Timer _g2 = ::haxe::Timer_obj::__new((int)2000);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(109)
			this->timer = _g2;

			HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_3_1,Array< ::Dynamic >,_g,Array< ::String >,path)
			Void run(){
				HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","DefaultAssetLibrary.hx",110,0x0fc48912)
				{
					HX_STACK_LINE(112)
					Float modified = ::sys::FileSystem_obj::stat(path->__get((int)0))->__Field(HX_CSTRING("mtime"),true)->__Field(HX_CSTRING("getTime"),true)();		HX_STACK_VAR(modified,"modified");
					HX_STACK_LINE(114)
					if (((modified > _g->__get((int)0).StaticCast< ::DefaultAssetLibrary >()->lastModified))){
						HX_STACK_LINE(116)
						_g->__get((int)0).StaticCast< ::DefaultAssetLibrary >()->lastModified = modified;
						HX_STACK_LINE(117)
						_g->__get((int)0).StaticCast< ::DefaultAssetLibrary >()->loadManifest();
						HX_STACK_LINE(119)
						if (((_g->__get((int)0).StaticCast< ::DefaultAssetLibrary >()->eventCallback != null()))){
							HX_STACK_LINE(121)
							_g->__get((int)0).StaticCast< ::DefaultAssetLibrary >()->eventCallback(_g->__get((int)0).StaticCast< ::DefaultAssetLibrary >(),HX_CSTRING("change"));
						}
					}
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_STACK_LINE(110)
			this->timer->run =  Dynamic(new _Function_3_1(_g,path));
		}
	}
}
;
	return null();
}

//DefaultAssetLibrary_obj::~DefaultAssetLibrary_obj() { }

Dynamic DefaultAssetLibrary_obj::__CreateEmpty() { return  new DefaultAssetLibrary_obj; }
hx::ObjectPtr< DefaultAssetLibrary_obj > DefaultAssetLibrary_obj::__new()
{  hx::ObjectPtr< DefaultAssetLibrary_obj > result = new DefaultAssetLibrary_obj();
	result->__construct();
	return result;}

Dynamic DefaultAssetLibrary_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DefaultAssetLibrary_obj > result = new DefaultAssetLibrary_obj();
	result->__construct();
	return result;}

bool DefaultAssetLibrary_obj::exists( ::String id,::openfl::_legacy::AssetType type){
	HX_STACK_FRAME("DefaultAssetLibrary","exists",0x972074de,"DefaultAssetLibrary.exists","DefaultAssetLibrary.hx",142,0x0fc48912)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_ARG(type,"type")
	HX_STACK_LINE(144)
	::openfl::_legacy::AssetType assetType = this->type->get(id);		HX_STACK_VAR(assetType,"assetType");
	HX_STACK_LINE(146)
	if (((assetType != null()))){
		HX_STACK_LINE(148)
		if (((bool((assetType == type)) || bool((bool(((bool((type == ::openfl::_legacy::AssetType_obj::SOUND)) || bool((type == ::openfl::_legacy::AssetType_obj::MUSIC))))) && bool(((bool((assetType == ::openfl::_legacy::AssetType_obj::MUSIC)) || bool((assetType == ::openfl::_legacy::AssetType_obj::SOUND)))))))))){
			HX_STACK_LINE(150)
			return true;
		}
		HX_STACK_LINE(154)
		if (((bool((bool((type == ::openfl::_legacy::AssetType_obj::BINARY)) || bool((type == null())))) || bool((bool((assetType == ::openfl::_legacy::AssetType_obj::BINARY)) && bool((type == ::openfl::_legacy::AssetType_obj::TEXT))))))){
			HX_STACK_LINE(156)
			return true;
		}
	}
	HX_STACK_LINE(162)
	return false;
}


::openfl::_legacy::display::BitmapData DefaultAssetLibrary_obj::getBitmapData( ::String id){
	HX_STACK_FRAME("DefaultAssetLibrary","getBitmapData",0xb8207f2d,"DefaultAssetLibrary.getBitmapData","DefaultAssetLibrary.hx",169,0x0fc48912)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(169)
	if ((this->className->exists(id))){
		HX_STACK_LINE(171)
		Dynamic _g = this->className->get(id);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(171)
		return hx::TCast< openfl::_legacy::display::BitmapData >::cast(::Type_obj::createInstance(_g,Dynamic( Array_obj<Dynamic>::__new())));
	}
	else{
		HX_STACK_LINE(175)
		::String _g1 = this->path->get(id);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(175)
		return ::openfl::_legacy::display::BitmapData_obj::load(_g1,null());
	}
	HX_STACK_LINE(169)
	return null();
}


::openfl::_legacy::utils::ByteArray DefaultAssetLibrary_obj::getBytes( ::String id){
	HX_STACK_FRAME("DefaultAssetLibrary","getBytes",0x86b4b377,"DefaultAssetLibrary.getBytes","DefaultAssetLibrary.hx",184,0x0fc48912)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(184)
	if ((this->className->exists(id))){
		HX_STACK_LINE(186)
		Dynamic _g = this->className->get(id);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(186)
		return hx::TCast< openfl::_legacy::utils::ByteArray >::cast(::Type_obj::createInstance(_g,Dynamic( Array_obj<Dynamic>::__new())));
	}
	else{
		HX_STACK_LINE(190)
		::String _g1 = this->path->get(id);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(190)
		return ::openfl::_legacy::utils::ByteArray_obj::readFile(_g1);
	}
	HX_STACK_LINE(184)
	return null();
}


::openfl::_legacy::text::Font DefaultAssetLibrary_obj::getFont( ::String id){
	HX_STACK_FRAME("DefaultAssetLibrary","getFont",0x974ed843,"DefaultAssetLibrary.getFont","DefaultAssetLibrary.hx",199,0x0fc48912)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(199)
	if ((this->className->exists(id))){
		HX_STACK_LINE(201)
		Dynamic fontClass = this->className->get(id);		HX_STACK_VAR(fontClass,"fontClass");
		HX_STACK_LINE(202)
		::openfl::_legacy::text::Font_obj::registerFont(fontClass);
		HX_STACK_LINE(203)
		return hx::TCast< openfl::_legacy::text::Font >::cast(::Type_obj::createInstance(fontClass,Dynamic( Array_obj<Dynamic>::__new())));
	}
	else{
		HX_STACK_LINE(207)
		::String _g = this->path->get(id);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(207)
		return ::openfl::_legacy::text::Font_obj::__new(_g,null(),null());
	}
	HX_STACK_LINE(199)
	return null();
}


::openfl::_legacy::media::Sound DefaultAssetLibrary_obj::getMusic( ::String id){
	HX_STACK_FRAME("DefaultAssetLibrary","getMusic",0xd9777bb1,"DefaultAssetLibrary.getMusic","DefaultAssetLibrary.hx",216,0x0fc48912)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(216)
	if ((this->className->exists(id))){
		HX_STACK_LINE(218)
		Dynamic _g = this->className->get(id);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(218)
		return hx::TCast< openfl::_legacy::media::Sound >::cast(::Type_obj::createInstance(_g,Dynamic( Array_obj<Dynamic>::__new())));
	}
	else{
		HX_STACK_LINE(222)
		::String _g1 = this->path->get(id);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(222)
		::openfl::_legacy::net::URLRequest _g2 = ::openfl::_legacy::net::URLRequest_obj::__new(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(222)
		return ::openfl::_legacy::media::Sound_obj::__new(_g2,null(),true);
	}
	HX_STACK_LINE(216)
	return null();
}


::String DefaultAssetLibrary_obj::getPath( ::String id){
	HX_STACK_FRAME("DefaultAssetLibrary","getPath",0x9de06019,"DefaultAssetLibrary.getPath","DefaultAssetLibrary.hx",237,0x0fc48912)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(237)
	return this->path->get(id);
}


::openfl::_legacy::media::Sound DefaultAssetLibrary_obj::getSound( ::String id){
	HX_STACK_FRAME("DefaultAssetLibrary","getSound",0x49e937db,"DefaultAssetLibrary.getSound","DefaultAssetLibrary.hx",246,0x0fc48912)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(246)
	if ((this->className->exists(id))){
		HX_STACK_LINE(248)
		Dynamic _g = this->className->get(id);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(248)
		return hx::TCast< openfl::_legacy::media::Sound >::cast(::Type_obj::createInstance(_g,Dynamic( Array_obj<Dynamic>::__new())));
	}
	else{
		HX_STACK_LINE(252)
		::String _g1 = this->path->get(id);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(252)
		::openfl::_legacy::net::URLRequest _g2 = ::openfl::_legacy::net::URLRequest_obj::__new(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(252)
		::openfl::_legacy::AssetType _g3 = this->type->get(id);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(252)
		bool _g4 = (_g3 == ::openfl::_legacy::AssetType_obj::MUSIC);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(252)
		return ::openfl::_legacy::media::Sound_obj::__new(_g2,null(),_g4);
	}
	HX_STACK_LINE(246)
	return null();
}


::String DefaultAssetLibrary_obj::getText( ::String id){
	HX_STACK_FRAME("DefaultAssetLibrary","getText",0xa0884721,"DefaultAssetLibrary.getText","DefaultAssetLibrary.hx",259,0x0fc48912)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(261)
	::openfl::_legacy::utils::ByteArray bytes = this->getBytes(id);		HX_STACK_VAR(bytes,"bytes");
	HX_STACK_LINE(263)
	if (((bytes == null()))){
		HX_STACK_LINE(265)
		return null();
	}
	else{
		HX_STACK_LINE(269)
		return bytes->readUTFBytes(bytes->length);
	}
	HX_STACK_LINE(263)
	return null();
}


bool DefaultAssetLibrary_obj::isLocal( ::String id,::openfl::_legacy::AssetType type){
	HX_STACK_FRAME("DefaultAssetLibrary","isLocal",0x968237df,"DefaultAssetLibrary.isLocal","DefaultAssetLibrary.hx",278,0x0fc48912)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_ARG(type,"type")
	HX_STACK_LINE(278)
	return true;
}


Array< ::String > DefaultAssetLibrary_obj::list( ::openfl::_legacy::AssetType type){
	HX_STACK_FRAME("DefaultAssetLibrary","list",0xf3604ee0,"DefaultAssetLibrary.list","DefaultAssetLibrary.hx",283,0x0fc48912)
	HX_STACK_THIS(this)
	HX_STACK_ARG(type,"type")
	HX_STACK_LINE(285)
	Array< ::String > items = Array_obj< ::String >::__new();		HX_STACK_VAR(items,"items");
	HX_STACK_LINE(287)
	for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->type->keys());  __it->hasNext(); ){
		::String id = __it->next();
		if (((  ((!(((type == null()))))) ? bool(this->exists(id,type)) : bool(true) ))){
			HX_STACK_LINE(291)
			items->push(id);
		}
;
	}
	HX_STACK_LINE(297)
	return items;
}


Void DefaultAssetLibrary_obj::loadBitmapData( ::String id,Dynamic handler){
{
		HX_STACK_FRAME("DefaultAssetLibrary","loadBitmapData",0x9243e881,"DefaultAssetLibrary.loadBitmapData","DefaultAssetLibrary.hx",304,0x0fc48912)
		HX_STACK_THIS(this)
		HX_STACK_ARG(id,"id")
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(304)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(HX_CSTRING("WORK"));
		HX_STACK_LINE(304)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(this->getBitmapData_dyn());
		HX_STACK_LINE(304)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(id);
		HX_STACK_LINE(304)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(handler);
		HX_STACK_LINE(304)
		(::DefaultAssetLibrary_obj::loading)++;
	}
return null();
}


Void DefaultAssetLibrary_obj::loadBytes( ::String id,Dynamic handler){
{
		HX_STACK_FRAME("DefaultAssetLibrary","loadBytes",0x8c71caa3,"DefaultAssetLibrary.loadBytes","DefaultAssetLibrary.hx",311,0x0fc48912)
		HX_STACK_THIS(this)
		HX_STACK_ARG(id,"id")
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(311)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(HX_CSTRING("WORK"));
		HX_STACK_LINE(311)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(this->getBytes_dyn());
		HX_STACK_LINE(311)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(id);
		HX_STACK_LINE(311)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(handler);
		HX_STACK_LINE(311)
		(::DefaultAssetLibrary_obj::loading)++;
	}
return null();
}


Void DefaultAssetLibrary_obj::loadFont( ::String id,Dynamic handler){
{
		HX_STACK_FRAME("DefaultAssetLibrary","loadFont",0x1da5ca97,"DefaultAssetLibrary.loadFont","DefaultAssetLibrary.hx",318,0x0fc48912)
		HX_STACK_THIS(this)
		HX_STACK_ARG(id,"id")
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(318)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(HX_CSTRING("WORK"));
		HX_STACK_LINE(318)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(this->getFont_dyn());
		HX_STACK_LINE(318)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(id);
		HX_STACK_LINE(318)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(handler);
		HX_STACK_LINE(318)
		(::DefaultAssetLibrary_obj::loading)++;
	}
return null();
}


Void DefaultAssetLibrary_obj::loadManifest( ){
{
		HX_STACK_FRAME("DefaultAssetLibrary","loadManifest",0x6f596c77,"DefaultAssetLibrary.loadManifest","DefaultAssetLibrary.hx",325,0x0fc48912)
		HX_STACK_THIS(this)
		HX_STACK_LINE(325)
		try
		{
		HX_STACK_CATCHABLE(Dynamic, 0);
		{
			HX_STACK_LINE(334)
			::openfl::_legacy::utils::ByteArray bytes = ::openfl::_legacy::utils::ByteArray_obj::readFile(HX_CSTRING("manifest"));		HX_STACK_VAR(bytes,"bytes");
			HX_STACK_LINE(337)
			if (((bytes != null()))){
				HX_STACK_LINE(339)
				bytes->position = (int)0;
				HX_STACK_LINE(341)
				if (((bytes->length > (int)0))){
					HX_STACK_LINE(343)
					::String data = bytes->readUTFBytes(bytes->length);		HX_STACK_VAR(data,"data");
					HX_STACK_LINE(345)
					if (((bool((data != null())) && bool((data.length > (int)0))))){
						HX_STACK_LINE(347)
						Dynamic manifest = ::haxe::Unserializer_obj::run(data);		HX_STACK_VAR(manifest,"manifest");
						HX_STACK_LINE(349)
						{
							HX_STACK_LINE(349)
							int _g = (int)0;		HX_STACK_VAR(_g,"_g");
							HX_STACK_LINE(349)
							while((true)){
								HX_STACK_LINE(349)
								if ((!(((_g < manifest->__Field(HX_CSTRING("length"),true)))))){
									HX_STACK_LINE(349)
									break;
								}
								HX_STACK_LINE(349)
								Dynamic asset = manifest->__GetItem(_g);		HX_STACK_VAR(asset,"asset");
								HX_STACK_LINE(349)
								++(_g);
								struct _Function_7_1{
									inline static bool Block( hx::ObjectPtr< ::DefaultAssetLibrary_obj > __this,Dynamic &asset){
										HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","DefaultAssetLibrary.hx",351,0x0fc48912)
										{
											HX_STACK_LINE(351)
											::String key = asset->__Field(HX_CSTRING("id"),true);		HX_STACK_VAR(key,"key");
											HX_STACK_LINE(351)
											return __this->className->exists(key);
										}
										return null();
									}
								};
								HX_STACK_LINE(351)
								if ((!(_Function_7_1::Block(this,asset)))){
									HX_STACK_LINE(353)
									{
										HX_STACK_LINE(353)
										::String key = asset->__Field(HX_CSTRING("id"),true);		HX_STACK_VAR(key,"key");
										HX_STACK_LINE(353)
										::String value = asset->__Field(HX_CSTRING("path"),true);		HX_STACK_VAR(value,"value");
										HX_STACK_LINE(353)
										this->path->set(key,value);
									}
									HX_STACK_LINE(354)
									{
										HX_STACK_LINE(354)
										::String key = asset->__Field(HX_CSTRING("id"),true);		HX_STACK_VAR(key,"key");
										HX_STACK_LINE(354)
										::openfl::_legacy::AssetType value = ::Type_obj::createEnum(hx::ClassOf< ::openfl::_legacy::AssetType >(),asset->__Field(HX_CSTRING("type"),true),null());		HX_STACK_VAR(value,"value");
										HX_STACK_LINE(354)
										this->type->set(key,value);
									}
								}
							}
						}
					}
				}
			}
			else{
				HX_STACK_LINE(366)
				::haxe::Log_obj::trace(HX_CSTRING("Warning: Could not load asset manifest (bytes was null)"),hx::SourceInfo(HX_CSTRING("DefaultAssetLibrary.hx"),366,HX_CSTRING("DefaultAssetLibrary"),HX_CSTRING("loadManifest")));
			}
		}
		}
		catch(Dynamic __e){
			{
				HX_STACK_BEGIN_CATCH
				Dynamic e = __e;{
					HX_STACK_LINE(372)
					::String _g = ::Std_obj::string(e);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(372)
					::String _g1 = (HX_CSTRING("Warning: Could not load asset manifest (") + _g);		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(372)
					::String _g2 = (_g1 + HX_CSTRING(")"));		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(372)
					::haxe::Log_obj::trace(_g2,hx::SourceInfo(HX_CSTRING("DefaultAssetLibrary.hx"),372,HX_CSTRING("DefaultAssetLibrary"),HX_CSTRING("loadManifest")));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DefaultAssetLibrary_obj,loadManifest,(void))

Void DefaultAssetLibrary_obj::loadMusic( ::String id,Dynamic handler){
{
		HX_STACK_FRAME("DefaultAssetLibrary","loadMusic",0xdf3492dd,"DefaultAssetLibrary.loadMusic","DefaultAssetLibrary.hx",381,0x0fc48912)
		HX_STACK_THIS(this)
		HX_STACK_ARG(id,"id")
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(381)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(HX_CSTRING("WORK"));
		HX_STACK_LINE(381)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(this->getMusic_dyn());
		HX_STACK_LINE(381)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(id);
		HX_STACK_LINE(381)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(handler);
		HX_STACK_LINE(381)
		(::DefaultAssetLibrary_obj::loading)++;
	}
return null();
}


Void DefaultAssetLibrary_obj::loadSound( ::String id,Dynamic handler){
{
		HX_STACK_FRAME("DefaultAssetLibrary","loadSound",0x4fa64f07,"DefaultAssetLibrary.loadSound","DefaultAssetLibrary.hx",388,0x0fc48912)
		HX_STACK_THIS(this)
		HX_STACK_ARG(id,"id")
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(388)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(HX_CSTRING("WORK"));
		HX_STACK_LINE(388)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(this->getSound_dyn());
		HX_STACK_LINE(388)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(id);
		HX_STACK_LINE(388)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(handler);
		HX_STACK_LINE(388)
		(::DefaultAssetLibrary_obj::loading)++;
	}
return null();
}


Void DefaultAssetLibrary_obj::loadText( ::String id,Dynamic handler){
{
		HX_STACK_FRAME("DefaultAssetLibrary","loadText",0x26df3975,"DefaultAssetLibrary.loadText","DefaultAssetLibrary.hx",393,0x0fc48912)
		HX_STACK_THIS(this)
		HX_STACK_ARG(id,"id")
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(393)
		Dynamic handler1 = Dynamic( Array_obj<Dynamic>::__new().Add(handler));		HX_STACK_VAR(handler1,"handler1");

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Dynamic,handler1)
		Void run(::openfl::_legacy::utils::ByteArray bytes){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","DefaultAssetLibrary.hx",397,0x0fc48912)
			HX_STACK_ARG(bytes,"bytes")
			{
				HX_STACK_LINE(397)
				if (((bytes == null()))){
					HX_STACK_LINE(399)
					handler1->__GetItem((int)0)(null()).Cast< Void >();
				}
				else{
					HX_STACK_LINE(403)
					::String _g = bytes->readUTFBytes(bytes->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(403)
					handler1->__GetItem((int)0)(_g).Cast< Void >();
				}
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(395)
		Dynamic callback =  Dynamic(new _Function_1_1(handler1));		HX_STACK_VAR(callback,"callback");
		HX_STACK_LINE(409)
		this->loadBytes(id,callback);
	}
return null();
}


Void DefaultAssetLibrary_obj::__load( Dynamic getMethod,::String id,Dynamic handler){
{
		HX_STACK_FRAME("DefaultAssetLibrary","__load",0xcdf05448,"DefaultAssetLibrary.__load","DefaultAssetLibrary.hx",442,0x0fc48912)
		HX_STACK_THIS(this)
		HX_STACK_ARG(getMethod,"getMethod")
		HX_STACK_ARG(id,"id")
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(444)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(HX_CSTRING("WORK"));
		HX_STACK_LINE(445)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(getMethod);
		HX_STACK_LINE(446)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(id);
		HX_STACK_LINE(447)
		::DefaultAssetLibrary_obj::workerIncomingQueue->add(handler);
		HX_STACK_LINE(449)
		(::DefaultAssetLibrary_obj::loading)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(DefaultAssetLibrary_obj,__load,(void))

int DefaultAssetLibrary_obj::loaded;

int DefaultAssetLibrary_obj::loading;

::cpp::vm::Deque DefaultAssetLibrary_obj::workerIncomingQueue;

::cpp::vm::Deque DefaultAssetLibrary_obj::workerResult;

::cpp::vm::Thread DefaultAssetLibrary_obj::workerThread;

Void DefaultAssetLibrary_obj::__doWork( ){
{
		HX_STACK_FRAME("DefaultAssetLibrary","__doWork",0x3075ad9e,"DefaultAssetLibrary.__doWork","DefaultAssetLibrary.hx",416,0x0fc48912)
		HX_STACK_LINE(416)
		while((true)){
			HX_STACK_LINE(418)
			::String message = ::DefaultAssetLibrary_obj::workerIncomingQueue->pop(true);		HX_STACK_VAR(message,"message");
			HX_STACK_LINE(420)
			if (((message == HX_CSTRING("WORK")))){
				HX_STACK_LINE(422)
				Dynamic getMethod = ::DefaultAssetLibrary_obj::workerIncomingQueue->pop(true);		HX_STACK_VAR(getMethod,"getMethod");
				HX_STACK_LINE(423)
				Dynamic id = ::DefaultAssetLibrary_obj::workerIncomingQueue->pop(true);		HX_STACK_VAR(id,"id");
				HX_STACK_LINE(424)
				Dynamic handler = ::DefaultAssetLibrary_obj::workerIncomingQueue->pop(true);		HX_STACK_VAR(handler,"handler");
				HX_STACK_LINE(426)
				Dynamic data = getMethod(id);		HX_STACK_VAR(data,"data");
				HX_STACK_LINE(427)
				::DefaultAssetLibrary_obj::workerResult->add(HX_CSTRING("RESULT"));
				HX_STACK_LINE(428)
				::DefaultAssetLibrary_obj::workerResult->add(data);
				HX_STACK_LINE(429)
				::DefaultAssetLibrary_obj::workerResult->add(handler);
			}
			else{
				HX_STACK_LINE(431)
				if (((message == HX_CSTRING("EXIT")))){
					HX_STACK_LINE(433)
					break;
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(DefaultAssetLibrary_obj,__doWork,(void))

Void DefaultAssetLibrary_obj::__poll( ){
{
		HX_STACK_FRAME("DefaultAssetLibrary","__poll",0xd0953861,"DefaultAssetLibrary.__poll","DefaultAssetLibrary.hx",456,0x0fc48912)
		HX_STACK_LINE(456)
		if (((::DefaultAssetLibrary_obj::loading > ::DefaultAssetLibrary_obj::loaded))){
			HX_STACK_LINE(458)
			if (((::DefaultAssetLibrary_obj::workerThread == null()))){
				HX_STACK_LINE(460)
				::cpp::vm::Thread _g = ::cpp::vm::Thread_obj::create(::DefaultAssetLibrary_obj::__doWork_dyn());		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(460)
				::DefaultAssetLibrary_obj::workerThread = _g;
			}
			HX_STACK_LINE(464)
			::String message = ::DefaultAssetLibrary_obj::workerResult->pop(false);		HX_STACK_VAR(message,"message");
			HX_STACK_LINE(466)
			while((true)){
				HX_STACK_LINE(466)
				if ((!(((message == HX_CSTRING("RESULT")))))){
					HX_STACK_LINE(466)
					break;
				}
				HX_STACK_LINE(468)
				(::DefaultAssetLibrary_obj::loaded)++;
				HX_STACK_LINE(470)
				Dynamic data = ::DefaultAssetLibrary_obj::workerResult->pop(true);		HX_STACK_VAR(data,"data");
				HX_STACK_LINE(471)
				Dynamic handler = ::DefaultAssetLibrary_obj::workerResult->pop(true);		HX_STACK_VAR(handler,"handler");
				HX_STACK_LINE(473)
				if (((handler != null()))){
					HX_STACK_LINE(475)
					handler(data);
				}
				HX_STACK_LINE(479)
				Dynamic _g1 = ::DefaultAssetLibrary_obj::workerResult->pop(false);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(479)
				message = _g1;
			}
		}
		else{
			HX_STACK_LINE(485)
			if (((::DefaultAssetLibrary_obj::workerThread != null()))){
				HX_STACK_LINE(487)
				::DefaultAssetLibrary_obj::workerIncomingQueue->add(HX_CSTRING("EXIT"));
				HX_STACK_LINE(488)
				::DefaultAssetLibrary_obj::workerThread = null();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(DefaultAssetLibrary_obj,__poll,(void))


DefaultAssetLibrary_obj::DefaultAssetLibrary_obj()
{
}

void DefaultAssetLibrary_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DefaultAssetLibrary);
	HX_MARK_MEMBER_NAME(className,"className");
	HX_MARK_MEMBER_NAME(path,"path");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(lastModified,"lastModified");
	HX_MARK_MEMBER_NAME(timer,"timer");
	::openfl::_legacy::AssetLibrary_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void DefaultAssetLibrary_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(className,"className");
	HX_VISIT_MEMBER_NAME(path,"path");
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(lastModified,"lastModified");
	HX_VISIT_MEMBER_NAME(timer,"timer");
	::openfl::_legacy::AssetLibrary_obj::__Visit(HX_VISIT_ARG);
}

Dynamic DefaultAssetLibrary_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"path") ) { return path; }
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		if (HX_FIELD_EQ(inName,"list") ) { return list_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"timer") ) { return timer; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"loaded") ) { return loaded; }
		if (HX_FIELD_EQ(inName,"__poll") ) { return __poll_dyn(); }
		if (HX_FIELD_EQ(inName,"exists") ) { return exists_dyn(); }
		if (HX_FIELD_EQ(inName,"__load") ) { return __load_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"loading") ) { return loading; }
		if (HX_FIELD_EQ(inName,"getFont") ) { return getFont_dyn(); }
		if (HX_FIELD_EQ(inName,"getPath") ) { return getPath_dyn(); }
		if (HX_FIELD_EQ(inName,"getText") ) { return getText_dyn(); }
		if (HX_FIELD_EQ(inName,"isLocal") ) { return isLocal_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"__doWork") ) { return __doWork_dyn(); }
		if (HX_FIELD_EQ(inName,"getBytes") ) { return getBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"getMusic") ) { return getMusic_dyn(); }
		if (HX_FIELD_EQ(inName,"getSound") ) { return getSound_dyn(); }
		if (HX_FIELD_EQ(inName,"loadFont") ) { return loadFont_dyn(); }
		if (HX_FIELD_EQ(inName,"loadText") ) { return loadText_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"className") ) { return className; }
		if (HX_FIELD_EQ(inName,"loadBytes") ) { return loadBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"loadMusic") ) { return loadMusic_dyn(); }
		if (HX_FIELD_EQ(inName,"loadSound") ) { return loadSound_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"workerResult") ) { return workerResult; }
		if (HX_FIELD_EQ(inName,"workerThread") ) { return workerThread; }
		if (HX_FIELD_EQ(inName,"lastModified") ) { return lastModified; }
		if (HX_FIELD_EQ(inName,"loadManifest") ) { return loadManifest_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getBitmapData") ) { return getBitmapData_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"loadBitmapData") ) { return loadBitmapData_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"workerIncomingQueue") ) { return workerIncomingQueue; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DefaultAssetLibrary_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"path") ) { path=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"timer") ) { timer=inValue.Cast< ::haxe::Timer >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"loaded") ) { loaded=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"loading") ) { loading=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"className") ) { className=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"workerResult") ) { workerResult=inValue.Cast< ::cpp::vm::Deque >(); return inValue; }
		if (HX_FIELD_EQ(inName,"workerThread") ) { workerThread=inValue.Cast< ::cpp::vm::Thread >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lastModified") ) { lastModified=inValue.Cast< Float >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"workerIncomingQueue") ) { workerIncomingQueue=inValue.Cast< ::cpp::vm::Deque >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DefaultAssetLibrary_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("className"));
	outFields->push(HX_CSTRING("path"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("lastModified"));
	outFields->push(HX_CSTRING("timer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("loaded"),
	HX_CSTRING("loading"),
	HX_CSTRING("workerIncomingQueue"),
	HX_CSTRING("workerResult"),
	HX_CSTRING("workerThread"),
	HX_CSTRING("__doWork"),
	HX_CSTRING("__poll"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(DefaultAssetLibrary_obj,className),HX_CSTRING("className")},
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(DefaultAssetLibrary_obj,path),HX_CSTRING("path")},
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(DefaultAssetLibrary_obj,type),HX_CSTRING("type")},
	{hx::fsFloat,(int)offsetof(DefaultAssetLibrary_obj,lastModified),HX_CSTRING("lastModified")},
	{hx::fsObject /*::haxe::Timer*/ ,(int)offsetof(DefaultAssetLibrary_obj,timer),HX_CSTRING("timer")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("className"),
	HX_CSTRING("path"),
	HX_CSTRING("type"),
	HX_CSTRING("lastModified"),
	HX_CSTRING("timer"),
	HX_CSTRING("exists"),
	HX_CSTRING("getBitmapData"),
	HX_CSTRING("getBytes"),
	HX_CSTRING("getFont"),
	HX_CSTRING("getMusic"),
	HX_CSTRING("getPath"),
	HX_CSTRING("getSound"),
	HX_CSTRING("getText"),
	HX_CSTRING("isLocal"),
	HX_CSTRING("list"),
	HX_CSTRING("loadBitmapData"),
	HX_CSTRING("loadBytes"),
	HX_CSTRING("loadFont"),
	HX_CSTRING("loadManifest"),
	HX_CSTRING("loadMusic"),
	HX_CSTRING("loadSound"),
	HX_CSTRING("loadText"),
	HX_CSTRING("__load"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DefaultAssetLibrary_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(DefaultAssetLibrary_obj::loaded,"loaded");
	HX_MARK_MEMBER_NAME(DefaultAssetLibrary_obj::loading,"loading");
	HX_MARK_MEMBER_NAME(DefaultAssetLibrary_obj::workerIncomingQueue,"workerIncomingQueue");
	HX_MARK_MEMBER_NAME(DefaultAssetLibrary_obj::workerResult,"workerResult");
	HX_MARK_MEMBER_NAME(DefaultAssetLibrary_obj::workerThread,"workerThread");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DefaultAssetLibrary_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(DefaultAssetLibrary_obj::loaded,"loaded");
	HX_VISIT_MEMBER_NAME(DefaultAssetLibrary_obj::loading,"loading");
	HX_VISIT_MEMBER_NAME(DefaultAssetLibrary_obj::workerIncomingQueue,"workerIncomingQueue");
	HX_VISIT_MEMBER_NAME(DefaultAssetLibrary_obj::workerResult,"workerResult");
	HX_VISIT_MEMBER_NAME(DefaultAssetLibrary_obj::workerThread,"workerThread");
};

#endif

Class DefaultAssetLibrary_obj::__mClass;

void DefaultAssetLibrary_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("DefaultAssetLibrary"), hx::TCanCast< DefaultAssetLibrary_obj> ,sStaticFields,sMemberFields,
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

void DefaultAssetLibrary_obj::__boot()
{
	loaded= (int)0;
	loading= (int)0;
	workerIncomingQueue= ::cpp::vm::Deque_obj::__new();
	workerResult= ::cpp::vm::Deque_obj::__new();
}


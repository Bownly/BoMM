package;


import haxe.Timer;
import haxe.Unserializer;
import lime.app.Preloader;
import lime.audio.AudioSource;
import lime.audio.openal.AL;
import lime.audio.AudioBuffer;
import lime.graphics.Image;
import lime.system.ThreadPool;
import lime.text.Font;
import lime.utils.ByteArray;
import lime.utils.UInt8Array;
import lime.Assets;

#if sys
import sys.FileSystem;
#end

#if (js && html5)
import lime.net.URLLoader;
import lime.net.URLRequest;
#elseif flash
import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.Loader;
import flash.events.Event;
import flash.media.Sound;
import flash.net.URLLoader;
import flash.net.URLRequest;
#end


class DefaultAssetLibrary extends AssetLibrary {
	
	
	public var className (default, null) = new Map <String, Dynamic> ();
	public var path (default, null) = new Map <String, String> ();
	public var type (default, null) = new Map <String, AssetType> ();
	
	private var lastModified:Float;
	private var threadPool:ThreadPool;
	private var timer:Timer;
	
	
	public function new () {
		
		super ();
		
		#if (openfl && !flash)
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		openfl.text.Font.registerFont (__ASSET__OPENFL__assets_fonts_nokiafc22_ttf);
		openfl.text.Font.registerFont (__ASSET__OPENFL__assets_fonts_arial_ttf);
		
		#end
		
		#if flash
		
		className.set ("assets/images/ado.png", __ASSET__assets_images_ado_png);
		type.set ("assets/images/ado.png", AssetType.IMAGE);
		className.set ("assets/images/balun.png", __ASSET__assets_images_balun_png);
		type.set ("assets/images/balun.png", AssetType.IMAGE);
		className.set ("assets/images/bossdoor.png", __ASSET__assets_images_bossdoor_png);
		type.set ("assets/images/bossdoor.png", AssetType.IMAGE);
		className.set ("assets/images/burd.png", __ASSET__assets_images_burd_png);
		type.set ("assets/images/burd.png", AssetType.IMAGE);
		className.set ("assets/images/burdegg.png", __ASSET__assets_images_burdegg_png);
		type.set ("assets/images/burdegg.png", AssetType.IMAGE);
		className.set ("assets/images/burdsmall.png", __ASSET__assets_images_burdsmall_png);
		type.set ("assets/images/burdsmall.png", AssetType.IMAGE);
		className.set ("assets/images/coin.png", __ASSET__assets_images_coin_png);
		type.set ("assets/images/coin.png", AssetType.IMAGE);
		className.set ("assets/images/crawler.png", __ASSET__assets_images_crawler_png);
		type.set ("assets/images/crawler.png", AssetType.IMAGE);
		className.set ("assets/images/drops.png", __ASSET__assets_images_drops_png);
		type.set ("assets/images/drops.png", AssetType.IMAGE);
		className.set ("assets/images/heart.png", __ASSET__assets_images_heart_png);
		type.set ("assets/images/heart.png", AssetType.IMAGE);
		className.set ("assets/images/images-go-here.txt", __ASSET__assets_images_images_go_here_txt);
		type.set ("assets/images/images-go-here.txt", AssetType.TEXT);
		className.set ("assets/images/juice.png", __ASSET__assets_images_juice_png);
		type.set ("assets/images/juice.png", AssetType.IMAGE);
		className.set ("assets/images/ladder.png", __ASSET__assets_images_ladder_png);
		type.set ("assets/images/ladder.png", AssetType.IMAGE);
		className.set ("assets/images/mc.png", __ASSET__assets_images_mc_png);
		type.set ("assets/images/mc.png", AssetType.IMAGE);
		className.set ("assets/images/mcbeck.png", __ASSET__assets_images_mcbeck_png);
		type.set ("assets/images/mcbeck.png", AssetType.IMAGE);
		className.set ("assets/images/metool.png", __ASSET__assets_images_metool_png);
		type.set ("assets/images/metool.png", AssetType.IMAGE);
		className.set ("assets/images/mm.png", __ASSET__assets_images_mm_png);
		type.set ("assets/images/mm.png", AssetType.IMAGE);
		className.set ("assets/images/mush.png", __ASSET__assets_images_mush_png);
		type.set ("assets/images/mush.png", AssetType.IMAGE);
		className.set ("assets/images/nes_tiles.png", __ASSET__assets_images_nes_tiles_png);
		type.set ("assets/images/nes_tiles.png", AssetType.IMAGE);
		className.set ("assets/images/notey.png", __ASSET__assets_images_notey_png);
		type.set ("assets/images/notey.png", AssetType.IMAGE);
		className.set ("assets/images/snaake.png", __ASSET__assets_images_snaake_png);
		type.set ("assets/images/snaake.png", AssetType.IMAGE);
		className.set ("assets/images/snobal.png", __ASSET__assets_images_snobal_png);
		type.set ("assets/images/snobal.png", AssetType.IMAGE);
		className.set ("assets/images/spike.png", __ASSET__assets_images_spike_png);
		type.set ("assets/images/spike.png", AssetType.IMAGE);
		className.set ("assets/images/spore.png", __ASSET__assets_images_spore_png);
		type.set ("assets/images/spore.png", AssetType.IMAGE);
		className.set ("assets/images/tiles.png", __ASSET__assets_images_tiles_png);
		type.set ("assets/images/tiles.png", AssetType.IMAGE);
		className.set ("assets/images/wood_tiles.png", __ASSET__assets_images_wood_tiles_png);
		type.set ("assets/images/wood_tiles.png", AssetType.IMAGE);
		className.set ("assets/images/wood_tiles2.png", __ASSET__assets_images_wood_tiles2_png);
		type.set ("assets/images/wood_tiles2.png", AssetType.IMAGE);
		className.set ("assets/images/wood_tiles3.png", __ASSET__assets_images_wood_tiles3_png);
		type.set ("assets/images/wood_tiles3.png", AssetType.IMAGE);
		className.set ("assets/levels/data-goes-here.txt", __ASSET__assets_levels_data_goes_here_txt);
		type.set ("assets/levels/data-goes-here.txt", AssetType.TEXT);
		className.set ("assets/levels/HaxeFlixelTestLevel1.oel", __ASSET__assets_levels_haxeflixeltestlevel1_oel);
		type.set ("assets/levels/HaxeFlixelTestLevel1.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_1_1.oel", __ASSET__assets_levels_level_1_1_1_oel);
		type.set ("assets/levels/level_1_1_1.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_1_1og2.oel", __ASSET__assets_levels_level_1_1_1og2_oel);
		type.set ("assets/levels/level_1_1_1og2.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_1_2.oel", __ASSET__assets_levels_level_1_1_2_oel);
		type.set ("assets/levels/level_1_1_2.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_1_3.oel", __ASSET__assets_levels_level_1_1_3_oel);
		type.set ("assets/levels/level_1_1_3.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_1_4.oel", __ASSET__assets_levels_level_1_1_4_oel);
		type.set ("assets/levels/level_1_1_4.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_2_1.oel", __ASSET__assets_levels_level_1_2_1_oel);
		type.set ("assets/levels/level_1_2_1.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_2_2.oel", __ASSET__assets_levels_level_1_2_2_oel);
		type.set ("assets/levels/level_1_2_2.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_2_3.oel", __ASSET__assets_levels_level_1_2_3_oel);
		type.set ("assets/levels/level_1_2_3.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_2_4.oel", __ASSET__assets_levels_level_1_2_4_oel);
		type.set ("assets/levels/level_1_2_4.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_3_1.oel", __ASSET__assets_levels_level_1_3_1_oel);
		type.set ("assets/levels/level_1_3_1.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_3_2.oel", __ASSET__assets_levels_level_1_3_2_oel);
		type.set ("assets/levels/level_1_3_2.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_3_3.oel", __ASSET__assets_levels_level_1_3_3_oel);
		type.set ("assets/levels/level_1_3_3.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_3_3og.oel", __ASSET__assets_levels_level_1_3_3og_oel);
		type.set ("assets/levels/level_1_3_3og.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_3_4.oel", __ASSET__assets_levels_level_1_3_4_oel);
		type.set ("assets/levels/level_1_3_4.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_4_1.oel", __ASSET__assets_levels_level_1_4_1_oel);
		type.set ("assets/levels/level_1_4_1.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_4_2.oel", __ASSET__assets_levels_level_1_4_2_oel);
		type.set ("assets/levels/level_1_4_2.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_4_3.oel", __ASSET__assets_levels_level_1_4_3_oel);
		type.set ("assets/levels/level_1_4_3.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_4_4.oel", __ASSET__assets_levels_level_1_4_4_oel);
		type.set ("assets/levels/level_1_4_4.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_end_1.oel", __ASSET__assets_levels_level_1_end_1_oel);
		type.set ("assets/levels/level_1_end_1.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_end_2.oel", __ASSET__assets_levels_level_1_end_2_oel);
		type.set ("assets/levels/level_1_end_2.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_end_3.oel", __ASSET__assets_levels_level_1_end_3_oel);
		type.set ("assets/levels/level_1_end_3.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_end_4.oel", __ASSET__assets_levels_level_1_end_4_oel);
		type.set ("assets/levels/level_1_end_4.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_item_end_1.oel", __ASSET__assets_levels_level_1_item_end_1_oel);
		type.set ("assets/levels/level_1_item_end_1.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_item_end_2.oel", __ASSET__assets_levels_level_1_item_end_2_oel);
		type.set ("assets/levels/level_1_item_end_2.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_item_end_3.oel", __ASSET__assets_levels_level_1_item_end_3_oel);
		type.set ("assets/levels/level_1_item_end_3.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_item_end_4.oel", __ASSET__assets_levels_level_1_item_end_4_oel);
		type.set ("assets/levels/level_1_item_end_4.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_item_mid.oel", __ASSET__assets_levels_level_1_item_mid_oel);
		type.set ("assets/levels/level_1_item_mid.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_item_start_1.oel", __ASSET__assets_levels_level_1_item_start_1_oel);
		type.set ("assets/levels/level_1_item_start_1.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_item_start_2.oel", __ASSET__assets_levels_level_1_item_start_2_oel);
		type.set ("assets/levels/level_1_item_start_2.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_item_start_3.oel", __ASSET__assets_levels_level_1_item_start_3_oel);
		type.set ("assets/levels/level_1_item_start_3.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_item_start_4.oel", __ASSET__assets_levels_level_1_item_start_4_oel);
		type.set ("assets/levels/level_1_item_start_4.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_shop_end_1.oel", __ASSET__assets_levels_level_1_shop_end_1_oel);
		type.set ("assets/levels/level_1_shop_end_1.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_shop_end_2.oel", __ASSET__assets_levels_level_1_shop_end_2_oel);
		type.set ("assets/levels/level_1_shop_end_2.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_shop_end_3.oel", __ASSET__assets_levels_level_1_shop_end_3_oel);
		type.set ("assets/levels/level_1_shop_end_3.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_shop_end_4.oel", __ASSET__assets_levels_level_1_shop_end_4_oel);
		type.set ("assets/levels/level_1_shop_end_4.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_start_1.oel", __ASSET__assets_levels_level_1_start_1_oel);
		type.set ("assets/levels/level_1_start_1.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_start_1woodman.oel", __ASSET__assets_levels_level_1_start_1woodman_oel);
		type.set ("assets/levels/level_1_start_1woodman.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_start_2.oel", __ASSET__assets_levels_level_1_start_2_oel);
		type.set ("assets/levels/level_1_start_2.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_start_3.oel", __ASSET__assets_levels_level_1_start_3_oel);
		type.set ("assets/levels/level_1_start_3.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_start_3airman.oel", __ASSET__assets_levels_level_1_start_3airman_oel);
		type.set ("assets/levels/level_1_start_3airman.oel", AssetType.TEXT);
		className.set ("assets/levels/level_1_start_4.oel", __ASSET__assets_levels_level_1_start_4_oel);
		type.set ("assets/levels/level_1_start_4.oel", AssetType.TEXT);
		className.set ("assets/music/music-goes-here.txt", __ASSET__assets_music_music_goes_here_txt);
		type.set ("assets/music/music-goes-here.txt", AssetType.TEXT);
		className.set ("assets/sounds/sounds-go-here.txt", __ASSET__assets_sounds_sounds_go_here_txt);
		type.set ("assets/sounds/sounds-go-here.txt", AssetType.TEXT);
		className.set ("assets/sounds/beep.mp3", __ASSET__assets_sounds_beep_mp3);
		type.set ("assets/sounds/beep.mp3", AssetType.MUSIC);
		className.set ("assets/sounds/flixel.mp3", __ASSET__assets_sounds_flixel_mp3);
		type.set ("assets/sounds/flixel.mp3", AssetType.MUSIC);
		className.set ("assets/fonts/nokiafc22.ttf", __ASSET__assets_fonts_nokiafc22_ttf);
		type.set ("assets/fonts/nokiafc22.ttf", AssetType.FONT);
		className.set ("assets/fonts/arial.ttf", __ASSET__assets_fonts_arial_ttf);
		type.set ("assets/fonts/arial.ttf", AssetType.FONT);
		
		
		#elseif html5
		
		var id;
		id = "assets/images/ado.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/balun.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/bossdoor.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/burd.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/burdegg.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/burdsmall.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/coin.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/crawler.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/drops.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/heart.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/images-go-here.txt";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/images/juice.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/ladder.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/mc.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/mcbeck.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/metool.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/mm.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/mush.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/nes_tiles.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/notey.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/snaake.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/snobal.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/spike.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/spore.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/tiles.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/wood_tiles.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/wood_tiles2.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/images/wood_tiles3.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/levels/data-goes-here.txt";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/HaxeFlixelTestLevel1.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_1_1.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_1_1og2.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_1_2.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_1_3.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_1_4.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_2_1.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_2_2.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_2_3.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_2_4.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_3_1.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_3_2.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_3_3.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_3_3og.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_3_4.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_4_1.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_4_2.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_4_3.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_4_4.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_end_1.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_end_2.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_end_3.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_end_4.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_item_end_1.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_item_end_2.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_item_end_3.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_item_end_4.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_item_mid.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_item_start_1.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_item_start_2.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_item_start_3.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_item_start_4.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_shop_end_1.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_shop_end_2.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_shop_end_3.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_shop_end_4.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_start_1.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_start_1woodman.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_start_2.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_start_3.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_start_3airman.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/levels/level_1_start_4.oel";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/music/music-goes-here.txt";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/sounds/sounds-go-here.txt";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "assets/sounds/beep.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/sounds/flixel.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/fonts/nokiafc22.ttf";
		className.set (id, __ASSET__assets_fonts_nokiafc22_ttf);
		
		type.set (id, AssetType.FONT);
		id = "assets/fonts/arial.ttf";
		className.set (id, __ASSET__assets_fonts_arial_ttf);
		
		type.set (id, AssetType.FONT);
		
		
		var assetsPrefix = ApplicationMain.config.assetsPrefix;
		if (assetsPrefix != null) {
			for (k in path.keys()) {
				path.set(k, assetsPrefix + path[k]);
			}
		}
		
		#else
		
		#if (windows || mac || linux)
		
		var useManifest = false;
		
		className.set ("assets/images/ado.png", __ASSET__assets_images_ado_png);
		type.set ("assets/images/ado.png", AssetType.IMAGE);
		
		className.set ("assets/images/balun.png", __ASSET__assets_images_balun_png);
		type.set ("assets/images/balun.png", AssetType.IMAGE);
		
		className.set ("assets/images/bossdoor.png", __ASSET__assets_images_bossdoor_png);
		type.set ("assets/images/bossdoor.png", AssetType.IMAGE);
		
		className.set ("assets/images/burd.png", __ASSET__assets_images_burd_png);
		type.set ("assets/images/burd.png", AssetType.IMAGE);
		
		className.set ("assets/images/burdegg.png", __ASSET__assets_images_burdegg_png);
		type.set ("assets/images/burdegg.png", AssetType.IMAGE);
		
		className.set ("assets/images/burdsmall.png", __ASSET__assets_images_burdsmall_png);
		type.set ("assets/images/burdsmall.png", AssetType.IMAGE);
		
		className.set ("assets/images/coin.png", __ASSET__assets_images_coin_png);
		type.set ("assets/images/coin.png", AssetType.IMAGE);
		
		className.set ("assets/images/crawler.png", __ASSET__assets_images_crawler_png);
		type.set ("assets/images/crawler.png", AssetType.IMAGE);
		
		className.set ("assets/images/drops.png", __ASSET__assets_images_drops_png);
		type.set ("assets/images/drops.png", AssetType.IMAGE);
		
		className.set ("assets/images/heart.png", __ASSET__assets_images_heart_png);
		type.set ("assets/images/heart.png", AssetType.IMAGE);
		
		className.set ("assets/images/images-go-here.txt", __ASSET__assets_images_images_go_here_txt);
		type.set ("assets/images/images-go-here.txt", AssetType.TEXT);
		
		className.set ("assets/images/juice.png", __ASSET__assets_images_juice_png);
		type.set ("assets/images/juice.png", AssetType.IMAGE);
		
		className.set ("assets/images/ladder.png", __ASSET__assets_images_ladder_png);
		type.set ("assets/images/ladder.png", AssetType.IMAGE);
		
		className.set ("assets/images/mc.png", __ASSET__assets_images_mc_png);
		type.set ("assets/images/mc.png", AssetType.IMAGE);
		
		className.set ("assets/images/mcbeck.png", __ASSET__assets_images_mcbeck_png);
		type.set ("assets/images/mcbeck.png", AssetType.IMAGE);
		
		className.set ("assets/images/metool.png", __ASSET__assets_images_metool_png);
		type.set ("assets/images/metool.png", AssetType.IMAGE);
		
		className.set ("assets/images/mm.png", __ASSET__assets_images_mm_png);
		type.set ("assets/images/mm.png", AssetType.IMAGE);
		
		className.set ("assets/images/mush.png", __ASSET__assets_images_mush_png);
		type.set ("assets/images/mush.png", AssetType.IMAGE);
		
		className.set ("assets/images/nes_tiles.png", __ASSET__assets_images_nes_tiles_png);
		type.set ("assets/images/nes_tiles.png", AssetType.IMAGE);
		
		className.set ("assets/images/notey.png", __ASSET__assets_images_notey_png);
		type.set ("assets/images/notey.png", AssetType.IMAGE);
		
		className.set ("assets/images/snaake.png", __ASSET__assets_images_snaake_png);
		type.set ("assets/images/snaake.png", AssetType.IMAGE);
		
		className.set ("assets/images/snobal.png", __ASSET__assets_images_snobal_png);
		type.set ("assets/images/snobal.png", AssetType.IMAGE);
		
		className.set ("assets/images/spike.png", __ASSET__assets_images_spike_png);
		type.set ("assets/images/spike.png", AssetType.IMAGE);
		
		className.set ("assets/images/spore.png", __ASSET__assets_images_spore_png);
		type.set ("assets/images/spore.png", AssetType.IMAGE);
		
		className.set ("assets/images/tiles.png", __ASSET__assets_images_tiles_png);
		type.set ("assets/images/tiles.png", AssetType.IMAGE);
		
		className.set ("assets/images/wood_tiles.png", __ASSET__assets_images_wood_tiles_png);
		type.set ("assets/images/wood_tiles.png", AssetType.IMAGE);
		
		className.set ("assets/images/wood_tiles2.png", __ASSET__assets_images_wood_tiles2_png);
		type.set ("assets/images/wood_tiles2.png", AssetType.IMAGE);
		
		className.set ("assets/images/wood_tiles3.png", __ASSET__assets_images_wood_tiles3_png);
		type.set ("assets/images/wood_tiles3.png", AssetType.IMAGE);
		
		className.set ("assets/levels/data-goes-here.txt", __ASSET__assets_levels_data_goes_here_txt);
		type.set ("assets/levels/data-goes-here.txt", AssetType.TEXT);
		
		className.set ("assets/levels/HaxeFlixelTestLevel1.oel", __ASSET__assets_levels_haxeflixeltestlevel1_oel);
		type.set ("assets/levels/HaxeFlixelTestLevel1.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_1_1.oel", __ASSET__assets_levels_level_1_1_1_oel);
		type.set ("assets/levels/level_1_1_1.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_1_1og2.oel", __ASSET__assets_levels_level_1_1_1og2_oel);
		type.set ("assets/levels/level_1_1_1og2.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_1_2.oel", __ASSET__assets_levels_level_1_1_2_oel);
		type.set ("assets/levels/level_1_1_2.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_1_3.oel", __ASSET__assets_levels_level_1_1_3_oel);
		type.set ("assets/levels/level_1_1_3.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_1_4.oel", __ASSET__assets_levels_level_1_1_4_oel);
		type.set ("assets/levels/level_1_1_4.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_2_1.oel", __ASSET__assets_levels_level_1_2_1_oel);
		type.set ("assets/levels/level_1_2_1.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_2_2.oel", __ASSET__assets_levels_level_1_2_2_oel);
		type.set ("assets/levels/level_1_2_2.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_2_3.oel", __ASSET__assets_levels_level_1_2_3_oel);
		type.set ("assets/levels/level_1_2_3.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_2_4.oel", __ASSET__assets_levels_level_1_2_4_oel);
		type.set ("assets/levels/level_1_2_4.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_3_1.oel", __ASSET__assets_levels_level_1_3_1_oel);
		type.set ("assets/levels/level_1_3_1.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_3_2.oel", __ASSET__assets_levels_level_1_3_2_oel);
		type.set ("assets/levels/level_1_3_2.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_3_3.oel", __ASSET__assets_levels_level_1_3_3_oel);
		type.set ("assets/levels/level_1_3_3.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_3_3og.oel", __ASSET__assets_levels_level_1_3_3og_oel);
		type.set ("assets/levels/level_1_3_3og.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_3_4.oel", __ASSET__assets_levels_level_1_3_4_oel);
		type.set ("assets/levels/level_1_3_4.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_4_1.oel", __ASSET__assets_levels_level_1_4_1_oel);
		type.set ("assets/levels/level_1_4_1.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_4_2.oel", __ASSET__assets_levels_level_1_4_2_oel);
		type.set ("assets/levels/level_1_4_2.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_4_3.oel", __ASSET__assets_levels_level_1_4_3_oel);
		type.set ("assets/levels/level_1_4_3.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_4_4.oel", __ASSET__assets_levels_level_1_4_4_oel);
		type.set ("assets/levels/level_1_4_4.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_end_1.oel", __ASSET__assets_levels_level_1_end_1_oel);
		type.set ("assets/levels/level_1_end_1.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_end_2.oel", __ASSET__assets_levels_level_1_end_2_oel);
		type.set ("assets/levels/level_1_end_2.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_end_3.oel", __ASSET__assets_levels_level_1_end_3_oel);
		type.set ("assets/levels/level_1_end_3.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_end_4.oel", __ASSET__assets_levels_level_1_end_4_oel);
		type.set ("assets/levels/level_1_end_4.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_item_end_1.oel", __ASSET__assets_levels_level_1_item_end_1_oel);
		type.set ("assets/levels/level_1_item_end_1.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_item_end_2.oel", __ASSET__assets_levels_level_1_item_end_2_oel);
		type.set ("assets/levels/level_1_item_end_2.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_item_end_3.oel", __ASSET__assets_levels_level_1_item_end_3_oel);
		type.set ("assets/levels/level_1_item_end_3.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_item_end_4.oel", __ASSET__assets_levels_level_1_item_end_4_oel);
		type.set ("assets/levels/level_1_item_end_4.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_item_mid.oel", __ASSET__assets_levels_level_1_item_mid_oel);
		type.set ("assets/levels/level_1_item_mid.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_item_start_1.oel", __ASSET__assets_levels_level_1_item_start_1_oel);
		type.set ("assets/levels/level_1_item_start_1.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_item_start_2.oel", __ASSET__assets_levels_level_1_item_start_2_oel);
		type.set ("assets/levels/level_1_item_start_2.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_item_start_3.oel", __ASSET__assets_levels_level_1_item_start_3_oel);
		type.set ("assets/levels/level_1_item_start_3.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_item_start_4.oel", __ASSET__assets_levels_level_1_item_start_4_oel);
		type.set ("assets/levels/level_1_item_start_4.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_shop_end_1.oel", __ASSET__assets_levels_level_1_shop_end_1_oel);
		type.set ("assets/levels/level_1_shop_end_1.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_shop_end_2.oel", __ASSET__assets_levels_level_1_shop_end_2_oel);
		type.set ("assets/levels/level_1_shop_end_2.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_shop_end_3.oel", __ASSET__assets_levels_level_1_shop_end_3_oel);
		type.set ("assets/levels/level_1_shop_end_3.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_shop_end_4.oel", __ASSET__assets_levels_level_1_shop_end_4_oel);
		type.set ("assets/levels/level_1_shop_end_4.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_start_1.oel", __ASSET__assets_levels_level_1_start_1_oel);
		type.set ("assets/levels/level_1_start_1.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_start_1woodman.oel", __ASSET__assets_levels_level_1_start_1woodman_oel);
		type.set ("assets/levels/level_1_start_1woodman.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_start_2.oel", __ASSET__assets_levels_level_1_start_2_oel);
		type.set ("assets/levels/level_1_start_2.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_start_3.oel", __ASSET__assets_levels_level_1_start_3_oel);
		type.set ("assets/levels/level_1_start_3.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_start_3airman.oel", __ASSET__assets_levels_level_1_start_3airman_oel);
		type.set ("assets/levels/level_1_start_3airman.oel", AssetType.TEXT);
		
		className.set ("assets/levels/level_1_start_4.oel", __ASSET__assets_levels_level_1_start_4_oel);
		type.set ("assets/levels/level_1_start_4.oel", AssetType.TEXT);
		
		className.set ("assets/music/music-goes-here.txt", __ASSET__assets_music_music_goes_here_txt);
		type.set ("assets/music/music-goes-here.txt", AssetType.TEXT);
		
		className.set ("assets/sounds/sounds-go-here.txt", __ASSET__assets_sounds_sounds_go_here_txt);
		type.set ("assets/sounds/sounds-go-here.txt", AssetType.TEXT);
		
		className.set ("assets/sounds/beep.mp3", __ASSET__assets_sounds_beep_mp3);
		type.set ("assets/sounds/beep.mp3", AssetType.MUSIC);
		
		className.set ("assets/sounds/flixel.mp3", __ASSET__assets_sounds_flixel_mp3);
		type.set ("assets/sounds/flixel.mp3", AssetType.MUSIC);
		
		className.set ("assets/fonts/nokiafc22.ttf", __ASSET__assets_fonts_nokiafc22_ttf);
		type.set ("assets/fonts/nokiafc22.ttf", AssetType.FONT);
		
		className.set ("assets/fonts/arial.ttf", __ASSET__assets_fonts_arial_ttf);
		type.set ("assets/fonts/arial.ttf", AssetType.FONT);
		
		
		if (useManifest) {
			
			loadManifest ();
			
			if (Sys.args ().indexOf ("-livereload") > -1) {
				
				var path = FileSystem.fullPath ("manifest");
				lastModified = FileSystem.stat (path).mtime.getTime ();
				
				timer = new Timer (2000);
				timer.run = function () {
					
					var modified = FileSystem.stat (path).mtime.getTime ();
					
					if (modified > lastModified) {
						
						lastModified = modified;
						loadManifest ();
						
						if (eventCallback != null) {
							
							eventCallback (this, "change");
							
						}
						
					}
					
				}
				
			}
			
		}
		
		#else
		
		loadManifest ();
		
		#end
		#end
		
	}
	
	
	private function createThreadPool ():Void {
		
		threadPool = new ThreadPool (0, 2);
		threadPool.doWork.add (function (id, data) {
			
			data.result = data.getMethod (id);
			threadPool.sendComplete (data.handler, data);
			
		});
		threadPool.onComplete.add (function (id, data) {
			
			data.handler (data.result);
			
		});
		
	}
	
	
	public override function exists (id:String, type:String):Bool {
		
		var requestedType = type != null ? cast (type, AssetType) : null;
		var assetType = this.type.get (id);
		
		if (assetType != null) {
			
			if (assetType == requestedType || ((requestedType == SOUND || requestedType == MUSIC) && (assetType == MUSIC || assetType == SOUND))) {
				
				return true;
				
			}
			
			#if flash
			
			if (requestedType == BINARY && (assetType == BINARY || assetType == TEXT || assetType == IMAGE)) {
				
				return true;
				
			} else if (requestedType == null || path.exists (id)) {
				
				return true;
				
			}
			
			#else
			
			if (requestedType == BINARY || requestedType == null || (assetType == BINARY && requestedType == TEXT)) {
				
				return true;
				
			}
			
			#end
			
		}
		
		return false;
		
	}
	
	
	public override function getAudioBuffer (id:String):AudioBuffer {
		
		#if flash
		
		var buffer = new AudioBuffer ();
		buffer.src = cast (Type.createInstance (className.get (id), []), Sound);
		return buffer;
		
		#elseif html5
		
		return null;
		//return new Sound (new URLRequest (path.get (id)));
		
		#else
		
		if (className.exists(id)) return AudioBuffer.fromBytes (cast (Type.createInstance (className.get (id), []), ByteArray));
		else return AudioBuffer.fromFile (path.get (id));
		
		#end
		
	}
	
	
	public override function getBytes (id:String):ByteArray {
		
		#if flash
		
		switch (type.get (id)) {
			
			case TEXT, BINARY:
				
				return cast (Type.createInstance (className.get (id), []), ByteArray);
			
			case IMAGE:
				
				var bitmapData = cast (Type.createInstance (className.get (id), []), BitmapData);
				return bitmapData.getPixels (bitmapData.rect);
			
			default:
				
				return null;
			
		}
		
		return cast (Type.createInstance (className.get (id), []), ByteArray);
		
		#elseif html5
		
		var bytes:ByteArray = null;
		var loader = Preloader.loaders.get (path.get (id));
		
		if (loader == null) {
			
			return null;
			
		}
		
		var data = loader.data;
		
		if (Std.is (data, String)) {
			
			bytes = new ByteArray ();
			bytes.writeUTFBytes (data);
			
		} else if (Std.is (data, ByteArray)) {
			
			bytes = cast data;
			
		} else {
			
			bytes = null;
			
		}
		
		if (bytes != null) {
			
			bytes.position = 0;
			return bytes;
			
		} else {
			
			return null;
		}
		
		#else
		
		if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), ByteArray);
		else return ByteArray.readFile (path.get (id));
		
		#end
		
	}
	
	
	public override function getFont (id:String):Font {
		
		#if flash
		
		var src = Type.createInstance (className.get (id), []);
		
		var font = new Font (src.fontName);
		font.src = src;
		return font;
		
		#elseif html5
		
		return cast (Type.createInstance (className.get (id), []), Font);
		
		#else
		
		if (className.exists (id)) {
			
			var fontClass = className.get (id);
			return cast (Type.createInstance (fontClass, []), Font);
			
		} else {
			
			return Font.fromFile (path.get (id));
			
		}
		
		#end
		
	}
	
	
	public override function getImage (id:String):Image {
		
		#if flash
		
		return Image.fromBitmapData (cast (Type.createInstance (className.get (id), []), BitmapData));
		
		#elseif html5
		
		return Image.fromImageElement (Preloader.images.get (path.get (id)));
		
		#else
		
		if (className.exists (id)) {
			
			var fontClass = className.get (id);
			return cast (Type.createInstance (fontClass, []), Image);
			
		} else {
			
			return Image.fromFile (path.get (id));
			
		}
		
		#end
		
	}
	
	
	/*public override function getMusic (id:String):Dynamic {
		
		#if flash
		
		return cast (Type.createInstance (className.get (id), []), Sound);
		
		#elseif openfl_html5
		
		//var sound = new Sound ();
		//sound.__buffer = true;
		//sound.load (new URLRequest (path.get (id)));
		//return sound;
		return null;
		
		#elseif html5
		
		return null;
		//return new Sound (new URLRequest (path.get (id)));
		
		#else
		
		return null;
		//if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), Sound);
		//else return new Sound (new URLRequest (path.get (id)), null, true);
		
		#end
		
	}*/
	
	
	public override function getPath (id:String):String {
		
		//#if ios
		
		//return SystemPath.applicationDirectory + "/assets/" + path.get (id);
		
		//#else
		
		return path.get (id);
		
		//#end
		
	}
	
	
	public override function getText (id:String):String {
		
		#if html5
		
		var bytes:ByteArray = null;
		var loader = Preloader.loaders.get (path.get (id));
		
		if (loader == null) {
			
			return null;
			
		}
		
		var data = loader.data;
		
		if (Std.is (data, String)) {
			
			return cast data;
			
		} else if (Std.is (data, ByteArray)) {
			
			bytes = cast data;
			
		} else {
			
			bytes = null;
			
		}
		
		if (bytes != null) {
			
			bytes.position = 0;
			return bytes.readUTFBytes (bytes.length);
			
		} else {
			
			return null;
		}
		
		#else
		
		var bytes = getBytes (id);
		
		if (bytes == null) {
			
			return null;
			
		} else {
			
			return bytes.readUTFBytes (bytes.length);
			
		}
		
		#end
		
	}
	
	
	public override function isLocal (id:String, type:String):Bool {
		
		var requestedType = type != null ? cast (type, AssetType) : null;
		
		#if flash
		
		//if (requestedType != AssetType.MUSIC && requestedType != AssetType.SOUND) {
			
			return className.exists (id);
			
		//}
		
		#end
		
		return true;
		
	}
	
	
	public override function list (type:String):Array<String> {
		
		var requestedType = type != null ? cast (type, AssetType) : null;
		var items = [];
		
		for (id in this.type.keys ()) {
			
			if (requestedType == null || exists (id, type)) {
				
				items.push (id);
				
			}
			
		}
		
		return items;
		
	}
	
	
	public override function loadAudioBuffer (id:String, handler:AudioBuffer -> Void):Void {
		
		#if (flash)
		
		if (path.exists (id)) {
			
			var soundLoader = new Sound ();
			soundLoader.addEventListener (Event.COMPLETE, function (event) {
				
				var audioBuffer:AudioBuffer = new AudioBuffer();
				audioBuffer.src = event.currentTarget;
				handler (audioBuffer);
				
			});
			
			soundLoader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getAudioBuffer (id));
			
		}
		
		#else
		
		handler (getAudioBuffer (id));
		
		#end
		
	}
	
	
	public override function loadBytes (id:String, handler:ByteArray -> Void):Void {
		
		#if flash
		
		if (path.exists (id)) {
			
			var loader = new URLLoader ();
			loader.addEventListener (Event.COMPLETE, function (event:Event) {
				
				var bytes = new ByteArray ();
				bytes.writeUTFBytes (event.currentTarget.data);
				bytes.position = 0;
				
				handler (bytes);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getBytes (id));
			
		}
		
		#elseif html5
		
		if (path.exists (id)) {
			
			var loader = new URLLoader ();
			loader.dataFormat = BINARY;
			loader.onComplete.add (function (_):Void {
				
				handler (loader.data);
				
			});
			
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getBytes (id));
			
		}
		
		#else
		
		if (threadPool == null) {
			
			createThreadPool ();
			
		}
		
		threadPool.queue (id, { handler: handler, getMethod: getBytes });
		
		#end
		
	}
	
	
	public override function loadImage (id:String, handler:Image -> Void):Void {
		
		#if flash
		
		if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event:Event) {
				
				var bitmapData = cast (event.currentTarget.content, Bitmap).bitmapData;
				handler (Image.fromBitmapData (bitmapData));
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getImage (id));
			
		}
		
		#elseif html5
		
		if (path.exists (id)) {
			
			var image = new js.html.Image ();
			image.onload = function (_):Void {
				
				handler (Image.fromImageElement (image));
				
			}
			image.src = path.get (id);
			
		} else {
			
			handler (getImage (id));
			
		}
		
		#else
		
		if (threadPool == null) {
			
			createThreadPool ();
			
		}
		
		threadPool.queue (id, { handler: handler, getMethod: getImage });
		
		#end
		
	}
	
	
	#if (!flash && !html5)
	private function loadManifest ():Void {
		
		try {
			
			#if blackberry
			var bytes = ByteArray.readFile ("app/native/manifest");
			#elseif tizen
			var bytes = ByteArray.readFile ("../res/manifest");
			#elseif emscripten
			var bytes = ByteArray.readFile ("assets/manifest");
			#elseif (mac && java)
			var bytes = ByteArray.readFile ("../Resources/manifest");
			#elseif ios
			var bytes = ByteArray.readFile ("assets/manifest");
			#else
			var bytes = ByteArray.readFile ("manifest");
			#end
			
			if (bytes != null) {
				
				bytes.position = 0;
				
				if (bytes.length > 0) {
					
					var data = bytes.readUTFBytes (bytes.length);
					
					if (data != null && data.length > 0) {
						
						var manifest:Array<Dynamic> = Unserializer.run (data);
						
						for (asset in manifest) {
							
							if (!className.exists (asset.id)) {
								
								#if ios
								path.set (asset.id, "assets/" + asset.path);
								#else
								path.set (asset.id, asset.path);
								#end
								type.set (asset.id, cast (asset.type, AssetType));
								
							}
							
						}
						
					}
					
				}
				
			} else {
				
				trace ("Warning: Could not load asset manifest (bytes was null)");
				
			}
		
		} catch (e:Dynamic) {
			
			trace ('Warning: Could not load asset manifest (${e})');
			
		}
		
	}
	#end
	
	
	/*public override function loadMusic (id:String, handler:Dynamic -> Void):Void {
		
		#if (flash || html5)
		
		//if (path.exists (id)) {
			
		//	var loader = new Loader ();
		//	loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event) {
				
		//		handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
		//	});
		//	loader.load (new URLRequest (path.get (id)));
			
		//} else {
			
			handler (getMusic (id));
			
		//}
		
		#else
		
		handler (getMusic (id));
		
		#end
		
	}*/
	
	
	public override function loadText (id:String, handler:String -> Void):Void {
		
		#if html5
		
		if (path.exists (id)) {
			
			var loader = new URLLoader ();
			loader.onComplete.add (function (_):Void {
				
				handler (loader.data);
				
			});
			
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getText (id));
			
		}
		
		#else
		
		var callback = function (bytes:ByteArray):Void {
			
			if (bytes == null) {
				
				handler (null);
				
			} else {
				
				handler (bytes.readUTFBytes (bytes.length));
				
			}
			
		}
		
		loadBytes (id, callback);
		
		#end
		
	}
	
	
}


#if !display
#if flash

@:keep @:bind #if display private #end class __ASSET__assets_images_ado_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_balun_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_bossdoor_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_burd_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_burdegg_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_burdsmall_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_coin_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_crawler_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_drops_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_heart_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_images_go_here_txt extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_images_juice_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_ladder_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_mc_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_mcbeck_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_metool_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_mm_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_mush_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_nes_tiles_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_notey_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_snaake_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_snobal_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_spike_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_spore_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_tiles_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_wood_tiles_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_wood_tiles2_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_images_wood_tiles3_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_levels_data_goes_here_txt extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_haxeflixeltestlevel1_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_1_1_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_1_1og2_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_1_2_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_1_3_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_1_4_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_2_1_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_2_2_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_2_3_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_2_4_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_3_1_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_3_2_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_3_3_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_3_3og_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_3_4_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_4_1_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_4_2_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_4_3_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_4_4_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_end_1_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_end_2_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_end_3_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_end_4_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_item_end_1_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_item_end_2_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_item_end_3_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_item_end_4_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_item_mid_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_item_start_1_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_item_start_2_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_item_start_3_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_item_start_4_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_shop_end_1_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_shop_end_2_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_shop_end_3_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_shop_end_4_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_start_1_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_start_1woodman_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_start_2_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_start_3_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_start_3airman_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_levels_level_1_start_4_oel extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_music_music_goes_here_txt extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_sounds_sounds_go_here_txt extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_sounds_beep_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_sounds_flixel_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_fonts_nokiafc22_ttf extends flash.text.Font { }
@:keep @:bind #if display private #end class __ASSET__assets_fonts_arial_ttf extends flash.text.Font { }


#elseif html5












































































@:keep #if display private #end class __ASSET__assets_fonts_nokiafc22_ttf extends lime.text.Font { public function new () { super (); name = "Nokia Cellphone FC Small"; } } 
@:keep #if display private #end class __ASSET__assets_fonts_arial_ttf extends lime.text.Font { public function new () { super (); name = "Arial"; } } 


#else



#if (windows || mac || linux || cpp)


@:image("assets/images/ado.png") #if display private #end class __ASSET__assets_images_ado_png extends lime.graphics.Image {}
@:image("assets/images/balun.png") #if display private #end class __ASSET__assets_images_balun_png extends lime.graphics.Image {}
@:image("assets/images/bossdoor.png") #if display private #end class __ASSET__assets_images_bossdoor_png extends lime.graphics.Image {}
@:image("assets/images/burd.png") #if display private #end class __ASSET__assets_images_burd_png extends lime.graphics.Image {}
@:image("assets/images/burdegg.png") #if display private #end class __ASSET__assets_images_burdegg_png extends lime.graphics.Image {}
@:image("assets/images/burdsmall.png") #if display private #end class __ASSET__assets_images_burdsmall_png extends lime.graphics.Image {}
@:image("assets/images/coin.png") #if display private #end class __ASSET__assets_images_coin_png extends lime.graphics.Image {}
@:image("assets/images/crawler.png") #if display private #end class __ASSET__assets_images_crawler_png extends lime.graphics.Image {}
@:image("assets/images/drops.png") #if display private #end class __ASSET__assets_images_drops_png extends lime.graphics.Image {}
@:image("assets/images/heart.png") #if display private #end class __ASSET__assets_images_heart_png extends lime.graphics.Image {}
@:file("assets/images/images-go-here.txt") #if display private #end class __ASSET__assets_images_images_go_here_txt extends lime.utils.ByteArray {}
@:image("assets/images/juice.png") #if display private #end class __ASSET__assets_images_juice_png extends lime.graphics.Image {}
@:image("assets/images/ladder.png") #if display private #end class __ASSET__assets_images_ladder_png extends lime.graphics.Image {}
@:image("assets/images/mc.png") #if display private #end class __ASSET__assets_images_mc_png extends lime.graphics.Image {}
@:image("assets/images/mcbeck.png") #if display private #end class __ASSET__assets_images_mcbeck_png extends lime.graphics.Image {}
@:image("assets/images/metool.png") #if display private #end class __ASSET__assets_images_metool_png extends lime.graphics.Image {}
@:image("assets/images/mm.png") #if display private #end class __ASSET__assets_images_mm_png extends lime.graphics.Image {}
@:image("assets/images/mush.png") #if display private #end class __ASSET__assets_images_mush_png extends lime.graphics.Image {}
@:image("assets/images/nes_tiles.png") #if display private #end class __ASSET__assets_images_nes_tiles_png extends lime.graphics.Image {}
@:image("assets/images/notey.png") #if display private #end class __ASSET__assets_images_notey_png extends lime.graphics.Image {}
@:image("assets/images/snaake.png") #if display private #end class __ASSET__assets_images_snaake_png extends lime.graphics.Image {}
@:image("assets/images/snobal.png") #if display private #end class __ASSET__assets_images_snobal_png extends lime.graphics.Image {}
@:image("assets/images/spike.png") #if display private #end class __ASSET__assets_images_spike_png extends lime.graphics.Image {}
@:image("assets/images/spore.png") #if display private #end class __ASSET__assets_images_spore_png extends lime.graphics.Image {}
@:image("assets/images/tiles.png") #if display private #end class __ASSET__assets_images_tiles_png extends lime.graphics.Image {}
@:image("assets/images/wood_tiles.png") #if display private #end class __ASSET__assets_images_wood_tiles_png extends lime.graphics.Image {}
@:image("assets/images/wood_tiles2.png") #if display private #end class __ASSET__assets_images_wood_tiles2_png extends lime.graphics.Image {}
@:image("assets/images/wood_tiles3.png") #if display private #end class __ASSET__assets_images_wood_tiles3_png extends lime.graphics.Image {}
@:file("assets/levels/data-goes-here.txt") #if display private #end class __ASSET__assets_levels_data_goes_here_txt extends lime.utils.ByteArray {}
@:file("assets/levels/HaxeFlixelTestLevel1.oel") #if display private #end class __ASSET__assets_levels_haxeflixeltestlevel1_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_1_1.oel") #if display private #end class __ASSET__assets_levels_level_1_1_1_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_1_1og2.oel") #if display private #end class __ASSET__assets_levels_level_1_1_1og2_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_1_2.oel") #if display private #end class __ASSET__assets_levels_level_1_1_2_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_1_3.oel") #if display private #end class __ASSET__assets_levels_level_1_1_3_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_1_4.oel") #if display private #end class __ASSET__assets_levels_level_1_1_4_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_2_1.oel") #if display private #end class __ASSET__assets_levels_level_1_2_1_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_2_2.oel") #if display private #end class __ASSET__assets_levels_level_1_2_2_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_2_3.oel") #if display private #end class __ASSET__assets_levels_level_1_2_3_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_2_4.oel") #if display private #end class __ASSET__assets_levels_level_1_2_4_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_3_1.oel") #if display private #end class __ASSET__assets_levels_level_1_3_1_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_3_2.oel") #if display private #end class __ASSET__assets_levels_level_1_3_2_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_3_3.oel") #if display private #end class __ASSET__assets_levels_level_1_3_3_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_3_3og.oel") #if display private #end class __ASSET__assets_levels_level_1_3_3og_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_3_4.oel") #if display private #end class __ASSET__assets_levels_level_1_3_4_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_4_1.oel") #if display private #end class __ASSET__assets_levels_level_1_4_1_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_4_2.oel") #if display private #end class __ASSET__assets_levels_level_1_4_2_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_4_3.oel") #if display private #end class __ASSET__assets_levels_level_1_4_3_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_4_4.oel") #if display private #end class __ASSET__assets_levels_level_1_4_4_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_end_1.oel") #if display private #end class __ASSET__assets_levels_level_1_end_1_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_end_2.oel") #if display private #end class __ASSET__assets_levels_level_1_end_2_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_end_3.oel") #if display private #end class __ASSET__assets_levels_level_1_end_3_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_end_4.oel") #if display private #end class __ASSET__assets_levels_level_1_end_4_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_item_end_1.oel") #if display private #end class __ASSET__assets_levels_level_1_item_end_1_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_item_end_2.oel") #if display private #end class __ASSET__assets_levels_level_1_item_end_2_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_item_end_3.oel") #if display private #end class __ASSET__assets_levels_level_1_item_end_3_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_item_end_4.oel") #if display private #end class __ASSET__assets_levels_level_1_item_end_4_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_item_mid.oel") #if display private #end class __ASSET__assets_levels_level_1_item_mid_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_item_start_1.oel") #if display private #end class __ASSET__assets_levels_level_1_item_start_1_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_item_start_2.oel") #if display private #end class __ASSET__assets_levels_level_1_item_start_2_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_item_start_3.oel") #if display private #end class __ASSET__assets_levels_level_1_item_start_3_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_item_start_4.oel") #if display private #end class __ASSET__assets_levels_level_1_item_start_4_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_shop_end_1.oel") #if display private #end class __ASSET__assets_levels_level_1_shop_end_1_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_shop_end_2.oel") #if display private #end class __ASSET__assets_levels_level_1_shop_end_2_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_shop_end_3.oel") #if display private #end class __ASSET__assets_levels_level_1_shop_end_3_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_shop_end_4.oel") #if display private #end class __ASSET__assets_levels_level_1_shop_end_4_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_start_1.oel") #if display private #end class __ASSET__assets_levels_level_1_start_1_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_start_1woodman.oel") #if display private #end class __ASSET__assets_levels_level_1_start_1woodman_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_start_2.oel") #if display private #end class __ASSET__assets_levels_level_1_start_2_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_start_3.oel") #if display private #end class __ASSET__assets_levels_level_1_start_3_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_start_3airman.oel") #if display private #end class __ASSET__assets_levels_level_1_start_3airman_oel extends lime.utils.ByteArray {}
@:file("assets/levels/level_1_start_4.oel") #if display private #end class __ASSET__assets_levels_level_1_start_4_oel extends lime.utils.ByteArray {}
@:file("assets/music/music-goes-here.txt") #if display private #end class __ASSET__assets_music_music_goes_here_txt extends lime.utils.ByteArray {}
@:file("assets/sounds/sounds-go-here.txt") #if display private #end class __ASSET__assets_sounds_sounds_go_here_txt extends lime.utils.ByteArray {}
@:file("C:/HaxeToolkit/haxe/lib/flixel/3,3,11/assets/sounds/beep.mp3") #if display private #end class __ASSET__assets_sounds_beep_mp3 extends lime.utils.ByteArray {}
@:file("C:/HaxeToolkit/haxe/lib/flixel/3,3,11/assets/sounds/flixel.mp3") #if display private #end class __ASSET__assets_sounds_flixel_mp3 extends lime.utils.ByteArray {}
@:font("C:/HaxeToolkit/haxe/lib/flixel/3,3,11/assets/fonts/nokiafc22.ttf") #if display private #end class __ASSET__assets_fonts_nokiafc22_ttf extends lime.text.Font {}
@:font("C:/HaxeToolkit/haxe/lib/flixel/3,3,11/assets/fonts/arial.ttf") #if display private #end class __ASSET__assets_fonts_arial_ttf extends lime.text.Font {}



#end
#end

#if (openfl && !flash)
@:keep #if display private #end class __ASSET__OPENFL__assets_fonts_nokiafc22_ttf extends openfl.text.Font { public function new () { var font = new __ASSET__assets_fonts_nokiafc22_ttf (); src = font.src; name = font.name; super (); }}
@:keep #if display private #end class __ASSET__OPENFL__assets_fonts_arial_ttf extends openfl.text.Font { public function new () { var font = new __ASSET__assets_fonts_arial_ttf (); src = font.src; name = font.name; super (); }}

#end

#end
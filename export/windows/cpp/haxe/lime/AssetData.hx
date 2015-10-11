package lime;


import lime.utils.Assets;


class AssetData {

	private static var initialized:Bool = false;
	
	public static var library = new #if haxe3 Map <String, #else Hash <#end LibraryType> ();
	public static var path = new #if haxe3 Map <String, #else Hash <#end String> ();
	public static var type = new #if haxe3 Map <String, #else Hash <#end AssetType> ();	
	
	public static function initialize():Void {
		
		if (!initialized) {
			
			path.set ("assets/images/ado.png", "assets/images/ado.png");
			type.set ("assets/images/ado.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/balun.png", "assets/images/balun.png");
			type.set ("assets/images/balun.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/burd.png", "assets/images/burd.png");
			type.set ("assets/images/burd.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/burdegg.png", "assets/images/burdegg.png");
			type.set ("assets/images/burdegg.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/burdsmall.png", "assets/images/burdsmall.png");
			type.set ("assets/images/burdsmall.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/coin.png", "assets/images/coin.png");
			type.set ("assets/images/coin.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/crawler.png", "assets/images/crawler.png");
			type.set ("assets/images/crawler.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/drops.png", "assets/images/drops.png");
			type.set ("assets/images/drops.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/heart.png", "assets/images/heart.png");
			type.set ("assets/images/heart.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/images-go-here.txt", "assets/images/images-go-here.txt");
			type.set ("assets/images/images-go-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/images/juice.png", "assets/images/juice.png");
			type.set ("assets/images/juice.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/ladder.png", "assets/images/ladder.png");
			type.set ("assets/images/ladder.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/mc.png", "assets/images/mc.png");
			type.set ("assets/images/mc.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/mcbeck.png", "assets/images/mcbeck.png");
			type.set ("assets/images/mcbeck.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/metool.png", "assets/images/metool.png");
			type.set ("assets/images/metool.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/mm.png", "assets/images/mm.png");
			type.set ("assets/images/mm.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/mush.png", "assets/images/mush.png");
			type.set ("assets/images/mush.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/nes_tiles.png", "assets/images/nes_tiles.png");
			type.set ("assets/images/nes_tiles.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/notey.png", "assets/images/notey.png");
			type.set ("assets/images/notey.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/snaake.png", "assets/images/snaake.png");
			type.set ("assets/images/snaake.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/snobal.png", "assets/images/snobal.png");
			type.set ("assets/images/snobal.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/spike.png", "assets/images/spike.png");
			type.set ("assets/images/spike.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/spore.png", "assets/images/spore.png");
			type.set ("assets/images/spore.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/tiles.png", "assets/images/tiles.png");
			type.set ("assets/images/tiles.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/wood_tiles.png", "assets/images/wood_tiles.png");
			type.set ("assets/images/wood_tiles.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/wood_tiles2.png", "assets/images/wood_tiles2.png");
			type.set ("assets/images/wood_tiles2.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/wood_tiles3.png", "assets/images/wood_tiles3.png");
			type.set ("assets/images/wood_tiles3.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/levels/data-goes-here.txt", "assets/levels/data-goes-here.txt");
			type.set ("assets/levels/data-goes-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/HaxeFlixelTestLevel1.oel", "assets/levels/HaxeFlixelTestLevel1.oel");
			type.set ("assets/levels/HaxeFlixelTestLevel1.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_1_1.oel", "assets/levels/level_1_1_1.oel");
			type.set ("assets/levels/level_1_1_1.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_1_1og2.oel", "assets/levels/level_1_1_1og2.oel");
			type.set ("assets/levels/level_1_1_1og2.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_1_2.oel", "assets/levels/level_1_1_2.oel");
			type.set ("assets/levels/level_1_1_2.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_1_3.oel", "assets/levels/level_1_1_3.oel");
			type.set ("assets/levels/level_1_1_3.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_1_4.oel", "assets/levels/level_1_1_4.oel");
			type.set ("assets/levels/level_1_1_4.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_2_1.oel", "assets/levels/level_1_2_1.oel");
			type.set ("assets/levels/level_1_2_1.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_2_2.oel", "assets/levels/level_1_2_2.oel");
			type.set ("assets/levels/level_1_2_2.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_2_3.oel", "assets/levels/level_1_2_3.oel");
			type.set ("assets/levels/level_1_2_3.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_2_4.oel", "assets/levels/level_1_2_4.oel");
			type.set ("assets/levels/level_1_2_4.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_3_1.oel", "assets/levels/level_1_3_1.oel");
			type.set ("assets/levels/level_1_3_1.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_3_2.oel", "assets/levels/level_1_3_2.oel");
			type.set ("assets/levels/level_1_3_2.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_3_3.oel", "assets/levels/level_1_3_3.oel");
			type.set ("assets/levels/level_1_3_3.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_3_3og.oel", "assets/levels/level_1_3_3og.oel");
			type.set ("assets/levels/level_1_3_3og.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_3_4.oel", "assets/levels/level_1_3_4.oel");
			type.set ("assets/levels/level_1_3_4.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_4_1.oel", "assets/levels/level_1_4_1.oel");
			type.set ("assets/levels/level_1_4_1.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_4_2.oel", "assets/levels/level_1_4_2.oel");
			type.set ("assets/levels/level_1_4_2.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_4_3.oel", "assets/levels/level_1_4_3.oel");
			type.set ("assets/levels/level_1_4_3.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_4_4.oel", "assets/levels/level_1_4_4.oel");
			type.set ("assets/levels/level_1_4_4.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_end_1.oel", "assets/levels/level_1_end_1.oel");
			type.set ("assets/levels/level_1_end_1.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_end_2.oel", "assets/levels/level_1_end_2.oel");
			type.set ("assets/levels/level_1_end_2.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_end_3.oel", "assets/levels/level_1_end_3.oel");
			type.set ("assets/levels/level_1_end_3.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_end_4.oel", "assets/levels/level_1_end_4.oel");
			type.set ("assets/levels/level_1_end_4.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_item_end_1.oel", "assets/levels/level_1_item_end_1.oel");
			type.set ("assets/levels/level_1_item_end_1.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_item_end_2.oel", "assets/levels/level_1_item_end_2.oel");
			type.set ("assets/levels/level_1_item_end_2.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_item_end_3.oel", "assets/levels/level_1_item_end_3.oel");
			type.set ("assets/levels/level_1_item_end_3.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_item_end_4.oel", "assets/levels/level_1_item_end_4.oel");
			type.set ("assets/levels/level_1_item_end_4.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_item_mid.oel", "assets/levels/level_1_item_mid.oel");
			type.set ("assets/levels/level_1_item_mid.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_item_start_1.oel", "assets/levels/level_1_item_start_1.oel");
			type.set ("assets/levels/level_1_item_start_1.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_item_start_2.oel", "assets/levels/level_1_item_start_2.oel");
			type.set ("assets/levels/level_1_item_start_2.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_item_start_3.oel", "assets/levels/level_1_item_start_3.oel");
			type.set ("assets/levels/level_1_item_start_3.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_item_start_4.oel", "assets/levels/level_1_item_start_4.oel");
			type.set ("assets/levels/level_1_item_start_4.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_shop_end_1.oel", "assets/levels/level_1_shop_end_1.oel");
			type.set ("assets/levels/level_1_shop_end_1.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_shop_end_2.oel", "assets/levels/level_1_shop_end_2.oel");
			type.set ("assets/levels/level_1_shop_end_2.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_shop_end_3.oel", "assets/levels/level_1_shop_end_3.oel");
			type.set ("assets/levels/level_1_shop_end_3.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_shop_end_4.oel", "assets/levels/level_1_shop_end_4.oel");
			type.set ("assets/levels/level_1_shop_end_4.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_start_1.oel", "assets/levels/level_1_start_1.oel");
			type.set ("assets/levels/level_1_start_1.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_start_1woodman.oel", "assets/levels/level_1_start_1woodman.oel");
			type.set ("assets/levels/level_1_start_1woodman.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_start_2.oel", "assets/levels/level_1_start_2.oel");
			type.set ("assets/levels/level_1_start_2.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_start_3.oel", "assets/levels/level_1_start_3.oel");
			type.set ("assets/levels/level_1_start_3.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_start_3airman.oel", "assets/levels/level_1_start_3airman.oel");
			type.set ("assets/levels/level_1_start_3airman.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/levels/level_1_start_4.oel", "assets/levels/level_1_start_4.oel");
			type.set ("assets/levels/level_1_start_4.oel", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/music/music-goes-here.txt", "assets/music/music-goes-here.txt");
			type.set ("assets/music/music-goes-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/sounds/sounds-go-here.txt", "assets/sounds/sounds-go-here.txt");
			type.set ("assets/sounds/sounds-go-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/sounds/beep.ogg", "assets/sounds/beep.ogg");
			type.set ("assets/sounds/beep.ogg", Reflect.field (AssetType, "sound".toUpperCase ()));
			path.set ("assets/sounds/flixel.ogg", "assets/sounds/flixel.ogg");
			type.set ("assets/sounds/flixel.ogg", Reflect.field (AssetType, "sound".toUpperCase ()));
			path.set ("assets/fonts/nokiafc22.ttf", "assets/fonts/nokiafc22.ttf");
			type.set ("assets/fonts/nokiafc22.ttf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/arial.ttf", "assets/fonts/arial.ttf");
			type.set ("assets/fonts/arial.ttf", Reflect.field (AssetType, "font".toUpperCase ()));
			
			
			initialized = true;
			
		} //!initialized
		
	} //initialize
	
	
} //AssetData

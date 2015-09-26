#if !lime_hybrid


package;


import haxe.Timer;
import haxe.Unserializer;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.MovieClip;
import openfl.events.Event;
import openfl.text.Font;
import openfl.media.Sound;
import openfl.net.URLRequest;
import openfl.utils.ByteArray;
import openfl.Assets;

#if neko
import neko.vm.Deque;
import neko.vm.Thread;
#elseif cpp
import cpp.vm.Deque;
import cpp.vm.Thread;
#end

#if sys
import sys.FileSystem;
#end

#if ios
import openfl._legacy.utils.SystemPath;
#end


@:access(openfl.media.Sound)
class DefaultAssetLibrary extends AssetLibrary {
	
	
	private static var loaded = 0;
	private static var loading = 0;
	private static var workerIncomingQueue = new Deque<Dynamic> ();
	private static var workerResult = new Deque<Dynamic> ();
	private static var workerThread:Thread;
	
	public var className (default, null) = new Map <String, Dynamic> ();
	public var path (default, null) = new Map <String, String> ();
	public var type (default, null) = new Map <String, AssetType> ();
	
	private var lastModified:Float;
	private var timer:Timer;
	
	
	public function new () {
		
		super ();
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		Font.registerFont (__ASSET__assets_fonts_nokiafc22_ttf);
		Font.registerFont (__ASSET__assets_fonts_arial_ttf);
		
		
		#if (windows || mac || linux)
		
		var useManifest = false;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		
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
		
	}
	
	
	public override function exists (id:String, type:AssetType):Bool {
		
		var assetType = this.type.get (id);
		
		if (assetType != null) {
			
			if (assetType == type || ((type == SOUND || type == MUSIC) && (assetType == MUSIC || assetType == SOUND))) {
				
				return true;
				
			}
			
			if (type == BINARY || type == null || (assetType == BINARY && type == TEXT)) {
				
				return true;
				
			}
			
		}
		
		return false;
		
	}
	
	
	public override function getBitmapData (id:String):BitmapData {
		
		if (className.exists (id)) {
			
			return cast (Type.createInstance (className.get (id), []), BitmapData);
			
		} else {
			
			return BitmapData.load (path.get (id));
			
		}
		
	}
	
	
	public override function getBytes (id:String):ByteArray {
		
		if (className.exists (id)) {
			
			return cast (Type.createInstance (className.get (id), []), ByteArray);
			
		} else {
			
			return ByteArray.readFile (path.get (id));
			
		}
		
	}
	
	
	public override function getFont (id:String):Font {
		
		if (className.exists (id)) {
			
			var fontClass = className.get (id);
			Font.registerFont (fontClass);
			return cast (Type.createInstance (fontClass, []), Font);
			
		} else {
			
			return new Font (path.get (id));
			
		}
		
	}
	
	
	public override function getMusic (id:String):Sound {
		
		if (className.exists (id)) {
			
			return cast (Type.createInstance (className.get (id), []), Sound);
			
		} else {
			
			return new Sound (new URLRequest (path.get (id)), null, true);
			
		}
		
	}
	
	
	public override function getPath (id:String):String {
		
		#if ios
		
		return SystemPath.applicationDirectory + "/assets/" + path.get (id);
		
		#else
		
		return path.get (id);
		
		#end
		
	}
	
	
	public override function getSound (id:String):Sound {
		
		if (className.exists (id)) {
			
			return cast (Type.createInstance (className.get (id), []), Sound);
			
		} else {
			
			return new Sound (new URLRequest (path.get (id)), null, type.get (id) == MUSIC);
			
		}
		
	}
	
	
	public override function getText (id:String):String {
		
		var bytes = getBytes (id);
		
		if (bytes == null) {
			
			return null;
			
		} else {
			
			return bytes.readUTFBytes (bytes.length);
			
		}
		
	}
	
	
	public override function isLocal (id:String, type:AssetType):Bool {
		
		return true;
		
	}
	
	
	public override function list (type:AssetType):Array<String> {
		
		var items = [];
		
		for (id in this.type.keys ()) {
			
			if (type == null || exists (id, type)) {
				
				items.push (id);
				
			}
			
		}
		
		return items;
		
	}
	
	
	public override function loadBitmapData (id:String, handler:BitmapData -> Void):Void {
		
		__load (getBitmapData, id, handler);
		
	}
	
	
	public override function loadBytes (id:String, handler:ByteArray -> Void):Void {
		
		__load (getBytes, id, handler);
		
	}
	
	
	public override function loadFont (id:String, handler:Font -> Void):Void {
		
		__load (getFont, id, handler);
		
	}
	
	
	private function loadManifest ():Void {
		
		try {
			
			#if blackberry
			var bytes = ByteArray.readFile ("app/native/manifest");
			#elseif tizen
			var bytes = ByteArray.readFile ("../res/manifest");
			#elseif emscripten
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
								
								path.set (asset.id, asset.path);
								type.set (asset.id, Type.createEnum (AssetType, asset.type));
								
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
	
	
	public override function loadMusic (id:String, handler:Sound -> Void):Void {
		
		__load (getMusic, id, handler);
		
	}
	
	
	public override function loadSound (id:String, handler:Sound -> Void):Void {
		
		__load (getSound, id, handler);
		
	}
	
	
	public override function loadText (id:String, handler:String -> Void):Void {
		
		var callback = function (bytes:ByteArray):Void {
			
			if (bytes == null) {
				
				handler (null);
				
			} else {
				
				handler (bytes.readUTFBytes (bytes.length));
				
			}
			
		}
		
		loadBytes (id, callback);
		
	}
	
	
	private static function __doWork ():Void {
		
		while (true) {
			
			var message = workerIncomingQueue.pop (true);
			
			if (message == "WORK") {
				
				var getMethod = workerIncomingQueue.pop (true);
				var id = workerIncomingQueue.pop (true);
				var handler = workerIncomingQueue.pop (true);
				
				var data = getMethod (id);
				workerResult.add ("RESULT");
				workerResult.add (data);
				workerResult.add (handler);
				
			} else if (message == "EXIT") {
				
				break;
				
			}
			
		}
		
	}
	
	
	private inline function __load<T> (getMethod:String->T, id:String, handler:T->Void):Void {
		
		workerIncomingQueue.add ("WORK");
		workerIncomingQueue.add (getMethod);
		workerIncomingQueue.add (id);
		workerIncomingQueue.add (handler);
		
		loading++;
		
	}
	
	
	public static function __poll ():Void {
		
		if (loading > loaded) {
			
			if (workerThread == null) {
				
				workerThread = Thread.create (__doWork);
				
			}
			
			var message = workerResult.pop (false);
			
			while (message == "RESULT") {
				
				loaded++;
				
				var data = workerResult.pop (true);
				var handler = workerResult.pop (true);
				
				if (handler != null) {
					
					handler (data);
					
				}
				
				message = workerResult.pop (false);
				
			}
			
		} else {
			
			if (workerThread != null) {
				
				workerIncomingQueue.add ("EXIT");
				workerThread = null;
				
			}
			
		}
		
	}
	
	
}


#if (windows || mac || linux)


@:font("C:/HaxeToolkit/haxe/lib/flixel/3,3,11/assets/fonts/nokiafc22.ttf") @:keep #if display private #end class __ASSET__assets_fonts_nokiafc22_ttf extends flash.text.Font {}
@:font("C:/HaxeToolkit/haxe/lib/flixel/3,3,11/assets/fonts/arial.ttf") @:keep #if display private #end class __ASSET__assets_fonts_arial_ttf extends flash.text.Font {}





#else


class __ASSET__assets_fonts_nokiafc22_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/nokiafc22.ttf"; fontName = "Nokia Cellphone FC Small";  }}
class __ASSET__assets_fonts_arial_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/arial.ttf"; fontName = "Arial";  }}


#end


#else


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
	private var loadHandlers:Map<String, Dynamic>;
	private var threadPool:ThreadPool;
	private var timer:Timer;
	
	
	public function new () {
		
		super ();
		
		#if flash
		
		path.set ("assets/images/ado.png", "assets/images/ado.png");
		type.set ("assets/images/ado.png", AssetType.IMAGE);
		path.set ("assets/images/balun.png", "assets/images/balun.png");
		type.set ("assets/images/balun.png", AssetType.IMAGE);
		path.set ("assets/images/burd.png", "assets/images/burd.png");
		type.set ("assets/images/burd.png", AssetType.IMAGE);
		path.set ("assets/images/burdegg.png", "assets/images/burdegg.png");
		type.set ("assets/images/burdegg.png", AssetType.IMAGE);
		path.set ("assets/images/burdsmall.png", "assets/images/burdsmall.png");
		type.set ("assets/images/burdsmall.png", AssetType.IMAGE);
		path.set ("assets/images/coin.png", "assets/images/coin.png");
		type.set ("assets/images/coin.png", AssetType.IMAGE);
		path.set ("assets/images/crawler.png", "assets/images/crawler.png");
		type.set ("assets/images/crawler.png", AssetType.IMAGE);
		path.set ("assets/images/drops.png", "assets/images/drops.png");
		type.set ("assets/images/drops.png", AssetType.IMAGE);
		path.set ("assets/images/heart.png", "assets/images/heart.png");
		type.set ("assets/images/heart.png", AssetType.IMAGE);
		path.set ("assets/images/images-go-here.txt", "assets/images/images-go-here.txt");
		type.set ("assets/images/images-go-here.txt", AssetType.TEXT);
		path.set ("assets/images/juice.png", "assets/images/juice.png");
		type.set ("assets/images/juice.png", AssetType.IMAGE);
		path.set ("assets/images/ladder.png", "assets/images/ladder.png");
		type.set ("assets/images/ladder.png", AssetType.IMAGE);
		path.set ("assets/images/mc.png", "assets/images/mc.png");
		type.set ("assets/images/mc.png", AssetType.IMAGE);
		path.set ("assets/images/mcbeck.png", "assets/images/mcbeck.png");
		type.set ("assets/images/mcbeck.png", AssetType.IMAGE);
		path.set ("assets/images/metool.png", "assets/images/metool.png");
		type.set ("assets/images/metool.png", AssetType.IMAGE);
		path.set ("assets/images/mm.png", "assets/images/mm.png");
		type.set ("assets/images/mm.png", AssetType.IMAGE);
		path.set ("assets/images/mush.png", "assets/images/mush.png");
		type.set ("assets/images/mush.png", AssetType.IMAGE);
		path.set ("assets/images/nes_tiles.png", "assets/images/nes_tiles.png");
		type.set ("assets/images/nes_tiles.png", AssetType.IMAGE);
		path.set ("assets/images/notey.png", "assets/images/notey.png");
		type.set ("assets/images/notey.png", AssetType.IMAGE);
		path.set ("assets/images/ranger.png", "assets/images/ranger.png");
		type.set ("assets/images/ranger.png", AssetType.IMAGE);
		path.set ("assets/images/shakuhachiman.png", "assets/images/shakuhachiman.png");
		type.set ("assets/images/shakuhachiman.png", AssetType.IMAGE);
		path.set ("assets/images/snaake.png", "assets/images/snaake.png");
		type.set ("assets/images/snaake.png", AssetType.IMAGE);
		path.set ("assets/images/snobal.png", "assets/images/snobal.png");
		type.set ("assets/images/snobal.png", AssetType.IMAGE);
		path.set ("assets/images/spike.png", "assets/images/spike.png");
		type.set ("assets/images/spike.png", AssetType.IMAGE);
		path.set ("assets/images/tiles.png", "assets/images/tiles.png");
		type.set ("assets/images/tiles.png", AssetType.IMAGE);
		path.set ("assets/images/wood_tiles.png", "assets/images/wood_tiles.png");
		type.set ("assets/images/wood_tiles.png", AssetType.IMAGE);
		path.set ("assets/images/wood_tiles2.png", "assets/images/wood_tiles2.png");
		type.set ("assets/images/wood_tiles2.png", AssetType.IMAGE);
		path.set ("assets/levels/data-goes-here.txt", "assets/levels/data-goes-here.txt");
		type.set ("assets/levels/data-goes-here.txt", AssetType.TEXT);
		path.set ("assets/levels/HaxeFlixelTestLevel1.oel", "assets/levels/HaxeFlixelTestLevel1.oel");
		type.set ("assets/levels/HaxeFlixelTestLevel1.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_1_1.oel", "assets/levels/level_1_1_1.oel");
		type.set ("assets/levels/level_1_1_1.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_1_1og2.oel", "assets/levels/level_1_1_1og2.oel");
		type.set ("assets/levels/level_1_1_1og2.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_1_2.oel", "assets/levels/level_1_1_2.oel");
		type.set ("assets/levels/level_1_1_2.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_1_3.oel", "assets/levels/level_1_1_3.oel");
		type.set ("assets/levels/level_1_1_3.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_1_4.oel", "assets/levels/level_1_1_4.oel");
		type.set ("assets/levels/level_1_1_4.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_2_1.oel", "assets/levels/level_1_2_1.oel");
		type.set ("assets/levels/level_1_2_1.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_2_2.oel", "assets/levels/level_1_2_2.oel");
		type.set ("assets/levels/level_1_2_2.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_2_3.oel", "assets/levels/level_1_2_3.oel");
		type.set ("assets/levels/level_1_2_3.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_2_4.oel", "assets/levels/level_1_2_4.oel");
		type.set ("assets/levels/level_1_2_4.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_3_1.oel", "assets/levels/level_1_3_1.oel");
		type.set ("assets/levels/level_1_3_1.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_3_2.oel", "assets/levels/level_1_3_2.oel");
		type.set ("assets/levels/level_1_3_2.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_3_3.oel", "assets/levels/level_1_3_3.oel");
		type.set ("assets/levels/level_1_3_3.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_3_3og.oel", "assets/levels/level_1_3_3og.oel");
		type.set ("assets/levels/level_1_3_3og.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_3_4.oel", "assets/levels/level_1_3_4.oel");
		type.set ("assets/levels/level_1_3_4.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_4_1.oel", "assets/levels/level_1_4_1.oel");
		type.set ("assets/levels/level_1_4_1.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_4_2.oel", "assets/levels/level_1_4_2.oel");
		type.set ("assets/levels/level_1_4_2.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_4_3.oel", "assets/levels/level_1_4_3.oel");
		type.set ("assets/levels/level_1_4_3.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_4_4.oel", "assets/levels/level_1_4_4.oel");
		type.set ("assets/levels/level_1_4_4.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_end_1.oel", "assets/levels/level_1_end_1.oel");
		type.set ("assets/levels/level_1_end_1.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_end_2.oel", "assets/levels/level_1_end_2.oel");
		type.set ("assets/levels/level_1_end_2.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_end_3.oel", "assets/levels/level_1_end_3.oel");
		type.set ("assets/levels/level_1_end_3.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_end_4.oel", "assets/levels/level_1_end_4.oel");
		type.set ("assets/levels/level_1_end_4.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_item_end_1.oel", "assets/levels/level_1_item_end_1.oel");
		type.set ("assets/levels/level_1_item_end_1.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_item_end_2.oel", "assets/levels/level_1_item_end_2.oel");
		type.set ("assets/levels/level_1_item_end_2.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_item_end_3.oel", "assets/levels/level_1_item_end_3.oel");
		type.set ("assets/levels/level_1_item_end_3.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_item_end_4.oel", "assets/levels/level_1_item_end_4.oel");
		type.set ("assets/levels/level_1_item_end_4.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_item_mid.oel", "assets/levels/level_1_item_mid.oel");
		type.set ("assets/levels/level_1_item_mid.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_item_start_1.oel", "assets/levels/level_1_item_start_1.oel");
		type.set ("assets/levels/level_1_item_start_1.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_item_start_2.oel", "assets/levels/level_1_item_start_2.oel");
		type.set ("assets/levels/level_1_item_start_2.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_item_start_3.oel", "assets/levels/level_1_item_start_3.oel");
		type.set ("assets/levels/level_1_item_start_3.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_item_start_4.oel", "assets/levels/level_1_item_start_4.oel");
		type.set ("assets/levels/level_1_item_start_4.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_shop_end_1.oel", "assets/levels/level_1_shop_end_1.oel");
		type.set ("assets/levels/level_1_shop_end_1.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_shop_end_2.oel", "assets/levels/level_1_shop_end_2.oel");
		type.set ("assets/levels/level_1_shop_end_2.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_shop_end_3.oel", "assets/levels/level_1_shop_end_3.oel");
		type.set ("assets/levels/level_1_shop_end_3.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_shop_end_4.oel", "assets/levels/level_1_shop_end_4.oel");
		type.set ("assets/levels/level_1_shop_end_4.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_start_1.oel", "assets/levels/level_1_start_1.oel");
		type.set ("assets/levels/level_1_start_1.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_start_1woodman.oel", "assets/levels/level_1_start_1woodman.oel");
		type.set ("assets/levels/level_1_start_1woodman.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_start_2.oel", "assets/levels/level_1_start_2.oel");
		type.set ("assets/levels/level_1_start_2.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_start_3.oel", "assets/levels/level_1_start_3.oel");
		type.set ("assets/levels/level_1_start_3.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_start_3airman.oel", "assets/levels/level_1_start_3airman.oel");
		type.set ("assets/levels/level_1_start_3airman.oel", AssetType.TEXT);
		path.set ("assets/levels/level_1_start_4.oel", "assets/levels/level_1_start_4.oel");
		type.set ("assets/levels/level_1_start_4.oel", AssetType.TEXT);
		path.set ("assets/music/music-goes-here.txt", "assets/music/music-goes-here.txt");
		type.set ("assets/music/music-goes-here.txt", AssetType.TEXT);
		path.set ("assets/sounds/sounds-go-here.txt", "assets/sounds/sounds-go-here.txt");
		type.set ("assets/sounds/sounds-go-here.txt", AssetType.TEXT);
		path.set ("assets/sounds/beep.ogg", "assets/sounds/beep.ogg");
		type.set ("assets/sounds/beep.ogg", AssetType.SOUND);
		path.set ("assets/sounds/flixel.ogg", "assets/sounds/flixel.ogg");
		type.set ("assets/sounds/flixel.ogg", AssetType.SOUND);
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
		id = "assets/images/ranger.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/images/shakuhachiman.png";
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
		id = "assets/images/tiles.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/images/wood_tiles.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/images/wood_tiles2.png";
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
		id = "assets/sounds/beep.ogg";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/sounds/flixel.ogg";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
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
		
		#if openfl
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		openfl.text.Font.registerFont (__ASSET__OPENFL__assets_fonts_nokiafc22_ttf);
		openfl.text.Font.registerFont (__ASSET__OPENFL__assets_fonts_arial_ttf);
		
		#end
		
		#if (windows || mac || linux)
		
		var useManifest = false;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		
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
		threadPool.doWork.add (function (id, getMethod) {
			
			threadPool.sendComplete (id, getMethod (id));
			
		});
		threadPool.onComplete.add (function (id, data) {
			
			var handler = loadHandlers.get (id);
			handler (data);
			
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
			
			loadHandlers = new Map ();
			createThreadPool ();
			
		}
		
		loadHandlers.set (id, handler);
		threadPool.queue (id, getBytes);
		
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
			
			loadHandlers = new Map ();
			createThreadPool ();
			
		}
		
		loadHandlers.set (id, handler);
		threadPool.queue (id, getImage);
		
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











































































@:keep @:bind #if display private #end class __ASSET__assets_fonts_nokiafc22_ttf extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_fonts_arial_ttf extends null { }


#elseif html5











































































@:keep #if display private #end class __ASSET__assets_fonts_nokiafc22_ttf extends lime.text.Font { public function new () { super (); name = "Nokia Cellphone FC Small"; } } 
@:keep #if display private #end class __ASSET__assets_fonts_arial_ttf extends lime.text.Font { public function new () { super (); name = "Arial"; } } 


#else



#if (windows || mac || linux)


@:font("C:/HaxeToolkit/haxe/lib/flixel/3,3,11/assets/fonts/nokiafc22.ttf") #if display private #end class __ASSET__assets_fonts_nokiafc22_ttf extends lime.text.Font {}
@:font("C:/HaxeToolkit/haxe/lib/flixel/3,3,11/assets/fonts/arial.ttf") #if display private #end class __ASSET__assets_fonts_arial_ttf extends lime.text.Font {}



#end

#if openfl
@:keep #if display private #end class __ASSET__OPENFL__assets_fonts_nokiafc22_ttf extends openfl.text.Font { public function new () { var font = new __ASSET__assets_fonts_nokiafc22_ttf (); src = font.src; name = font.name; super (); }}
@:keep #if display private #end class __ASSET__OPENFL__assets_fonts_arial_ttf extends openfl.text.Font { public function new () { var font = new __ASSET__assets_fonts_arial_ttf (); src = font.src; name = font.name; super (); }}

#end

#end
#end


#end
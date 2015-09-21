#if !macro


@:access(lime.app.Application)
@:access(lime.Assets)
@:access(openfl.display.Stage)


class ApplicationMain {
	
	
	public static var config:lime.app.Config;
	public static var preloader:openfl.display.Preloader;
	
	
	public static function create ():Void {
		
		var app = new openfl.display.Application ();
		app.create (config);
		
		var display = new flixel.system.FlxPreloader ();
		
		preloader = new openfl.display.Preloader (display);
		app.setPreloader (preloader);
		preloader.onComplete.add (init);
		preloader.create (config);
		
		#if (js && html5)
		var urls = [];
		var types = [];
		
		
		urls.push ("assets/data/data-goes-here.txt");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/HaxeFlixelTestLevel1.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_1_1.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_1_1og2.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_1_2.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_1_3.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_1_4.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_2_1.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_2_2.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_2_3.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_2_4.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_3_1.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_3_2.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_3_3.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_3_3og.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_3_4.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_4_1.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_4_2.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_4_3.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_4_4.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_end_1.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_end_2.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_end_3.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_end_4.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_item_end_1.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_item_end_2.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_item_end_3.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_item_end_4.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_item_mid.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_item_start_1.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_item_start_2.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_item_start_3.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_item_start_4.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_start_1.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_start_1woodman.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_start_2.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_start_3.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_start_3og.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/data/level_1_start_4.oel");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/images/ado.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/burd.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/burdegg.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/burdsmall.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/coin.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/crawler.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/drops.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/heart.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/images-go-here.txt");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/images/juice.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/ladder.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/mc.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/mcbeck.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/metool.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/mm.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/nes_tiles.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/notey.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/ranger.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/shakuhachiman.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/snaake.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/snobal.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/spike.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/tiles.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/wood_tiles.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/images/wood_tiles2.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/music/music-goes-here.txt");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/sounds/sounds-go-here.txt");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/sounds/beep.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/sounds/flixel.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/sounds/beep.ogg");
		types.push (lime.Assets.AssetType.SOUND);
		
		
		urls.push ("assets/sounds/flixel.ogg");
		types.push (lime.Assets.AssetType.SOUND);
		
		
		urls.push ("Nokia Cellphone FC Small");
		types.push (lime.Assets.AssetType.FONT);
		
		
		urls.push ("Arial");
		types.push (lime.Assets.AssetType.FONT);
		
		
		
		if (config.assetsPrefix != null) {
			
			for (i in 0...urls.length) {
				
				if (types[i] != lime.Assets.AssetType.FONT) {
					
					urls[i] = config.assetsPrefix + urls[i];
					
				}
				
			}
			
		}
		
		preloader.load (urls, types);
		#end
		
		var result = app.exec ();
		
		#if (sys && !nodejs && !emscripten)
		Sys.exit (result);
		#end
		
	}
	
	
	public static function init ():Void {
		
		var loaded = 0;
		var total = 0;
		var library_onLoad = function (__) {
			
			loaded++;
			
			if (loaded == total) {
				
				start ();
				
			}
			
		}
		
		preloader = null;
		
		
		
		if (total == 0) {
			
			start ();
			
		}
		
	}
	
	
	public static function main () {
		
		config = {
			
			build: "1289",
			company: "HaxeFlixel",
			file: "HaxeFlixelVlog",
			fps: 60,
			name: "HaxeFlixelVlog",
			orientation: "portrait",
			packageName: "com.example.myapp",
			version: "0.0.1",
			windows: [
				
				{
					antialiasing: 0,
					background: 0,
					borderless: false,
					depthBuffer: false,
					display: 0,
					fullscreen: false,
					hardware: true,
					height: 480,
					parameters: "{}",
					resizable: true,
					stencilBuffer: true,
					title: "HaxeFlixelVlog",
					vsync: true,
					width: 640,
					x: null,
					y: null
				},
			]
			
		};
		
		#if hxtelemetry
		var telemetry = new hxtelemetry.HxTelemetry.Config ();
		telemetry.allocations = true;
		telemetry.host = "localhost";
		telemetry.app_name = config.name;
		Reflect.setField (config, "telemetry", telemetry);
		#end
		
		#if (js && html5)
		#if (munit || utest)
		openfl.Lib.embed (null, 640, 480, "000000");
		#end
		#else
		create ();
		#end
		
	}
	
	
	public static function start ():Void {
		
		var hasMain = false;
		var entryPoint = Type.resolveClass ("Main");
		
		for (methodName in Type.getClassFields (entryPoint)) {
			
			if (methodName == "main") {
				
				hasMain = true;
				break;
				
			}
			
		}
		
		lime.Assets.initialize ();
		
		if (hasMain) {
			
			Reflect.callMethod (entryPoint, Reflect.field (entryPoint, "main"), []);
			
		} else {
			
			var instance:DocumentClass = Type.createInstance (DocumentClass, []);
			
			/*if (Std.is (instance, openfl.display.DisplayObject)) {
				
				openfl.Lib.current.addChild (cast instance);
				
			}*/
			
		}
		
		openfl.Lib.current.stage.dispatchEvent (new openfl.events.Event (openfl.events.Event.RESIZE, false, false));
		
	}
	
	
	#if neko
	@:noCompletion public static function __init__ () {
		
		var loader = new neko.vm.Loader (untyped $loader);
		loader.addPath (haxe.io.Path.directory (Sys.executablePath ()));
		loader.addPath ("./");
		loader.addPath ("@executable_path/");
		
	}
	#end
	
	
}


@:build(DocumentClass.build())
@:keep class DocumentClass extends Main {}


#else


import haxe.macro.Context;
import haxe.macro.Expr;


class DocumentClass {
	
	
	macro public static function build ():Array<Field> {
		
		var classType = Context.getLocalClass ().get ();
		var searchTypes = classType;
		
		while (searchTypes.superClass != null) {
			
			if (searchTypes.pack.length == 2 && searchTypes.pack[1] == "display" && searchTypes.name == "DisplayObject") {
				
				var fields = Context.getBuildFields ();
				
				var method = macro {
					
					openfl.Lib.current.addChild (this);
					super ();
					dispatchEvent (new openfl.events.Event (openfl.events.Event.ADDED_TO_STAGE, false, false));
					
				}
				
				fields.push ({ name: "new", access: [ APublic ], kind: FFun({ args: [], expr: method, params: [], ret: macro :Void }), pos: Context.currentPos () });
				
				return fields;
				
			}
			
			searchTypes = searchTypes.superClass.t.get ();
			
		}
		
		return null;
		
	}
	
	
}


#end

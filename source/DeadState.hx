package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxSubState;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import flixel.util.FlxPoint;

/**
 * ...
 * @author ...
 */
class DeadState extends FlxSubState
{
	var fakePlayer:FlxSprite;
	var circle:FlxSprite;
	var orb1:FlxSprite;
	var orb2:FlxSprite;
	var orb3:FlxSprite;
	var orb4:FlxSprite;
	var orbXSpeed:Int = 200;
	var orbYSpeed:Int;
	var _player:Player;
	
	public function new(BGColor:Int=FlxColor.TRANSPARENT, P:Player) 
	{
		super(BGColor);
		orbYSpeed = orbXSpeed;
		_player = P;
		
		fakePlayer = new FlxSprite(P.x - 9, P.y - 6);
		fakePlayer.loadGraphic(AssetPaths.mcgurlhair__png, true, 32, 32);
		fakePlayer.flipX = P.flipX;
		var o = 24 * P.curWeaponLoc;
		fakePlayer.animation.add("hurt", [15 + o]);
		fakePlayer.animation.play("hurt");
		add(fakePlayer);
		
		if (!P.flipX)
			circle = new FlxSprite(P.x - 18, P.y - 16);
		else
			circle = new FlxSprite(P.x - 16, P.y - 16);
		circle.loadGraphic(AssetPaths.death_circle__png, true, 48, 48);
		circle.animation.add("anim", [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15], 24, false);
		circle.animation.play("anim");
		add(circle);
		
	}
	
	public override function update()
	{
		if (FlxG.keys.anyJustReleased(["P"]))
		{
			//this.destroy();
			this.close();
		}
		if (circle.animation.frameIndex == 7)
		{
			fakePlayer.visible = false;
		}
		if (circle.animation.finished && orb1 == null)
		{
			circle.visible = false;
			var colorOffset:Int = 0;
			
			if (Reg.colorArray.indexOf(Reg.G) != -1)
				colorOffset = 0;
			else
				colorOffset = 0;	
			orb1 = new FlxSprite(circle.x + 16, circle.y + 18);
			orb1.loadGraphic(AssetPaths.death_orbs__png, true, 8, 8);
			orb1.animation.add("anim", [0 + colorOffset]);
			orb1.animation.play("anim");
			orb1.velocity.x = -orbXSpeed;
			orb1.velocity.y = -orbYSpeed;
			add(orb1);
			
			if (Reg.colorArray.indexOf(Reg.C) != -1)
				colorOffset = 1;
			else
				colorOffset = 0;	
			orb2 = new FlxSprite(circle.x + 26, circle.y + 18);
			orb2.loadGraphic(AssetPaths.death_orbs__png, true, 8, 8);
			orb2.animation.add("anim", [0 + colorOffset]);
			orb2.animation.play("anim");
			orb2.velocity.x = orbXSpeed;
			orb2.velocity.y = -orbYSpeed;	
			add(orb2);
			
			if (Reg.colorArray.indexOf(Reg.M) != -1)
				colorOffset = 2;
			else
				colorOffset = 0;	
			orb3 = new FlxSprite(circle.x + 26, circle.y + 27);
			orb3.loadGraphic(AssetPaths.death_orbs__png, true, 8, 8);
			orb3.animation.add("anim", [0 + colorOffset]);
			orb3.animation.play("anim");
			orb3.velocity.x = orbXSpeed;
			orb3.velocity.y = orbYSpeed;	
			add(orb3);
			
			if (Reg.colorArray.indexOf(Reg.Y) != -1)
				colorOffset = 3;
			else
				colorOffset = 0;	
			orb4 = new FlxSprite(circle.x + 16, circle.y + 27);
			orb4.loadGraphic(AssetPaths.death_orbs__png, true, 8, 8);
			orb4.animation.add("anim", [0 + colorOffset]);
			orb4.animation.play("anim");
			orb4.velocity.x = -orbXSpeed;
			orb4.velocity.y = orbYSpeed;	
			add(orb4);
			
		}
		
		if (orb1 != null && !orb1.isOnScreen() && !orb2.isOnScreen() && !orb3.isOnScreen() && !orb4.isOnScreen())
		{
			FlxG.switchState(new MenuState());
		}
		
		super.update();
	}
	
}
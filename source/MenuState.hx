package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;

/**
 * A FlxState which can be used for the game's menu.
 */
class MenuState extends FlxState
{
	
	var colorDefault = 0xFA9FA9;
	var colorSelected = 0x9AF9AF;
	var selectedLevel = 0;
	
	private var txtLevel0:FlxText;
	private var txtLevel1:FlxText;
	private var txtLevel2:FlxText;
	private var txtLevel3:FlxText;
	private var grpLevel:FlxTypedGroup<FlxText>;
	
	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{
		super.create();
		add(new FlxText(6, 9, 200, "Dev Cheat Hacks Level Select"));
		//FlxG.camera.bgColor = 0xFFBADA55;
		FlxG.camera.bgColor = 0xFA9FA9;
		
		
		//FlxG.fullscreen = true;
		
		
		grpLevel = new FlxTypedGroup<FlxText>();
		txtLevel0 = new FlxText(100, 25, 0, "hub", 8);
		txtLevel1 = new FlxText(100, 50, 0, "Cave", 8);
		txtLevel2 = new FlxText(100, 75, 0, "Level2", 8);
		txtLevel3 = new FlxText(100, 100, 0, "Level3", 8);
		
		add(grpLevel);
		grpLevel.add(txtLevel0);
		grpLevel.add(txtLevel1);
		grpLevel.add(txtLevel2);
		grpLevel.add(txtLevel3);

	}
	

	override public function update():Void
	{
		colorize();
		
		if (FlxG.keys.anyJustPressed(["DOWN", "S"])) 
		{
			selectedLevel++;
		}
		else if (FlxG.keys.anyJustPressed(["UP", "W"]))
		{
			selectedLevel--;
		}
		if (selectedLevel >= 4)
			selectedLevel = 0;
		else if (selectedLevel < 0)
			selectedLevel = 3;
			
		if (FlxG.keys.anyJustPressed(["ENTER", "J"]))
		{
			switch (selectedLevel)
			{
				case (0):
					gotoLevel0();
				case (1):
					gotoLevel1();
				case (2):
					gotoLevel2();
				case (3):
					gotoLevel3();
			}
		}
		super.update();
	}	
	
	
	function colorize():Void
	{
		for (level in grpLevel)
			level.setFormat(8, 0x9AF9AF);
		switch (selectedLevel)
		{
			case (0):
				txtLevel0.setFormat(8, 0xFA9FA9);
			case (1):
				txtLevel1.setFormat(8, 0xFA9FA9);
			case (2):
				txtLevel2.setFormat(8, 0xFA9FA9);
			case (3):
				txtLevel3.setFormat(8, 0xFA9FA9);
		}
	}
	
	function gotoLevel0():Void
	{
		FlxG.switchState(new HubState());
	}	
	function gotoLevel1():Void
	{
		FlxG.switchState(new Level1(Reg.door1Color));
	}
	function gotoLevel2():Void
	{
		FlxG.switchState(new Level2(Reg.door2Color));
	}
	function gotoLevel3():Void
	{
		FlxG.switchState(new Level3(Reg.door3Color));
	}
	

	
	/**
	 * Function that is called when this state is destroyed - you might want to 
	 * consider setting all objects this state uses to null to help garbage collection.
	 */
	override public function destroy():Void
	{
		super.destroy();
	}


}
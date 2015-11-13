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
	var selectedSelection = 0;
	
	private var txtSelection0:FlxText;
	private var txtSelection1:FlxText;
	private var txtSelection2:FlxText;
	private var grpSelections:FlxTypedGroup<FlxText>;
	
	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{
		super.create();
		add(new FlxText(6, 9, 200, "title screen art goes here"));
		FlxG.camera.bgColor = 0xFA9FA9;
		
		
		//FlxG.fullscreen = true;
		
		
		grpSelections = new FlxTypedGroup<FlxText>();
		txtSelection0 = new FlxText(100, 25, 0, "New Game", 8);
		txtSelection1 = new FlxText(100, 50, 0, "Settings", 8);
		txtSelection2 = new FlxText(100, 75, 0, "Extras", 8);
		
		add(grpSelections);
		grpSelections.add(txtSelection0);
		grpSelections.add(txtSelection1);
		grpSelections.add(txtSelection2);

	}
	

	override public function update():Void
	{
		colorize();
		
		if (FlxG.keys.anyJustPressed(["DOWN", "S"])) 
		{
			selectedSelection++;
		}
		else if (FlxG.keys.anyJustPressed(["UP", "W"]))
		{
			selectedSelection--;
		}
		if (selectedSelection >= 3)
			selectedSelection = 0;
		else if (selectedSelection < 0)
			selectedSelection = 2;
			
		if (FlxG.keys.anyJustPressed(["ENTER", "J"]))
		{
			switch (selectedSelection)
			{
				case (0):
					gotoHub();
				case (1):
					gotoSettings();
				case (2):
					gotoExtras();
			}
		}
		super.update();
	}	
	
	
	function colorize():Void
	{
		for (level in grpSelections)
			level.setFormat(8, 0x9AF9AF);
		switch (selectedSelection)
		{
			case (0):
				txtSelection0.setFormat(8, 0xFA9FA9);
			case (1):
				txtSelection1.setFormat(8, 0xFA9FA9);
			case (2):
				txtSelection2.setFormat(8, 0xFA9FA9);

		}
	}
	
	function gotoHub():Void
	{
		Reg.resetValues();
		Reg.shuffleColors();
		FlxG.switchState(new HubState());
	}	
	function gotoSettings():Void
	{
		FlxG.switchState(new Level1(Reg.door1Color));
	}
	function gotoExtras():Void
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
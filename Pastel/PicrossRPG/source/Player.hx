package;

import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.ui.FlxButton;
import flixel.ui.FlxVirtualPad;

/**
 * ...
 * @author .:BuzzJeux:., Bownly
 */

class Player extends FlxSprite
{
	private static inline var TILE_SIZE:Int = 16;
	private static inline var MOVEMENT_SPEED:Int = 2;
	
	public var isMoving:Bool;
	
	public var canMove:Bool = true;
	
	var _state:TownState;

	public function new(X:Float, Y:Float, Facing:Int, State:TownState)
	{
		super(X, Y);
		
		_state = State;
		facing = Facing;
		
		
		loadGraphic(AssetPaths.mctest__png, true, 16, 16);
		animation.add("up", [0, 1], 4, true);
		animation.add("dn", [2, 3], 4, true);
		animation.add("lf", [4, 5], 4, true);
		animation.add("rt", [6, 7], 4, true);
		
		setFacing(facing);
	}
	
	override public function update():Void
	{
		super.update();  
		
		// Move the player to the next block
		if (isMoving)
		{
			switch (facing)
			{
				case FlxObject.UP:
					y -= MOVEMENT_SPEED;
				case FlxObject.DOWN:
					y += MOVEMENT_SPEED;
				case FlxObject.LEFT:
					x -= MOVEMENT_SPEED;
				case FlxObject.RIGHT:
					x += MOVEMENT_SPEED;
			}
		}
		
		
		// Check if the player has now reached the next block
		if ((x % TILE_SIZE == 0) && (y % TILE_SIZE == 0))
		{
			isMoving = false;
		}
	
		
		// Check for WASD or arrow key presses and move accordingly
		if (!isMoving)
		{
			if (FlxG.keys.anyPressed(["UP", "W"]))
			{
				facing = FlxObject.UP;
				canMove = collisionCheck(facing);
				if (canMove)
					moveTo(FlxObject.UP);
				animation.play("up");
			}
			else if (FlxG.keys.anyPressed(["DOWN", "S"]))
			{
				facing = FlxObject.DOWN;
				canMove = collisionCheck(facing);
				if (canMove)
					moveTo(FlxObject.DOWN);
				animation.play("dn");
			}
			else if (FlxG.keys.anyPressed(["LEFT", "A"]))
			{
				facing = FlxObject.LEFT;
				canMove = collisionCheck(facing);
				if (canMove)
					moveTo(FlxObject.LEFT);
				animation.play("lf");
			}
			else if (FlxG.keys.anyPressed(["RIGHT", "D"]))
			{
				facing = FlxObject.RIGHT;
				canMove = collisionCheck(facing);
				if (canMove)
					moveTo(FlxObject.RIGHT);
				animation.play("rt");
			}
			
			// interaction
			if (FlxG.keys.anyJustPressed(["J", "SPACE"]))
			{
				interactionCheck(facing);
			}
			
			// stats menu
			if (FlxG.keys.anyJustPressed(["K", "ENTER"]))
			{
				var sub = new StatsSubState(x, y);
				_state.openSubState(sub);
			}
			
		}
	}
	
	public function setFacing(Dir:Int):Void
	{
		switch (Dir)
		{
			case FlxObject.UP:
			{
				facing = FlxObject.UP;
				animation.play("up");
			}
			case FlxObject.DOWN:
			{
				facing = FlxObject.DOWN;
				animation.play("dn");
			}
			case FlxObject.LEFT:
			{
				facing = FlxObject.LEFT;
				animation.play("lf");
			}
			case FlxObject.RIGHT:
			{
				facing = FlxObject.RIGHT;
				animation.play("rt");
			}
		}
	}
	
	public function moveTo(Direction:Int):Void
	{
		// Only change direction if not already moving
		if (!isMoving)
		{
			facing = Direction;
			isMoving = true;
		}
	}
	
	public function collisionCheck(Direction:Int):Bool
	{
		var xx:Int = 0;
		var yy:Int = 0;
		
		switch (facing)
		{
			case FlxObject.UP:
				yy = -16;
			case FlxObject.DOWN:
				yy = 16;
			case FlxObject.LEFT:
				xx = -16;
			case FlxObject.RIGHT:
				xx = 16;
		}
		var map = _state._tileMap;
		if (map.getTile(Math.floor((x + xx) / TILE_SIZE ), Math.floor((y + yy) / TILE_SIZE )) > 9)
			return false;

		
		for (item in _state._grpNPCs)
		{
			if (item.y == y + yy && item.x == x + xx)
				return false;				
		}
		if (!Reg.postDialogBattleFlag)
			Reg.encounterCounter -= _state.encounterDecrementer;

		return true;
	}
	
	public function interactionCheck(Direction:Int):Void
	{
		var xx:Int = 0;
		var yy:Int = 0;
		
		
		switch (facing)
		{
			case FlxObject.UP:
				yy = -16;
			case FlxObject.DOWN:
				yy = 16;
			case FlxObject.LEFT:
				xx = -16;
			case FlxObject.RIGHT:
				xx = 16;
		}
		
		for (item in _state._grpNPCs)
		{
			
			if (item.y == y + yy && item.x == x + xx)
			{
				item.triggered(facing);
				return;
			}
		}
		return;
	}
	
}
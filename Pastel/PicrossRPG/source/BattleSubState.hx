package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxSubState;
import flixel.group.FlxGroup;
import flixel.group.FlxTypedGroup;
import flixel.system.FlxSound;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import flixel.util.FlxRandom;

/**
 * ...
 * @author ...
 */
class BattleSubState extends FlxSubState
{

	private var _sprBack:FlxSprite;
    private var _txtHP:FlxText;
    private var _txtMessage:FlxText;
    private var _txtVS:FlxText;
	private var _sprPlayer:FlxSprite;
	private var _sprEnemy:FlxSprite;
	private var _sprCursor:FlxSprite;
	
	var _grpTexts:FlxTypedGroup<FlxText>;
	var _grpSprites:FlxTypedGroup<FlxSprite>;
	var _grpPicross:FlxTypedGroup<PicrossSquare>;
	var _grpCursor:FlxTypedGroup<FlxSprite>;
	
	var _enemyID:Int;
	var _dimens:Int;
	var _winCount:Int = 0;
	var _curCount:Int = 0;
	
	var _rowArray:Array<Int> = new Array<Int>();
	var _colArray:Array<Array<Int>> = new Array<Array<Int>>();
	var _rowHints:Array<String> = new Array<String>();
	var _colHints:Array<String> = new Array<String>();
	
	var _mp:Float = Reg.pMP;
	var _msgTimer:Float = 0;
	var _msgDuration:Float = 1.5;
	
	var _mcHurtTimer:Float = 0;
	var _mcHurtDuration:Float = 1.5;
	
	var isVictoly:Bool = false;
	var isDefeat:Bool = false;
	var isEscaped:Bool = false;
	
	var songBattle:FlxSound = FlxG.sound.load("assets/music/battle.wav");
	var songFanfare:FlxSound = FlxG.sound.load("assets/music/victoly fanfare.wav");
	var songLost:FlxSound = FlxG.sound.load("assets/music/lost the battle.wav");
	
	public function new(EnemyID:Int, ?BGColor:Int=FlxColor.TRANSPARENT) 
	{
		super();
	
		_enemyID = EnemyID;
		_dimens = 4 + _enemyID; 
		if (_enemyID == 4)  // aka endboss
			_dimens = 10;
	
		_grpTexts = new FlxTypedGroup<FlxText>();
		_grpSprites = new FlxTypedGroup<FlxSprite>();
		_grpPicross = new FlxTypedGroup<PicrossSquare>();
		_grpCursor = new FlxTypedGroup<FlxSprite>();
		
		_sprBack = new FlxSprite().makeGraphic(160, 160, FlxColor.BLACK);
		_sprBack.x = FlxG.width / 2 - _sprBack.width / 2;
		_sprBack.y = FlxG.height / 2 - _sprBack.height / 2;
		
		_txtHP = new FlxText(_sprBack.x, _sprBack.y, 64, "HP: " + _mp, 8);
		
		_sprPlayer = new FlxSprite(_sprBack.x, _txtHP.y + _txtHP.height);
		_sprPlayer.loadGraphic("assets/images/mctest.png", true, 16, 16);
		_sprPlayer.animation.add("idle", [2, 3], 4, true);
		_sprPlayer.animation.add("dead", [8, 9], 4, true);
		_sprPlayer.animation.play("idle");
		
		_txtVS = new FlxText(_sprPlayer.x + _sprPlayer.width, _sprPlayer.y + 8, 16, "vs", 8);
		
		_sprEnemy = new FlxSprite(_sprPlayer.x + _sprPlayer.width * 2, _sprPlayer.y);
		_sprEnemy.loadGraphic("assets/images/enemies.png", true, 16, 16);
		var o:Int = 4;  // amount of tiles per enemy
		o *= _enemyID;
		_sprEnemy.animation.add("idle", [1 + o, 0 + o, 1 + o, 2 + o], 4, true);
		_sprEnemy.animation.add("dead", [3 + o]);
		_sprEnemy.animation.play("idle");
		
		_sprCursor = new FlxSprite(_sprBack.x + 48, _sprBack.y + 48);
		_sprCursor.loadGraphic("assets/images/picross_hair.png", true, 9, 9);
		_sprCursor.animation.add("idle", [0, 1], 4, true);
		_sprCursor.animation.play("idle");
		
		_txtMessage = new FlxText(_sprBack.x, _sprBack.y + _sprBack.height - 14, _sprBack.width, "", 8);
		_txtMessage.alignment = "center";
	
	
		_grpCursor.add(_sprCursor);
		_grpSprites.add(_sprBack);
		_grpSprites.add(_sprEnemy);	
		_grpSprites.add(_sprPlayer);	
		_grpTexts.add(_txtHP);
		_grpTexts.add(_txtVS);
		_grpTexts.add(_txtMessage);
		
		add(_grpSprites);
		add(_grpTexts);
		add(_grpPicross);
		add(_grpCursor);  // for zlayer reasons, this has to be added last


		// sets up the values of the randomized grid
		for (i in 0..._dimens)
		{
			_rowArray = [];
			for (j in 0..._dimens)
			{
				var rand:Int = FlxRandom.intRanged(0, 1);
				_rowArray.push(rand);
				if (rand == 1)
					_winCount++;
			}
			calcRowHints(_rowArray);
			_colArray.push(_rowArray);
		}
		calcColHints(_colArray);
		
		// sets up the actual grid of PicrossSquares
		for (X in 0..._rowArray.length)
		{
			for (Y in 0..._colArray.length)
			{
				var pSquare:PicrossSquare = new PicrossSquare(_sprBack.x + 48 + X * 10, _sprBack.y + 48 + Y * 10, Math.floor(_enemyID / 2), _colArray[Y][X]);
				_grpPicross.add(pSquare);
			}
		}
		
		// sets up the hints for the rows
		for (Y in 0..._rowArray.length)
		{
			var txt:FlxText = new FlxText(_sprBack.x, _sprBack.y + 46 + Y * 10, 48, _rowHints[Y], 8);
			txt.alignment = "right";
			_grpTexts.add(txt);
		}
		// sets up the hints for the cols
		for (X in 0..._colArray.length)
		{
			var str:String = _colHints[X];
			var lng:Int = Math.floor(str.length / 2) - 1;
			//lng = str.length;
			var txt:FlxText = new FlxText(_sprBack.x + 48 + X * 10, _sprBack.y + 48, 14, str, 8);
			txt.y -= txt.height;
			_grpTexts.add(txt);
			
		}
	
	
		// sets all of the elements to stay centered to the current camera location
		for(text in _grpTexts) 
			text.scrollFactor.set();
		for(spr in _grpSprites) 
			spr.scrollFactor.set();
		for(pX in _grpPicross) 
			pX.scrollFactor.set();
		for(cursor in _grpCursor) 
			cursor.scrollFactor.set();		
	}
	
	private function calcRowHints(Row:Array<Int>):Void
	{
		var count:Int = 0;
		var str:String = "";
		for (cell in Row)
		{
			if (cell == 1)
			{
				count++;
			}
			else
			{
				if (count != 0)
				{
					str += " " + count;
					count = 0;
				}
			}
		}
		if (count != 0)  // have to do this one more time because it won't otherwise check after the last cell
		{
			str += " " + count;
		}
		_rowHints.push(str);
	}
	
	private function calcColHints(Col:Array<Array<Int>>):Void
	{
		var count:Int = 0;
		var str:String = "";
		
		for (i in 0...Col.length)
		{
			str = "";
			for (row in Col)
			{
				if (row[i] == 1)
				{
					count++;
				}
				else
				{
					if (count != 0)
					{
						str += "\n" + count;
						count = 0;
					}
				}
			}
			if (count != 0)  // have to do this one more time because it won't otherwise check after the last cell
			{
				str += "\n" + count;
				count = 0;
			}
			_colHints.push(str);	
		}
	}
	
	
	
	public override function update()
	{
		// timer buisness
		if (_txtMessage.text != "")
			_msgTimer -= FlxG.elapsed;
		if (_msgTimer <= 0)
			_txtMessage.text = "";

		if (!isVictoly && !isEscaped && !isDefeat)
		{
		
		// this block is basically resolveAnimations()
		// TODO: make it resolveAnimations() if you add a 3rd animation to resolve
		if (_mcHurtTimer > 0)
			{
				_mcHurtTimer -= FlxG.elapsed;
				_sprPlayer.animation.play("dead");
			}
		else
			_sprPlayer.animation.play("idle");
		
			if (!Reg.isMuted)
				songBattle.play();
			else 
				songBattle.pause();
		}
		if (!Reg.isMuted)
		{
			if (isVictoly)
			{
				songBattle.pause();
				songFanfare.play();
			}
			else if (isDefeat)
			{
				songBattle.pause();
				songLost.play();			
			}
		}
		else
		{
			songFanfare.pause();
			songLost.pause();
		}
		_txtHP.text = "MP: " + Math.floor(_mp);
		
		// cursor movement
		if (!isEscaped && !isVictoly && !isDefeat)
		{
			if (FlxG.keys.anyJustPressed(["UP", "W"]))
			{
				if (_sprCursor.y <= _sprBack.y + 48)
					_sprCursor.y = _sprBack.y + 48 + (_rowArray.length - 1) * 10  // look, ma, no semicolon! 
				else
					_sprCursor.y -= 10;
			}
			if (FlxG.keys.anyJustPressed(["DOWN", "S"]))
			{
				if (_sprCursor.y >= _sprBack.y + 48 + (_rowArray.length - 1) * 10)
					_sprCursor.y = _sprBack.y + 48;
				else
					_sprCursor.y += 10;
			}		
			if (FlxG.keys.anyJustPressed(["LEFT", "A"]))
			{
				if (_sprCursor.x <= _sprBack.x + 48)
					_sprCursor.x = _sprBack.x + 48 + (_rowArray.length - 1) * 10;
				else
					_sprCursor.x -= 10;
			}
			if (FlxG.keys.anyJustPressed(["RIGHT", "D"]))
			{
				if (_sprCursor.x >= _sprBack.x + 48 + (_rowArray.length - 1) * 10)
					_sprCursor.x = _sprBack.x + 48;
					else
					_sprCursor.x += 10;
			}
			
			// mark a square as good
			if (FlxG.keys.anyJustPressed(["J", "ENTER", "SPACE"]))
			{
				for (cell in _grpPicross)
				{
					if (_sprCursor.x == cell.x && _sprCursor.y == cell.y)
					{
						var result:Int = cell.turnOnOrOff(PicrossSquare.ON);
						switch (result)
						{
							case PicrossSquare.CORRECT:
								_curCount++;
							case PicrossSquare.GOODHURT:
							{
								_curCount++;
								takeDamage();
							}
							case PicrossSquare.HURT:
							{
								//deadCheck();
								takeDamage();
							}
						}
						break;
					}
				}
			}
			
			// mark a square as marked
			if (FlxG.keys.anyJustPressed(["K", "BACKSLASH"]))
			{
				for (cell in _grpPicross)
				{
					if (_sprCursor.x == cell.x && _sprCursor.y == cell.y)
					{
						var result:Int = cell.turnOnOrOff(PicrossSquare.MARK);
						
						switch (result)
						{
							case PicrossSquare.CORRECT:
								_curCount++;
							case PicrossSquare.GOODHURT:
							{
								_curCount++;
								takeDamage();
							}
							case PicrossSquare.HURT:
								takeDamage();
						}
					}
				}
			}	
		}
		
		// if you die
		if (_mp <= 0)
		{
			_mp = 0;
			if (!isDefeat)
			{
				_sprPlayer.animation.play("dead");
				_txtMessage.text = "You got stumped on, kid.";
				_msgTimer = _msgDuration;
				isDefeat = true;
			}
			else if (isDefeat && _txtMessage.text == "")
			{
				Reg.resetEncounterCounter();
				this.close();
			}
		}
		
		// if you win
		if (_curCount == _winCount)
		{
			if (!isVictoly)
			{
				_sprEnemy.animation.play("dead");
				_sprPlayer.animation.play("idle");
				_txtMessage.text = "YOU DEFEATED";
				_msgTimer = _msgDuration;
				isVictoly = true;
			}
			else if (isVictoly && _txtMessage.text == "")
			{
				Reg.resetEncounterCounter();
				Reg.AddXP(2 + 3 * _enemyID);
				this.close();
			}
		}
		
		// if you run
		if (FlxG.keys.anyPressed(["ESCAPE"]))
		{
			if (!isEscaped)
			{
				_txtMessage.text = "Escaping...";
				_msgTimer = _msgDuration;
				isEscaped = true;
			}
		}
		if (isEscaped && _txtMessage.text == "")
		{
			Reg.resetEncounterCounter();
			//Reg.AddXP(3 + 2 * _enemyID);
			this.close();
		}
		
		if (FlxG.keys.anyJustPressed(["M"]))
			Reg.muteToggle();
		
		super.update();
	}
	
	override public function close():Void
	{
		songBattle.stop();
		songFanfare.stop();
		songLost.stop();
		super.close();
	}
	
	private function takeDamage():Void
	{
		_mp -= 10 * (_enemyID + 1);
		_txtMessage.text = " ";
		_txtMessage.text = "Suffered " + 10 * (_enemyID + 1) + " damages.";
		_msgTimer = _msgDuration;
		_mcHurtTimer = _mcHurtDuration;
	}

}
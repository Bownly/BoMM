package;

/**
 * ...
 * @author ...
 */
class Level2 extends PlayState
{

	public function new(clr:Int) 
	{
		super(clr);
		
		levelId = "2";
		tileName = "assets/images/forest_tiles.png";
		nonCollidableTiles = [6, 18, 19, 20, 21, 22, 23, 30, 33, 42, 45];
		_numRooms = 1;

	}
	
}
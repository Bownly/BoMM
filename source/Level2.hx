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
		nonCollidableTiles = [6, 18, 19, 20, 21, 22, 23, 30, 31, 32, 33, 42, 43, 44, 45, 55];
		_numRooms = 21;
		_numEarliestRoom = 1;
		_numUniqueRooms = 10;


	}
	
}
package;

/**
 * ...
 * @author ...
 */
class Level3 extends PlayState
{

	public function new(clr:Int) 
	{
		super(clr);
		
		levelId = "3";
		tileName = "assets/images/sky_tiles.png";
		nonCollidableTiles = [14];
		_numRooms = 5;
		_numUniqueRooms = 4;
		_numEarliestRoom = 4;

	}
	
}
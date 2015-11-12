package;

/**
 * ...
 * @author ...
 */
class Level1 extends PlayState
{

	public function new(Color:Int) 
	{
		super(Color);
		
		levelId = "1";
		tileName = "assets/images/cave_tiles.png";
		nonCollidableTiles = [21, 33, 45, 43, 47];
		_numRooms = 20;
		_numUniqueRooms = 20;
	}
	
}
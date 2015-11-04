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

		tileName = "assets/images/wood_tiles_persist.png";
		tileName = "assets/images/cave_grass_tiles.png";
		tileName = "assets/images/cave_tiles.png";
	}
	
}
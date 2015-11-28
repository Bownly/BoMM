package;

/**
 * ...
 * @author ...
 */
class Town1 extends TownState
{

	public function new() 
	{
		super();
		
		levelName = "assets/levels/town_1.oel";
		tileName = "assets/images/tiles_town.png";
		nonCollidableTiles = [0, 1, 2, 3, 4, 5, 6];
		worldMapPosX = 16;
		worldMapPosY = 432;
	}
	
}
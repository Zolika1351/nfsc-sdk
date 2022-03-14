#include "../../../include/CarbonSDK.cpp"

// this will run each frame outside menus if the game isn't paused
void scriptMain()
{
	// force player heat to 5x if the player car is an RX8
	if (auto ply = PlayerList.Get(0))
	{
		if (auto simable = ply->GetSimable())
		{
			auto veh = (PVehicle*)simable->GetParent(); // a simable's parent is a PhysicsObject, the player's one is always a PVehicle
			if (veh->m_sVehicle.GetVehicleKey() == stringhash32("rx8")) // NOTE: stringhash32 is case sensitive!
			{
				Game_SetWorldHeat(5);
			}
		}
	}
}

// this will run in both menus and in-game, as well as the pause menu
void worldMain()
{
	// set all cars to a random LOD level every frame (LOD ranges from 0-4, 0 being the highest and 4 being the lowest, set it to -1 to disable forced LOD)
	ForceCarLOD = rand() % 5;
}

// add events and other initialization code here
void plugin::gameStartupEvent()
{
	plugin::processWorldEvent::Add(worldMain);
	plugin::processSimSystemEvent::Add(scriptMain);
}
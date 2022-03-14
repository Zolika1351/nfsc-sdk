#include "../../../include/CarbonSDK.cpp"

void SetCarDamage(IVehicle* veh, float damage)
{
	// find the vehicle's IDamageable
	if (auto damageable = veh->m_pList->Find<IDamageable>())
	{
		// set the DamageVehicle's damage value
		damageable->GetParent<DamageVehicle>()->m_fDamage = damage;
	}
}

// this will run each frame outside menus if the game isn't paused
void scriptMain()
{
	// force player heat to 5x if the player car is an RX8, or destroy it if it's an M3 GTR
	if (auto ply = PlayerList.Get(0))
	{
		// get the player's simable
		if (auto simable = ply->GetSimable())
		{
			// get the vehicle
			if (auto veh = simable->m_pList->Find<IVehicle>())
			{
				// NOTE: stringhash32 is case sensitive!
				if (veh->GetVehicleKey() == stringhash32("rx8")) Game_SetWorldHeat(5);
				if (veh->GetVehicleKey() == stringhash32("bmwm3gtre46")) SetCarDamage(veh, 1);
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
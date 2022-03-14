#include "../../../include/CarbonSDK.cpp"

// this will run each frame outside menus if the game isn't paused
void scriptMain()
{
	// make all cars spin
	// first loop through the vehicle list
	for (int i = 0; i < VehicleList.mSize; i++)
	{
		if (auto veh = VehicleList.Get(i))
		{
			// get the physics state from the car simable's rigidbody
			if (auto state = *veh->GetParent()->m_sSimable.GetRigidBody()->m_pPhysicsState)
			{
				// set the turn velocity
				state->m_vTurnVelocity = { 1,1,1 };
			}
		}
	}

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
	// set all cars to a random LOD level every frame (LOD ranges from 0-4, 0 being the highest and 4 being the lowest)
	ForceCarLOD = rand() % 5;
}

// this runs right before the game finishes drawing, anything drawn here will display above all game UI
void drawingMain()
{
	// draw a 100x100 black square in the top left of the screen
	gD3DDevice->Clear(1, new D3DRECT{ 0, 0, 100, 100 }, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 0, 0);
}

// add events and other initialization code here
void plugin::gameStartupEvent()
{
	plugin::processWorldEvent::Add(worldMain);
	plugin::processSimSystemEvent::Add(scriptMain);
	plugin::drawingEvent::Add(drawingMain);
}
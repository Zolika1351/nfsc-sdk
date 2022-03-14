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
			// get the car's rigidbody
			if (auto rb = veh->m_pList->Find<IRigidBody>())
			{
				// get the physics state from the rigidbody
				if (auto state = rb->GetParent<RBVehicle>()->m_pPhysicsState[0])
				{
					// set the turn velocity
					state->m_vTurnVelocity = { 1,1,1 };
				}
			}
		}
	}
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
	plugin::processSimSystemEvent::Add(scriptMain);
	plugin::drawingEvent::Add(drawingMain);
}
#define VALIDATE_SIZE(struc, size) static_assert(sizeof(struc) == size, "Invalid structure size of " #struc)
#define VALIDATE_OFFSET(struc, member, offset) \
	static_assert(offsetof(struc, member) == offset, "The offset of " #member " in " #struc " is not " #offset "...")

namespace plugin
{
	uint32_t gBaseAddress = (uint32_t)GetModuleHandle(NULL);
	void gameStartupEvent();
}

#include "UMath.h"
#include "Engine.h"
#include "UTL.h"
#include "eModel.h"
#include "Timer.h"
#include "HUD.h"
#include "Sim.h"
#include "CameraAI.h"
#include "Object.h"
#include "Entity.h"
#include "IRigidBody.h"
#include "ISimable.h"
#include "GameFlowManager.h"
#include "Game.h"
#include "ActionQueue.h"
#include "PhysicsObject.h"
#include "AITrafficManager.h"
#include "Attrib.h"
#include "IPursuitAI.h"
#include "AIPursuit.h"
#include "ITrafficAI.h"
#include "FeGarageMain.h"
#include "DALFeVehicle.h"
#include "FECarRecord.h"
#include "FECustomizationRecord.h"
#include "FEPlayerCarDB.h"
#include "FEManager.h"
#include "ITransmission.h"
#include "ISuspension.h"
#include "IInput.h"
#include "IVehicle.h"
#include "PVehicle.h"
#include "IInputPlayer.h"
#include "IPerpetrator.h"
#include "IVehicleAI.h"
#include "AIVehicle.h"
#include "IDamageable.h"
#include "DamageVehicle.h"
#include "IEngineDamage.h"
#include "IEngine.h"
#include "EngineRacer.h"
#include "IPlayer.h"
#include "RecordablePlayer.h"
#include "RaceStarter.h"
#include "Camera.h"
#include "TrackInfo.h"
#include "Explosion.h"
#include "Lists.h"
#include "Draw.h"
#include "DebugVehicleSelection.h"
#include "GCareer.h"
#include "FacePixelation.h"
#include "eViewPlatInterface.h"
#include "LoadingScreenBase.h"
#include "DALVehicle.h"
#include "GrandSceneryCullInfo.h"
#include "GRaceStatus.h"
#include "AICopManager.h"
#include "ISpikeable.h"
#include "EAXSound.h"
#include "AIWingman.h"
#include "WCollisionMgr.h"
#include "GTrigger.h"
#include "WCollisionTri.h"
#include "WCollisionBarrier.h"
#include "WCollider.h"
#include "FEObject.h"
#include "SlotPool.h"
#include "GRaceParameters.h"
#include "IResetable.h"

auto& CarLoaderPoolSizes = *(uint32_t*)0xA62C48;
auto& EnableReleasePrintf = *(bool*)0xA85340;

void InitQueuedFiles()
{
	((void(__cdecl*)())0x69B8D0)();
}

auto& Tweak_CanyonRaceUseDrop = *(bool*)0xA610DA;
auto& Tweak_ManualShift = *(bool*)0xA83A6E;
class IVehicleCache { uint8_t pad[0x4]; };
class WRoadNav { uint8_t pad[0x4]; };

class AITrafficManager
{
public:
	uint8_t pad[0x48];						// 00-48
	IVehicleCache m_nCache;					// 48-4C
};
VALIDATE_OFFSET(AITrafficManager, m_nCache, 0x48);
class AICopManager
{
public:
	uint8_t pad[0x54];						// 00-54
	IVehicleCache m_nCache;					// 54-4C
};
VALIDATE_OFFSET(AICopManager, m_nCache, 0x54);

AICopManager*& TheOneCopManager = *(AICopManager**)0xA83A58;
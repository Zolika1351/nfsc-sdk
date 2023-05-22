class AICopManager
{
public:
	uint8_t pad[0x54];						// 00-54
	IVehicleCache m_nCache;					// 54-58
	uint8_t pad2[0x30];						// 58-88
	uint32_t mMaxCopCars;					// 88-8C
	uint8_t pad3[0x4];						// 8C-90
	uint32_t mNumActiveCopCars;				// 90-94
	uint32_t mMaxActiveCopCars;				// 94-98
};

VALIDATE_OFFSET(AICopManager, m_nCache, 0x54);
VALIDATE_OFFSET(AICopManager, mMaxCopCars, 0x88);
VALIDATE_OFFSET(AICopManager, mNumActiveCopCars, 0x90);
VALIDATE_OFFSET(AICopManager, mMaxActiveCopCars, 0x94);

AICopManager*& TheOneCopManager = *(AICopManager**)0xA83A58;
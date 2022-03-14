class EngineRacer
{
public:
	uint8_t pad[0x4C];						// 000-04C
	IEngine m_sEngine;						// 04C-054
	uint8_t pad2[0x1C];						// 054-070
	IEngineDamage m_sEngineDamage;			// 070-078
	uint8_t pad3[0x78];						// 078-0F0
	float m_fNitro;							// 0F0-0F4
	uint8_t pad4[0x24];						// 0F4-118
	NOSData* m_pNOSData;					// 118-11C
};
VALIDATE_OFFSET(EngineRacer, m_sEngineDamage, 0x70);
VALIDATE_OFFSET(EngineRacer, m_fNitro, 0xF0);
VALIDATE_OFFSET(EngineRacer, m_pNOSData, 0x118);
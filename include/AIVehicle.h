class AIVehicle
{
public:
	uint8_t pad[0x40];							// 000-040
	IVehicle* m_pVehicle;						// 040-044
	IVehicleAI m_sAI;							// 044-04C

	void SetGoal(uint32_t* goalHash)
	{
		((void(__thiscall*)(AIVehicle*, uint32_t*))(*(void***)this)[60])(this, goalHash);
	}
};
VALIDATE_OFFSET(AIVehicle, m_sAI, 0x44);

class AIPerpVehicle : public AIVehicle
{
public:
	uint8_t pad3[0x90];							// 04C-0DC
	AIPursuit* m_pPursuit;						// 0DC-0E0
	uint8_t pad4[0x1C];							// 0E0-0FC
	void* m_pTransmission;						// 0FC-100
	uint8_t pad5[0x104];						// 100-204
	IPerpetrator m_sPerpetrator;				// 204-20C
	uint8_t pad[0x14];							// 20C-220
	float m_fHeatLevel;							// 220-224
	uint8_t pad2[0x4];							// 224-228
	int m_nCostToState;							// 228-22C
};
VALIDATE_OFFSET(AIPerpVehicle, m_pPursuit, 0xDC);
VALIDATE_OFFSET(AIPerpVehicle, m_pTransmission, 0xFC);
VALIDATE_OFFSET(AIPerpVehicle, m_sPerpetrator, 0x204);
VALIDATE_OFFSET(AIPerpVehicle, m_fHeatLevel, 0x220);
VALIDATE_OFFSET(AIPerpVehicle, m_nCostToState, 0x228);

class AIVehiclePursuit : public AIVehicle
{
public:
	uint8_t pad3[0x1B8];						// 070-204
	IPursuitAI m_sPursuitAI;					// 204-???
};
VALIDATE_OFFSET(AIVehiclePursuit, m_sPursuitAI, 0x204);

class AIVehicleHuman : public AIPerpVehicle
{
public:
	uint8_t pad[0x68];							// 22C-294
	IInputPlayer m_sInput;						// 294-29C
	bool m_bAIControl;							// 29C-29D
	uint8_t pad2[0x55];							// 29D-2F2
	bool m_bInputsBlocked;						// 2F2-2F3
	uint8_t pad3;								// 2F3-2F4

	void GoToGear(int gear)
	{
		((void(__thiscall*)(AIVehicle*, int))(0x419290))(this, gear);
	}
};
VALIDATE_SIZE(AIVehicleHuman, 0x2F4);
VALIDATE_OFFSET(AIVehicleHuman, m_sInput, 0x294);
VALIDATE_OFFSET(AIVehicleHuman, m_bAIControl, 0x29C);
VALIDATE_OFFSET(AIVehicleHuman, m_bInputsBlocked, 0x2F2);
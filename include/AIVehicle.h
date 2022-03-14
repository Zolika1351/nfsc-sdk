class AIVehicle;

class IPerpetrator
{
public:
	uint8_t pad[0x1C];							// 00-1C
	float m_fHeatLevel;							// 1C-20
	uint8_t pad2[0x4];							// 20-24
	int m_nCostToState;							// 24-28

	float GetHeat()
	{
		((void(__thiscall*)(IPerpetrator*))(*(void***)this)[1])(this);
	}
	void SetHeat(float heat)
	{
		((void(__thiscall*)(IPerpetrator*, float))(*(void***)this)[2])(this, heat);
	}
};
VALIDATE_OFFSET(IPerpetrator, m_nCostToState, 0x24);

class IVehicleAI
{
public:
	uint8_t pad[0x8];							// 00-08

	template<typename T>
	inline T* GetAIVehicle()
	{
		return (T*)(((uintptr_t)this) - 0x44);
	}
	ISimable* GetSimable()
	{
		return ((ISimable*(__thiscall*)(IVehicleAI*))(*(void***)this)[1])(this);
	}
	void SetSpawned()
	{
		((void(__thiscall*)(IVehicleAI*))(*(void***)this)[37])(this);
	}
	IVehicle* GetWingman()
	{
		return ((IVehicle*(__thiscall*)(IVehicleAI*))(*(void***)this)[50])(this);
	}
	AIPursuit* GetPursuit()
	{
		return ((AIPursuit*(__thiscall*)(IVehicleAI*))(*(void***)this)[44])(this);
	}

	// warp car to a random nav point
	void ResetVehicleToRoadNav(WRoadNav* nav)
	{
		((void(__thiscall*)(IVehicleAI*, WRoadNav*))(*(void***)this)[22])(this, nav);
	}
};

class AIVehicle
{
public:
	uint8_t pad[0x40];							// 000-040
	IVehicle* m_pVehicle;						// 040-044
	IVehicleAI m_sAI;							// 044-04C

	// directly
	void _SetGoal(uint32_t* goalHash)
	{
		((void(__thiscall*)(AIVehicle*, uint32_t*))(0x427A60))(this, goalHash);
	}
	// from vft
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
	IPerpetrator m_sPerpetrator;				// 204-22C
};
VALIDATE_OFFSET(AIPerpVehicle, m_pPursuit, 0xDC);
VALIDATE_OFFSET(AIPerpVehicle, m_pTransmission, 0xFC);
VALIDATE_OFFSET(AIPerpVehicle, m_sPerpetrator, 0x204);

class AIVehiclePursuit : public AIVehicle
{
public:
	uint8_t pad3[0x1B8];						// 070-204
	IPursuitAI m_sPursuitAI;					// 204-???
};
VALIDATE_OFFSET(AIVehiclePursuit, m_sPursuitAI, 0x204);

class IInputPlayer
{
public:
	uint8_t pad[0x8];							// 00-08
};

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
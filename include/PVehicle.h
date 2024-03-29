class IVehicleAI;
class IDamageable;
class IEngine;

enum DriverClass
{
	DRIVER_HUMAN,
	DRIVER_TRAFFIC,
	DRIVER_COP,
	DRIVER_RACER,
	DRIVER_NONE
};

enum DriverStyle
{
	STYLE_RACING,
	STYLE_DRAG,
	STYLE_DRIFT,
	STYLE_HIGH_SPEED,
	STYLE_TRAFFIC
};

class PVehicle : public PhysicsObject
{
public:
	uint8_t pad2[0x88];							// 030-0B8
	IVehicle m_sVehicle;						// 0B8-0C0
	uint8_t pad3[0x38];							// 0C0-0F8
	IEngine* mEngine;							// 0F8-0FC
	IDamageable* mDamage;						// 0FC-100
	uint8_t pad4[0x4];							// 100-104
	IVehicleAI* mAI;							// 104-108
	uint8_t pad5[0x40];							// 108-148
	uint32_t mDriverClass;						// 148-14C
	uint32_t mDriverStyle;						// 14C-150
	uint32_t mGlareState;						// 150-154
	uint8_t pad6[0x90];							// 154-1E4

	void _dtor(bool a1)
	{
		((void(__thiscall*)(PVehicle*, bool))(*(void***)this)[1])(this, a1);
	}

	// originals:										 
	// 9FB193F0 0 -> stringhash32("VehicleParams")		 
	// 0019FABC 4 -> ptr to 9FB193F0					 
	// 00000006 8 -> unk								 
	// 00000000 C -> unk								 
	// 00000001 10 -> driver class?						 
	// 03CFDE70 14 -> rx8 -> 03CF4590					
	// 0B6B9E50 18 -> some struct						 
	// 00000000 1C -> unk								 
	// 00000000 20 -> unk								 
	// 0019FAA4 24 -> &Vector {0,0,1}					 
	// 0019FAB0 28 -> &Vector3 {0,0,0}					 
	// 00000000 2C -> FECustomizationRecord				 
	// 038884E8 30 -> AITrafficManager::IVehicleCache	 
	// 00000000 34 -> unk								 
	// 00000000 38 -> unk								 
	// 0019FE50 3C -> 0019FEBC -> 0019FEFC				 
	// 00993078 40 -> return address, end of stack		 

	struct VehicleParams
	{
		uint32_t m_nTypeHash = stringhash32("VehicleParams");			// 00-04
		uint32_t* m_pTypeHash = &m_nTypeHash;							// 04-08
		uint32_t pad = 6;												// 08-0C
		uint32_t pad2 = 0;												// 0C-10
		uint32_t m_nAIType = 0;											// 10-14
		Attrib::Instance m_nModel;										// 14-24
		UMath::Vector3* initialVec = nullptr;							// 24-28
		UMath::Vector3* initialPos = nullptr;							// 28-2C
		VehicleCustomizations* m_pCustomizationRecord = nullptr;		// 2C-30
		IVehicleCache* VehicleCache = nullptr;							// 30-34
		uint32_t matched = 0;											// 34-38
		uint32_t Flags = 0;												// 38-3C
		uint32_t pad5 = 0;												// 3C-40
	};
	VALIDATE_OFFSET(VehicleParams, m_nAIType, 0x10);
	VALIDATE_OFFSET(VehicleParams, m_nModel, 0x14);
	VALIDATE_OFFSET(VehicleParams, initialVec, 0x24);
	VALIDATE_OFFSET(VehicleParams, m_pCustomizationRecord, 0x2C);
	VALIDATE_OFFSET(VehicleParams, VehicleCache, 0x30);

	static void GetModel(Attrib::Instance* mdl, uint32_t hash, int unk)
	{
		return ((void(__thiscall*)(Attrib::Instance*, uint32_t, int))0x412520)(mdl, hash, unk);
	}

	static ISimable* Construct(uint32_t typeHash, VehicleParams* params)
	{
		return ((ISimable*(__cdecl*)(uint32_t, VehicleParams*))0x6DAA80)(typeHash, params);
	}

	class AttribData
	{
	public:
		uint8_t pad[0x24];							// 00-24
		char* m_sName;								// 24-28
	};
};
VALIDATE_SIZE(PVehicle, 0x1E4);
VALIDATE_OFFSET(PVehicle::AttribData, m_sName, 0x24);
VALIDATE_OFFSET(PVehicle, m_sSimable, 0x24);
VALIDATE_OFFSET(PVehicle, m_sVehicle, 0xB8);
VALIDATE_OFFSET(PVehicle, mDamage, 0xFC);
VALIDATE_OFFSET(PVehicle, mEngine, 0xF8);
VALIDATE_OFFSET(PVehicle, mAI, 0x104);
VALIDATE_OFFSET(PVehicle, mDriverClass, 0x148);
VALIDATE_OFFSET(PVehicle, mGlareState, 0x150);
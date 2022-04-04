class IVehicleAI;
class IDamageable;
class IEngine;

class PVehicle : public PhysicsObject
{
public:
	uint8_t pad2[0x88];							// 030-0B8
	IVehicle m_sVehicle;						// 0B8-0C0
	uint8_t pad3[0x38];							// 0C0-0F8
	IEngine* m_pEngine;							// 0F8-0FC
	IDamageable* m_pDamageable;					// 0FC-100
	uint8_t pad4[0x4];							// 100-104
	IVehicleAI* m_pVehicleAI;					// 104-108
	uint8_t pad5[0x40];							// 108-148
	uint32_t m_nDriverClass;					// 148-14C
	uint32_t m_nDriverStyle;					// 14C-150
	uint8_t pad6[0x94];							// 150-1E4

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
		UMath::Vector3* m_pRotation = nullptr;							// 24-28
		UMath::Vector3* m_pPosition = nullptr;							// 28-2C
		VehicleCustomizations* m_pCustomizationRecord = nullptr;		// 2C-30
		IVehicleCache* m_pVehicleCache = nullptr;						// 30-34
		uint32_t pad4 = 0;												// 34-38
		uint32_t m_nFlags = 0;											// 38-3C
		uint32_t pad5 = 0;												// 3C-40
	};
	VALIDATE_OFFSET(VehicleParams, m_nAIType, 0x10);
	VALIDATE_OFFSET(VehicleParams, m_nModel, 0x14);
	VALIDATE_OFFSET(VehicleParams, m_pRotation, 0x24);
	VALIDATE_OFFSET(VehicleParams, m_pCustomizationRecord, 0x2C);
	VALIDATE_OFFSET(VehicleParams, m_pVehicleCache, 0x30);

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
VALIDATE_OFFSET(PVehicle, m_pDamageable, 0xFC);
VALIDATE_OFFSET(PVehicle, m_pEngine, 0xF8);
VALIDATE_OFFSET(PVehicle, m_pVehicleAI, 0x104);
VALIDATE_OFFSET(PVehicle, m_nDriverClass, 0x148);
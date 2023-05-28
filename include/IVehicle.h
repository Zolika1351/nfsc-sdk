class IVehicleAI;
class PVehicle;

class IVehicle : public UTL::COM::Object
{
public:
	inline PVehicle* GetParent()
	{
		return (PVehicle*)(((uintptr_t)this) - 0xB8);
	}

	bool GetTrafficAI(ITrafficAI** ai)
	{
		return ((bool(__thiscall*)(IVehicle*, ITrafficAI**))(0x40E6A0))(this, ai);
	}

	bool IsStaging()
	{
		return ((bool(__thiscall*)(IVehicle*))(*(void***)this)[9])(this);
	}

	// 0: normal, 2: drift
	void SetDriverStyle(int style)
	{
		((void(__thiscall*)(IVehicle*, int))(*(void***)this)[12])(this, style);
	}

	void* GetVehicleClass()
	{
		return ((void*(__thiscall*)(IVehicle*))(*(void***)this)[21])(this);
	}

	char* GetVehicleName()
	{
		return ((char*(__thiscall*)(IVehicle*))(*(void***)this)[23])(this);
	}

	uint32_t GetVehicleKey()
	{
		return ((uint32_t(__thiscall*)(IVehicle*))(*(void***)this)[24])(this);
	}

	bool IsLoading()
	{
		return ((bool(__thiscall*)(IVehicle*))(*(void***)this)[28])(this);
	}
	
	void Activate()
	{
		((void(__thiscall*)(IVehicle*))(*(void***)this)[37])(this);
	}
	
	void Deactivate()
	{
		((void(__thiscall*)(IVehicle*))(*(void***)this)[38])(this);
	}

	bool IsActive()
	{
		return ((bool(__thiscall*)(IVehicle*))(*(void***)this)[39])(this);
	}

	void SetDriverClass(int id)
	{
		((void(__thiscall*)(IVehicle*, int))(*(void***)this)[26])(this, id);
	}

	int GetDriverClass()
	{
		return ((int(__thiscall*)(IVehicle*))(*(void***)this)[27])(this);
	}

	IVehicleAI* GetAIVehiclePtr()
	{
		return ((IVehicleAI*(__thiscall*)(IVehicle*))(*(void***)this)[48])(this);
	}

	static uint32_t IHandle() { return 0x403D30; };
};
VALIDATE_SIZE(IVehicle, 0x8);
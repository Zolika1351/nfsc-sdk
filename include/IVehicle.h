class IVehicleAI;
class PVehicle;

class IVehicle
{
public:
	uint8_t pad[0x8];							// 00-08

	inline PVehicle* GetParent()
	{
		return (PVehicle*)(((uintptr_t)this) - 0xB8);
	}

	bool GetTrafficAI(ITrafficAI** ai)
	{
		return ((bool(__thiscall*)(IVehicle*, ITrafficAI**))(0x40E6A0))(this, ai);
	}

	void* GetVehicleClass()
	{
		return ((void*(__thiscall*)(IVehicle*))(*(void***)this)[21])(this);
	}

	char* GetVehicleName()
	{
		return ((char*(__thiscall*)(IVehicle*))(*(void***)this)[23])(this);
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
};
VALIDATE_SIZE(IVehicle, 0x8);
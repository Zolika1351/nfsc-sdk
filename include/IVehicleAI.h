class IVehicleAI : public UTL::COM::Object
{
public:
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

	static uint32_t IHandle() { return 0x4036A0; };
};

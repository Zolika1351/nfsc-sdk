class DALFeVehicle
{
public:
	static bool GetQuickRaceCarHandle(int* handle, int id)
	{
		return ((bool(__stdcall*)(int*, int))(0x4A2FA0))(handle, id);
	}

	static bool GetCarHandleByIndex(int* handle, int id, uint32_t flags)
	{
		return ((bool(__stdcall*)(int*, int, uint32_t))(0x4A3070))(handle, id, flags);
	}
};
class DALVehicle
{
public:
	static void GetIsPlayerControlling(int* ret, int id)
	{
		((bool(__stdcall*)(int*, int))(0x4C3540))(ret, id);
	}

	static void GetIsDrivingCamera(int* ret, int id)
	{
		((bool(__stdcall*)(int*, int))(0x4B6D50))(ret, id);
	}

	static void GetIsHudVisible(int* ret, int id)
	{
		((bool(__stdcall*)(int*, int))(0x4B6DA0))(ret, id);
	}
};
class FeGarageMain
{
public:
	static void SetRideInfo(int handle)
	{
		((void(__stdcall*)(int))0x85EB20)(handle);
	}
};
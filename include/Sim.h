namespace Sim
{
	int GetUserMode()
	{
		return ((bool(__cdecl*)())0x75CF70)();
	}
	bool Exists()
	{
		return ((bool(__cdecl*)())0x75CDF0)();
	}
	double GetTime()
	{
		return ((double(__cdecl*)())0x75CF60)();
	}
	double GetTimeStep()
	{
		return ((double(__cdecl*)())0x75CF20)();
	}
}
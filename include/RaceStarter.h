class RaceStarter
{
public:
	static void StartCareerFreeRoam(int unk)
	{
		((void(__cdecl*)(int))0x7A9D20)(unk);
	}
	static void StartRace(const char* eventName, const int entryPoint)
	{
		((void(__cdecl*)(const char*, const int))0x7CA1F0)(eventName, entryPoint);
	}
	static void StartRace(int eventHash, const int entryPoint)
	{
		((void(__cdecl*)(int, const int))0x7BBED0)(eventHash, entryPoint);
	}
};
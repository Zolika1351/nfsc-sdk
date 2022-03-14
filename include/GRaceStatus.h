class GRaceStatus
{
public:
	int GetRacerCount()
	{
		return ((int(__thiscall*)(GRaceStatus*))0x612230)(this);
	}
	int GetRaceType()
	{
		return ((int(__thiscall*)(GRaceStatus*))0x6136A0)(this);
	}

	static inline GRaceStatus*& fObj = *(GRaceStatus**)0xA98284;
};
class GRaceStatus
{
public:
	void ClearCheckpoints()
	{
		((void(__thiscall*)(GRaceStatus*))0x634170)(this);
	}
	void StopMasterTimer()
	{
		((void(__thiscall*)(GRaceStatus*))0x624F30)(this);
	}
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
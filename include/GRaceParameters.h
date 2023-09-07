class GRaceParameters
{
public:
	int GetNumOpponents()
	{
		return ((int(__thiscall*)(GRaceParameters*))0x63C660)(this);
	}
	void* GetOpponentChar(int id)
	{
		return ((void* (__thiscall*)(GRaceParameters*, int))0x63F630)(this, id);
	}
};
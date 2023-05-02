class EAXSound
{
public:

	void ReStartRace(bool is321)
	{
		((void(__thiscall*)(EAXSound*, bool))0x516910)(this, is321);
	}
};
EAXSound*& g_pEAXSound = *(EAXSound**)0xA8BA38;

void SetSoundControlState(char value, int type)
{
	((void(__cdecl*)(char, int))0x50C370)(value, type);
}
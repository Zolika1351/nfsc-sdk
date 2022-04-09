class ISpikeable : public UTL::COM::Object
{
public:
	int GetTireDamage(int tire) { return ((int(__thiscall*)(ISpikeable*, int))(*(void***)this)[1])(this, tire); }
	int GetNumBlowouts() { return ((int(__thiscall*)(ISpikeable*))(*(void***)this)[2])(this); }
	void Puncture(int tire) { ((void(__thiscall*)(ISpikeable*, int))(*(void***)this)[3])(this, tire); }

	static uint32_t IHandle() { return 0x6DE150; };
};
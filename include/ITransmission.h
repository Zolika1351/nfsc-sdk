class ITransmission : public UTL::COM::Object
{
public:
	int GetGear() { return ((int(__thiscall*)(ITransmission*))(*(void***)this)[1])(this); }
	int GetTopGear() { return ((int(__thiscall*)(ITransmission*))(*(void***)this)[2])(this); }
	void Shift(int gear) { ((void(__thiscall*)(ITransmission*, int))(*(void***)this)[3])(this, gear); }
	bool IsGearChanging() { return ((bool(__thiscall*)(ITransmission*))(*(void***)this)[4])(this); }
	bool IsReversing() { return ((bool(__thiscall*)(ITransmission*))(*(void***)this)[5])(this); }

	static uint32_t IHandle() { return 0x403C80; }
};
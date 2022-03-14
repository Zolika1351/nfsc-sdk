class IEngineDamage : public UTL::COM::Object
{
public:
	bool IsBlown()
	{
		return ((bool(__thiscall*)(IEngineDamage*))(*(void***)this)[1])(this);
	}
	void Blow()
	{
		((void(__thiscall*)(IEngineDamage*))(*(void***)this)[2])(this);
	}
	void Sabotage(float unk)
	{
		((void(__thiscall*)(IEngineDamage*, float))(*(void***)this)[3])(this, unk);
	}
	bool IsSabotaged()
	{
		return ((bool(__thiscall*)(IEngineDamage*))(*(void***)this)[4])(this);
	}
	void Repair()
	{
		((void(__thiscall*)(IEngineDamage*))(*(void***)this)[5])(this);
	}
	
	static uint32_t IHandle() { return 0x4A9D00; }
};
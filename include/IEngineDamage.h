class IEngineDamage
{
public:
	uint8_t pad[0x8];										// 00-08

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
};
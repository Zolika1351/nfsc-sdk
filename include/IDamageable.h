class IDamageable
{
public:
	uint8_t pad[0x34];										// 00-34
	float m_fDamage;										// 34-38

	void SetInShock(float shock)
	{
		((void(__thiscall*)(IDamageable*, float))(*(void***)this)[2])(this, shock);
	}
	void SetShockForce(float force)
	{
		((void(__thiscall*)(IDamageable*, float))(*(void***)this)[2])(this, force);
	}
	float InShock()
	{
		return ((float(__thiscall*)(IDamageable*))(*(void***)this)[3])(this);
	}
	void ResetDamage()
	{
		((void(__thiscall*)(IDamageable*))(*(void***)this)[4])(this);
	}
	float GetHealth()
	{
		return ((float(__thiscall*)(IDamageable*))(*(void***)this)[5])(this);
	}
	bool IsDestroyed()
	{
		return ((bool(__thiscall*)(IDamageable*))(*(void***)this)[6])(this);
	}
	void Destroy()
	{
		((void(__thiscall*)(IDamageable*))(*(void***)this)[7])(this);
	}
};
VALIDATE_OFFSET(IDamageable, m_fDamage, 0x34);
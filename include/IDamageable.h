class IDamageable : public UTL::COM::Object
{
public:
	template<typename T>
	inline T* GetParent()
	{
		return (T*)(((uintptr_t)this) - 0x44);
	}
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
	
	static uint32_t IHandle() { return 0x406040; }
};
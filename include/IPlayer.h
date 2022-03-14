class IPlayer : public UTL::COM::Object
{
public:
	template<typename T>
	inline T* GetParent()
	{
		return (T*)(((uintptr_t)this) - 0x44);
	}

	ISimable* GetSimable()
	{
		return ((ISimable*(__thiscall*)(IPlayer*))(*(void***)this)[1])(this);
	}

	static uint32_t IHandle() { return 0x66B460; }
};
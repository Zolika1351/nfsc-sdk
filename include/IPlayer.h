class IPlayer
{
public:
	uint8_t pad[0x8];						// 00-08

	template<typename T>
	inline T* GetParent()
	{
		return (T*)(((uintptr_t)this) - 0x44);
	}

	ISimable* GetSimable()
	{
		return ((ISimable*(__thiscall*)(IPlayer*))(*(void***)this)[1])(this);
	}
};
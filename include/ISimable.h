class PhysicsObject;

class ISimable
{
public:
	uint8_t pad[0xC];							// 00-0C

	inline PhysicsObject* GetParent()
	{
		return (PhysicsObject*)(((uintptr_t)this) - 0x24);
	}

	int GetSimableType()
	{
		return ((int(__thiscall*)(ISimable*))(*(void***)this)[1])(this);
	}

	void Kill()
	{
		((void(__thiscall*)(ISimable*))(*(void***)this)[2])(this);
	}

	void Attach(void* ptr)
	{
		((void(__thiscall*)(ISimable*, void*))(*(void***)this)[3])(this, ptr);
	}

	void Detach(void* ptr)
	{
		((void(__thiscall*)(ISimable*, void*))(*(void***)this)[4])(this, ptr);
	}

	IRigidBody* GetRigidBody()
	{
		return ((IRigidBody * (__thiscall*)(ISimable*))(*(void***)this)[20])(this);
	}
};
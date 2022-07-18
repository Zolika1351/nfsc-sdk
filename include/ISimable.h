class PhysicsObject;

class ISimable : public UTL::COM::Object
{
public:
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

	uint32_t GetOwnerHandle()
	{
		return ((uint32_t(__thiscall*)(ISimable*))(*(void***)this)[13])(this);
	}

	void* GetOwner()
	{
		return ((void* (__thiscall*)(ISimable*))(*(void***)this)[14])(this);
	}

	IRigidBody* GetRigidBody()
	{
		return ((IRigidBody*(__thiscall*)(ISimable*))(*(void***)this)[20])(this);
	}

	static uint32_t IHandle() { return 0x4040B0; };
};
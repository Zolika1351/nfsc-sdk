class WCollider;

class PhysicsState
{
public:
	UMath::Quaternion m_vRotation;				// 00-10
	UMath::Vector3 m_vPosition;					// 10-1C
	uint32_t pad2;								// 1C-20
	UMath::Vector3 m_vVelocity;					// 20-2C
	float m_fMass;								// 2C-30
	UMath::Vector3 m_vTurnVelocity;				// 30-3C
	float m_fOOMass;							// 3C-40
	uint8_t pad3[0x10];							// 40-50
	UMath::Vector3 m_vForce;					// 50-5C
	uint8_t pad4[0x2];							// 5C-5E
	uint16_t m_nIndex;							// 5E-60
	UMath::Vector3 m_vTorque;					// 60-6C
	float m_fRadius;							// 6C-70
	UMath::Matrix4 m_mMatrix;					// 70-B0
};
VALIDATE_OFFSET(PhysicsState, m_vRotation, 0x0);
VALIDATE_OFFSET(PhysicsState, m_vPosition, 0x10);
VALIDATE_OFFSET(PhysicsState, m_vVelocity, 0x20);
VALIDATE_OFFSET(PhysicsState, m_fMass, 0x2C);
VALIDATE_OFFSET(PhysicsState, m_vTurnVelocity, 0x30);
VALIDATE_OFFSET(PhysicsState, m_fOOMass, 0x3C);
VALIDATE_OFFSET(PhysicsState, m_vForce, 0x50);
VALIDATE_OFFSET(PhysicsState, m_nIndex, 0x5E);
VALIDATE_OFFSET(PhysicsState, m_vTorque, 0x60);
VALIDATE_OFFSET(PhysicsState, m_fRadius, 0x6C);
VALIDATE_OFFSET(PhysicsState, m_mMatrix, 0x70);

class IRigidBody : public UTL::COM::Object
{
public:
	template<typename T>
	inline T* GetParent()
	{
		return (T*)(((uintptr_t)this) - 0x40);
	}
	void SetPosition(UMath::Vector3* v)
	{
		((void(__thiscall*)(IRigidBody*, UMath::Vector3*))(*(void***)this)[23])(this, v);
	}
	void SetLinearVelocity(UMath::Vector3* v)
	{
		((void(__thiscall*)(IRigidBody*, UMath::Vector3*))(*(void***)this)[24])(this, v);
	}
	void SetAngularVelocity(UMath::Vector3* v)
	{
		((void(__thiscall*)(IRigidBody*, UMath::Vector3*))(*(void***)this)[25])(this, v);
	}
	void SetOrientation(UMath::Matrix4* mat)
	{
		((void(__thiscall*)(IRigidBody*, UMath::Matrix4*))(*(void***)this)[28])(this, mat);
	}
	void SetOrientation(UMath::Quaternion* quat)
	{
		((void(__thiscall*)(IRigidBody*, UMath::Quaternion*))(*(void***)this)[29])(this, quat);
	}

	static uint32_t IHandle() { return 0x403750; };
};

enum eInvulnerability
{
	INVULNERABLE_NONE,
	INVULNERABLE_FROM_MANUAL_RESET,
	INVULNERABLE_FROM_RESET,
	INVULNERABLE_FROM_CONTROL_SWITCH,
	INVULNERABLE_FROM_PHYSICS_SWITCH,
};

class IRBVehicle
{
public:
	uint8_t pad[0x4];

	void SetInvulnerability(int state, float time)
	{
		((void(__thiscall*)(IRBVehicle*, int, float))(*(void***)this)[5])(this, state, time);
	}
	int GetInvulnerability()
	{
		return ((int(__thiscall*)(IRBVehicle*))(*(void***)this)[6])(this);
	}

	static uint32_t IHandle() { return 0x403740; };
};

class RBVehicle
{
public:
	uint8_t pad[0x40];							// 000-040
	IRigidBody m_sRigidBody;					// 040-048
	uint8_t pad2[0x28];							// 048-070
	PhysicsState** m_pPhysicsState;				// 070-074
	uint8_t pad3[0x6C];							// 074-0E0
	WCollider* m_pCollider;						// 0E0-0E4
	uint8_t pad4[0x40];							// 0E4-124
	IRBVehicle m_sRBVehicle;					// 124-128
	uint8_t pad5[0xD8];							// 128-200
};
VALIDATE_SIZE(RBVehicle, 0x200);
VALIDATE_OFFSET(RBVehicle, m_sRigidBody, 0x40);
VALIDATE_OFFSET(RBVehicle, m_pPhysicsState, 0x70);
VALIDATE_OFFSET(RBVehicle, m_pCollider, 0xE0);
VALIDATE_OFFSET(RBVehicle, m_sRBVehicle, 0x124);

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
	uint32_t pad4;								// 5C-60
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

	static uint32_t IHandle() { return 0x403750; };
};

class RBVehicle
{
public:
	uint8_t pad[0x40];							// 000-040
	IRigidBody m_sRigidBody;					// 040-048
	uint8_t pad2[0x28];							// 048-070
	PhysicsState** m_pPhysicsState;				// 070-074
	uint8_t pad3[0x18C];						// 074-200
};
VALIDATE_SIZE(RBVehicle, 0x200);
VALIDATE_OFFSET(RBVehicle, m_sRigidBody, 0x40);
VALIDATE_OFFSET(RBVehicle, m_pPhysicsState, 0x70);

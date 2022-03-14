class PhysicsState
{
public:
	UMath::Vector3 m_vRotation;					// 00-0C
	uint32_t pad;								// 0C-10
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

class IRigidBody
{
public:
	uint8_t pad[0x30];							// 00-30
	PhysicsState** m_pPhysicsState;				// 30-34

	template<typename T>
	inline T* GetParent()
	{
		return (T*)(((uintptr_t)this) - 0x40);
	}
	void SetOrientation(UMath::Matrix4* mat)
	{
		((void(__thiscall*)(IRigidBody*, UMath::Matrix4*))(*(void***)this)[28])(this, mat);
	}
};
VALIDATE_OFFSET(IRigidBody, m_pPhysicsState, 0x30);

class RBVehicle
{
public:
	uint8_t pad[0x40];							// 000-040
	IRigidBody m_sRigidBody;					// 040-074
	uint8_t pad2[0x18C];						// 074-200
};
VALIDATE_SIZE(RBVehicle, 0x200);
VALIDATE_OFFSET(RBVehicle, m_sRigidBody, 0x40);

class DamageVehicle
{
public:
	uint8_t pad[0x44];					// 00-44
	IDamageable m_sDamageable;			// 44-4C
	uint8_t pad2[0x2C];					// 4C-78
	float m_fDamage;					// 78-7C
};
VALIDATE_OFFSET(DamageVehicle, m_fDamage, 0x78);
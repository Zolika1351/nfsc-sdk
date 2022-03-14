
class Explosion
{
public:

	// a1: D4B6AEA6
	// a2 struct:
	// D4B6AEA6	0 -> stringhash32("ExplosionParams");
	// 0019FE84	4 -> D4B6AEA6
	// 0C4A1840	8 -> 
	// 0.2f		C
	// 0019FE28	10 -> UMath::Vector3(-2835.26709, 149.0571136, 3891.854004);
	// 10.0f	14
	// 5.0f		18
	// 0		1C
	// 4002		20 (00000FA2)
	// 009A0001	24 flags of some sort
	// 1		28

	struct ExplosionParams
	{
		uint32_t m_nTypeHash = stringhash32("ExplosionParams");			// 00-04
		uint32_t* m_pTypeHash = &m_nTypeHash;							// 04-08
		uint32_t m_nHash1 = 0;											// 08-0C
		float m_fParam1 = 0.2;											// 0C-10
		UMath::Vector3* m_vPosition = nullptr;							// 10-14
		float m_fParam2 = 10;											// 14-18
		float m_fParam3 = 5;											// 18-1C
		uint32_t m_nUnk1 = 0;											// 1C-20
		uint32_t m_nFlags = 4002;										// 20-24
		uint32_t m_nUnk2 = 0x9A0001;									// 24-28
		uint32_t m_nUnk3 = 1;											// 28-2C
	};
	VALIDATE_SIZE(ExplosionParams, 0x2C);
	VALIDATE_OFFSET(ExplosionParams, m_vPosition, 0x10);

	static ISimable* Construct(uint32_t typeHash, ExplosionParams* params)
	{
		return ((ISimable*(__cdecl*)(uint32_t, ExplosionParams*))0x6DA3C0)(typeHash, params);
	}
};
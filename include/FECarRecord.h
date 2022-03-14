class FECarRecord
{
public:
	enum eCarFlags
	{
		LIST_STOCK = 1,
		LIST_CAREER = 2,
		LIST_MY_CARS = 4,
		LIST_BONUS = 8,
		LIST_CUSTOM = 16,
	};

	uint32_t m_nHandle;							// 00-04
	uint8_t pad[0x4];							// 04-08
	uint32_t m_nModelHash;						// 08-0C
	uint32_t m_nFlags;							// 0C-10
	uint8_t m_nCustomizationRecordHandle;		// 10-11
	uint8_t pad3[0x3];							// 11-14

	uint32_t GetNameHash()
	{
		return ((uint32_t(__thiscall*)(FECarRecord*))0x4C43A0)(this);
	}
	uint32_t GetFEKey()
	{
		return ((uint32_t(__thiscall*)(FECarRecord*))0x4AE1D0)(this);
	}
	char* GetDebugName()
	{
		return ((char* (__thiscall*)(FECarRecord*))0x4AE320)(this);
	}
};
VALIDATE_SIZE(FECarRecord, 0x14);
VALIDATE_OFFSET(FECarRecord, m_nHandle, 0x0);
VALIDATE_OFFSET(FECarRecord, m_nModelHash, 0x8);
VALIDATE_OFFSET(FECarRecord, m_nFlags, 0xC);
VALIDATE_OFFSET(FECarRecord, m_nCustomizationRecordHandle, 0x10);

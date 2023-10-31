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

	uint32_t Handle;							// 00-04
	uint32_t FEKey;								// 04-08
	uint32_t VehicleKey;						// 08-0C
	uint32_t FilterBits;						// 0C-10
	uint8_t Customization;						// 10-11
	uint8_t CareerHandle;						// 11-12
	uint8_t IsPresetSkin;						// 12-13
	uint8_t pad;								// 13-14

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
VALIDATE_OFFSET(FECarRecord, Handle, 0x0);
VALIDATE_OFFSET(FECarRecord, VehicleKey, 0x8);
VALIDATE_OFFSET(FECarRecord, FilterBits, 0xC);
VALIDATE_OFFSET(FECarRecord, Customization, 0x10);

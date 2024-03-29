class FEPlayerCarDB
{
public:
	FECarRecord CarTable[200];					// 00234-011D4
	FECustomizationRecord Customizations[75];	// 011D4-15EA4

	FECarRecord* GetCarRecordByHandle(uint32_t handle)
	{
		return ((FECarRecord*(__thiscall*)(FEPlayerCarDB*, uint32_t))0x49C020)(this, handle);
	}
	FECarRecord* CreateNewCarRecord()
	{
		return ((FECarRecord*(__thiscall*)(FEPlayerCarDB*))0x4BA1F0)(this);
	}
};
VALIDATE_SIZE(FEPlayerCarDB, 0x15C70);
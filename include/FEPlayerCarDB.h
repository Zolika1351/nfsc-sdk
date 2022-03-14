class FEPlayerCarDB
{
public:
	FECarRecord m_aCars[200];					// 00234-011D4
	FECustomizationRecord m_aCustomization[75];	// 011D4-15EA4

	FECarRecord* GetCarRecordByHandle(uint32_t handle)
	{
		return ((FECarRecord*(__thiscall*)(FEPlayerCarDB*, uint32_t))0x49C020)(this, handle);
	}
	FECarRecord* CreateNewCarRecord()
	{
		return ((FECarRecord*(__thiscall*)(FEPlayerCarDB*))0x4BA1F0)(this);
	}
};
class VehicleCustomizations
{
public:
	uint8_t pad[0x42C];									// 000-42C

	VehicleCustomizations()
	{
		((int(__thiscall*)(VehicleCustomizations*))(0x412790))(this);
	}
};
VALIDATE_SIZE(VehicleCustomizations, 0x42C);

class FECustomizationRecord
{
public:
	uint8_t pad[0x24];									// 000-024
	uint32_t m_nEngineUpgrade;							// 024-028
	uint8_t pad2[0x440];								// 028-468
	float m_fRideHeight;								// 468-46C
	uint8_t pad3[0x4];									// 46C-470

	void WriteToGame(uint32_t hash, VehicleCustomizations* dest)
	{
		((void(__thiscall*)(FECustomizationRecord*, uint32_t, VehicleCustomizations*))(0x4BAD10))(this, hash, dest);
	}
};
VALIDATE_SIZE(FECustomizationRecord, 0x470);
VALIDATE_OFFSET(FECustomizationRecord, m_nEngineUpgrade, 0x24);
VALIDATE_OFFSET(FECustomizationRecord, m_fRideHeight, 0x468);
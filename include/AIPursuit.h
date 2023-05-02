class AIPursuit
{
public:
	enum eStatus
	{
		PURSUIT_STATUS_ONGOING,
		PURSUIT_STATUS_COOLDOWN = 2,
	};

	uint8_t pad[0xFC];					// 000-0FC
	float m_fMaxHeat;					// 0FC-100
	uint8_t pad2[0x44];					// 100-144
	bool m_bPerpBusted;					// 144-145

	void AddVehicleToContingent(void* veh)
	{
		((void(__thiscall*)(AIPursuit*, void*))(0x43FC70))(this, veh);
	}
	void RequestRoadBlock()
	{
		((void(__thiscall*)(AIPursuit*))(0x41CFB0))(this);
	}
	void BailPursuit()
	{
		((void(__thiscall*)(AIPursuit*))(0x41D430))(this);
	}
};
VALIDATE_OFFSET(AIPursuit, m_fMaxHeat, 0xFC);
VALIDATE_OFFSET(AIPursuit, m_bPerpBusted, 0x144);
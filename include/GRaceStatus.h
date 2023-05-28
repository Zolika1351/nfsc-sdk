class GRacerInfo
{
public:
	uint32_t m_nHandle;								// 000-004
	uint8_t pad[0x4];								// 004-008
	char m_sName[32];								// 008-00C
	uint32_t m_nRacerId;							// 028-02C
	uint8_t pad2[0x358];							// 02C-384

	GRacerInfo()
	{
		((GRacerInfo*(__thiscall*)(GRacerInfo*))0x629350)(this);
	}
};
VALIDATE_SIZE(GRacerInfo, 0x384);
VALIDATE_OFFSET(GRacerInfo, m_nHandle, 0x0);
VALIDATE_OFFSET(GRacerInfo, m_sName, 0x8);
VALIDATE_OFFSET(GRacerInfo, m_nRacerId, 0x28);

class GRaceStatus
{
public:
	uint8_t pad[0x18];								// 0000-0018
	GRacerInfo m_aRacerArray[30];					// 0018-6990
	int m_aLazyRankings[30];						// 6990-6A08
	uint32_t m_nRacerCount;							// 6A08-6A0C
	uint8_t pad2[0x8];								// 6A0C-6A14
	uint32_t m_bIsRacing;							// 6A14-6A18

	void DisableBarriers()
	{
		((void(__thiscall*)(GRaceStatus*))0x63DE50)(this);
	}
	void ClearCheckpoints()
	{
		((void(__thiscall*)(GRaceStatus*))0x634170)(this);
	}
	void StopMasterTimer()
	{
		((void(__thiscall*)(GRaceStatus*))0x624F30)(this);
	}
	int GetRacerCount()
	{
		return ((int(__thiscall*)(GRaceStatus*))0x612230)(this);
	}
	int GetRaceType()
	{
		return ((int(__thiscall*)(GRaceStatus*))0x6136A0)(this);
	}
	GRacerInfo* GetRacerInfo(int id)
	{
		return ((GRacerInfo*(__thiscall*)(GRaceStatus*, int))0x6121E0)(this, id);
	}

	static inline GRaceStatus*& fObj = *(GRaceStatus**)0xA98284;
};
VALIDATE_OFFSET(GRaceStatus, m_nRacerCount, 0x6A08);
VALIDATE_OFFSET(GRaceStatus, m_aLazyRankings, 0x6990);
VALIDATE_OFFSET(GRaceStatus, m_bIsRacing, 0x6A14);
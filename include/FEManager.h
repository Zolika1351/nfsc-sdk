class FEVinylRecord
{
public:
	uint8_t pad[0x1C];							// 00-1C
};

class UserProfile
{
public:
	uint8_t pad[0x10];							// 00000-00010
	char m_sPlayerName[16];						// 00010-00020
	uint8_t pad2[0x214];						// 00020-00234
	FEPlayerCarDB m_sPlayerCarDB;				// 00234-15EA4
	uint8_t pad_15EA4[0x9678];					// 15EA4-1F51C
	FEVinylRecord m_aVinyls[700];				// 1F51C-241AC
	uint8_t pad4[0x184];						// 241AC-24330
	int32_t m_nCash;							// 24330-24334
	uint8_t pad5[0x6DF4];						// 24334-2B128
	uint32_t m_aQuickRaceHandles[4];			// 2B128-2B138
};
VALIDATE_OFFSET(UserProfile, m_sPlayerName, 0x10);
VALIDATE_OFFSET(UserProfile, m_sPlayerCarDB, 0x234);
VALIDATE_OFFSET(UserProfile, m_aVinyls, 0x1F51C);
VALIDATE_OFFSET(UserProfile, m_nCash, 0x24330);
VALIDATE_OFFSET(UserProfile, m_aQuickRaceHandles, 0x2B128);

class FEManager
{
public:
	static inline FEManager*& mInstance = *(FEManager**)0xA97A7C;
	static inline int32_t& mPauseRequest = *(int32_t*)0xA8AD18;

	UserProfile* GetUserProfile(int id)
	{
		return ((UserProfile*(__thiscall*)(FEManager*, int))(0x572B90))(this, id);
	}
};

void FE_ShowWinningPostRaceScreen()
{
	((void(__cdecl*)())0x65E270)();
}

void FE_ShowPostRaceScreen(bool win)
{
	((void(__cdecl*)(bool))0x65C6A0)(win);
}

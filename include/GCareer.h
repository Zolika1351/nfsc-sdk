class GCrew
{
public:
	uint8_t pad[0x34];						// 00-34
	uint32_t m_nProgress;					// 34-38 >= 3 -> max heat level 5, < 1 -> max heat level 2, else 4
};

class GCareer
{
public:
	static inline GCareer*& mObj = *(GCareer**)0xA982B8;

	uint8_t pad[0xDC];						// 00-DC
	GCrew* m_pCrew;							// DC-E0
};
class RecordablePlayer : public Sim::Entity
{
public:
	uint8_t pad[0x34];					// 08-3C
	ISimable* m_pSimable;				// 3C-40
	uint8_t pad2[0x4];					// 40-44
	IPlayer m_sPlayer;					// 44-4C
	uint8_t pad3[0x30];					// 4C-7C
	float mGameBreakerCharge;			// 7C-80
};
VALIDATE_OFFSET(RecordablePlayer, m_pSimable, 0x3C);
VALIDATE_OFFSET(RecordablePlayer, m_sPlayer, 0x44);
VALIDATE_OFFSET(RecordablePlayer, mGameBreakerCharge, 0x7C);
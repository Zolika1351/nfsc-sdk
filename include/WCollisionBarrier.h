class WCollisionBarrier
{
public:
	UMath::Vector3 vMin;			// 00-0C
	uint8_t nSurface;				// 0C-0D
	uint8_t fFlags;					// 0D-0E
	uint16_t pad = 0;				// 0E-10
	UMath::Vector3 vMax;			// 10-1C
	float fInvLen;					// 1C-20
	void* nUnk = nullptr;			// 20-24
	float fUnk2 = 0;				// 24-28
};
VALIDATE_SIZE(WCollisionBarrier, 0x28);

class WCollisionBarrierList
{
public:
	WCollisionBarrier* pFirst = nullptr;	// 00-04
	WCollisionBarrier* pLast = nullptr;		// 04-08
	uint8_t pad2[0x4];						// 08-0C
};
VALIDATE_SIZE(WCollisionBarrierList, 0xC);
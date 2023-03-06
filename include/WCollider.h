class WCollisionInstanceCacheList
{
public:
	uint8_t pad[0x4];						// 00-04
	void* pFirst = nullptr;					// 04-08
	void* pLast = nullptr;					// 08-0C
	uint8_t pad2[0x4];						// 0C-10
};
VALIDATE_SIZE(WCollisionInstanceCacheList, 0x10);

class WCollider
{
public:
	UMath::Vector3 fRequestedPosition;				// 00-0C
	float fRequestedRadius;							// 0C-10
	UMath::Vector3 fLastRequestedPosition;			// 10-1C
	float fLastRequestedRadius;						// 1C-20
	UMath::Vector3 fPosition;						// 20-2C
	float fRadius;									// 2C-30
	UMath::Vector3 fLastRefreshedPosition;			// 30-3C
	WCollisionInstanceCacheList instanceList;		// 3C-4C
	WCollisionBarrierList barrierList;				// 4C-??

	bool IsEmpty()
	{
		return ((bool(__thiscall*)(WCollider*))0x7F49F0)(this);
	}
	void Refresh(UMath::Vector3* pt, float radius, bool predictiveSizing)
	{
		return ((void(__thiscall*)(WCollider*, UMath::Vector3*, float, bool))0x816BF0)(this, pt, radius, predictiveSizing);
	}
	void PrepareRegion(int flags)
	{
		return ((void(__thiscall*)(WCollider*, int))0x814A60)(this, flags);
	}
};
VALIDATE_OFFSET(WCollider, fRequestedRadius, 0xC);
VALIDATE_OFFSET(WCollider, fRadius, 0x2C);
VALIDATE_OFFSET(WCollider, barrierList, 0x4C);
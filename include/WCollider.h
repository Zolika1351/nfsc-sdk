class WCollider
{
public:
	UMath::Vector3 fRequestedPosition;
	float fRequestedRadius;
	UMath::Vector3 fLastRequestedPosition;
	float fLastRequestedRadius;
	UMath::Vector3 fPosition;
	float fRadius;
	UMath::Vector3 fLastRefreshedPosition;

	bool IsEmpty()
	{
		return ((bool(__thiscall*)(WCollider*))0x7F49F0)(this);
	}
	void Refresh(UMath::Vector3* pt, float radius, bool predictiveSizing)
	{
		return ((void(__thiscall*)(WCollider*, UMath::Vector3*, float, bool))0x816BF0)(this, pt, radius, predictiveSizing);
	}
};
VALIDATE_OFFSET(WCollider, fRequestedRadius, 0xC);
VALIDATE_OFFSET(WCollider, fRadius, 0x2C);
class WCollisionTri
{
public:
	UMath::Vector3 fPt0;
	void* fSurfaceRef = 0;
	UMath::Vector3 fPt1;
	uint32_t fFlags = 0;
	UMath::Vector3 fPt2;
	uint16_t fSurface = 0;
	uint16_t pad = 0;
};
VALIDATE_SIZE(WCollisionTri, 0x30);
class WCollisionMgr
{
public:
	class WorldCollisionInfo
	{
	public:
		UMath::Vector3 m_vHitPos;		// 00-0C
		uint8_t pad[0x4];				// 0C-10
		UMath::Vector3 m_vHitNormal;	// 10-1C
		uint8_t pad2[0x35];				// 1C-51
		uint8_t m_bHit;					// 51-52
		uint8_t pad3[0x6];				// 52-58

		WorldCollisionInfo()
		{
			((void(__thiscall*)(WorldCollisionInfo*))0x404A20)(this);
		}
	};
	VALIDATE_SIZE(WorldCollisionInfo, 0x58);
	VALIDATE_OFFSET(WorldCollisionInfo, m_bHit, 0x51);

	struct tInputSeg
	{
		UMath::Vector3 v1 = { 0,0,0 };
		float unk1_1 = 1.0;
		UMath::Vector3 v2 = { 0,0,0 };
		float unk1_2 = 1.0;
	};

	uint32_t fSurfaceExclusionMask = 0;
	uint32_t fPrimitiveMask = 3;

	bool CheckHitWorld(tInputSeg* inputSeg, WCollisionMgr::WorldCollisionInfo* cInfo, unsigned int primMask)
	{
		return ((bool(__thiscall*)(WCollisionMgr*, tInputSeg*, WCollisionMgr::WorldCollisionInfo*, unsigned int))0x814D70)(this, inputSeg, cInfo, primMask);
	}

	static bool GetWorldHeightAtPointRigorous(UMath::Vector3* pt, UMath::Vector3* outPoint, UMath::Vector3* outNormal)
	{
		return ((bool(__stdcall*)(UMath::Vector3*, UMath::Vector3*, UMath::Vector3*))0x816DF0)(pt, outPoint, outNormal);
	}
};
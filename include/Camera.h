class Camera
{
public:
	bMatrix4 m_mMatrix;											// 000-040
	UMath::Vector3 m_vStreamingPosition;						// 040-04C v.y, -v.z, v.x
	uint8_t pad[0x88];											// 04C-0D4
	float m_fNearClip;											// 0D4-0D8
	float m_fFarClip;											// 0D8-0DC
	uint8_t pad3[0x8];											// 0DC-0E4
	uint16_t m_nFOV;											// 0E4-0E8

	static inline bool& StopUpdating = *(bool*)0xA888D8;

	void SetCameraMatrix(bMatrix4* m, float fTime)
	{
		((void(__thiscall*)(Camera*, bMatrix4*, float))0x4822F0)(this, m, fTime);
	}
};
Camera& TheCamera = *(Camera*)0xB1D520;

VALIDATE_OFFSET(Camera, m_vStreamingPosition, 0x40);
VALIDATE_OFFSET(Camera, m_fNearClip, 0xD4);
VALIDATE_OFFSET(Camera, m_fFarClip, 0xD8);
VALIDATE_OFFSET(Camera, m_nFOV, 0xE4);
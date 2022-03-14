class Camera
{
public:
	uint8_t pad[0x40];											// 00-40
	UMath::Vector3 m_vStreamingPosition;						// 40-4C v.y, -v.z, v.x

	static inline bool& StopUpdating = *(bool*)0xA888D8;

	void SetCameraMatrix(UMath::Matrix4* mat, float unk)
	{
		((void(__cdecl*)(Camera*, UMath::Matrix4*, float))0x4822F0)(this, mat, unk);
	}
};
Camera& TheCamera = *(Camera*)0xB1D520;

VALIDATE_OFFSET(Camera, m_vStreamingPosition, 0x40);
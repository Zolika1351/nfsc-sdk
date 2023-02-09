class ViewTransform
{
public:
	UMath::Matrix4 m_mViewMatrix;
	UMath::Matrix4 m_mProjectionMatrix;
	UMath::Matrix4 m_mProjectionZBiasMatrix;
	UMath::Matrix4 m_mViewProjectionMatrix;
	UMath::Matrix4 m_mViewProjectionZBiasMatrix;
};
VALIDATE_OFFSET(ViewTransform, m_mProjectionMatrix, 0x40);
VALIDATE_OFFSET(ViewTransform, m_mViewProjectionMatrix, 0xC0);

class eViewPlatInterface
{
public:
	ViewTransform* m_pTransform;										// 00-04

	void GetScreenPosition(UMath::Vector3* out, UMath::Vector3* in)
	{
		((void(__thiscall*)(eViewPlatInterface*, UMath::Vector3*, UMath::Vector3*))0x70F1F0)(this, out, in);
	}

	void Render(eModel* model, bMatrix4* mat, void* unk, uint32_t flags, bMatrix4* unk2, void* blendData)
	{
		((void(__thiscall*)(eViewPlatInterface*, eModel*, bMatrix4*, void*, uint32_t, bMatrix4*, void*))0x729320)(this, model, mat, unk, flags, unk2, blendData);
	}
};

class View
{
public:
	static inline eViewPlatInterface* sViews = (eViewPlatInterface*)0xB4AF90;
};

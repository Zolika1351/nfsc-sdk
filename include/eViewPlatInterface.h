class ViewTransform
{
public:
	uint8_t pad[0x80];													// 00-80
	UMath::Matrix4 m_mMatrix;											// 80-
};

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

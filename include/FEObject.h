class FEObject
{
public:

	void SetVisibility(bool on)
	{
		((void(__cdecl*)(FEObject*, bool))0x570460)(this, on);
	}

	void SetColor(uint32_t color)
	{
		((void(__cdecl*)(FEObject*, uint32_t))0x5157E0)(this, color);
	}

	void SetCenter(float x, float y)
	{
		((void(__cdecl*)(FEObject*, float, float))0x597A70)(this, x, y);
	}

	void SetRotationZ(float f)
	{
		((void(__cdecl*)(FEObject*, float))0x5705A0)(this, f);
	}

	void SetSize(float x, float y)
	{
		((void(__cdecl*)(FEObject*, float, float))0x570A90)(this, x, y);
	}
};
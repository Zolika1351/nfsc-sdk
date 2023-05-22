class IPerpetrator : public UTL::COM::Object
{
public:
	float GetHeat()
	{
		return ((float(__thiscall*)(IPerpetrator*))(*(void***)this)[1])(this);
	}
	void SetHeat(float heat)
	{
		((void(__thiscall*)(IPerpetrator*, float))(*(void***)this)[2])(this, heat);
	}
};
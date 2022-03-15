class IInput : public UTL::COM::Object
{
public:
	void ClearInput()
	{
		((void(__thiscall*)(IInput*))(*(void***)this)[1])(this);
	}
	void SetControlSteering(float value)
	{
		((void(__thiscall*)(IInput*, float))(*(void***)this)[9])(this, value);
	}
	void SetControlGas(float value)
	{
		((void(__thiscall*)(IInput*, float))(*(void***)this)[11])(this, value);
	}
	void SetControlBrake(float value)
	{
		((void(__thiscall*)(IInput*, float))(*(void***)this)[12])(this, value);
	}

	static uint32_t IHandle() { return 0x403AA0; }
};
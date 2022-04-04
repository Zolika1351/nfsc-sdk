class IInput : public UTL::COM::Object
{
public:
	void ClearInput() { ((void(__thiscall*)(IInput*))(*(void***)this)[1])(this); }
	float GetControlBrake() { return ((float(__thiscall*)(IInput*))(*(void***)this)[2])(this); }
	float GetControlGas() { return ((float(__thiscall*)(IInput*))(*(void***)this)[3])(this); }
	float GetControlSteering() { return ((float(__thiscall*)(IInput*))(*(void***)this)[4])(this); }
	float GetControlOverSteer() { return ((float(__thiscall*)(IInput*))(*(void***)this)[5])(this); }
	bool GetControlNOS() { return ((bool(__thiscall*)(IInput*))(*(void***)this)[6])(this); }
	float GetControlHandBrake() { return ((float(__thiscall*)(IInput*))(*(void***)this)[7])(this); }
	float GetControlClutch() { return ((float(__thiscall*)(IInput*))(*(void***)this)[8])(this); }
	void SetControlSteering(float value) { ((void(__thiscall*)(IInput*, float))(*(void***)this)[9])(this, value); }
	void SetControlOverSteer(float value) { ((void(__thiscall*)(IInput*, float))(*(void***)this)[10])(this, value); }
	void SetControlGas(float value) { ((void(__thiscall*)(IInput*, float))(*(void***)this)[11])(this, value); }
	void SetControlBrake(float value) { ((void(__thiscall*)(IInput*, float))(*(void***)this)[12])(this, value); }
	void SetControlNOS(bool value) { ((void(__thiscall*)(IInput*, bool))(*(void***)this)[13])(this, value); }
	void SetControlHandBrake(float value) { ((void(__thiscall*)(IInput*, float))(*(void***)this)[14])(this, value); }
	void SetControlClutch(float value) { ((void(__thiscall*)(IInput*, float))(*(void***)this)[15])(this, value); }
	bool IsLookBackButtonPressed() { return ((bool(__thiscall*)(IInput*))(*(void***)this)[16])(this); }
	bool IsPullBackButtonPressed() { return ((bool(__thiscall*)(IInput*))(*(void***)this)[17])(this); }
	bool IsWingmanActivationButtonPressed() { return ((bool(__thiscall*)(IInput*))(*(void***)this)[18])(this); }
	bool IsAutomaticShift() { return ((bool(__thiscall*)(IInput*))(*(void***)this)[19])(this); }

	static uint32_t IHandle() { return 0x403AA0; }
};
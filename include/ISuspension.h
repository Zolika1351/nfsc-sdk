class ISuspension : public UTL::COM::Object
{
public:
	float GetWheelVelocity(int wheel)
	{
		return ((float(__thiscall*)(ISuspension*, int))(*(void***)this)[19])(this, wheel);
	}
	int GetNumWheelsOnGround()
	{
		return ((int(__thiscall*)(ISuspension*))(*(void***)this)[19])(this);
	}
	float GetWheelAngularVelocity(int wheel)
	{
		return ((float(__thiscall*)(ISuspension*, int))(*(void***)this)[20])(this, wheel);
	}
	void SetWheelAngularVelocity(int wheel, float velocity)
	{
		((void(__thiscall*)(ISuspension*, int, float))(*(void***)this)[21])(this, wheel, velocity);
	}
	float GetWheelSteer(int wheel)
	{
		return ((float(__thiscall*)(ISuspension*, int))(*(void***)this)[22])(this, wheel);
	}

	static uint32_t IHandle() { return 0x403CE0; }
};
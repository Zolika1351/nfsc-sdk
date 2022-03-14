class ITrafficAI : public UTL::COM::Object
{
public:
	void StartDriving(float speed)
	{
		((void(__thiscall*)(ITrafficAI*, float))(*(void***)this)[1])(this, speed);
	}

	static uint32_t IHandle() { return 0x403770; };
};
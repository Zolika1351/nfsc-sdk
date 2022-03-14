class IPursuitAI : public UTL::COM::Object
{
public:
	void StartPatrol()
	{
		((void(__thiscall*)(IPursuitAI*))(*(void***)this)[1])(this);
	}

	static uint32_t IHandle() { return 0x4055B0; };
};
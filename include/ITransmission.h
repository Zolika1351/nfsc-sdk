class ITransmission : public UTL::COM::Object
{
public:
	bool IsReversing()
	{
		return ((bool(__thiscall*)(ITransmission*))(*(void***)this)[5])(this);
	}

	static uint32_t IHandle() { return 0x403C80; }
};
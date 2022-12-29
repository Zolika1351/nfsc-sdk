class IInputPlayer : public UTL::COM::Object
{
public:

	void BlockInput() { return ((void(__thiscall*)(IInputPlayer*))(*(void***)this)[1])(this); }
	bool IsBlocked() { return ((bool(__thiscall*)(IInputPlayer*))(*(void***)this)[2])(this); }
	void FetchInput() { return ((void(__thiscall*)(IInputPlayer*))(*(void***)this)[3])(this); }
	void ClearInput() { return ((void(__thiscall*)(IInputPlayer*))(*(void***)this)[4])(this); }

	static uint32_t IHandle() { return 0x403A90; }
};

class IResetable
{
public:

	bool HasResetPosition() { return ((bool(__thiscall*)(IResetable*))(*(void***)this)[1])(this); }
	void ResetVehicle(bool manual) { return ((void(__thiscall*)(IResetable*, bool))(*(void***)this)[2])(this, manual); }
	void SetResetPosition(const UMath::Vector3* position, const UMath::Vector3* direction) { return ((void(__thiscall*)(IResetable*, const UMath::Vector3*, const UMath::Vector3*))(*(void***)this)[3])(this, position, direction); }
	void ClearResetPosition() { return ((void(__thiscall*)(IResetable*))(*(void***)this)[4])(this); }

	static uint32_t IHandle() { return 0x403D00; }
};
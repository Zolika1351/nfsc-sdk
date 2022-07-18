class AIWingman
{
public:
	uint8_t pad[0x8];				// 00-08
	IVehicle* m_pLeader;			// 08-0C

	IVehicle* GetLeader() { return ((IVehicle*(__thiscall*)(AIWingman*))(*(void***)this)[1])(this); }
	void SetLeader(IVehicle* leader) { ((void(__thiscall*)(AIWingman*, IVehicle*))(*(void***)this)[2])(this, leader); }
	int GetWingmanRole() { return ((int(__thiscall*)(AIWingman*))(*(void***)this)[3])(this); }
	void ChangeWingmanRole(int role) { ((void(__thiscall*)(AIWingman*, int))(*(void***)this)[4])(this, role); }
	bool GetIsWingmanActivated() { return ((bool(__thiscall*)(AIWingman*))(*(void***)this)[5])(this); }
};
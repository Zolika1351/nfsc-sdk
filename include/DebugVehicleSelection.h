class DebugVehicleSelection
{
public:
	static inline DebugVehicleSelection*& mThis = *(DebugVehicleSelection**)0xB74BE8;

	void SwitchPlayerVehicle(char* modelName)
	{
		((void(__thiscall*)(DebugVehicleSelection*, char*))(0x7D4E40))(this, modelName);
	}
};
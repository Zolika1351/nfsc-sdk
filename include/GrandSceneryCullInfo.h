class GrandSceneryCullInfo
{
public:

	void DoCulling()
	{
		((void(__thiscall*)(GrandSceneryCullInfo*))(0x7A4BA0))(this);
	}
	void CullView(eViewPlatInterface* view)
	{
		((void(__thiscall*)(GrandSceneryCullInfo*, eViewPlatInterface*))(0x7A4B30))(this, view);
	}
	int WhatSectionsShouldWeDraw(uint16_t* arr, int arrSize, eViewPlatInterface* view)
	{
		return ((int(__thiscall*)(GrandSceneryCullInfo*, uint16_t*, int, eViewPlatInterface*))(0x7A4900))(this, arr, arrSize, view);
	}
};

void SetupWorldCulling(GrandSceneryCullInfo* info)
{
	((void(__cdecl*)(GrandSceneryCullInfo*))(0x7103C0))(info);
}

int& PrecullerMode = *(int*)0xA72C28;
int& DisablePrecullerCounter = *(int*)0xB69BF0;
int& AllSceneryChecksum = *(int*)0xB69BFC;
float& EnablePrecullingSpeed = *(float*)0xB71438;
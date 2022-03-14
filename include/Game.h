enum eGameFlowState
{
	STATE_MENUS = 3,
	STATE_LOADING_1,
	STATE_LOADING_2,
	STATE_INGAME
};

UMath::Vector3& gGpsDestination = *(UMath::Vector3*)0xA98484;
int& TheGameFlowManager = *(int*)0xA99BBC;
bool& UnlockAllThings = *(bool*)0xA9E6C0;
bool& SkipCareerIntro = *(bool*)0xA9E6C1;
bool& SkipNISs = *(bool*)0xA9E64E;
int& ForceCarLOD = *(int*)0xA7309C;
int& ForceTireLOD = *(int*)0xA730A0;

void Game_ForceAIControl(int unk)
{
	((void(__cdecl*)(int))0x65C2C0)(unk);
}

void Game_ClearAIControl(int unk)
{
	((void(__cdecl*)(int))0x65C330)(unk);
}

void Game_SetWorldHeat(float heat)
{
	((void(__cdecl*)(float))0x65C550)(heat);
}

void Game_PreventPlayerBeingBusted()
{
	((void(__cdecl*)())0x6516D0)();
}

void Game_AbandonRace()
{
	((void(__cdecl*)())0x656300)();
}

void Game_PlayFinishCamera(char* win, char* lose)
{
	((void(__cdecl*)(char*, char*))0x6513A0)(win, lose);
}

void Game_EnterPostRaceFlow()
{
	((void(__cdecl*)())0x65EF00)();
}

void Game_ShowPauseMenu()
{
	((void(__cdecl*)())0x64B620)();
}

float Game_GetStoryLineProgression()
{
	return ((float(__cdecl*)())0x64C380)();
}

void Game_ActivateDriftMode()
{
	((void(__cdecl*)())0x65C8B0)();
}

void Game_DeactivateDriftMode()
{
	((void(__cdecl*)())0x65C910)();
}

void Game_SabotageEngine(ISimable* veh, float time)
{
	((void(__cdecl*)(ISimable*, float))0x6515D0)(veh, time);
}

void Game_ForcePursuitStart(int* unk)
{
	((void(__cdecl*)(int*))0x651430)(unk);
}

void Game_JumpToSafeHouse()
{
	((void(__cdecl*)())0x64B800)();
}

void Game_JumpToCarLot()
{
	((void(__cdecl*)())0x64B7A0)();
}
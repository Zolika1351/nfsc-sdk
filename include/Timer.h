float& RealTimeElapsedFrame = *(float*)0xA99A5C;
float& Tweak_GameSpeed = *(float*)0xA712AC;
float& WorldTimeElapsed = *(float*)0xA996F8;
uint32_t& loop_ticker = *(uint32_t*)0xA992B0;

uint64_t bGetTicker()
{
	return ((uint64_t(__cdecl*)())0x46CEC0)();
}
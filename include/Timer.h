auto& RealTimeElapsedFrame = *(float*)0xA99A5C;
auto& Tweak_GameSpeed = *(float*)0xA712AC;
auto& WorldTimeElapsed = *(float*)0xA996F8;
auto& loop_ticker = *(uint32_t*)0xA992B0;
auto& TicksToMilliseconds = *(float*)0xA84A10;

uint64_t bGetTicker()
{
	return ((uint64_t(__cdecl*)())0x46CEC0)();
}
void HUD_ShowMessage(const char* text)
{
	((void(__cdecl*)(const char*))0x65B1B0)(text);
}

const char* GetLocalizedString(uint32_t hash)
{
	return ((const char* (__cdecl*)(uint32_t))0x578830)(hash);
}
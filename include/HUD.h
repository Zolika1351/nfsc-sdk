void HUD_ShowMessage(const char* text)
{
	((void(__cdecl*)(const char*))0x65B1B0)(text);
}

const char* GetLocalizedString(uint32_t hash)
{
	return ((const char* (__cdecl*)(uint32_t))0x578830)(hash);
}

bool GetLocalizedWideString(wchar_t* out, int length, uint32_t hash)
{
	return ((bool(__cdecl*)(wchar_t*, int, uint32_t))0x588F20)(out, length, hash);
}

auto NumStringRecords = (int*)0xA95384;

struct tStringRecord
{
	uint32_t hash;
	char* string;
};
auto RecordTables = (tStringRecord**)0xA95378;
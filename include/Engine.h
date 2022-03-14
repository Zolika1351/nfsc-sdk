uint32_t stringhash32(const char* string)
{
	return ((uint32_t(__cdecl*)(const char*))0x606B60)(string);
}

uint32_t bStringHash(const char* string)
{
	return ((uint32_t(__cdecl*)(const char*))0x471050)(string);
}

uint32_t bStringHashUpper(const char* string)
{
	return ((uint32_t(__cdecl*)(const char*))0x4710B0)(string);
}

uint32_t bStringHash(const char* string, uint32_t existingHash)
{
	return ((uint32_t(__cdecl*)(const char*, uint32_t))0x471080)(string, existingHash);
}

IDirect3DDevice9*& gD3DDevice = *(IDirect3DDevice9**)(0xAB0ABC);
HWND& ghWnd = *(HWND*)(0xAB0AD8);
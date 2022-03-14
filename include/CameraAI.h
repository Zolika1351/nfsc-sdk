class CameraAI
{
public:
	static void SetAction(int id, char* action)
	{
		((void(__cdecl*)(int, char*))0x48D620)(id, action);
	}
};
class ITrafficAI
{
public:

	void StartDriving(float speed)
	{
		((void(__thiscall*)(ITrafficAI*, float))(*(void***)this)[1])(this, speed);
	}
};
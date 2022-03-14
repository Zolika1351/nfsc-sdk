class NOSData
{
public:
	uint8_t pad[0x4];						// 00-04
	float m_fPower;							// 04-08
	uint8_t pad2[0x4];						// 08-10
	float m_fCapacity;						// 10-14
	float m_fCapacity2;						// 14-18
	float m_fRegenTime;						// 18-1C
};

class IEngine : public UTL::COM::Object
{
public:
	template<typename T>
	inline T* GetParent()
	{
		return (T*)(((uintptr_t)this) - 0x4C);
	}
	
	static uint32_t IHandle() { return 0x403CB0; }
};
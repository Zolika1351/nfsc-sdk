class PhysicsObject
{
public:
	uint8_t pad[0x24];							// 000-024
	ISimable m_sSimable;						// 024-02C
	uint8_t pad2[0x4];							// 02C-030
};
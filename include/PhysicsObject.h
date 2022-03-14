class PhysicsObject
{
public:
	uint8_t pad[0x24];							// 000-024
	ISimable m_sSimable;						// 024-030
};
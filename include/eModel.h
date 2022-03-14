class eModel
{
public:
	uint8_t pad[0x18];							// 00-18
};
VALIDATE_SIZE(eModel, 0x18);
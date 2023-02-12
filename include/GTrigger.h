struct GTrigger
{
	uint8_t pad[0x54];
	UMath::Vector3 m_vPosition;
};
VALIDATE_OFFSET(GTrigger, m_vPosition, 0x54);
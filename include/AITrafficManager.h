enum eVehicleCacheResult
{
	VCR_WANT,
	VCR_DONTCARE
};

class IVehicle;

class IVehicleCache
{
public:
	uint8_t pad[0x4];

	char* GetCacheName()
	{
		return ((char* (__thiscall*)(IVehicleCache*))(*(void***)this)[1])(this);
	}
	bool OnQueryVehicleCache(IVehicle* vehicle, const IVehicleCache* who)
	{
		return ((bool (__thiscall*)(IVehicleCache*, IVehicle*, const IVehicleCache*))(*(void***)this)[2])(this, vehicle, who);
	}
	bool OnRemovedVehicleCache(IVehicle* vehicle)
	{
		return ((bool (__thiscall*)(IVehicleCache*, IVehicle*))(*(void***)this)[3])(this, vehicle);
	}
};
class WRoadNav { uint8_t pad[0x4]; };

class AITrafficManager
{
public:
	uint8_t pad[0x48];						// 00-48
	IVehicleCache m_nCache;					// 48-4C
};
VALIDATE_OFFSET(AITrafficManager, m_nCache, 0x48);
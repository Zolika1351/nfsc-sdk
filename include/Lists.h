template<typename T, uintptr_t begin>
class ListableSet
{
public:
	static inline uint8_t*& mBegin = *(uint8_t**)(begin);
	static inline uint32_t& mSize = *(uint32_t*)(begin+8);

	static T* Get(unsigned int id)
	{
		if (id >= mSize) return nullptr;
		return *(T**)(mBegin + (id * 4));
	}
};

ListableSet<IPlayer, 0xA9FF5C> PlayerList;
ListableSet<IVehicle, 0xA9F48C> RacerList;
ListableSet<IVehicle, 0xA9F15C> VehicleList;
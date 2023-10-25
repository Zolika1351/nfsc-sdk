template<typename T, uintptr_t addr>
class ListableSet
{
public:
	static inline uint8_t*& mBegin = *(uint8_t**)(addr);
	static inline uint32_t& mCapacity = *(uint32_t*)(addr + 4);
	static inline uint32_t& mSize = *(uint32_t*)(addr + 8);

	static T* Get(unsigned int id)
	{
		if (id >= mSize) return nullptr;
		return *(T**)(mBegin + (id * 4));
	}

	struct Iterator
	{
		Iterator(ListableSet<T, addr>* ptr, int id)
		{
			pool = ptr;
			index = id;
			if (index >= pool->mSize) index = -1;
		}

		T* operator*() const { return pool->Get(index); }
		Iterator& operator++()
		{
			index++;
			if (index >= pool->mSize) index = -1;
			return *this;
		}
		bool operator!= (const Iterator& b) { return index != b.index; };

	private:
		ListableSet<T, addr>* pool;
		int index = 0;
	};
};

template<typename T, uintptr_t addr>
auto begin(ListableSet<T, addr>& pool) { return ListableSet<T, addr>::Iterator(&pool, 0); }
template<typename T, uintptr_t addr>
auto end(ListableSet<T, addr>& pool) { return ListableSet<T, addr>::Iterator(&pool, -1); }

ListableSet<IPlayer, 0xA9FF5C> PlayerList;
ListableSet<IVehicle, 0xA9F48C> RacerList;
ListableSet<IVehicle, 0xA9F15C> VehicleList;
ListableSet<IVehicleCache, 0xAA253C> VehicleCacheList;
enum SlotPoolFlags
{
	SLOTPOOL_FLAG_OVERFLOW_IF_FULL = 1,
	SLOTPOOL_FLAG_ZERO_ALLOCATED_MEMORY = 2,
	SLOTPOOL_FLAG_WARN_IF_OVERFLOW = 4,
	SLOTPOOL_FLAG_WARN_IF_NONEMPTY_DELETE = 8
};

class SlotPool
{
public:
	uint8_t pad[0x8];
	SlotPool* NextSlotPool;
	char* DebugName;
	uint32_t FreeSlots;
	uint32_t Flags;
	uint32_t NumAllocatedSlots;
	uint32_t MostNumAllocatedSlots;
	uint32_t MemoryPool;
	uint32_t NumSlots;
	uint32_t SlotSize;
	uint32_t TotalNumSlots;
};
VALIDATE_SIZE(SlotPool, 0x30); 

SlotPool* bNewSlotPool(int slot_size, int num_slots, const char* debug_name, int memory_pool)
{
	return ((SlotPool*(__cdecl*)(int, int, const char*, int))0x477B80)(slot_size, num_slots, debug_name, memory_pool);
}
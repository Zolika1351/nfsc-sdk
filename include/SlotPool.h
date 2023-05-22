class SlotPool;
SlotPool* bNewSlotPool(int slot_size, int num_slots, const char* debug_name, int memory_pool)
{
	return ((SlotPool*(__cdecl*)(int, int, const char*, int))0x477B80)(slot_size, num_slots, debug_name, memory_pool);
}
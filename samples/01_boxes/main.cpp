#include <serenity.h>
#include <cassert>

int main()
{
	Serenity_CapacityDesc capacity_desc = {};
	capacity_desc.max_elements = 256;
	capacity_desc.max_frame_arena_size = 64 * 1024;

	uint64_t memory_size = serenityGetRequiredMemory(&capacity_desc);
	uint8_t *memory = new uint8_t[memory_size];

	Serenity_InstanceDesc desc = {};
	desc.capacity = capacity_desc;
	desc.memory_size = memory_size;
	desc.memory = memory;

	Serenity_Instance instance = SERENITY_NULL_HANDLE;

	Serenity_Result result = serenityCreateInstance(&desc, &instance);
	assert(result == SERENITY_SUCCESS);

	result = serenityDestroyInstance(instance);
	assert(result == SERENITY_SUCCESS);

	delete[] memory;
	return 0;
}

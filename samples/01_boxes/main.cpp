#include <serenity.h>
#include <vector>
#include <cassert>

int main()
{
	Serenity_Instance instance = SERENITY_NULL_HANDLE;

	Serenity_InstanceDesc instance_desc =
	{
	};

	Serenity_Result result = serenityCreateInstance(&instance_desc, &instance);
	assert(result == SERENITY_SUCCESS);

	result = serenityDestroyInstance(instance);
	assert(result == SERENITY_SUCCESS);

	return 0;
}

#include "serenity_internal.h"

#include <assert.h>
#include <string.h>

/*
 */
typedef struct Serenity_InstanceInternal_t
{
	Serenity_InstanceTable *vtbl;
} Serenity_InstanceInternal;

/*
 */
Serenity_Result serenityCreateInstance(const Serenity_InstanceDesc *desc, Serenity_Instance *instance)
{
	return impl_createInstance(desc, instance);
}

Serenity_Result serenityGetInstanceTable(Serenity_Instance instance, Serenity_InstanceTable *instance_table)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	if (instance_table == NULL)
		return SERENITY_INVALID_OUTPUT_ARGUMENT;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);

	memcpy(instance_table, ptr->vtbl, sizeof(Serenity_InstanceTable));
	return SERENITY_SUCCESS;
}

/*
 */
Serenity_Result serenityMaskRectangle(Serenity_Instance instance, const Serenity_MaskRectangleDesc *desc)
{
	SERENITY_UNUSED(desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityMaskImage(Serenity_Instance instance, const Serenity_MaskImageDesc *desc)
{
	SERENITY_UNUSED(desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityMaskText(Serenity_Instance instance, const Serenity_MaskTextDesc *desc)
{
	SERENITY_UNUSED(desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityDecorateRectangle(Serenity_Instance instance, const Serenity_DecorationRectangleDesc *desc)
{
	SERENITY_UNUSED(desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityDecorateImage(Serenity_Instance instance, const Serenity_DecorationImageDesc *desc)
{
	SERENITY_UNUSED(desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityDecorateText(Serenity_Instance instance, const Serenity_DecorationTextDesc *desc)
{
	SERENITY_UNUSED(desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityDecorateCustom(Serenity_Instance instance, const Serenity_DecorationCustomDesc *desc)
{
	SERENITY_UNUSED(desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

/*
 */
Serenity_Result serenityDestroyInstance(Serenity_Instance instance)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->destroyInstance);

	return ptr->vtbl->destroyInstance(instance);
}

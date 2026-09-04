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
Serenity_Result serenityBeginFrame(Serenity_Instance instance, const Serenity_FrameDesc *desc)
{
	SERENITY_UNUSED(desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityEndFrame(Serenity_Instance instance, Serenity_RenderData *data)
{
	SERENITY_UNUSED(data);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenitySetPointerState(Serenity_Instance instance, Serenity_PointerId id, Serenity_Vec2 position, uint32_t pressed)
{
	SERENITY_UNUSED(id);
	SERENITY_UNUSED(position);
	SERENITY_UNUSED(pressed);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityGetPointerState(Serenity_Instance instance, Serenity_PointerId id, Serenity_Vec2 *position, uint32_t *pressed)
{
	SERENITY_UNUSED(id);
	SERENITY_UNUSED(position);
	SERENITY_UNUSED(pressed);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenitySetButtonState(Serenity_Instance instance, Serenity_ButtonId id, uint32_t pressed)
{
	SERENITY_UNUSED(id);
	SERENITY_UNUSED(pressed);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityGetButtonState(Serenity_Instance instance, Serenity_ButtonId id, uint32_t *pressed)
{
	SERENITY_UNUSED(id);
	SERENITY_UNUSED(pressed);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenitySetAxisState(Serenity_Instance instance, Serenity_AxisId id, float value)
{
	SERENITY_UNUSED(id);
	SERENITY_UNUSED(value);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityGetAxisState(Serenity_Instance instance, Serenity_AxisId id, float *value)
{
	SERENITY_UNUSED(id);
	SERENITY_UNUSED(value);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityBeginContainer(Serenity_Instance instance, const Serenity_ContainerDesc *desc)
{
	SERENITY_UNUSED(desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityEndContainer(Serenity_Instance instance)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityBeginMaskRectangle(Serenity_Instance instance, const Serenity_MaskRectangleDesc *desc)
{
	SERENITY_UNUSED(desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityBeginMaskImage(Serenity_Instance instance, const Serenity_MaskImageDesc *desc)
{
	SERENITY_UNUSED(desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityBeginMaskText(Serenity_Instance instance, const Serenity_MaskTextDesc *desc)
{
	SERENITY_UNUSED(desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityBeginMaskCustom(Serenity_Instance instance, const Serenity_MaskCustomDesc *desc)
{
	SERENITY_UNUSED(desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityEndMask(Serenity_Instance instance)
{
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

Serenity_Result serenityPointerTargetRectangle(Serenity_Instance instance, const Serenity_PointerTargetDesc *desc, Serenity_PointerResponse *response)
{
	SERENITY_UNUSED(desc);
	SERENITY_UNUSED(response);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityPointerTargetEllipse(Serenity_Instance instance, const Serenity_PointerTargetDesc *desc, Serenity_PointerResponse *response)
{
	SERENITY_UNUSED(desc);
	SERENITY_UNUSED(response);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}


Serenity_Result serenityFocusTarget(Serenity_Instance instance, const Serenity_FocusTargetDesc *desc, Serenity_FocusResponse *response)
{
	SERENITY_UNUSED(desc);
	SERENITY_UNUSED(response);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenitySetFocus(Serenity_Instance instance, Serenity_FocusTargetId target_id)
{
	SERENITY_UNUSED(target_id);

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

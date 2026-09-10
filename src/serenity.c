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
Serenity_Transform serenityIdentityTransform()
{
	Serenity_Transform result;

	result.anchor.x = 0.0f;
	result.anchor.y = 0.0f;
	result.offset.x = 0.0f;
	result.offset.y = 0.0f;
	result.scale.x = 1.0f;
	result.scale.y = 1.0f;
	result.angle = 0.0f;

	return result;
}

Serenity_LayoutSize serenityLayoutFit()
{
	Serenity_LayoutSize result;

	result.mode = SERENITY_LAYOUT_SIZE_MODE_FIT;
	result.value = 0.0f;
	result.min_size = 0.0f;
	result.max_size = 0.0f;

	return result;
}

Serenity_LayoutSize serenityLayoutFlex()
{
	Serenity_LayoutSize result;

	result.mode = SERENITY_LAYOUT_SIZE_MODE_FLEX;
	result.value = 1.0f;
	result.min_size = 0.0f;
	result.max_size = 0.0f;

	return result;
}

Serenity_LayoutSize serenityLayoutFlexWeighted(float weight)
{
	Serenity_LayoutSize result;

	result.mode = SERENITY_LAYOUT_SIZE_MODE_FLEX;
	result.value = weight;
	result.min_size = 0.0f;
	result.max_size = 0.0f;

	return result;
}

Serenity_LayoutSize serenityLayoutFixed(float value)
{
	Serenity_LayoutSize result;

	result.mode = SERENITY_LAYOUT_SIZE_MODE_FIXED;
	result.value = value;
	result.min_size = 0.0f;
	result.max_size = 0.0f;

	return result;
}

Serenity_AnchoredRect serenityAnchoredFill(float inset)
{
	Serenity_AnchoredRect result;

	result.min_anchor.x = 0.0f;
	result.min_anchor.y = 0.0f;
	result.max_anchor.x = 1.0f;
	result.max_anchor.y = 1.0f;
	result.min_offset.x = inset;
	result.min_offset.y = inset;
	result.max_offset.x = -inset;
	result.max_offset.y = -inset;

	return result;
}

uint32_t serenityHashId(uint32_t seed, const void *data, uint32_t size)
{
	SERENITY_UNUSED(seed);
	SERENITY_UNUSED(data);
	SERENITY_UNUSED(size);

	// TODO: implement this
	return SERENITY_ID_NONE;
}

uint32_t serenityCombineId(uint32_t parent, uint32_t key)
{
	SERENITY_UNUSED(parent);
	SERENITY_UNUSED(key);

	// TODO: implement this
	return SERENITY_ID_NONE;
}

uint64_t serenityGetRequiredMemory(const Serenity_CapacityDesc *capacity)
{
	SERENITY_UNUSED(capacity);

	// TODO: implement this
	return 0;
}

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
Serenity_Result serenityBeginFrame(Serenity_Instance instance, const Serenity_FrameDesc *desc, Serenity_FrameResponse *response)
{
	SERENITY_UNUSED(desc);
	SERENITY_UNUSED(response);

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

Serenity_Result serenitySetPointerState(Serenity_Instance instance, Serenity_PointerId id, Serenity_Vec2 root_position, uint32_t pressed)
{
	SERENITY_UNUSED(id);
	SERENITY_UNUSED(root_position);
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

Serenity_Result serenitySetAxisState(Serenity_Instance instance, Serenity_AxisId id, float value)
{
	SERENITY_UNUSED(id);
	SERENITY_UNUSED(value);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityAbortPointer(Serenity_Instance instance, Serenity_PointerId pointer_id)
{
	SERENITY_UNUSED(pointer_id);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityAbortButton(Serenity_Instance instance, Serenity_ButtonId button_id)
{
	SERENITY_UNUSED(button_id);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityAbortAxis(Serenity_Instance instance, Serenity_AxisId axis_id)
{
	SERENITY_UNUSED(axis_id);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityPointerFallback(Serenity_Instance instance, int32_t z_order, Serenity_PointerFallbackResponse *response)
{
	SERENITY_UNUSED(z_order);
	SERENITY_UNUSED(response);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityBeginRootContainer(Serenity_Instance instance, const Serenity_ContainerDesc *desc, const Serenity_RootDesc *root_desc)
{
	SERENITY_UNUSED(desc);
	SERENITY_UNUSED(root_desc);

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

Serenity_Result serenityText(Serenity_Instance instance, const Serenity_ContainerDesc *container_desc, const Serenity_TextDesc *text_desc)
{
	SERENITY_UNUSED(container_desc);
	SERENITY_UNUSED(text_desc);

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

Serenity_Result serenityBeginLayoutRootContainer(Serenity_Instance instance, const Serenity_LayoutContainerDesc *desc, const Serenity_RootDesc *root_desc)
{
	SERENITY_UNUSED(desc);
	SERENITY_UNUSED(root_desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityBeginLayoutScrollContainer(Serenity_Instance instance, const Serenity_LayoutContainerDesc *desc, Serenity_Vec2 offset, Serenity_ScrollResponse *response)
{
	SERENITY_UNUSED(desc);
	SERENITY_UNUSED(offset);
	SERENITY_UNUSED(response);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityBeginLayoutContainer(Serenity_Instance instance, const Serenity_LayoutContainerDesc *desc)
{
	SERENITY_UNUSED(desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityLayoutText(Serenity_Instance instance, const Serenity_LayoutContainerDesc *container_desc, const Serenity_TextDesc *text_desc)
{
	SERENITY_UNUSED(container_desc);
	SERENITY_UNUSED(text_desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityEndLayoutContainer(Serenity_Instance instance)
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

Serenity_Result serenityDecorateCustom(Serenity_Instance instance, const Serenity_DecorationCustomDesc *desc)
{
	SERENITY_UNUSED(desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityPointerTargetRectangle(Serenity_Instance instance, const Serenity_PointerTargetDesc *desc, Serenity_PointerTargetResponse *response)
{
	SERENITY_UNUSED(desc);
	SERENITY_UNUSED(response);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityPointerTargetEllipse(Serenity_Instance instance, const Serenity_PointerTargetDesc *desc, Serenity_PointerTargetResponse *response)
{
	SERENITY_UNUSED(desc);
	SERENITY_UNUSED(response);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityFocusTarget(Serenity_Instance instance, const Serenity_FocusTargetDesc *desc, Serenity_FocusTargetResponse *response)
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

Serenity_Result serenityFocusLink(Serenity_Instance instance, const Serenity_FocusLinkDesc *desc)
{
	SERENITY_UNUSED(desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityBeginFocusRow(Serenity_Instance instance, const Serenity_FocusSequenceDesc *desc)
{
	SERENITY_UNUSED(desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityEndFocusRow(Serenity_Instance instance)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityBeginFocusColumn(Serenity_Instance instance, const Serenity_FocusSequenceDesc *desc)
{
	SERENITY_UNUSED(desc);

	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	return SERENITY_NOT_IMPLEMENTED;
}

Serenity_Result serenityEndFocusColumn(Serenity_Instance instance)
{
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

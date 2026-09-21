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

static SERENITY_INLINE uint32_t murmur3Scramble(uint32_t value)
{
	value *= 0xcc9e2d51;
	value = (value << 15) | (value >> 17);
	value *= 0x1b873593;

	return value;
}

static SERENITY_INLINE uint32_t murmur3Hash(uint32_t seed, const void *data, uint32_t size)
{
	assert(size == 0 || data);

	uint32_t hash = seed;
	uint32_t temp;

	const uint8_t *key = (const uint8_t *)data;

	for (uint32_t i = size / 4; i > 0; i--)
	{
		temp = ((uint32_t)key[3] << 24)
			 | ((uint32_t)key[2] << 16)
			 | ((uint32_t)key[1] << 8)
			 | ((uint32_t)key[0]);

		key += sizeof(uint32_t);

		hash ^= murmur3Scramble(temp);
		hash = (hash << 13) | (hash >> 19);
		hash = hash * 5 + 0xe6546b64;
	}

	if (size % 4 != 0)
	{
		temp = 0;
		for (uint32_t i = size % 4; i > 0; i--)
		{
			temp = (temp << 8) | key[i - 1];
		}

		hash ^= murmur3Scramble(temp);
	}

	hash ^= size;
	hash ^= hash >> 16;
	hash *= 0x85ebca6b;
	hash ^= hash >> 13;
	hash *= 0xc2b2ae35;
	hash ^= hash >> 16;

	return hash;
}

static SERENITY_INLINE uint32_t serenityGuardId(uint32_t hash)
{
	assert(SERENITY_ID_GUARD != SERENITY_ID_NONE);
	return (hash != SERENITY_ID_NONE) ? hash : SERENITY_ID_GUARD;
}

uint32_t serenityHashId(uint32_t seed, const void *data, uint32_t size)
{
	uint32_t hash = murmur3Hash(seed, data, size);
	return serenityGuardId(hash);
}

uint32_t serenityCombineId(uint32_t parent, uint32_t key)
{
	uint8_t bytes[4];
	bytes[0] = (uint8_t)(key >> 0);
	bytes[1] = (uint8_t)(key >> 8);
	bytes[2] = (uint8_t)(key >> 16);
	bytes[3] = (uint8_t)(key >> 24);

	uint32_t hash = murmur3Hash(parent, bytes, 4);
	return serenityGuardId(hash);
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
Serenity_Result serenitySetPointerState(Serenity_Instance instance, Serenity_PointerId id, Serenity_Vec2 root_position, uint32_t pressed)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->setPointerState);

	return ptr->vtbl->setPointerState(instance, id, root_position, pressed);
}

Serenity_Result serenitySetButtonState(Serenity_Instance instance, Serenity_ButtonId id, uint32_t pressed)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->setButtonState);

	return ptr->vtbl->setButtonState(instance, id, pressed);
}

Serenity_Result serenitySetAxisState(Serenity_Instance instance, Serenity_AxisId id, float value)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->setAxisState);

	return ptr->vtbl->setAxisState(instance, id, value);
}


Serenity_Result serenityAbortPointer(Serenity_Instance instance, Serenity_PointerId id)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->abortPointer);

	return ptr->vtbl->abortPointer(instance, id);
}

Serenity_Result serenityAbortButton(Serenity_Instance instance, Serenity_ButtonId id)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->abortButton);

	return ptr->vtbl->abortButton(instance, id);
}

Serenity_Result serenityAbortAxis(Serenity_Instance instance, Serenity_AxisId id)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->abortAxis);

	return ptr->vtbl->abortAxis(instance, id);
}

Serenity_Result serenityBeginFrame(Serenity_Instance instance, const Serenity_FrameDesc *desc)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->beginFrame);

	return ptr->vtbl->beginFrame(instance, desc);
}

Serenity_Result serenityEndFrame(Serenity_Instance instance, Serenity_RenderData *data)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->endFrame);

	return ptr->vtbl->endFrame(instance, data);
}

Serenity_Result serenityBeginRootContainer(Serenity_Instance instance, const Serenity_ContainerDesc *desc, const Serenity_RootDesc *root_desc)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->beginRootContainer);

	return ptr->vtbl->beginRootContainer(instance, desc, root_desc);
}

Serenity_Result serenityBeginContainer(Serenity_Instance instance, const Serenity_ContainerDesc *desc)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->beginContainer);

	return ptr->vtbl->beginContainer(instance, desc);
}

Serenity_Result serenityText(Serenity_Instance instance, const Serenity_ContainerDesc *desc, const Serenity_TextDesc *text_desc)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->text);

	return ptr->vtbl->text(instance, desc, text_desc);
}

Serenity_Result serenityEndContainer(Serenity_Instance instance)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->endContainer);

	return ptr->vtbl->endContainer(instance);
}

Serenity_Result serenityBeginLayoutRootContainer(Serenity_Instance instance, const Serenity_LayoutContainerDesc *desc, const Serenity_RootDesc *root_desc)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->beginLayoutRootContainer);

	return ptr->vtbl->beginLayoutRootContainer(instance, desc, root_desc);
}

Serenity_Result serenityBeginLayoutScrollContainer(Serenity_Instance instance, const Serenity_LayoutContainerDesc *desc, Serenity_Vec2 offset, Serenity_ScrollResponse *response)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->beginLayoutScrollContainer);

	return ptr->vtbl->beginLayoutScrollContainer(instance, desc, offset, response);
}

Serenity_Result serenityBeginLayoutContainer(Serenity_Instance instance, const Serenity_LayoutContainerDesc *desc)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->beginLayoutContainer);

	return ptr->vtbl->beginLayoutContainer(instance, desc);
}

Serenity_Result serenityLayoutText(Serenity_Instance instance, const Serenity_LayoutContainerDesc *desc, const Serenity_TextDesc *text_desc)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->layoutText);

	return ptr->vtbl->layoutText(instance, desc, text_desc);
}

Serenity_Result serenityEndLayoutContainer(Serenity_Instance instance)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->endLayoutContainer);

	return ptr->vtbl->endLayoutContainer(instance);
}

Serenity_Result serenityBeginMaskRectangle(Serenity_Instance instance, const Serenity_MaskRectangleDesc *desc)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->beginMaskRectangle);

	return ptr->vtbl->beginMaskRectangle(instance, desc);
}

Serenity_Result serenityBeginMaskImage(Serenity_Instance instance, const Serenity_MaskImageDesc *desc)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->beginMaskImage);

	return ptr->vtbl->beginMaskImage(instance, desc);
}

Serenity_Result serenityBeginMaskText(Serenity_Instance instance, const Serenity_MaskTextDesc *desc)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->beginMaskText);

	return ptr->vtbl->beginMaskText(instance, desc);
}

Serenity_Result serenityBeginMaskCustom(Serenity_Instance instance, const Serenity_MaskCustomDesc *desc)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->beginMaskCustom);

	return ptr->vtbl->beginMaskCustom(instance, desc);
}

Serenity_Result serenityEndMask(Serenity_Instance instance)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->endMask);

	return ptr->vtbl->endMask(instance);
}

Serenity_Result serenityDecorateRectangle(Serenity_Instance instance, const Serenity_DecorationRectangleDesc *desc)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->decorateRectangle);

	return ptr->vtbl->decorateRectangle(instance, desc);
}

Serenity_Result serenityDecorateImage(Serenity_Instance instance, const Serenity_DecorationImageDesc *desc)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->decorateImage);

	return ptr->vtbl->decorateImage(instance, desc);
}

Serenity_Result serenityDecorateCustom(Serenity_Instance instance, const Serenity_DecorationCustomDesc *desc)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->decorateCustom);

	return ptr->vtbl->decorateCustom(instance, desc);
}

Serenity_Result serenityPointerTargetRectangle(Serenity_Instance instance, const Serenity_PointerTargetDesc *desc, Serenity_PointerTargetResponse *response)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->pointerTargetRectangle);

	return ptr->vtbl->pointerTargetRectangle(instance, desc, response);
}

Serenity_Result serenityPointerTargetEllipse(Serenity_Instance instance, const Serenity_PointerTargetDesc *desc, Serenity_PointerTargetResponse *response)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->pointerTargetEllipse);

	return ptr->vtbl->pointerTargetEllipse(instance);
}

Serenity_Result serenitySetFocus(Serenity_Instance instance, Serenity_FocusNodeId id)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->setFocus);

	return ptr->vtbl->setFocus(instance, id);
}

Serenity_Result serenityFocusNode(Serenity_Instance instance, const Serenity_FocusNodeDesc *desc, Serenity_FocusNodeResponse *response)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->focusNode);

	return ptr->vtbl->focusNode(instance, desc, response);
}

Serenity_Result serenityFocusLink(Serenity_Instance instance, const Serenity_FocusLinkDesc *desc)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->focusLink);

	return ptr->vtbl->focusLink(instance, desc);
}

Serenity_Result serenityBeginFocusSequence(Serenity_Instance instance, const Serenity_FocusSequenceDesc *desc)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->beginFocusSequence);

	return ptr->vtbl->beginFocusSequence(instance, desc);
}

Serenity_Result serenityEndFocusSequence(Serenity_Instance instance)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->endFocusSequence);

	return ptr->vtbl->endFocusSequence(instance);
}

Serenity_Result serenityDestroyInstance(Serenity_Instance instance)
{
	if (instance == SERENITY_NULL_HANDLE)
		return SERENITY_INVALID_INSTANCE;

	Serenity_InstanceInternal *ptr = (Serenity_InstanceInternal *)instance;
	assert(ptr->vtbl);
	assert(ptr->vtbl->destroyInstance);

	return ptr->vtbl->destroyInstance(instance);
}

#include "impl_internal.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>

/*
 */
static Serenity_Result impl_instanceSetPointerState(Serenity_Instance this, Serenity_PointerId id, Serenity_Vec2 root_position, uint32_t pressed)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(id);
	SERENITY_UNUSED(root_position);
	SERENITY_UNUSED(pressed);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceSetButtonState(Serenity_Instance this, Serenity_ButtonId id, uint32_t pressed)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(id);
	SERENITY_UNUSED(pressed);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceSetAxisState(Serenity_Instance this, Serenity_AxisId id, float value)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(id);
	SERENITY_UNUSED(value);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceAbortPointer(Serenity_Instance this, Serenity_PointerId id)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(id);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceAbortButton(Serenity_Instance this, Serenity_ButtonId id)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(id);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceAbortAxis(Serenity_Instance this, Serenity_AxisId id)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(id);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceBeginFrame(Serenity_Instance this, const Serenity_FrameDesc *desc)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceEndFrame(Serenity_Instance this, Serenity_RenderData *data)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(data);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceBeginRootContainer(Serenity_Instance this, const Serenity_ContainerDesc *desc, const Serenity_RootDesc *root_desc)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);
	SERENITY_UNUSED(root_desc);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceBeginContainer(Serenity_Instance this, const Serenity_ContainerDesc *desc)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceText(Serenity_Instance this, const Serenity_ContainerDesc *desc, const Serenity_TextDesc *text_desc)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);
	SERENITY_UNUSED(text_desc);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceEndContainer(Serenity_Instance this)
{
	SERENITY_UNUSED(this);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceBeginLayoutRootContainer(Serenity_Instance this, const Serenity_LayoutContainerDesc *desc, const Serenity_RootDesc *root_desc)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);
	SERENITY_UNUSED(root_desc);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceBeginLayoutScrollContainer(Serenity_Instance this, const Serenity_LayoutContainerDesc *desc, Serenity_Vec2 offset, Serenity_ScrollResponse *response)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);
	SERENITY_UNUSED(offset);
	SERENITY_UNUSED(response);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceBeginLayoutContainer(Serenity_Instance this, const Serenity_LayoutContainerDesc *desc)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceLayoutText(Serenity_Instance this, const Serenity_LayoutContainerDesc *desc, const Serenity_TextDesc *text_desc)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);
	SERENITY_UNUSED(text_desc);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceEndLayoutContainer(Serenity_Instance this)
{
	SERENITY_UNUSED(this);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceBeginMaskRectangle(Serenity_Instance this, const Serenity_MaskRectangleDesc *desc)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceBeginMaskImage(Serenity_Instance this, const Serenity_MaskImageDesc *desc)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceBeginMaskText(Serenity_Instance this, const Serenity_MaskTextDesc *desc)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceBeginMaskCustom(Serenity_Instance this, const Serenity_MaskCustomDesc *desc)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceEndMask(Serenity_Instance this)
{
	SERENITY_UNUSED(this);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceDecorateRectangle(Serenity_Instance this, const Serenity_DecorationRectangleDesc *desc)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceDecorateImage(Serenity_Instance this, const Serenity_DecorationImageDesc *desc)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceDecorateCustom(Serenity_Instance this, const Serenity_DecorationCustomDesc *desc)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instancePointerTargetRectangle(Serenity_Instance this, const Serenity_PointerTargetDesc *desc, Serenity_PointerTargetResponse *response)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);
	SERENITY_UNUSED(response);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instancePointerTargetEllipse(Serenity_Instance this, const Serenity_PointerTargetDesc *desc, Serenity_PointerTargetResponse *response)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);
	SERENITY_UNUSED(response);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceSetFocus(Serenity_Instance this, Serenity_FocusNodeId id)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(id);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceFocusNode(Serenity_Instance this, const Serenity_FocusNodeDesc *desc, Serenity_FocusNodeResponse *response)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);
	SERENITY_UNUSED(response);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceFocusLink(Serenity_Instance this, const Serenity_FocusLinkDesc *desc)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceBeginFocusSequence(Serenity_Instance this, const Serenity_FocusSequenceDesc *desc)
{
	SERENITY_UNUSED(this);
	SERENITY_UNUSED(desc);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceEndFocusSequence(Serenity_Instance this)
{
	SERENITY_UNUSED(this);

	return SERENITY_NOT_IMPLEMENTED;
}

static Serenity_Result impl_instanceDestroy(Serenity_Instance this)
{
	assert(this);

	Impl_Instance *ptr = (Impl_Instance *)this;

	free(ptr);
	return SERENITY_SUCCESS;
}

/*
 */
static Serenity_InstanceTable instance_vtbl =
{
	impl_instanceSetPointerState,
	impl_instanceSetButtonState,
	impl_instanceSetAxisState,

	impl_instanceAbortPointer,
	impl_instanceAbortButton,
	impl_instanceAbortAxis,

	impl_instanceBeginFrame,
	impl_instanceEndFrame,

	impl_instanceBeginRootContainer,
	impl_instanceBeginContainer,
	impl_instanceText,
	impl_instanceEndContainer,

	impl_instanceBeginLayoutRootContainer,
	impl_instanceBeginLayoutScrollContainer,
	impl_instanceBeginLayoutContainer,
	impl_instanceLayoutText,
	impl_instanceEndLayoutContainer,

	impl_instanceBeginMaskRectangle,
	impl_instanceBeginMaskImage,
	impl_instanceBeginMaskText,
	impl_instanceBeginMaskCustom,
	impl_instanceEndMask,

	impl_instanceDecorateRectangle,
	impl_instanceDecorateImage,
	impl_instanceDecorateCustom,

	impl_instancePointerTargetRectangle,
	impl_instancePointerTargetEllipse,

	impl_instanceSetFocus,
	impl_instanceFocusNode,
	impl_instanceFocusLink,

	impl_instanceBeginFocusSequence,
	impl_instanceEndFocusSequence,

	impl_instanceDestroy,
};

/*
 */
Serenity_Result impl_createInstance(const Serenity_InstanceDesc *desc, Serenity_Instance *instance)
{
	assert(desc);
	assert(instance);

	SERENITY_UNUSED(desc);

	Impl_Instance *ptr = (Impl_Instance *)malloc(sizeof(Impl_Instance));
	assert(ptr);

	// vtable
	ptr->vtbl = &instance_vtbl;

	// data

	// pools

	*instance = (Serenity_Instance)ptr;
	return SERENITY_SUCCESS;
}

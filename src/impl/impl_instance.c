#include "impl_internal.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>

/*
 */
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

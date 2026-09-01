#pragma once

#include <serenity.h>

#define SERENITY_UNUSED(x) do { (void)(x); } while(0)

Serenity_Result impl_createInstance(const Serenity_InstanceDesc *desc, Serenity_Instance *instance);

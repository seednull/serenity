#pragma once

#include <stdint.h> // TODO: get rid of this dependency later

// Version
#define SERENITY_VERSION_MAJOR 1
#define SERENITY_VERSION_MINOR 0
#define SERENITY_VERSION_PATCH 0
#define SERENITY_VERSION "1.0.0-dev"

// Platform specific defines
#if defined(_WIN32)
	#define SERENITY_EXPORT		__declspec(dllexport)
	#define SERENITY_IMPORT		__declspec(dllimport)
	#define SERENITY_INLINE		__forceinline
	#define SERENITY_RESTRICT	__restrict
#else
	#define SERENITY_EXPORT		__attribute__((visibility("default")))
	#define SERENITY_IMPORT
	#define SERENITY_INLINE		__inline__
	#define SERENITY_RESTRICT	__restrict
#endif

#if defined(SERENITY_SHARED_LIBRARY)
	#define SERENITY_APIENTRY extern SERENITY_EXPORT
#else
	#define SERENITY_APIENTRY extern SERENITY_IMPORT
#endif

#if !defined(SERENITY_NULL_HANDLE)
	#define SERENITY_NULL_HANDLE 0
#endif

#define SERENITY_DEFINE_HANDLE(TYPE) typedef uint64_t TYPE

#ifdef __cplusplus
extern "C" {
#endif

// Opaque handles
SERENITY_DEFINE_HANDLE(Serenity_Instance);

// Enums
typedef enum Serenity_Result_t
{
	SERENITY_SUCCESS = 0,

	SERENITY_NOT_IMPLEMENTED,
	SERENITY_INVALID_INSTANCE,
	SERENITY_INVALID_OUTPUT_ARGUMENT,

	// FIXME: add more error codes for internal errors
	SERENITY_INTERNAL_ERROR,

	SERENITY_RESULT_ENUM_MAX,
	SERENITY_RESULT_ENUM_FORCE32 = 0x7FFFFFFF,
} Serenity_Result;

// Structs
typedef struct Serenity_InstanceDesc_t
{
	uint32_t max_containers;
	uint32_t max_container_nesting_depth;
	uint32_t max_masks;
	uint32_t max_mask_nesting_depth;
	uint32_t max_decorations;
	// TODO: text shaping func ptr
} Serenity_InstanceDesc;

typedef struct Serenity_Vec2_t
{
	float x;
	float y;
} Serenity_Vec2;

typedef struct Serenity_Sides_t
{
	float left;
	float right;
	float top;
	float bottom;
} Serenity_Sides;

typedef struct Serenity_Corners_t
{
	float left_top;
	float left_bottom;
	float right_top;
	float right_bottom;
} Serenity_Corners;

typedef struct Serenity_Color_t
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
} Serenity_Color;

typedef struct Serenity_Rect_t
{
	Serenity_Vec2 min;
	Serenity_Vec2 max;
} Serenity_Rect;

typedef struct Serenity_AnchoredRect_t
{
	Serenity_Vec2 min_anchor;
	Serenity_Vec2 max_anchor;
	Serenity_Vec2 min_offset;
	Serenity_Vec2 max_offset;
} Serenity_AnchoredRect;

typedef struct Serenity_FrameDesc_t
{
	Serenity_Rect root_rect;
} Serenity_FrameDesc;

typedef struct Serenity_ContainerDesc_t
{
	uint64_t id;
	Serenity_Rect local_rect;
} Serenity_ContainerDesc;

typedef struct Serenity_MaskBoxDesc_t
{
	uint64_t id;
	Serenity_AnchoredRect anchored_rect;
	Serenity_Sides falloff;
} Serenity_MaskBoxDesc;

typedef struct Serenity_MaskImageDesc_t
{
	uint64_t id;
	Serenity_AnchoredRect anchored_rect;
	uint64_t image_id;
} Serenity_MaskImageDesc;

typedef struct Serenity_DecorationBoxStyle_t
{
	Serenity_Corners radii;
	Serenity_Color color;
} Serenity_DecorationBoxStyle;

typedef struct Serenity_DecorationTextStyle_t
{
	Serenity_Color color;
} Serenity_DecorationTextStyle;

typedef struct Serenity_DecorationBoxDesc_t
{
	Serenity_AnchoredRect anchored_rect;
	Serenity_DecorationBoxStyle style;
} Serenity_DecorationBoxDesc;

typedef struct Serenity_DecorationImageDesc_t
{
	Serenity_AnchoredRect anchored_rect;
	uint64_t image_id;
} Serenity_DecorationImageDesc;

typedef struct Serenity_DecorationTextDesc_t
{
	Serenity_AnchoredRect anchored_rect;
	Serenity_DecorationTextStyle style;
	const char *text;
	uint64_t text_size;
} Serenity_DecorationTextDesc;

typedef struct Serenity_DecorationCustomDesc_t
{
	Serenity_AnchoredRect anchored_rect;
	const void *data;
	uint64_t data_size;
} Serenity_DecorationCustomDesc;

// Function pointers
// TODO: add function pointers once API surface is finished
typedef Serenity_Result (*PFN_serenityDestroyInstance)(Serenity_Instance instance);

typedef struct Serenity_InstanceTable_t
{
	// TODO: add function pointers once API surface is finished

	PFN_serenityDestroyInstance destroyInstance;
} Serenity_InstanceTable;

// API
#if !defined(SERENITY_NO_PROTOTYPES)
SERENITY_APIENTRY Serenity_Result serenityCreateInstance(const Serenity_InstanceDesc *desc, Serenity_Instance* instance);
SERENITY_APIENTRY Serenity_Result serenityGetInstanceTable(Serenity_Instance instance, Serenity_InstanceTable *instance_table);

SERENITY_APIENTRY Serenity_Result serenityBeginFrame(Serenity_Instance instance, const Serenity_FrameDesc *desc);
SERENITY_APIENTRY Serenity_Result serenityEndFrame(Serenity_Instance instance);

SERENITY_APIENTRY Serenity_Result serenityBeginContainer(Serenity_Instance instance, const Serenity_ContainerDesc *desc);
SERENITY_APIENTRY Serenity_Result serenityEndContainer(Serenity_Instance instance);

SERENITY_APIENTRY Serenity_Result serenityBeginMaskBox(Serenity_Instance instance, const Serenity_MaskBoxDesc *desc);
SERENITY_APIENTRY Serenity_Result serenityBeginMaskImage(Serenity_Instance instance, const Serenity_MaskImageDesc *desc);
SERENITY_APIENTRY Serenity_Result serenityEndMask(Serenity_Instance instance);

SERENITY_APIENTRY Serenity_Result serenityDecorateBox(Serenity_Instance instance, const Serenity_DecorationBoxDesc *desc);
SERENITY_APIENTRY Serenity_Result serenityDecorateImage(Serenity_Instance instance, const Serenity_DecorationImageDesc *desc);
SERENITY_APIENTRY Serenity_Result serenityDecorateText(Serenity_Instance instance, const Serenity_DecorationTextDesc *desc);
SERENITY_APIENTRY Serenity_Result serenityDecorateCustom(Serenity_Instance instance, const Serenity_DecorationCustomDesc *desc);

SERENITY_APIENTRY Serenity_Result serenityDestroyInstance(Serenity_Instance instance);
#endif

#ifdef __cplusplus
}
#endif

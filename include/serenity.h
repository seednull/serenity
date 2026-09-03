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

#if !defined(SERENITY_ID_NONE)
	#define SERENITY_ID_NONE 0
#endif

#define SERENITY_DEFINE_HANDLE(TYPE) typedef uint64_t TYPE
#define SERENITY_DEFINE_ID(TYPE) typedef uint32_t TYPE

#ifdef __cplusplus
extern "C" {
#endif

// Opaque handles
SERENITY_DEFINE_HANDLE(Serenity_Instance);

// Ids
SERENITY_DEFINE_ID(Serenity_ContainerId);
SERENITY_DEFINE_ID(Serenity_ImageId);
SERENITY_DEFINE_ID(Serenity_FontId);
SERENITY_DEFINE_ID(Serenity_CustomTypeId);

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

typedef enum Serenity_ShapedGlyphFlags_t
{
	SERENITY_SHAPED_GLYPH_FLAGS_INVISIBLE = 0x00000001,
	SERENITY_SHAPED_GLYPH_FLAGS_UNSAFE_TO_BREAK = 0x00000002,

	SERENITY_SHAPED_GLYPH_FLAGS_ENUM_FORCE32 = 0x7FFFFFFF,
} Serenity_ShapedGlyphFlags;

typedef enum Serenity_TextBreakType_t
{
	SERENITY_TEXT_BREAK_ALLOWED = 0,
	SERENITY_TEXT_BREAK_MANDATORY,

	SERENITY_TEXT_BREAK_TYPE_ENUM_MAX,
	SERENITY_TEXT_BREAK_TYPE_ENUM_FORCE32 = 0x7FFFFFFF,
} Serenity_TextBreakType;

typedef enum Serenity_RenderMaskType_t
{
	SERENITY_RENDER_MASK_TYPE_RECTANGLE = 0,
	SERENITY_RENDER_MASK_TYPE_IMAGE,
	SERENITY_RENDER_MASK_TYPE_TEXT,
	SERENITY_RENDER_MASK_TYPE_CUSTOM,

	SERENITY_RENDER_MASK_TYPE_ENUM_MAX,
	SERENITY_RENDER_MASK_TYPE_ENUM_FORCE32 = 0x7FFFFFFF,
} Serenity_RenderMaskType;

typedef enum Serenity_RenderCommandType_t
{
	SERENITY_RENDER_COMMAND_TYPE_RECTANGLE = 0,
	SERENITY_RENDER_COMMAND_TYPE_IMAGE,
	SERENITY_RENDER_COMMAND_TYPE_TEXT,
	SERENITY_RENDER_COMMAND_TYPE_CUSTOM,

	SERENITY_RENDER_COMMAND_TYPE_ENUM_MAX,
	SERENITY_RENDER_COMMAND_TYPE_ENUM_FORCE32 = 0x7FFFFFFF,
} Serenity_RenderCommandType;

// Structs
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

typedef struct Serenity_TextSpan_t
{
	const char *data;
	uint32_t length;
} Serenity_TextSpan;

typedef struct Serenity_FontDesc_t
{
	Serenity_FontId id;
	float line_height; // TODO: abstraction leak, fix this somehow
} Serenity_FontDesc;

typedef struct Serenity_FrameDesc_t
{
	Serenity_Rect root_rect;
} Serenity_FrameDesc;

typedef struct Serenity_ContainerDesc_t
{
	Serenity_ContainerId id;
	Serenity_Rect local_rect;
} Serenity_ContainerDesc;

typedef struct Serenity_MaskRectangleStyle_t
{
	Serenity_Corners radii;
	Serenity_Sides falloff;
} Serenity_MaskRectangleStyle;

typedef struct Serenity_MaskRectangleDesc_t
{
	Serenity_AnchoredRect anchored_rect;
	Serenity_MaskRectangleStyle style;
} Serenity_MaskRectangleDesc;

typedef struct Serenity_MaskImageDesc_t
{
	Serenity_AnchoredRect anchored_rect;
	Serenity_ImageId image_id;
} Serenity_MaskImageDesc;

typedef struct Serenity_MaskTextDesc_t
{
	Serenity_AnchoredRect anchored_rect;
	Serenity_TextSpan text;
	Serenity_FontDesc font;
} Serenity_MaskTextDesc;

typedef struct Serenity_MaskCustomDesc_t
{
	Serenity_AnchoredRect anchored_rect;
	Serenity_CustomTypeId type_id;
	const void *data;
	uint64_t data_size;
} Serenity_MaskCustomDesc;

typedef struct Serenity_DecorationRectangleStyle_t
{
	Serenity_Corners radii;
	Serenity_Color color;
} Serenity_DecorationRectangleStyle;

typedef struct Serenity_DecorationTextStyle_t
{
	Serenity_Color color;
} Serenity_DecorationTextStyle;

typedef struct Serenity_DecorationRectangleDesc_t
{
	Serenity_AnchoredRect anchored_rect;
	Serenity_DecorationRectangleStyle style;
} Serenity_DecorationRectangleDesc;

typedef struct Serenity_DecorationImageDesc_t
{
	Serenity_AnchoredRect anchored_rect;
	Serenity_ImageId image_id;
} Serenity_DecorationImageDesc;

typedef struct Serenity_DecorationTextDesc_t
{
	Serenity_AnchoredRect anchored_rect;
	Serenity_TextSpan text;
	Serenity_FontDesc font;
	Serenity_DecorationTextStyle style;
} Serenity_DecorationTextDesc;

typedef struct Serenity_DecorationCustomDesc_t
{
	Serenity_AnchoredRect anchored_rect;
	Serenity_CustomTypeId type_id;
	const void *data;
	uint64_t data_size;
} Serenity_DecorationCustomDesc;

typedef struct Serenity_ShapedGlyph_t
{
	Serenity_FontId font_id;
	Serenity_ShapedGlyphFlags flags;

	uint32_t glyph_id;
	uint32_t cluster;

	Serenity_Vec2 advance;
	Serenity_Vec2 offset;

	Serenity_Rect local_bounds;
} Serenity_ShapedGlyph;

typedef struct Serenity_TextBreak_t
{
	Serenity_TextBreakType type;

	uint32_t text_end;
	uint32_t next_text;
} Serenity_TextBreak;

typedef struct Serenity_RenderTransform_t
{
	float m[3][2];
} Serenity_RenderTransform;

typedef struct Serenity_RenderMaskDataRectangle_t
{
	Serenity_Corners radii;
	Serenity_Sides falloff;
} Serenity_RenderMaskDataRectangle;

typedef struct Serenity_RenderMaskDataImage_t
{
	Serenity_ImageId id;
} Serenity_RenderMaskDataImage;

typedef struct Serenity_RenderMaskDataText_t
{
	uint64_t first_glyph;
	uint64_t num_glyphs;
} Serenity_RenderMaskDataText;

typedef struct Serenity_RenderMaskDataCustom_t
{
	Serenity_CustomTypeId type_id;
	uint64_t offset;
	uint64_t size;
} Serenity_RenderMaskDataCustom;

typedef union Serenity_RenderMaskData_t
{
	Serenity_RenderMaskDataRectangle rectangle;
	Serenity_RenderMaskDataImage image;
	Serenity_RenderMaskDataText text;
	Serenity_RenderMaskDataCustom custom;
} Serenity_RenderMaskData;

typedef struct Serenity_RenderMask_t
{
	Serenity_RenderMaskType type;
	Serenity_RenderMaskData data;

	uint64_t mask;
	Serenity_Rect local_rect;
	Serenity_RenderTransform transform;
} Serenity_RenderMask;

typedef struct Serenity_RenderCommandDataRectangle_t
{
	Serenity_Corners radii;
	Serenity_Color color;
} Serenity_RenderCommandDataRectangle;

typedef struct Serenity_RenderCommandDataImage_t
{
	Serenity_ImageId id;
} Serenity_RenderCommandDataImage;

typedef struct Serenity_RenderCommandDataText_t
{
	uint64_t first_glyph;
	uint64_t num_glyphs;
	Serenity_Color color;
} Serenity_RenderCommandDataText;

typedef struct Serenity_RenderCommandDataCustom_t
{
	Serenity_CustomTypeId type_id;
	uint64_t offset;
	uint64_t size;
} Serenity_RenderCommandDataCustom;

typedef union Serenity_RenderCommandData_t
{
	Serenity_RenderCommandDataRectangle rectangle;
	Serenity_RenderCommandDataImage image;
	Serenity_RenderCommandDataText text;
	Serenity_RenderCommandDataCustom custom;
} Serenity_RenderCommandData;

typedef struct Serenity_RenderCommand_t
{
	Serenity_RenderCommandType type;
	Serenity_RenderCommandData data;

	uint64_t mask;
	Serenity_Rect local_rect;
	Serenity_RenderTransform transform;
} Serenity_RenderCommand;

typedef struct Serenity_RenderGlyph_t
{
	Serenity_FontId font_id;
	uint32_t glyph_id;

	Serenity_Rect local_rect;
} Serenity_RenderGlyph;

typedef struct Serenity_RenderData_t
{
	uint64_t num_masks;
	const Serenity_RenderMask *masks;

	uint64_t num_commands;
	const Serenity_RenderCommand *commands;

	uint64_t num_glyphs;
	const Serenity_RenderGlyph *glyphs;

	uint64_t custom_data_size;
	const void *custom_data;
} Serenity_RenderData;

// Function pointers
typedef Serenity_Result (*PFN_serenityShapeText)(void *user_data, Serenity_TextSpan text, Serenity_FontDesc font, uint32_t max_glyphs, Serenity_ShapedGlyph *glyphs, uint32_t *glyphs_written);
typedef Serenity_Result (*PFN_serenityBreakText)(void *user_data, Serenity_TextSpan text, uint32_t max_breaks, Serenity_TextBreak *breaks, uint32_t *breaks_written);

// TODO: add function pointers once API surface is finished
typedef Serenity_Result (*PFN_serenityDestroyInstance)(Serenity_Instance instance);

typedef struct Serenity_InstanceTable_t
{
	// TODO: add function pointers once API surface is finished

	PFN_serenityDestroyInstance destroyInstance;
} Serenity_InstanceTable;

typedef struct Serenity_InstanceDesc_t
{
	uint32_t max_containers;
	uint32_t max_container_nesting_depth;
	uint32_t max_masks;
	uint32_t max_mask_nesting_depth;
	uint32_t max_decorations;
	uint32_t max_custom_data_size;

	PFN_serenityShapeText shapeText;
	PFN_serenityBreakText breakText;
	void *user_data;
} Serenity_InstanceDesc;

// API
#if !defined(SERENITY_NO_PROTOTYPES)
SERENITY_APIENTRY Serenity_Result serenityCreateInstance(const Serenity_InstanceDesc *desc, Serenity_Instance* instance);
SERENITY_APIENTRY Serenity_Result serenityGetInstanceTable(Serenity_Instance instance, Serenity_InstanceTable *instance_table);

SERENITY_APIENTRY Serenity_Result serenityBeginFrame(Serenity_Instance instance, const Serenity_FrameDesc *desc);
SERENITY_APIENTRY Serenity_Result serenityEndFrame(Serenity_Instance instance, Serenity_RenderData *data);

SERENITY_APIENTRY Serenity_Result serenityBeginContainer(Serenity_Instance instance, const Serenity_ContainerDesc *desc);
SERENITY_APIENTRY Serenity_Result serenityEndContainer(Serenity_Instance instance);

SERENITY_APIENTRY Serenity_Result serenityBeginMaskRectangle(Serenity_Instance instance, const Serenity_MaskRectangleDesc *desc);
SERENITY_APIENTRY Serenity_Result serenityBeginMaskImage(Serenity_Instance instance, const Serenity_MaskImageDesc *desc);
SERENITY_APIENTRY Serenity_Result serenityBeginMaskText(Serenity_Instance instance, const Serenity_MaskTextDesc *desc);
SERENITY_APIENTRY Serenity_Result serenityBeginMaskCustom(Serenity_Instance instance, const Serenity_MaskCustomDesc *desc);
SERENITY_APIENTRY Serenity_Result serenityEndMask(Serenity_Instance instance);

SERENITY_APIENTRY Serenity_Result serenityDecorateRectangle(Serenity_Instance instance, const Serenity_DecorationRectangleDesc *desc);
SERENITY_APIENTRY Serenity_Result serenityDecorateImage(Serenity_Instance instance, const Serenity_DecorationImageDesc *desc);
SERENITY_APIENTRY Serenity_Result serenityDecorateText(Serenity_Instance instance, const Serenity_DecorationTextDesc *desc);
SERENITY_APIENTRY Serenity_Result serenityDecorateCustom(Serenity_Instance instance, const Serenity_DecorationCustomDesc *desc);

SERENITY_APIENTRY Serenity_Result serenityDestroyInstance(Serenity_Instance instance);
#endif

#ifdef __cplusplus
}
#endif

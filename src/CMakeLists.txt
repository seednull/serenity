cmake_minimum_required(VERSION 3.10)
set(TARGET serenity)

# ==================================================================================================
# Options
# ==================================================================================================

# ==================================================================================================
# Variables
# ==================================================================================================
set(SERENITY_PLATFORM_DEFINES "")
set(SERENITY_TARGET_TYPE SHARED)

if (WIN32)
	set(SERENITY_PLATFORM_DEFINES SERENITY_PLATFORM_WIN32 SERENITY_SHARED_LIBRARY NOMINMAX)
endif()

if (APPLE)
	set(SERENITY_PLATFORM_DEFINES SERENITY_PLATFORM_MACOS SERENITY_SHARED_LIBRARY)
endif()

if (EMSCRIPTEN)
	set(SERENITY_PLATFORM_DEFINES SERENITY_PLATFORM_WEB)
	set(SERENITY_TARGET_TYPE STATIC)
endif()

# ==================================================================================================
# Dependencies
# ==================================================================================================

# ==================================================================================================
# Sources
# ==================================================================================================
file(GLOB SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.c
	${CMAKE_CURRENT_SOURCE_DIR}/common/*.c
	${CMAKE_CURRENT_SOURCE_DIR}/impl/*.c
)

file(GLOB HEADERS
	${CMAKE_CURRENT_SOURCE_DIR}/*.h
	${CMAKE_CURRENT_SOURCE_DIR}/common/*.h
	${CMAKE_CURRENT_SOURCE_DIR}/impl/*.h
)

file (GLOB PUBLIC_HEADERS
	${SERENITY_DIR_API}/serenity.h
)

# ==================================================================================================
# Target
# ==================================================================================================
add_library(${TARGET} ${SERENITY_TARGET_TYPE} ${SOURCES} ${HEADERS} ${PUBLIC_HEADERS})

set_target_properties(${TARGET} PROPERTIES DEBUG_POSTFIX d)
set_target_properties(${TARGET} PROPERTIES PUBLIC_HEADER ${PUBLIC_HEADERS})

if (WIN32)
	set_target_properties(${TARGET} PROPERTIES PREFIX "")
	set_target_properties(${TARGET} PROPERTIES IMPORT_PREFIX "")
	set_target_properties(${TARGET} PROPERTIES IMPORT_SUFFIX ".lib")
else()
	set_target_properties(${TARGET} PROPERTIES IMPORT_SUFFIX ".a")
endif()

# ==================================================================================================
# Includes
# ==================================================================================================
target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${SERENITY_DIR_API})

# ==================================================================================================
# Preprocessor
# ==================================================================================================
target_compile_definitions(${TARGET} PRIVATE ${SERENITY_PLATFORM_DEFINES})

# ==================================================================================================
# Linker
# ==================================================================================================

# ==================================================================================================
# Libraries
# ==================================================================================================

# ==================================================================================================
# Installation
# ==================================================================================================
install(
	TARGETS ${TARGET}
	EXPORT ${TARGET}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	INCLUDES DESTINATION include
	PUBLIC_HEADER DESTINATION include
)

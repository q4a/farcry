set(PROJECT_NAME FARCRY)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "resource.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "Main.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${ALL_FILES})

#use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    TARGET_NAME_DEBUG     "${TARGET_NAME}$ENV{TargetExt}"
    TARGET_NAME_RELEASE   "${TARGET_NAME}$ENV{TargetExt}"
    TARGET_NAME_RELEASE64 "${TARGET_NAME}$ENV{TargetExt}"
)

set_target_properties(${PROJECT_NAME} PROPERTIES
OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../Bin32"
OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../Bin32"
OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_SOURCE_DIR}/../Bin32"
OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_SOURCE_DIR}/../Bin32"
LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../Bin32"
LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../Bin32"
LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_SOURCE_DIR}/../Bin32"
LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_SOURCE_DIR}/../Bin32"
)

################################################################################
# MSVC runtime library
################################################################################
#get_property(MSVC_RUNTIME_LIBRARY_DEFAULT TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY)
#string(CONCAT "MSVC_RUNTIME_LIBRARY_STR"
#    $<$<CONFIG:Debug>:
#        MultiThreadedDLL
#    >
#    $<$<CONFIG:Debug64>:
#        MultiThreadedDebugDLL
#    >
#    $<$<CONFIG:Profile>:
#        MultiThreadedDLL
#    >
#    $<$<CONFIG:Release>:
#        MultiThreadedDLL
#    >
#    $<$<CONFIG:Release64>:
#        MultiThreadedDLL
#    >
#    $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Debug64>,$<CONFIG:Profile>,$<CONFIG:Release>,$<CONFIG:Release64>>>:${MSVC_RUNTIME_LIBRARY_DEFAULT}>
#)
#set_target_properties(${PROJECT_NAME} PROPERTIES MSVC_RUNTIME_LIBRARY ${MSVC_RUNTIME_LIBRARY_STR})

################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/../CryCommon"
)

################################################################################
# Compile definitions
################################################################################
#target_compile_definitions(${PROJECT_NAME} PRIVATE
#    "$<$<CONFIG:Debug>:"
#        "_RELEASE;"
#        "NDEBUG"
#    ">"
#    "$<$<CONFIG:Debug64>:"
#        "_DEBUG"
#    ">"
#    "$<$<CONFIG:Profile>:"
#        "NDEBUG"
#    ">"
#    "$<$<CONFIG:Release>:"
#        "_RELEASE;"
#        "NDEBUG"
#    ">"
#    "$<$<CONFIG:Release64>:"
#        "_RELEASE;"
#        "NDEBUG"
#    ">"
#    "WIN32;"
#   "_WINDOWS;"
#    "_USRDLL;"
#    "CRYSYSTEM_EXPORTS;"
#    "_MBCS"
#)

target_compile_definitions(${PROJECT_NAME} PRIVATE "CRYSYSTEM_EXPORTS")

################################################################################
# Compile and link options
################################################################################

################################################################################
# Dependencies
################################################################################

#TODO: Make this toggle later, but for now we are disabling it since we only build for linux
#set(ADDITIONAL_LIBRARY_DEPENDENCIES
#    "wininet"
#)
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")


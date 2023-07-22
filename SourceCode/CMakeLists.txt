cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

project(Game01 C CXX)

################################################################################
# Output directory
################################################################################

################################################################################
# Common utils
################################################################################
include(CMake/Utils.cmake)

################################################################################
# Additional Global Settings(add specific info there)
################################################################################
include(CMake/GlobalSettingsInclude.cmake OPTIONAL)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -DLINUX -DLINUX64 -w -fpermissive -lcpuid")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -DLINUX -DLINUX64 -w -fpermissive -lcpuid")

################################################################################
# Use solution folders feature
################################################################################
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

################################################################################
# Sub-projects
################################################################################
add_subdirectory(CryCommon)
add_subdirectory(CrySystem)
add_subdirectory(CryScriptSystem)
add_subdirectory(CryNetwork)
add_subdirectory(CryPhysics)
add_subdirectory(RenderDll/XRenderNULL)
#add_subdirectory(RenderDll/XRenderOGL)
#add_subdirectory(CryInput) Denis Koveshnikov is working on this
add_subdirectory(CrySoundSystem)
add_subdirectory(CryFont)
add_subdirectory(CryAISystem)
add_subdirectory(CryEntitySystem)
add_subdirectory(CryAnimation)
add_subdirectory(Cry3DEngine)
add_subdirectory(CryGame)
add_subdirectory(FARCRY)

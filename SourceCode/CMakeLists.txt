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
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -DLINUX -DLINUX64 -fpermissive -w")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -DLINUX -DLINUX64 -fpermissive -w")

################################################################################
# Use solution folders feature
################################################################################
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

################################################################################
# Sub-projects
################################################################################
add_subdirectory(CryCommon)
add_subdirectory(CrySystem)


#add_subdirectory(FARCRY)
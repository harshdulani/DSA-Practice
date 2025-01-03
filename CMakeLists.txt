cmake_minimum_required(VERSION 3.30.0-rc3)
project(DSA_Practice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add standard build types
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

# Collect all source files recursively
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "source/*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "source/*.h")

add_executable(DSA source/Main.cpp)

# Add these sources to the main executable
target_sources(DSA PRIVATE ${SOURCES} ${HEADERS})
# Include directories for all subfolders
target_include_directories(DSA PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source/")
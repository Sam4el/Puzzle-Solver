cmake_minimum_required(VERSION 3.16)
project(puzzleSolver)

set(CMAKE_CXX_STANDARD 17)
# Don't silently fall back to an older version if C++17 is not available
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add include directories
# Header locations for #include "something.h"
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Add subdirectory
# There is another CMakeLists.txt in this catalog
add_subdirectory(src/) # TODO

# Add executable
# Build executable from there
add_executable(puzzleSolver src/main.cpp)

# Link modules
# Link puzzleSolver with XYZ library
# PRIVATE means only puzzleSolver will know about this,
# not thing that depend on puzzleSolver
target_link_libraries(puzzleSolver PRIVATE xyz)

# Add GoogleTest
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

# Only do this for testing
FetchContent_MakeAvailable(googletest)

enable_testing()
add_subdirectory(test/xyz) # TODO
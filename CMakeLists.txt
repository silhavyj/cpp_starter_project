# Minimum required version of cmake
cmake_minimum_required(VERSION 3.0)

# Specify the C++ standard used in the project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the name of the project, version, description,
# home URL, and a list of all languages used in the project
project(
    myproject
    VERSION 0.0.1
    DESCRIPTION ""
    HOMEPAGE_URL "%%myurl%%"
    LANGUAGES CXX C)

# Add include directories, so there is no need
# to specify relative paths
include_directories(lib)
include_directories(include)

# Add submodules (libraries)
add_subdirectory(external/spdlog)
add_subdirectory(external/cxxopts)
add_subdirectory(external/googletest)
add_subdirectory(external/sdl)

# Add src folder
add_subdirectory(src)

# Add test folder
enable_testing()
add_subdirectory(test)

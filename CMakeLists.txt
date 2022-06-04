# Minimum required version of cmake
cmake_minimum_required(VERSION 3.0)

# Specify the C++ standard used in the project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add name of the project, version, description,
# home URL, and a list of all languages used in the project
project(
    myproject
    VERSION 0.0.1
    DESCRIPTION ""
    HOMEPAGE_URL "%%myurl%%"
    LANGUAGES CXX C)

# Specify compile options
if(MSVC)
    string(REGEX REPLACE "/W[1-3]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# Add include directories, so there is no need
# to specify relative paths
include_directories(lib)
include_directories(include)

# Add sumbodules (libraries)
add_subdirectory(extern/spdlog)
add_subdirectory(extern/cxxopts)
add_subdirectory(extern/googletest)

# Add src folder
add_subdirectory(src)

# Add test folder
option(ENABLE_TESTING "Enable the tests" ${PROJECT_IS_TOP_LEVEL})
if(ENABLE_TESTING)
  enable_testing()
  add_subdirectory(test)
endif()
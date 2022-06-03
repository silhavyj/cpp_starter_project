cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(
    myproject
    VERSION 0.0.1
    DESCRIPTION ""
    HOMEPAGE_URL "%%myurl%%"
    LANGUAGES CXX C)

include_directories(lib)
include_directories(include)

add_subdirectory(extern/spdlog)
add_subdirectory(extern/cxxopts)
add_subdirectory(extern/googletest)

add_subdirectory(src)

option(ENABLE_TESTING "Enable the tests" ${PROJECT_IS_TOP_LEVEL})
if(ENABLE_TESTING)
  enable_testing()
  add_subdirectory(test)
endif()
# Specify compile options
if(MSVC)
    string(REGEX REPLACE "/W[1-3]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# Find all .cpp files (recursively)
file(GLOB_RECURSE cpp_files "./*.cpp")

# List all source files that make up the final executable
add_executable(${PROJECT_NAME} ${cpp_files})

# Link libraries to the executable
target_link_libraries(
    ${PROJECT_NAME}
    spdlog
    cxxopts
    glfw)
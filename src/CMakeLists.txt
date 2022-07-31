# Specify compile options
if(MSVC)
    string(REGEX REPLACE "/W[1-3]" "/W4" "/O1" "/O2" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror -O3)
endif()

# Locate OpenGL (this dependency must be installed separately)
find_package(OpenGL REQUIRED)

# Add include directories, so there is no need to specify relative paths
include_directories(../external/imgui)
include_directories(../external/imgui/backends)
include_directories(../external/implot)

# Find all .cpp files (recursively)
file(GLOB_RECURSE cpp_files "./*.cpp")

# Find all imgui .cpp files
file(GLOB imgui_cpp_files "../external/imgui/*.cpp")

# Find all imgui backend .cpp files
file(GLOB imgui_backend_cpp_files
    ../external/imgui/backends/imgui_impl_sdl.cpp
    ../external/imgui/backends/imgui_impl_opengl2.cpp)

# Find all implot .cpp files
file (GLOB implot_cpp_files "../external/implot/*.cpp")

# List all source files that make up the final executable
add_executable(
    ${PROJECT_NAME}
    ${cpp_files}
    ${imgui_cpp_files}
    ${imgui_backend_cpp_files}
    ${implot_cpp_files})

# Link libraries to the executable
target_link_libraries(
    ${PROJECT_NAME}
    ${OPENGL_gl_LIBRARY}
    spdlog
    cxxopts
    SDL2)

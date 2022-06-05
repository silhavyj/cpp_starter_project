# Specify compile options
if(MSVC)
    string(REGEX REPLACE "/W[1-3]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# Locate OpenGL (this dependency must be installed separately)
find_package(OpenGL REQUIRED)

# Find all .cpp files (recursively)
file(GLOB_RECURSE cpp_files "./*.cpp")

# List all source files that make up the final executable
add_executable(
    ${PROJECT_NAME}
    ${cpp_files}
    ../external/imgui/imgui.cpp 
    ../external/imgui/imgui_demo.cpp
    ../external/imgui/imgui_draw.cpp
    ../external/imgui/imgui_tables.cpp
    ../external/imgui/imgui_widgets.cpp
    ../external/imgui/backends/imgui_impl_sdl.cpp
    ../external/imgui/backends/imgui_impl_opengl2.cpp)

# Link libraries to the executable
target_link_libraries(
    ${PROJECT_NAME}
    ${OPENGL_gl_LIBRARY}
    spdlog
    cxxopts
    SDL2)
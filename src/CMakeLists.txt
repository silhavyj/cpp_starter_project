# List all source files that make up the final executable
add_executable(
    ${PROJECT_NAME}
    main.cpp
    my_math.cpp)

# Link libraries to the executable
target_link_libraries(
    ${PROJECT_NAME}
    spdlog
    cxxopts)
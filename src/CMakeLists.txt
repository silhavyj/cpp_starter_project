add_executable(${PROJECT_NAME} main.cpp my_math.cpp)

target_link_libraries(
    ${PROJECT_NAME}
    spdlog
    cxxopts)
add_executable(MyTest 
    main.cpp
    tests1.cpp ../src/my_math.cpp)

target_link_libraries(MyTest gtest)

enable_testing()

add_test(MyTest test)
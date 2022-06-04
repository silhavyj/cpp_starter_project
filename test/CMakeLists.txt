add_executable(mytest 
    main.cpp
    tests1.cpp ../src/my_math.cpp)

target_link_libraries(mytest gtest)
add_test(mytest test)
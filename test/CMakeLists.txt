# List all test files that make up the
# final executable (mytest)
add_executable(
    mytest 
    main.cpp
    tests1.cpp ../src/my_math.cpp)

# Link googletest to the final executable
target_link_libraries(mytest gtest)

# Add the test
add_test(mytest test)
cmake_minimum_required(VERSION 3.10)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add main application
add_executable(calculator main.cpp calculator.cpp)

# GoogleTest requires threading support
find_package(Threads REQUIRED)

# Enable Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test executable
add_executable(test_calculator test_calculator.cpp calculator.cpp)
target_link_libraries(test_calculator ${GTEST_LIBRARIES} Threads::Threads)

# Include Google Test in CTest
include(GoogleTest)
gtest_discover_tests(test_calculator)

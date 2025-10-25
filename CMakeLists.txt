cmake_minimum_required(VERSION 3.10)
project(oop_lab3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(include)

add_library(figures_lib 
    src/Figure.cpp
    src/Trapeze.cpp
    src/Rhombus.cpp
    src/Pentagon.cpp
)

add_executable(main_app main.cpp)
target_link_libraries(main_app figures_lib)

enable_testing()
add_executable(tests test/tests.cpp)
target_link_libraries(tests figures_lib gtest_main)

add_test(NAME GeometryTests COMMAND tests)
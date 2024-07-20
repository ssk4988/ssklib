cmake_minimum_required(VERSION 3.5)
project(lib VERSION 0.1.0 LANGUAGES CXX)


if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
    enable_testing()
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 17)
include(CPack)

# include_directories(${CMAKE_CURRENT_SOURCE_DIR})
option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()


# Define library targets
add_library(lib STATIC src/lib.cpp)
target_include_directories(lib PUBLIC include)


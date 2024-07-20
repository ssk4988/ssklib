# Download and build Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.10.0.tar.gz
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


macro(package_add_test TESTNAME)
    # create an executable in which the tests will be stored
    add_executable(${TESTNAME} ${ARGN})
    # link the Google test infrastructure, mocking library, and a default main function to
    # the test executable.  Remove g_test_main if writing your own main function.
    target_link_libraries(${TESTNAME} gtest gtest_main)
    target_link_libraries(${TESTNAME} lib)
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    # gtest_discover_tests replaces gtest_add_tests,
    # see https://cmake.org/cmake/help/v3.10/module/GoogleTest.html for more options to pass to it
    # gtest_discover_tests(${TESTNAME}
    #     # set a working directory so your project root so that you can find test data via paths relative to the project root
    #     WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    #     PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
    # )
    # set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

package_add_test(test_LRUCache test_LRUCache.cpp)
package_add_test(test_LRUCacheT test_LRUCacheT.cpp)

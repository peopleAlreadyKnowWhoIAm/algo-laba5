cmake_minimum_required(VERSION 3.14)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 17)

project(RabinKarpSearchAlgorithm)

add_library(RabinKarpSearchAlgorithm STATIC src/rabin-karp-search-algorithm.cpp include/rabin-karp-search-algorithm.hpp)

target_include_directories(RabinKarpSearchAlgorithm PUBLIC include)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(RabinKarpSearchTest tests/test.cpp)

target_link_libraries(RabinKarpSearchTest GTest::gtest_main RabinKarpSearchAlgorithm)

add_custom_command(TARGET RabinKarpSearchTest POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/tests/resources/ $<TARGET_FILE_DIR:RabinKarpSearchTest>/resources)

include(GoogleTest)
gtest_discover_tests(RabinKarpSearchTest)

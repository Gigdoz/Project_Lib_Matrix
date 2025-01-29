cmake_minimum_required(VERSION 3.10)

project(demo)

add_library(Lib lib/Matrix.h lib/Matrix.cpp)
target_include_directories(Lib PUBLIC lib)

add_executable(Tests tests/catch.h tests/tests.cpp)

target_link_libraries(Tests PUBLIC Lib)

enable_testing()

add_test(
  NAME Tests
  COMMAND $<TARGET_FILE:Tests>
  )
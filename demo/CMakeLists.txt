﻿project (demo)
cmake_minimum_required (VERSION 3.8)


add_library(StaticLib StaticLib/Matrix.h  StaticLib/Matrix.cpp "StaticLib/Matrix.cpp" "StaticLib/Matrix.h")
target_include_directories(StaticLib PUBLIC StaticLib)


add_executable(tests tests/catch.h tests/tests.cpp "StaticLib/Matrix.cpp" "StaticLib/Matrix.h")

target_link_libraries(tests StaticLib)
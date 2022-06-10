cmake_minimum_required(VERSION 3.21)
project(OptimizedC__Linux)

set(CMAKE_CXX_STANDARD 11)
#03 Chapter
add_subdirectory(03StopWatch)
add_subdirectory(04OptimizeString)
add_subdirectory(06DynamicVariables)
add_executable(OptimizedC__Linux main.cpp 06DynamicVariables/TestSmartPointPerformance.h 06DynamicVariables/blockCopyOperator.h 06DynamicVariables/TestBlockCopyOperator.cpp 06DynamicVariables/testMoveExample.h)

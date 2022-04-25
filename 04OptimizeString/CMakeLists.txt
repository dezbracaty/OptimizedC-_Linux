project(TestOptimezedString)
add_executable(${PROJECT_NAME}
        TestOptimezeString.cpp
        stringFunctions.h
        ../03StopWatch/baseTimer.h
        ../03StopWatch/StopWatch.h
        fixedBlockString.h blockAlloctor.cpp blockAlloctor.h)

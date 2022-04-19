//
// Created by allen on 22-4-19.
//
#include "StopWatch.h"
#include <iostream>

void testStopWatchWithClock(){
    basic_StopWatch<baseTimerClock> baSW_Clock("Test StopWatch With Clock Function ");

    for(int i = 0 ;i < 10000000; i ++){
        int x = i * i / 10 ;
        int y = i * x * i / 10;
    }

}

int main(int argc,char **argv){
    testStopWatchWithClock();

}
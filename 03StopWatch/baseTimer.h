//
// Created by allen on 22-4-18.
//
#include <iostream>
#include <sys/time.h>

#ifndef OPTIMIZEDC__LINUX_BASETIMER_H
#define OPTIMIZEDC__LINUX_BASETIMER_H

//this timer based on clock()
class baseTimerClock{
public:
    // tick type
    typedef clock_t tick_t;

    baseTimerClock() : m_start(-1){};

    void clear(){
        m_start = -1 ;
    };

    bool isStarted() const {
        return m_start != -1 ;
    };
    //when start the clock , reset m_start to current time
    void start(){
        m_start = clock();
    };

    tick_t getTicks(){
        if (isStarted()) {
            tick_t now = clock();
            tick_t dt  = (now - m_start);
            return dt;
        }
        return 0;
    };

    // get the number of milliseconds since the timer was started
    unsigned getMs() {
        return GetMs(getTicks());
    };

    static unsigned GetMs(tick_t dt) {
        return (unsigned long)((dt + (500/CLOCKS_PER_SEC)) / (CLOCKS_PER_SEC / 1000));
    };
private:
    tick_t m_start;
};


//this Timer based on getTimeofDay()
class baseTimerGetTimeOfDay {
public:
    //	clears the timer
    baseTimerGetTimeOfDay() { m_start.tv_sec = m_start.tv_usec = 0; }

    //  clears the timer
    void clear()			{ m_start.tv_sec = m_start.tv_usec = 0; }

    //	returns true if the timer is running
    bool isStarted() const  {
        return (m_start.tv_sec != 0) | (m_start.tv_usec != 0);
    }

    //	start the timer
    void start()            { gettimeofday(&m_start, NULL); }

    //	get the number of milliseconds since the timer was started
    unsigned getMs() {
        timeval now;
        if (isStarted()) {
            gettimeofday(&now, NULL);
            long dt = (now.tv_sec * 1000000 + now.tv_usec) - (m_start.tv_sec * 1000000 + m_start.tv_usec);
            return (unsigned long)(dt + 500) / 1000; // round to mSec
        }
        return 0;
    }
private:
    timeval m_start;
};

#include <chrono>
//this Timer based on std::chrono
using namespace std::chrono;
class baseTimerChrono{
public:

    // 清除计时器
    baseTimerChrono() : m_start(system_clock::time_point::min()) { };

    // 清除计时器
    void Clear() {
        m_start = system_clock::time_point::min();
    }

    // 如果计时器正在计时，则返回true
    bool isStarted() const {
        return (m_start.time_since_epoch() != system_clock::duration(0));
    }

    // 启动计时器
    void Start() {
        m_start = system_clock::now();
    }

    // 得到自计时开始后的毫秒值
    unsigned long GetMs() {
        if (isStarted()) {
            system_clock::duration diff;
            diff = system_clock::now() - m_start;
            return (unsigned)(duration_cast<milliseconds>(diff).count());
        }
        return 0;
    }
private:
    system_clock::time_point m_start;
};
#endif //OPTIMIZEDC__LINUX_BASETIMER_H

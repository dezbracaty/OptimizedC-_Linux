//
// Created by allen on 2022/4/18.
// Github Project Address :
// https://github.com/dezbracaty/OptimizedC-_Linux
//

#ifndef OPTIMIZEDC__LINUX_STOPWATCH_H
#define OPTIMIZEDC__LINUX_STOPWATCH_H
#include <iostream>
#include "baseTimer.h"
template<typename T> class basic_StopWatch :public T {
public:
    typedef T BaseTimer;
    typedef clock_t tick_t;
    explicit basic_StopWatch(bool start);
    explicit basic_StopWatch(char const* activity = "Stopwatch",
                             bool start=true);
    basic_StopWatch(std::ostream& log,char const* activity="Stopwatch",bool start=true);

    //stop and destory
    ~basic_StopWatch();

    // get last lap time (time of last stop)
    tick_t LapGet() const;

    // predicate: return true if the stopwatch is running
    bool IsStarted() const;

    // show accumulated time, keep running, set/return lap
    tick_t Show(char const* event="show");

    // (re)start a stopwatch, set/return lap time
    tick_t Start(char const* event_namee="start");

    // stop a running stopwatch, set/return lap time
    tick_t Stop(char const* event_name="stop");

    tick_t GetTicks() {
        return BaseTimer::getTicks();          //we can use different method to achieve getTichs() function.
    }

private:
    char const*     m_activity; // "activity" string
    tick_t          m_lap;		// lap time (time of last stop or 0)
    std::ostream&   m_log;		// stream on which to log events

};

//  performs a Start() if start_now == true
template<typename T>
basic_StopWatch<T>::basic_StopWatch(bool start) : m_activity("StopWatch"),
    m_lap(0),m_log(std::cout){
    if(start)
        Start();
}

//	performs a start if start_now == true, suppress print by ctor("")
template<typename T>
basic_StopWatch<T>::basic_StopWatch(const char *activity, bool start):m_activity(activity && activity[0] ? activity : nullptr ),
    m_lap(0),m_log(std::cout) {
    if(start){
        if(m_activity)
            Start();
        else
            Start(nullptr);
    }
}

//	set log output, optional printout, optional start
template<typename T>
basic_StopWatch<T>::basic_StopWatch(std::ostream &log, const char *activity, bool start):
    m_activity(activity && activity[0] ? activity : nullptr)
    , m_lap(0)
    , m_log(log)  {
    if (start) {
        if (m_activity)
            Start();
        else
            Start(nullptr);
    }
}

//	stop/destroy stopwatch, print message if activity was set in ctor
template<typename T>
basic_StopWatch<T>::~basic_StopWatch() {
    if (IsStarted()) {
        if (m_activity)
            Stop();
        else
            Stop(nullptr);
    }
}

template<typename T>
typename basic_StopWatch<T>::tick_t basic_StopWatch<T>::LapGet() const {
    return 0;
}

template<typename T>
bool basic_StopWatch<T>::IsStarted() const {
    return BaseTimer::isStarted();
}

template<typename T>
typename basic_StopWatch<T>::tick_t basic_StopWatch<T>::Show(const char *event) {
    if (IsStarted()) {
        m_lap = GetTicks();
        if (event && event[0]) {
            if (m_activity)
                m_log << m_activity << ": ";
            m_log << event << " at " << BaseTimer::GetMs(m_lap) << "mS" << std::endl << std::flush;
        }
    }
    else {
        if (m_activity)
            m_log << m_activity << ": not started" << std::endl << std::flush;
    }
    return m_lap;
}

template<typename T>
typename basic_StopWatch<T>::tick_t basic_StopWatch<T>::Start(const char *event_name) {
    if (IsStarted()) {
        Stop(event_name);
    }
    else {
        if (event_name && event_name[0]) {
            if (m_activity)
                m_log << m_activity << ": ";
            m_log << event_name << std::endl << std::flush;
        }
    }
    BaseTimer::start();
    return m_lap;
}

template<typename T>
typename basic_StopWatch<T>::tick_t basic_StopWatch<T>::Stop(const char *event_name) {
    if (IsStarted()) {
        m_lap = GetTicks();
        if (event_name && event_name[0]) {
            if (m_activity)
                m_log << m_activity << ": ";
            m_log << event_name << " Take "<<m_lap << "\tTicks and Take "  << (float) BaseTimer::GetMs(m_lap) << "\tmS" << std::endl << std::flush;
        }
    }
    BaseTimer::clear();
    return m_lap;
}


#endif //OPTIMIZEDC__LINUX_STOPWATCH_H

#ifndef STOPWATCH_H_INCLUDED
#define STOPWATCH_H_INCLUDED

#include <chrono>

class Stopwatch
{
    private:
        bool hasStarted, hasStoped;
        std::chrono::high_resolution_clock::time_point startTimestamp, stopTimestamp;
    
    public:
        Stopwatch();
        ~Stopwatch();
        constexpr const bool getHasStarted();
        constexpr const bool getHasStoped();
        constexpr const long double getDuration();
        void start();
        void stop();
        void reset();
};

#endif
#ifndef RUNNING_TIME_PROFILER_H_INCLUDED
#define RUNNING_TIME_PROFILER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <functional>

#include "stopwatch.cpp"

class RunningTimeProfiler
{
private:
    Stopwatch callbackStopwatch;
    Stopwatch executionStopwatch;
    std::fstream outputFile;
    unsigned long long int inputStartSize;
    unsigned long long int inputLeapSize;
    unsigned long long int inputLimitSize;
    unsigned long long int loopLimitSize;

public:
    RunningTimeProfiler(
        const unsigned long long int inputStartSize,
        const unsigned long long int inputLeapSize,
        const unsigned long long int inputLimitSize);
    ~RunningTimeProfiler();
    void execute(
        const std::string &outputFilePath,
        const std::function<void(const unsigned long long int &)> &callback);
};

#endif
#ifndef CODE_PROFILER_H_INCLUDED
#define CODE_PROFILER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <filesystem>

#include "stopwatch.h"
#include "codeProfilerSettings.h"

class CodeProfiler
{
private:
    std::ofstream* outputFileStream;
    Stopwatch* subExecutionStopwatch, *mainExecutionStopwatch;
    CodeProfilerSettings* settings;

public:
    CodeProfiler(
        const std::string&,
        const unsigned long long int,
        const unsigned long long int,
        const unsigned long long int);
    ~CodeProfiler();
    void recordRunningTime(
        const std::string&,
        const std::function<void(unsigned long long int)> &,
        const std::function<void(unsigned long long int)>,
        const std::function<void(unsigned long long int)>);
    void visualizeResults();
};

#endif

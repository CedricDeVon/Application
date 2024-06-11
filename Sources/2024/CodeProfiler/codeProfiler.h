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
    Stopwatch* subExecutionStopwatch, *mainExecutionStopwatch;
    CodeProfilerSettings* settings;

    void logToConsole(const std::string&);
    void logToFile(const std::string&, const std::string&);

public:
    CodeProfiler(CodeProfilerSettings*&);
    ~CodeProfiler();
    void recordRunningTime(
        const std::string&,
        const std::function<void(unsigned long long int)> &,
        const std::function<void(unsigned long long int)>,
        const std::function<void(unsigned long long int)>);
    void visualizeResults();
};

#endif
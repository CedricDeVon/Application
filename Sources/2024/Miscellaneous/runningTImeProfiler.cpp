#include <iostream>
#include <fstream>
#include <string>
#include <functional>

#include "runningTimeProfiler.h"

RunningTimeProfiler::RunningTimeProfiler(
    const unsigned long long int inputStartSize,
    const unsigned long long int inputLeapSize,
    const unsigned long long int inputLimitSize)
{
    if (inputStartSize > inputLimitSize || inputLimitSize < inputStartSize)
    {
        throw std::runtime_error("AlgorithmProfiler() Exception: 'inputStartSize' must be less than 'inputLimitSize' and 'inputLimitSize' must be greater than 'inputStartSize'");
    }

    this->inputStartSize = inputStartSize;
    this->inputLeapSize = inputLeapSize;
    this->inputLimitSize = inputLimitSize;
    this->loopLimitSize = inputLimitSize + 1;
}

RunningTimeProfiler::~RunningTimeProfiler()
{

}

void RunningTimeProfiler::execute(
    const std::string &outputFilePath,
    const std::function<void(const unsigned long long int &)> &callback)
{
    this->executionStopwatch.start();
    std::cout << '\'' << outputFilePath << "\' Profiling began." << '\n';

    this->outputFile.open(outputFilePath, std::ios::out);
    std::ostringstream outputFileContent;
    for (unsigned long long int current = this->inputStartSize;
            current < this->loopLimitSize;
            current += this->inputLeapSize)
    {
        this->callbackStopwatch.start();
        callback(current);
        this->callbackStopwatch.stop();
        outputFileContent << current << ',' << this->callbackStopwatch.getDuration() << '\n';
        this->callbackStopwatch.reset();
    }
    this->outputFile << outputFileContent.str();
    this->outputFile.close();

    this->executionStopwatch.stop();
    std::cout << '\'' << outputFilePath << "\' Profiling ended. Took " << this->executionStopwatch.getDuration() << " seconds" << '\n';
    this->executionStopwatch.reset();
}

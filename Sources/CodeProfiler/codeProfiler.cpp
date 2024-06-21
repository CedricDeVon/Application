#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
#include <filesystem>

#include "stopwatch.h"
#include "codeProfilerSettings.h"
#include "codeProfiler.h"

CodeProfiler::CodeProfiler(
    const std::string& subResultsFolderName,
    const unsigned long long int inputStartSize,
    const unsigned long long int inputLimitSize,
    const unsigned long long int inputLeapSize)
{
    this->outputFileStream = new std::ofstream();
    this->subExecutionStopwatch = new Stopwatch();
    this->mainExecutionStopwatch = new Stopwatch();
    this->settings = new CodeProfilerSettings(subResultsFolderName, inputStartSize, inputLimitSize, inputLeapSize);
    std::string filePath = this->settings->getRootResultsFolderPath();
    if (!std::filesystem::exists(filePath))
    {
        std::filesystem::create_directories(filePath);
    }
    filePath = settings->getSubResultsFolderPath(); 
    if (std::filesystem::exists(filePath))
    {
        std::filesystem::remove_all(filePath);
    }
    std::filesystem::create_directories(filePath);
}

CodeProfiler::~CodeProfiler()
{
    delete this->outputFileStream;
    delete this->settings;
    delete this->subExecutionStopwatch;
    delete this->mainExecutionStopwatch;
}

void CodeProfiler::recordRunningTime(
    const std::string& outputResultsFile,
    const std::function<void(unsigned long long int)> &duringExecution,
    const std::function<void(unsigned long long int)> beforeExecution = [](unsigned long long int) -> void {},
    const std::function<void(unsigned long long int)> afterExecution = [](unsigned long long int) -> void {})
{
    this->mainExecutionStopwatch->start();
    this->settings->setResultsFileName(outputResultsFile);
    const bool isConsoleLoggingEnabled = this->settings->getIsConsoleLoggingEnabled();
    unsigned long long int currentInputSize = this->settings->getInputStartSize();
    const unsigned long long int loopLimitSize = this->settings->getLoopLimitSize(),
        inputLeapSize = this->settings->getInputLeapSize();
    std::string resultsFileData, currentResultString;
    if (isConsoleLoggingEnabled)
    {
        std::cout << '\'' + outputResultsFile + "\' Running Time Profile:\nInput Size, Running Time (In Seconds)\n";
    }
    while (currentInputSize < loopLimitSize)
    {
        beforeExecution(currentInputSize);
        this->subExecutionStopwatch->start();
        duringExecution(currentInputSize);
        this->subExecutionStopwatch->stop();
        afterExecution(currentInputSize);
        currentResultString = (std::ostringstream() << currentInputSize).str() + ',' + (std::ostringstream() << this->subExecutionStopwatch->getDuration()).str() + '\n';
        this->subExecutionStopwatch->reset();
        if (isConsoleLoggingEnabled)
        {
            std::cout << currentResultString;
        }
        resultsFileData += currentResultString;
        currentInputSize += inputLeapSize;
    }
    this->outputFileStream->open(this->settings->getResultsFilePath(), std::ios::out);
    *this->outputFileStream << resultsFileData;
    this->outputFileStream->close();
    this->mainExecutionStopwatch->stop();
    if (isConsoleLoggingEnabled)
    {
        std::cout << "Total Duration: " + (std::ostringstream() << this->mainExecutionStopwatch->getDuration()).str() + "\n\n";
    }
    this->mainExecutionStopwatch->reset();
}

void CodeProfiler::visualizeResults()
{
    if (this->settings->getIsVisualizationEnabled())
    {
        std::cout << "Visualizing \'" +  this->settings->getSubResultsFolderName() + "\' code running time results...\n";
        system(("python " + this->settings->getResultsVisualizerFilePath() + " " + this->settings->getSubResultsFolderPath() + " " + this->settings->getSubResultsFolderName()).c_str());
        std::cout << "Complete!\n";
    }
}



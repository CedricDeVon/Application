#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <filesystem>

#include "codeProfiler.h"

CodeProfiler::CodeProfiler(
    CodeProfilerSettings*& settings)
{
    this->settings = settings;
    this->subExecutionStopwatch = new Stopwatch();
    this->mainExecutionStopwatch = new Stopwatch();

    std::string folderPath = settings->rootResultsFolderPath;
    if (!std::filesystem::exists(folderPath))
    {
        std::filesystem::create_directories(folderPath);
    }
    folderPath = settings->getSubResultsFolderPath(); 
    if (std::filesystem::exists(folderPath))
    {
        std::filesystem::remove_all(folderPath);
    }
    std::filesystem::create_directories(folderPath);
}

CodeProfiler::~CodeProfiler()
{
    delete this->settings;
    delete this->subExecutionStopwatch;
    delete this->mainExecutionStopwatch;
}

void CodeProfiler::logToConsole(const std::string& text)
{
    if (this->settings->isConsoleLoggingEnabled)
    {
        std::cout << text;
    }
}

void CodeProfiler::logToFile(const std::string& outputFilePath, const std::string& text)
{
    std::fstream outputFile;
    outputFile.open(outputFilePath, std::ios::out);
    outputFile << text;
    outputFile.close();
}

void CodeProfiler::recordRunningTime(
    const std::string& outputResultFile,
    const std::function<void(unsigned long long int)> &duringExecution,
    const std::function<void(unsigned long long int)> beforeExecution = [](unsigned long long int) -> void {},
    const std::function<void(unsigned long long int)> afterExecution = [](unsigned long long int) -> void {})
{
    this->mainExecutionStopwatch->start();
    std::string resultFileData, currentInputSizeString, currentDurationString;
    this->logToConsole('\'' + outputResultFile + "\' Running Time Profile:\nInput Size, Running Time (In Seconds)\n");
    for (unsigned long long int currentInputSize = this->settings->inputStartSize;
         currentInputSize < this->settings->loopLimitSize;
         currentInputSize += this->settings->inputLeapSize)
    {
        currentInputSizeString = (std::ostringstream() << currentInputSize).str();
        this->subExecutionStopwatch->start();
        duringExecution(currentInputSize);
        this->subExecutionStopwatch->stop();
        currentDurationString = (std::ostringstream() << this->subExecutionStopwatch->getDuration()).str();
        this->logToConsole(currentInputSizeString + ", " + currentDurationString + '\n');
        this->subExecutionStopwatch->reset();

        resultFileData += currentInputSizeString + ',' + currentDurationString + '\n';
    }
    this->logToFile(this->settings->getResultFilePath(outputResultFile), resultFileData);
    this->mainExecutionStopwatch->stop();
    this->logToConsole("Total Duration: " + (std::ostringstream() << this->mainExecutionStopwatch->getDuration()).str() + "\n\n");
    this->mainExecutionStopwatch->reset();
}

void CodeProfiler::visualizeResults()
{
    if (this->settings->isVisualizationEnabled)
    {
        std::cout << "Visualizing \'" +  this->settings->subResultsFolderName + "\' code profiler results...\n";
        system(("python " + this->settings->getResultVisualizerFilePath() + " " + this->settings->getSubResultsFolderPath() + " " + this->settings->subResultsFolderName).c_str());
        std::cout << "Complete!\n";
    }
}
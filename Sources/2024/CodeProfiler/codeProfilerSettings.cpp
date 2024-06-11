#include <string>

#include "./codeProfilerSettings.h"

std::string CodeProfilerSettings::packageFolderPath = "../CodeProfiler/";
std::string CodeProfilerSettings::rootResultsFolderPath = "./CodeProfilerResults/";
const std::string CodeProfilerSettings::resultFileExtension = ".csv";
const std::string CodeProfilerSettings::resultVisualizerFileName = "codeProfilerResultVisualizer.py";

CodeProfilerSettings::CodeProfilerSettings(
    const std::string& subResultsFolderName,
    const unsigned long long int inputStartSize,
    const unsigned long long int inputLimitSize,
    const unsigned long long int inputLeapSize,
    const bool isConsoleLoggingEnabled = true,
    const bool isVisualizationEnabled = true)
{
    // if (inputStartSize > inputLimitSize || inputLimitSize < inputStartSize)
    // {
    //     throw std::runtime_error("AlgorithmProfiler() Exception: 'inputStartSize' must be less than 'inputLimitSize' and 'inputLimitSize' must be greater than 'inputStartSize'");
    // }

    this->inputStartSize = inputStartSize;
    this->inputLimitSize = this->loopLimitSize = inputLimitSize;
    ++this->loopLimitSize;
    this->inputLeapSize = inputLeapSize;
    this->isConsoleLoggingEnabled = isConsoleLoggingEnabled;
    this->isVisualizationEnabled = isVisualizationEnabled;
    this->subResultsFolderName = subResultsFolderName;
}

CodeProfilerSettings::~CodeProfilerSettings()
{

}

const std::string CodeProfilerSettings::getSubResultsFolderPath()
{
    return this->rootResultsFolderPath + this->subResultsFolderName + '/';
}

const std::string CodeProfilerSettings::getResultVisualizerFilePath()
{
    return this->packageFolderPath + this->resultVisualizerFileName;
}

const std::string CodeProfilerSettings::getResultFilePath(const std::string& resultFileName)
{
    return this->getSubResultsFolderPath() + resultFileName + this->resultFileExtension;
}
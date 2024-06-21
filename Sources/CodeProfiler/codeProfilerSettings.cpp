#include <string>

#include "./codeProfilerSettings.h"

std::string CodeProfilerSettings::packageFolderPath = "../CodeProfiler/";
std::string CodeProfilerSettings::rootResultsFolderPath = "./CodeProfilerResults/";
const std::string CodeProfilerSettings::resultsFileExtension = ".csv";
const std::string CodeProfilerSettings::resultsVisualizerFileName = "codeProfilerResultsVisualizer.py";

CodeProfilerSettings::CodeProfilerSettings(
    const std::string& subResultsFolderName,
    const unsigned long long int inputStartSize,
    const unsigned long long int inputLimitSize,
    const unsigned long long int inputLeapSize,
    const bool isConsoleLoggingEnabled = true,
    const bool isVisualizationEnabled = true)
{
    if (!std::filesystem::exists(this->packageFolderPath) ||
        !std::filesystem::exists(this->getResultsVisualizerFilePath()) ||
        subResultsFolderName.length() == 0 ||
        inputStartSize > inputLimitSize ||
        inputLimitSize < inputStartSize)
    {
        throw std::runtime_error("Error found at CodeProfilerSettings(): 'CodeProfiler' package does not exist, 'visualizer' file does not exist, 'subResultsFolderName' must not be empty, 'inputStartSize' must be less than 'inputLimitSize', and 'inputLimitSize' must be greater than 'inputStartSize'");
    }

    this->setSubResultsFolderName(subResultsFolderName);
    this->inputStartSize = inputStartSize;
    this->inputLimitSize = this->loopLimitSize = inputLimitSize;
    ++this->loopLimitSize;
    this->inputLeapSize = inputLeapSize;
    this->isConsoleLoggingEnabled = isConsoleLoggingEnabled;
    this->isVisualizationEnabled = isVisualizationEnabled;
}

CodeProfilerSettings::~CodeProfilerSettings()
{

}

const bool CodeProfilerSettings::getIsConsoleLoggingEnabled()
{
    return this->isConsoleLoggingEnabled;
}

void CodeProfilerSettings::setIsConsoleLoggingEnabled(const bool value)
{
    this->isConsoleLoggingEnabled = value;
}

const bool CodeProfilerSettings::getIsVisualizationEnabled()
{
    return this->isVisualizationEnabled;
}

void CodeProfilerSettings::setIsVisualizationEnabled(const bool value)
{
    this->isVisualizationEnabled = value;
}

const unsigned long long int CodeProfilerSettings::getInputStartSize()
{
    return this->inputStartSize;
}

const unsigned long long int CodeProfilerSettings::getInputLimitSize()
{
    return this->inputLimitSize;
}

const unsigned long long int CodeProfilerSettings::getInputLeapSize()
{
    return this->inputLeapSize;
}

const unsigned long long int CodeProfilerSettings::getLoopLimitSize()
{
    return this->loopLimitSize;
}

const std::string CodeProfilerSettings::getSubResultsFolderName()
{
    return this->subResultsFolderName;
}

void CodeProfilerSettings::setSubResultsFolderName(const std::string& value)
{
    if (value.length() == 0)
    {
        throw std::runtime_error("Error found at CodeProfilerSettings.setSubResultsFolderName(): File name cannot be null or empty");
    }

    this->subResultsFolderName = value;
    this->updateSubResultsFolderPath();
}

const std::string CodeProfilerSettings::getSubResultsFolderPath()
{
    return this->subResultsFolderPath;
}

const std::string CodeProfilerSettings::getResultsFileName()
{
    return this->resultsFileName;
}

void CodeProfilerSettings::setResultsFileName(const std::string& value)
{
    if (value.length() == 0)
    {
        throw std::runtime_error("Error found at CodeProfilerSettings.setResultsFileName(): File name cannot be null or empty");
    }

    this->resultsFileName = value;
    this->updateResultsFilePath();
}

const std::string CodeProfilerSettings::getResultsFilePath()
{
    return this->resultsFilePath;
}

const std::string CodeProfilerSettings::getPackageFolderPath()
{   
    return this->packageFolderPath;
}

void CodeProfilerSettings::setPackageFolderPath(const std::string& value)
{
    if (!std::filesystem::exists(value))
    {
        throw std::runtime_error("Error found at CodeProfilerSettings.setPackageFolderPath(): Folder does not exist");
    }

    this->packageFolderPath = value;
}

const std::string CodeProfilerSettings::getRootResultsFolderPath()
{
    return this->rootResultsFolderPath;
}

void CodeProfilerSettings::setRootResultsFolderPath(const std::string& value)
{
    if (!std::filesystem::exists(value))
    {
        throw std::runtime_error("Error found at CodeProfilerSettings.setRootResultsFolderPath(): Folder does not exist");
    }

    this->rootResultsFolderPath = value;
    this->updateRootResultsFolderPath();
}

const std::string CodeProfilerSettings::getResultsVisualizerFilePath()
{
    return this->packageFolderPath + this->resultsVisualizerFileName;
}

const std::string CodeProfilerSettings::getResultsFileExtension()
{
    return this->resultsFileExtension;
}

const std::string CodeProfilerSettings::getVisualizerFileName()
{
    return this->resultsVisualizerFileName;
}

void CodeProfilerSettings::updateSubResultsFolderPath()
{   
    this->subResultsFolderPath = this->rootResultsFolderPath + this->subResultsFolderName + '/';
}

void CodeProfilerSettings::updateResultsFilePath()
{
    this->resultsFilePath = this->getSubResultsFolderPath() + this->resultsFileName + this->resultsFileExtension;
}

void CodeProfilerSettings::updateRootResultsFolderPath()
{
    this->setSubResultsFolderName(this->subResultsFolderName);
}

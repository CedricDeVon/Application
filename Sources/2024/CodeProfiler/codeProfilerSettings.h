#ifndef CODE_PROFILE_SETTINGS_H_INCLUDED
#define CODE_PROFILE_SETTINGS_H_INCLUDED

#include <string>

class CodeProfilerSettings
{
private:

public:
    bool isConsoleLoggingEnabled, isVisualizationEnabled;
    unsigned long long int inputStartSize, inputLimitSize, inputLeapSize, loopLimitSize;
    std::string subResultsFolderName;
    static std::string packageFolderPath, rootResultsFolderPath;
    const static std::string resultFileExtension, resultVisualizerFileName;

    CodeProfilerSettings(
        const std::string&,
        const unsigned long long int,
        const unsigned long long int,
        const unsigned long long int,
        const bool,
        const bool);
    ~CodeProfilerSettings();
    const std::string getSubResultsFolderPath();
    const std::string getResultVisualizerFilePath();
    const std::string getResultFilePath(const std::string&);
};

#endif
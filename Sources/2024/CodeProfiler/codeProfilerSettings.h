#ifndef CODE_PROFILE_SETTINGS_H_INCLUDED
#define CODE_PROFILE_SETTINGS_H_INCLUDED

#include <string>

class CodeProfilerSettings
{
private:
    bool isConsoleLoggingEnabled, isVisualizationEnabled;
    unsigned long long int inputStartSize, inputLimitSize, inputLeapSize, loopLimitSize;
    std::string subResultsFolderName, subResultsFolderPath, resultsFileName, resultsFilePath;
    static std::string packageFolderPath, rootResultsFolderPath;
    const static std::string resultsFileExtension, resultsVisualizerFileName;
    void updateSubResultsFolderPath();
    void updateResultsFilePath();
    void updateRootResultsFolderPath();

public:
    CodeProfilerSettings(
        const std::string&,
        const unsigned long long int,
        const unsigned long long int,
        const unsigned long long int,
        const bool,
        const bool);
    ~CodeProfilerSettings();
    const bool getIsConsoleLoggingEnabled();
    void setIsConsoleLoggingEnabled(const bool);
    const bool getIsVisualizationEnabled();
    void setIsVisualizationEnabled(const bool);
    const unsigned long long int getInputStartSize();
    const unsigned long long int getInputLimitSize();
    const unsigned long long int getInputLeapSize();
    const unsigned long long int getLoopLimitSize();
    const std::string getSubResultsFolderName();
    void setSubResultsFolderName(const std::string&);
    const std::string getSubResultsFolderPath();
    const std::string getResultsFileName();
    void setResultsFileName(const std::string&);
    const std::string getResultsFilePath();
    const std::string getPackageFolderPath();
    void setPackageFolderPath(const std::string&);
    const std::string getRootResultsFolderPath();
    void setRootResultsFolderPath(const std::string&);
    const std::string getResultsVisualizerFilePath();
    const std::string getResultsFileExtension();
    const std::string getVisualizerFileName();
};

#endif


// CodeProfilerSettings* settings = new CodeProfilerSettings("A", 0, 1000, 1, false, true);
// std::cout << "Before:\n";
// std::cout << "getIsConsoleLoggingEnabled() : " << settings->getIsConsoleLoggingEnabled() << '\n';
// std::cout << "getIsVisualizationEnabled() : " << settings->getIsVisualizationEnabled() << '\n';
// std::cout << "getInputStartSize() : " << settings->getInputStartSize() << '\n';
// std::cout << "getInputLimitSize() : " << settings->getInputLimitSize() << '\n';
// std::cout << "getInputLeapSize() : " << settings->getInputLeapSize() << '\n';
// std::cout << "getLoopLimitSize() : " << settings->getLoopLimitSize() << '\n';
// std::cout << "getSubResultsFolderName() : " << settings->getSubResultsFolderName() << '\n';
// std::cout << "getSubResultsFolderPath() : " << settings->getSubResultsFolderPath() << '\n';
// std::cout << "getResultsFileName() : " << settings->getResultsFileName() << '\n';
// std::cout << "getResultsFilePath() : " << settings->getResultsFilePath() << '\n';
// std::cout << "getPackageFolderPath() : " << settings->getPackageFolderPath() << '\n';
// std::cout << "getRootResultsFolderPath() : " << settings->getRootResultsFolderPath() << '\n';
// std::cout << "getResultsVisualizerFilePath() : " << settings->getResultsVisualizerFilePath() << '\n';
// std::cout << "getResultsFileExtension() : " << settings->getResultsFileExtension() << '\n';
// std::cout << "getVisualizerFileName() : " << settings->getVisualizerFileName() << '\n';

// settings->setIsConsoleLoggingEnabled(true);
// settings->setIsVisualizationEnabled(false);
// settings->setPackageFolderPath("./CodeProfilerV2/");
// settings->setRootResultsFolderPath("./RootResults/");
// settings->setSubResultsFolderName("B");
// settings->setResultsFileName("V1");

// std::cout << "\nAfter:\n";
// std::cout << "getIsConsoleLoggingEnabled() : " << settings->getIsConsoleLoggingEnabled() << '\n';
// std::cout << "getIsVisualizationEnabled() : " << settings->getIsVisualizationEnabled() << '\n';
// std::cout << "getInputStartSize() : " << settings->getInputStartSize() << '\n';
// std::cout << "getInputLimitSize() : " << settings->getInputLimitSize() << '\n';
// std::cout << "getInputLeapSize() : " << settings->getInputLeapSize() << '\n';
// std::cout << "getLoopLimitSize() : " << settings->getLoopLimitSize() << '\n';
// std::cout << "getSubResultsFolderName() : " << settings->getSubResultsFolderName() << '\n';
// std::cout << "getSubResultsFolderPath() : " << settings->getSubResultsFolderPath() << '\n';
// std::cout << "getResultsFileName() : " << settings->getResultsFileName() << '\n';
// std::cout << "getResultsFilePath() : " << settings->getResultsFilePath() << '\n';
// std::cout << "getPackageFolderPath() : " << settings->getPackageFolderPath() << '\n';
// std::cout << "getRootResultsFolderPath() : " << settings->getRootResultsFolderPath() << '\n';
// std::cout << "getResultsVisualizerFilePath() : " << settings->getResultsVisualizerFilePath() << '\n';
// std::cout << "getResultsFileExtension() : " << settings->getResultsFileExtension() << '\n';
// std::cout << "getVisualizerFileName() : " << settings->getVisualizerFileName() << '\n';

// delete settings;
// settings = NULL;
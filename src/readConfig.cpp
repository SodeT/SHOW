#include <vector> // vectors
#include <string> // strings
#include <sstream> // istringstream

#include <filterConfig.hpp> // filterConfig class

std::vector<filterConfig> readConfig(std::string inputFile, std::string* parseFilePaths)
{
    std::vector<filterConfig> configArr;
    std::string currentLine;

    int currentType;
    std::string filterName;
    int filterCount = 0;

    const int optionsCount = 6;
    std::string options[optionsCount];
    int currentoption = 0;

    do
    {
        std::getline((std::stringstream)inputFile, currentLine, '\n');
        inputFile = inputFile.substr(currentLine.length()); // remove the line we just read

        if (currentLine.find("all:") != std::string::npos)
        {
            currentType = 0;
            continue;
        }
        else if (currentLine.find("quotes:") != std::string::npos)
        {
            currentType = 1;
            continue;
        }
        else if (currentLine.find("numbers:") != std::string::npos)
        {
            currentType = 2;
            continue;
        }
        else if (currentLine.find("filter:") != std::string::npos)
        {
            currentType++;
            filterName = currentLine.substr(7); // "filter:".length = 7
            parseFilePaths[filterCount] = filterName;
            filterCount++;
            continue;
        }

        // ============================================================================================
        // ============================================================================================
        // ============================================================================================
        // ============================= check if the currenLine is empty =============================
        // ============================================================================================
        // ============================================================================================
        // ============================================================================================

        options[currentoption] = currentLine.substr(currentLine.find(": "));
        currentoption++;

        if (currentoption >= optionsCount)
        {
            configArr.emplace_back(options[0], options[1], options[2], options[3], options[4], currentType);
            currentoption = 0;
        }
        
    } while (inputFile.length() > 0);

    return configArr;
}
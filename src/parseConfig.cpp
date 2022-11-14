#include <vector> // vectors
#include <string> // strings
#include <sstream> // istringstream

#include <structs.hpp> // filterConfig and filterFile structs

void parseConfig(std::string inputFile, std::vector<filter>* filters)
{
    std::string currentLine;
    int currentType = 0;

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
            continue;
        }
        else if (currentLine.find("quotes:") != std::string::npos)
        {
            currentType++;
            continue;
        }
        else if (currentLine.find("numbers:") != std::string::npos)
        {
            currentType++;
            continue;
        }
        else if (currentLine.find("filter:") != std::string::npos)
        {
            currentType++;
            filterName = currentLine.substr(7); // "filter:".length = 7
            filterCount++;
            continue;
        }

        if (currentLine == "")
        {
            continue;
        }

        options[currentoption] = currentLine.substr(currentLine.find(": "));
        currentoption++;

        if (currentoption >= optionsCount)
        {
            filters->emplace_back(options[0], options[1], options[2], options[3], options[4], filterName, currentType);
            currentoption = 0;
            filterName = "";
        }
        
    } while (inputFile.length() > 0);

    return;
}
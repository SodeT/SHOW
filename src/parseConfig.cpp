#include <vector> // vectors
#include <string> // strings
#include <sstream> // istringstream
#include <iostream> // cout
#include <structs.hpp> // filterConfig and filterFile structs

#include <utils.hpp>

void parseConfig(std::string inputFile, std::vector<filter>& filters)
{
    std::string currentLine;
    int currentType = 0;

    std::string filterName = "";
    int filterCount = 0;

    const int optionsCount = 5;
    std::string options[optionsCount];
    int currentOption = 0;
    

    do
    {
        currentLine = inputFile.substr(0, inputFile.find('\n') +1);
        inputFile = inputFile.substr(currentLine.length()); // remove the line we just read

        currentLine = chomp(currentLine, forbiddenChars);

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
            filterName = currentLine.substr(7); // "filter: ".length = 8
            filterCount++;
            continue;
        }

        if (currentLine == "") 
        {
            std::cout << "Empty\n";
            continue;
        }

        std::cout << currentLine << "\n";
        options[currentOption] = currentLine.substr(currentLine.find(":"));
        currentOption++;


        if (currentOption >= optionsCount)
        {
            filters.emplace_back(options[0], options[1], options[2], options[3], options[4], filterName, currentType);
            currentOption = 0;
            filterName = "";
        }
    } while (inputFile.length() > 0);
    
    return;
}
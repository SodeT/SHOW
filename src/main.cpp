#include <string> // string parsing
#include <vector> // vector
#include <thread> // multithreading
#include <cstring> // strtok
#include <sstream> // istringstream
#include <numeric> //std::accumulate
#include <iostream> // cout
#include <stdio.h> // printf

#include "readFile.hpp"
#include "parseWords.hpp"
#include "../config.hpp"

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("Error, incorrect arguments: \"<input.txt> <output.odt>\"...\n");
        exit(1);
    }

    std::vector<std::string> binPathSplit;
    std::string fullString = argv[0];
    std::string pathSegment;
    while (true)
    {
        // ------------------------------------------------- error in this region of the code base (get dir of the executable)
        std::cout << fullString << std::endl;
        try
        {
            pathSegment = std::strtok((char*)fullString.c_str(), "\\");
            binPathSplit.emplace_back(fullString);
            fullString.erase(0, pathSegment.length());
            std::cout << fullString << std::endl;
        }
        catch (const std::exception& e)
        {
            break;
        }        
    }
    std::cout << fullString << std::endl;

    std::string binPath = std::accumulate(binPathSplit.begin(), binPathSplit.end() - 1, std::string("/"));

    std::cout << binPath << std::endl;

    std::string languageFilePath;
    std::string inputFilePath;
    std::string outputFilePath;

    inputFilePath = argv[1];
    outputFilePath = argv[2];
    if (argc >= 4)
    {
        languageFilePath = argv[3];
    }
    else 
    {
        languageFilePath = "English/";
    }

    
    std::string inputFile = readFile(inputFilePath);

    // read filter files
    for (int i = 0; i < parseNum; i++)
    {
        parseFiles[i] = readFile(languageFilePath + parseFilePaths[i]);
    }

    // split input file into words
    std::vector<std::string> inputWords;
    std::string tempString;
    int wordNum = 0;
    while (std::getline((std::istringstream)inputFile, tempString, ' ')) 
    {
        inputWords.push_back(tempString);
        wordNum++;
    }

    // start a thread for each filter file
    int ret[5];
    std::string strVar[] = {"var", "har", "har", "var", "har"};
    parseWords("var", strVar, 5, 1, ret);
    //parseWords("var", strVar, 5, 1, ret);

    std::cout << ret << std::endl;

    return 0;
}
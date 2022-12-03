#include <string> // string parsing
#include <vector> // vector
#include <cstring> // strtok
#include <sstream> // istringstream
#include <numeric> //std::accumulate
#include <iostream> // cout
#include <stdio.h> // printf
#include <limits.h> // INT_MAX
#include <regex> // regex_replace

#include <utility>
#include <chrono>

#include <thread> // multithreading
#include <filesystem> // filesystem

#include <utils.hpp>
#include <structs.hpp>

void log(const char* msg)
{
    printf("%s\n", msg);
}

enum filterType {ft_unknown = 0, ft_quote, ft_number}; // what is the usecase???

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("Error, incorrect arguments: \"<input.txt> <output.odt>\"...\n");
        exit(1);
    }

    // get path of executable 
    std::string aux(argv[0]);
#if defined(_WIN32) || defined(WIN32) // for crosscompilation
    int pos = aux.rfind('\\');
#else
    int pos = aux.rfind('/');
#endif
    std::string execPath = aux.substr(0,pos+1);

    // get input and output path
    std::string inputFilePath = argv[1];
    std::string outputFilePath = argv[2];
    std::string languageFilePath;

    if (argc >= 4)
        languageFilePath = execPath + argv[3];
    else 
        languageFilePath = execPath + "English\\";

    
    // read and parse config file
    std::vector<filter> filters;
    printf("read\n");
    parseConfig(readFile(languageFilePath + "config.conf"), filters);
    printf("read2\n");
    // read input file
    std::string inputFile = readFile(inputFilePath);
    printf("read3\n");

    // read filter files
    for (size_t i = 0; i < filters.size(); i++)
    {
        if (filters[i].fileName == "")
        {
            continue;
        }
        filters[i].content = readFile(languageFilePath + filters[i].fileName);
    }


    // split input file into words
    std::vector<std::string> inputWords;
    std::string tempString;
    int wordCount = 0;
    do
    {
        std::getline((std::stringstream)inputFile, tempString, ' ');
        inputWords.push_back(tempString);
        wordCount++;
        try
        {
            inputFile = inputFile.substr(tempString.length() + 1);
        }
        catch(const std::exception& e)
        {
            inputWords.push_back(inputFile);
            break;
        }
        
    } while (inputFile.length() > 1);

    // start a parseWords thread for each filter file
    std::vector<int> filterOutput;
    for (size_t i = 0; i < filters.size(); i++)
    {
        filterOutput = parseWords(filters, inputWords);
    }


    printf("filterOutput: \n");
    for (size_t i = 0; i < filterOutput.size(); i++)
    {
        std::cout << filterOutput[i] << std::endl;   
    }

    // copy xml template

    // write changes to xml file

    // compress to zip --> odt

    // done

    return 0;
}
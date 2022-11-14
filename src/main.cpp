#include <string> // string parsing
#include <vector> // vector
#include <cstring> // strtok
#include <sstream> // istringstream
#include <numeric> //std::accumulate
#include <iostream> // cout
#include <stdio.h> // printf
#include <limits.h> // INT_MAX
#include <regex> // regex_replace

#include <thread> // multithreading
#include <filesystem> // filesystem

#include <utils.hpp>
#include <structs.hpp>


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
        languageFilePath = execPath + "English/";

    
    // read and parse config file
    std::vector<filter> filters;
    parseConfig(readFile(languageFilePath + "config.conf"), &filters);

    // read input file
    std::string inputFile = readFile(inputFilePath);


    // read filter files
    for (int i = 0; i < (int)filters.size(); i++)
    {
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
    // reserve size
    std::vector<std::thread> filterThreads;
    std::vector<std::vector<int>> filterOutput;

    for (int i = 0; i < (int)filters.size(); i++)
    {
        filterThreads.emplace_back(parseWords, filters[i].content, inputWords.data(), wordCount, filters[i].type, filterOutput[i]);
    }

    for (int i = 0; i < (int)filters.size(); i++)
    {
        filterThreads[i].join();
    }

    // merge return arrays 
    std::vector<int> returnArray;
    std::vector<int> currentWord;
    for (int i = 0; i < wordCount; i++)
    {
        for (int j = 0; j < (int)filters.size(); j++)
        {
            currentWord.push_back(filterOutput[i][j * wordCount]);
        }
        returnArray.push_back(mergeArray(currentWord));
        currentWord.clear();
    }

    for (int i = 0; i < wordCount; i++)
    {
        std::cout << returnArray[i] << std::endl;
    }

    // copy xml template

    // write changes to xml file

    // compress to zip --> odt

    // done

    return 0;
}
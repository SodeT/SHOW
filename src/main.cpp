#include <string> // string parsing
#include <vector> // vector
#include <cstring> // strtok
#include <sstream> // istringstream
#include <numeric> //std::accumulate
#include <iostream> // cout
#include <stdio.h> // printf
#include <limits.h> // INT_MAX
#include <regex> // regex_replace
#include <algorithm> // join

#include <utility>
#include <chrono>

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
    parseConfig(readFile(languageFilePath + "config.conf"), filters);
    
    // read input file
    std::string inputFile = readFile(inputFilePath);
    

    // read filter files
    for (size_t i = 0; i < filters.size(); i++)
    {
        if (filters[i].fileName == "")
        {
            continue;
        }
        filters[i].content = splitString(readFile(languageFilePath + filters[i].fileName));
    }


    // split input file into words
    std::vector<std::string> inputWords = splitString(inputFile);
    
    // start a parseWords thread for each filter file
    std::vector<int> filterOutput;
    filterOutput = parseWords(filters, inputWords);
    
    /*for (size_t i = 0; i < filters.size(); i++)
    {
    }*/

    // copy xml template
    std::string content = readFile(execPath + "template/template.html");

    std::vector<std::string> styleVec;
    for (size_t i = 0; i < filters.size(); i++)
    {
        styleVec.push_back(writeStyle(filters[i]));
    }
    std::string style = joinContent(styleVec, "\n");

    std::vector<std::string> textVec;
    for (size_t i = 0; i < inputWords.size(); i++)
    {
        textVec.push_back(writeWords(inputWords[i], filterOutput[i]));
    }
    std::string text = joinContent(textVec, "\n");

    content = patternReplace(style, "-STYLE-", content);
    content = patternReplace(text, "-TEXT-", content);

    // write changes to html file
    writeFile(outputFilePath, content);


    // done

    return 0;
}
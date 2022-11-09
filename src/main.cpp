#include <string> // string parsing
#include <vector> // vector
#include <thread> // multithreading
#include <cstring> // strtok
#include <sstream> // istringstream
#include <numeric> //std::accumulate
#include <iostream> // cout
#include <stdio.h> // printf
#include <limits.h> // INT_MAX

#include <utils.hpp>
#include "../config.hpp"

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

    // read input file

    std::string inputFile = readFile(inputFilePath);


    // read filter files
    for (int i = 0; i < filterNum; i++)
    {
        parseFiles[i] = readFile(languageFilePath + parseFilePaths[i]);
    }


    // split input file into words
    std::vector<std::string> inputWords;
    std::string tempString;
    int wordNum = 0;
    do
    {
        std::getline((std::stringstream)inputFile, tempString, ' ');
        inputWords.push_back(tempString);
        wordNum++;
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
    int* ret1 = (int*)malloc(wordNum);
    int* ret2 = (int*)malloc(wordNum);

    parseWords(parseFiles[0], inputWords.data(), wordNum, 1, ret1);
    parseWords(parseFiles[1], inputWords.data(), wordNum, 2, ret2);

    int* rets[2] = {ret1, ret2};
    bool notSet = true;
    // merge return arrays 
    int* retArr = (int*)malloc(wordNum);
    for (int i = 0; i < wordNum; i++)
    {
        notSet = true;
        retArr[i] = INT_MAX;
        for (int j = 0; j < filterNum; j++)
        {
            if (rets[j][i] != pt_unknown)
            {
                retArr[i] = rets[j][i];
                notSet = false;
            }
        }
        if (notSet)
        {
            retArr[i] = pt_unknown;
        }
    }



    for (int i = 0; i < wordNum; i++)
    {
        std::cout << retArr[i] << std::endl;
    }

    free(ret1);
    free(ret2);
    free(retArr);

    // copy xml template

    // write changes to xml file

    // compress to zip --> odt

    // done

    return 0;
}
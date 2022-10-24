#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

std::string readFile(std::string path)
{

    std::string output;
    std::string fileLine;
    std::fstream fileStream;
    fileStream.open(path, std::ios::in); 
    if (fileStream.is_open())
    { 
        while (std::getline(fileStream, fileLine))
        {  
            output.append(fileLine + '\n');
        }
        fileStream.close();   
    }
    else 
    {
        std::cout << path << std::endl;
        printf("Error reading file, aborting...\n");
        exit(1);
    }
    return output;
}
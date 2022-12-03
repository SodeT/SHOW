#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <utils.hpp>

std::string readFile(std::string path)
{

    path = chomp(path, forbiddenChars);
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
        printf("%S\n", output.c_str());
    }
    else 
    {
        printf("Error reading file: \"%s\", aborting...\n", path.c_str());
        
        exit(1);
    }
    return output;
}
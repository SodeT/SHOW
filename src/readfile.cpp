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
        printf("Error reading file: \"%s\", aborting...\n", path.c_str());
        
        exit(1);
    }
    return output;
}
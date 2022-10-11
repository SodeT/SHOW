#include <iostream> // cout
#include <string> // string parsing
#include <thread> // multithreading
#include <stdio.h> // printf
#include <stdlib.h> // fopen
#include <memory> // smart ptr

#include <readfile.hpp>

int main(int Argc, char* Argv[])
{
    if (Argc < 3)
    {
        printf("Error, incorrect arguments: \"<input.txt> <output.odt>\"...\n");
        exit(1);
    }

    std::string LanguageFilePath;
    std::string InputFilePath;
    std::string OutputFilePath;
    std::string InputText;
    std::shared_ptr<FILE> InputFile = std::make_shared<FILE>();


    InputFilePath = Argv[1];
    OutputFilePath = Argv[2];
    if (Argc == 4)
    {
        LanguageFilePath = Argv[3];
    }
    else 
    {
        LanguageFilePath = "English/";
    }

    // InputText gets address out of bounds
    // Error most prob in fread but not sure.
    // Use GDB to find what line it gets out of bounds 
    InputText = *ReadFile(InputFilePath, InputFile.get()); 
    printf("Hello World! 1\n");
    printf(InputText.c_str());
    
    return 0;
}
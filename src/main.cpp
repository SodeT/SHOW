#include <iostream> // cout
#include <string> // string parsing
#include <thread> // multithreading
#include <stdio.h> // printf
#include <stdlib.h> // fopen
#include <memory> // smart ptr

void ReadFile(std::string InputFilePath, FILE* InputFile, std::string* FileBuffer);

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
    ReadFile(InputFilePath, InputFile.get(), &InputText); 
    printf("Hello World! 1\n");
    printf(InputText.c_str());
    
    return 0;
}

void ReadFile(std::string InputFilePath, FILE* InputFile, std::string* FileBuffer)
{
    try
    {
        InputFile = fopen(InputFilePath.c_str(), "r");

        fseek(InputFile, 0, SEEK_END);
        int FileSize = ftell(InputFile);
        FileBuffer->reserve(FileSize);
        fseek(InputFile, 0, SEEK_SET);

        int ret = fread(FileBuffer, FileSize + 1, 1, InputFile);

    }
    catch (int ExitCode)
    {
        printf("Error, failed to load input file...\n Exit code: %i\n", ExitCode);
        exit(1);
    }
    return;
}
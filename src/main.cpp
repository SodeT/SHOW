#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <thread>

void ReadInputFile(std::string InputFilePath, File* InputFile);

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
    File* InputFile;

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

    ReadInputFile(InputFilePath, InputFile);
    printf(InputFile);
    return 0;
}

void ReadInputFile(std::string InputFilePath, File* InputFile)
{
    
    try
    {
        
        if ((InputFile = fopen(InputFilePath, "r")) != NULL) // port to f open from c++ bloat
        {
            printf("Error, could not open file...\n");
            exit(1);
        }

        InputFileStream.seekg(0, InputFileStream.end);
        int FileLength = InputFileStream.tellg();
        char* Buffer = new char[FileLength];
        InputFileStream.seekg(0, InputFileStream.beg);
        
        InputFileStream.read(Buffer, FileLength);
        InputFile = Buffer;
        delete[] Buffer;
    }
    catch (int ExitCode)
    {
        printf("Error, failed to load input file...\n Exit code: %i\n", ExitCode);
        exit(1);
    }
    return;

}
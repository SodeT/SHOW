#include <string> // std::string
#include <stdlib.h> // fopen
#include <memory> // smart ptr

std::shared_ptr<char> ReadFile(std::string InputFilePath, FILE* InputFile)
{
    try
    {
        InputFile = fopen(InputFilePath.c_str(), "r");

        fseek(InputFile, 0, SEEK_END);
        int FileSize = ftell(InputFile);
        std::shared_ptr<char> FileBuffer = std::make_shared<char>(FileSize);
        fseek(InputFile, 0, SEEK_SET);
        printf("Seg1\n");
        fread(FileBuffer.get(), FileSize + 1, 1, InputFile);
        printf("seg2\n");
        return FileBuffer;
    }
    catch (int ExitCode)
    {
        printf("Error, failed to load input file...\n Exit code: %i\n", ExitCode);
        exit(1);
    }
}
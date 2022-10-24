#include <string>
#include <vector>

void parseWords(std::string parseFile, std::string inputWords[], int wordCount, int type, int output[])
{
    for (int i = 0; i < wordCount; i++)
    {
        // find first occurance 
        if (parseFile.find(inputWords[i]) != std::string::npos)
        {
            output[i] = type;
        }
        else
        {
            output[i] = 0; //pt_unknown; // fix "extern enum" problem
        }

    }
    return;
}
#include <string>
#include <utils.hpp> 

std::string chomp(std::string input, std::string forbiddenChars)
{
    std::string output = "";
    for (size_t i = 0; i < input.length(); i++)
    {
        if (forbiddenChars.find(input[i]) == std::string::npos)
        {
            output += input[i];
        }
    }

    return output;
}
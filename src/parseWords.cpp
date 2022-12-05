#include <string>
#include <vector>
#include <iostream>
#include <structs.hpp>

std::vector<int> parseWords(std::vector<filter> filters, std::vector<std::string> inputWords)  //, std::vector<int>& output)
{
    std::vector<int> output;
    bool assigned = false;
    for (size_t i = 0; i < inputWords.size(); i++)
    {
        assigned = false;
        for (size_t j = 0; j < filters.size(); j++)
        {
            if (filters[j].content.find(inputWords[i]) != std::string::npos)
            {
                output.push_back(filters[j].type);
                assigned = true;
            }
        }
        if (!assigned)
        {
            output.push_back(0);
        }
    }
    return output;
}
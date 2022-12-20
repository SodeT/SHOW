#include <string>
#include <vector>
#include <iostream>
#include <structs.hpp>
#include <utils.hpp>
#include <algorithm>

// 0 = none, 1 = quote, 2 = number

std::vector<int> parseWords(std::vector<filter> filters, std::vector<std::string> inputWords)
{
    std::vector<int> output;
    bool assigned = false;
    bool quote = false;
    bool skip = false;
    std::string word;
    for (size_t i = 0; i < inputWords.size(); i++)
    {
        word = inputWords[i];
        skip = false;
        if (word.find("\"") != std::string::npos)
        {
            if (word.find("\"") == word.rfind("\""))
                quote = !quote;
            output.push_back(1);
            skip = true;
        }
        else if (quote)
        {
            output.push_back(1);
            skip = true;
        }

        if (word.find_first_of("0123456789") != std::string::npos)
        {
            output.push_back(2);
            continue;
        }

        if (skip)
        {
            continue;
        }

        word = downcase(word);

        assigned = false;
        for (size_t j = 0; j < filters.size(); j++)
        {
            std::vector<std::string>::iterator strIterator;
            strIterator = std::find(filters[j].content.begin(), filters[j].content.end(), word);
            if (strIterator != filters[j].content.end())
            {
                output.push_back(filters[j].type);
                assigned = true;
                break;
            }
        }
        if (!assigned)
        {
            output.push_back(0);
        }
    }
    return output;
}
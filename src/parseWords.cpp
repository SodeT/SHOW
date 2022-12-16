#include <string>
#include <vector>
#include <iostream>
#include <structs.hpp>
#include <utils.hpp>
#include <algorithm>

// 0 = none, 1 = quote, 2 = number

std::vector<int> parseWords(std::vector<filter> filters, std::vector<std::string> inputWords)  //, std::vector<int>& output)
{
    std::vector<int> output;
    bool assigned = false;
    bool quote = false;
    std::string word;
    for (size_t i = 0; i < inputWords.size(); i++)
    {
        word = inputWords[i];
        if (word.find_first_of("0123456789") != std::string::npos)
        {
            output.push_back(2);
            continue;
        }
        else if (word.find("\"") != std::string::npos)
        {
            quote = !quote;
            output.push_back(1);
            continue;
        }
        else if (quote)
        {
            output.push_back(1);
            continue;
        }

        word = downcase(word);

        assigned = false;
        for (size_t j = 0; j < filters.size(); j++)
        {
            for (size_t h = 0; h < filters[j].content.size(); h++)
            {
                std::vector<std::string>::iterator strIterator;
                strIterator = std::find(filters[j].content.begin(), filters[j].content.end(), word);
                if (strIterator != filters[j].content.end())
                {
                    output.push_back(filters[j].type);
                    assigned = true;
                    goto end;
                }
            }
        }
        end:
        if (!assigned)
        {
            output.push_back(0);
        }
    }
    return output;
}
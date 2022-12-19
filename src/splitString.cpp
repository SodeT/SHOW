#include <string>
#include <vector>
#include <iostream>
#include <utils.hpp>

std::vector<std::string> splitString(std::string input)
{
    std::vector<std::string> words;
    std::string word;
    long long unsigned int spaceIndex; // bruh fr
    do
    {
        spaceIndex = input.find(" ");
        if (spaceIndex == std::string::npos)
        {
            words.push_back(input);
            break;
        }
        word = input.substr(0, spaceIndex +1);
        input = input.substr(word.length());
        words.push_back(word);


    } while (input.length() > 0);

    return words;
}
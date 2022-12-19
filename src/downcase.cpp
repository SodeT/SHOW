#include <string>
#include <utils.hpp>

std::string downcase(std::string str)
{
    std::string ret;
    for (size_t i = 0; i < str.length(); i++)
    {
        ret += std::tolower(str[i]);
    }
    return ret;
}
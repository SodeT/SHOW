#include <string>
#include <vector>
#include <utils.hpp>

std::string joinContent(std::vector<std::string> content, std::string symbol)
{
    std::string ret;

    for (size_t i = 0; i < content.size(); i++)
    {
        ret += content[i];
        ret += symbol;
    }

    return ret;
}
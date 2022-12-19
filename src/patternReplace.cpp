#include <string> 
#include <utils.hpp>

std::string patternReplace(std::string insert, std::string symbol, std::string str)
{
    size_t pos = str.find(symbol);
    str.replace(pos, symbol.length(), insert);
    return str;
}
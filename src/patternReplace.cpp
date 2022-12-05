#include <string> 

std::string patternReplace(std::string insert, std::string symbol, std::string styleTemplate)
{
    size_t pos = styleTemplate.find(symbol);
    styleTemplate.replace(pos, symbol.length(), insert);
    return styleTemplate;

}
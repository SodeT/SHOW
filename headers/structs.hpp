#ifndef FILTER_CONFIG_HPP
#define FILTER_CONFIG_HPP

#include <vector>
#include <string>

struct filter
{
    std::string fg;
    std::string bg;
    std::string font;
    std::string size;
    std::string weight;

    std::string fileName;
    std::vector<std::string> content;
    
    int type;


    filter(std::string fg, std::string bg, std::string font, std::string size, std::string weight, std::string fileName, int type);
};

#endif


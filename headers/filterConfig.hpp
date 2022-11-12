#ifndef FILTER_CONFIG_HPP
#define FILTER_CONFIG_HPP

#include <vector>
#include <string>

class filterConfig
{
public:
    std::string fg;
    std::string bg;
    std::string font;
    std::string size;
    std::string weight;

    int type;

    filterConfig(std::string fg, std::string bg, std::string font, std::string size, std::string weight, int type);

};

#endif
#include <string>
#include <filterConfig.hpp>

filterConfig::filterConfig(std::string fg, std::string bg, std::string font, std::string size, std::string weight, int type)
    : fg(fg), bg(bg), font(font), size(size), weight(weight), type(type)
{
    return;
}
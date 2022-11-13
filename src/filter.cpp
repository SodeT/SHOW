#include <string>
#include <structs.hpp>
#include <utils.hpp>

filter::filter(std::string fg, std::string bg, std::string font, std::string size, std::string weight, std::string fileName, int type)
    : fg(fg), bg(bg), font(font), size(size), weight(weight), fileName(fileName), type(type)
{
    return;
}
#include <string>
#include <structs.hpp>
#include <utils.hpp>

#include <iostream>

std::string writeStyle(filter currentFilter)
{
    std::string styleTemplate = ".T-TYPE- {color: -FG-; background-color: -BG-; size: -SIZE-; font-weight: -WEIGHT-; font-family: -FONT-;}";

    styleTemplate = patternReplace(std::to_string(currentFilter.type), "-TYPE-", styleTemplate);
    styleTemplate = patternReplace(currentFilter.fg, "-FG-", styleTemplate);
    styleTemplate = patternReplace(currentFilter.bg, "-BG-", styleTemplate);
    styleTemplate = patternReplace(currentFilter.size, "-SIZE-", styleTemplate);
    styleTemplate = patternReplace(currentFilter.weight, "-WEIGHT-", styleTemplate);
    styleTemplate = patternReplace(currentFilter.font, "-FONT-", styleTemplate);
    return styleTemplate;
}
#include <string>
#include <structs.hpp>
#include <utils.hpp>

std::string writeStyle(filter currentFilter)
{
    std::string styleTemplate = "<style:style style:name=\"T-TYPE-\" style:family=\"text\"><style:text-properties fo:font-size=\"-SIZE-.00pt\" fo:font-weight=\"-WEIGHT-\" fo:font-family=\"-FONT-\" style:font-family-asian=\"-FONT-\" style:font-family-complex=\"-FONT-\" fo:background-color=\"-BG-\" fo:color=\"-FG-\" /></style:style>";

    styleTemplate = patternReplace(std::to_string(currentFilter.type), "-TYPE-", styleTemplate);
    styleTemplate = patternReplace(currentFilter.fg, "-FG-", styleTemplate);
    styleTemplate = patternReplace(currentFilter.bg, "-BG-", styleTemplate);
    styleTemplate = patternReplace(currentFilter.size, "-SIZE-", styleTemplate);
    styleTemplate = patternReplace(currentFilter.weight, "-WEIGHT-", styleTemplate);
    for (int i = 0; i < 3; i++)
    {
        styleTemplate = patternReplace(currentFilter.font, "-FONT-", styleTemplate);
    }

    return styleTemplate;
}
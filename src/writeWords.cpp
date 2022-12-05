#include <string>
#include <structs.hpp>
#include <utils.hpp>

std::string writeWords(std::string word, int type)
{
    std::string wordTemplate = "<text:span text:style-name=\"T-STYLE-\">-WORD-<text:s /></text:span>";

    wordTemplate = patternReplace(std::to_string(type), "-STYLE-", wordTemplate);
    wordTemplate = patternReplace(word, "-WORD-", wordTemplate);

    return wordTemplate;
}
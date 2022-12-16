#include <string>
#include <structs.hpp>
#include <utils.hpp>

std::string writeWords(std::string word, int type)
{
    std::string wordTemplate = "<p class=\"T-TYPE-\">-WORD- </p>";

    wordTemplate = patternReplace(std::to_string(type), "-TYPE-", wordTemplate);
    wordTemplate = patternReplace(word, "-WORD-", wordTemplate);

    return wordTemplate;
}
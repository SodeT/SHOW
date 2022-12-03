#ifndef UTILS_HPP
#define UTILS_HPP

#include <structs.hpp>

const std::string forbiddenChars = " \n\r";

std::vector<int> parseWords(std::vector<filter> filters, std::vector<std::string> inputWords);
std::string readFile(std::string path);
void parseConfig(std::string inputFile, std::vector<filter>& filters);
std::string chomp(std::string input, std::string forbiddenChars);

#endif
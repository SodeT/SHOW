#ifndef UTILS_HPP
#define UTILS_HPP

#include <structs.hpp>

// variables
const std::string escChars = " \n\r";
const std::string specChars = " \n\r.:,;-_*'¨^´()[]{}!?+-@#£$%&/‘\\";

// parse input
std::vector<int> parseWords(std::vector<filter> filters, std::vector<std::string> inputWords);
void parseConfig(std::string inputFile, std::vector<filter>& filters);

// generate html
std::string writeStyle(filter filters);
std::string writeWords(std::string word, int type);

// help functions
std::string chomp(std::string input, std::string forbiddenChars);
std::string patternReplace(std::string insert, std::string symbol, std::string str);
std::string joinContent(std::vector<std::string> content, std::string symbol);
std::string downcase(std::string str);
std::vector<std::string> splitString(std::string input);

// read write
std::string readFile(std::string path);
void writeFile(std::string path, std::string content);

#endif
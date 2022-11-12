#ifndef UTILS_HPP
#define UTILS_HPP

#include <filterConfig.hpp>

void parseWords(std::string parseFile, std::string inputWords[], int wordCount, int type, int output[]);
std::string readFile(std::string path);
std::vector<filterConfig> readConfig(std::string inputFile, std::string* parseFilePaths);
#endif
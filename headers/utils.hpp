#ifndef UTILS_HPP
#define UTILS_HPP

#include <structs.hpp>

void parseWords(std::string parseFile, std::string inputWords[], int wordCount, int type, std::vector<int> output);

std::string readFile(std::string path);

void parseConfig(std::string inputFile, std::vector<filter>* filters);

int mergeArray(std::vector<int> options);

#endif
#ifndef CONFIG_HPP
#define CONFIG_HPP

const int filterNum = 2;
std::string parseFiles[filterNum];
std::string parseFilePaths[filterNum] = {"nouns.txt", "adjectives.txt"};
enum phraseTypes {pt_unknown = 0, pt_quote, pt_number, pt_nouns, pt_adjectives}; 

#endif
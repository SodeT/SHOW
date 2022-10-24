#ifndef CONFIG_HPP
#define CONFIG_HPP

const int parseNum = 2;
std::string parseFiles[parseNum];
std::string parseFilePaths[parseNum] = {"nouns.txt", "adjectives.txt"};
enum phraseTypes {pt_unknown = 0, pt_nouns, pt_adjectives}; 

#endif
// This is file is used for special settings and the project must be recompiled for the changes to take effect.

#ifndef CONFIG_HPP
#define CONFIG_HPP

const int filterNum = 16;
std::string parseFiles[filterNum];
std::string parseFilePaths[filterNum];
enum filterType {ft_unknown = 0, ft_quote, ft_number}; 

#endif
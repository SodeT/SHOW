#include <fstream>

void writeFile(std::string path, std::string content)
{
    std::ofstream file;
    file.open(path);
    file << content;
    file.close();
    return;
}
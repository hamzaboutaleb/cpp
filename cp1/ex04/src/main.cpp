#include <iostream>
#include <fstream>

void replace(std::string &s, const std::string &to_find, const std::string &to_replace)
{
    size_t pos = 0;
    if (to_find.empty() || to_find == to_replace)
        return;

    while ((pos = s.find(to_find, pos)) != std::string::npos)
    {
        s.erase(pos, to_find.size());
        s.insert(pos, to_replace);
        pos += to_replace.size();
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Invalid number of args" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string newFileName = filename + ".replace";
    std::string oldString = argv[2];
    std::string newString = argv[3];

    std::ifstream inFile(filename.c_str());
    std::ofstream outFile(newFileName.c_str());

    if (!inFile)
    {
        std::cerr << "file: " << filename << " doesnt exists" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        replace(line, oldString, newString);
        outFile << line << std::endl;
    }
    return 0;
}
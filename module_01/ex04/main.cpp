#include <iostream>
#include <fstream>
#include <string>

std::string findReplace(std::string inStr, std::string find,
                        std::string replaceBy)
{
    size_t findLen = find.length();
    if (findLen == 0) {
        return (inStr);
    }
    std::string outStr = "";
    std::string subString;
    for (size_t i=0; i<inStr.length(); i++) {
        subString = inStr.substr(i, findLen);
        if (i + findLen > inStr.length()) {
            outStr += inStr.at(i);
        }
        else if (subString == find) {
            outStr += replaceBy;
            i += (findLen - 1);
        }
        else {
            outStr += inStr.at(i);
        }
    };
    return (outStr);
}

bool parseInput(int argc, char *argv[],
                std::string &filename, std::string &s1,
                std::string &s2, std::ifstream &inFile)
{
    if (argc != 4) {
        std::cout << "Error: invalid number of arguments" << std::endl;
        return (false);
    }
    filename = argv[1];
    s1 = argv[2];
    s2 = argv[3];
    inFile.open(filename);
    if (!inFile) {
        std::cout << "Error: file " << filename << " does not exist" << std::endl;
        return (false);
    }
    if (s1.empty()) {
        std::cout << "Error: the second argument can not be an empty string"
                  << std::endl;
        return (false);
    }
    return (true);
}

int main(int argc, char *argv[])
{
    std::ifstream inFile;
    std::string filename;
    std::string s1;
    std::string s2;

    if (!parseInput(argc, argv, filename, s1, s2, inFile)) {
        return (1);
    }
    std::ofstream outFile(filename + ".replace");
    std::string lineIn;
    while (std::getline(inFile, lineIn)) {
        outFile << findReplace(lineIn, s1, s2) << std::endl;
    }
    inFile.close();
    outFile.close();
    return (0);
}

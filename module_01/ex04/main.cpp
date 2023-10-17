#include <iostream>
#include <fstream>
#include <string>

std::string findReplace(std::string inStr, std::string find,
                        std::string replaceBy)
{
    size_t findLen = find.length();
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

int main(int argc, char *argv[])
{
    // parsing inputs
    if (argc != 4) {
        std::cout << "invalid number of arguments" << std::endl;
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cout << "file " << filename << " does not exist" << std::endl;
        return (1);
    }

    // create output file
    std::ofstream outFile(filename + ".replace");
    std::string lineIn;
    while (std::getline(inFile, lineIn)) {
        outFile << findReplace(lineIn, s1, s2) << std::endl;
    }
    inFile.close();
    outFile.close();
    return (0);
}
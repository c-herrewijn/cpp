
#include <iostream>
#include <utility>
#include <list>
#include <sstream>
#include <regex>

#include "PmergeMe.hpp"

/*
accepted range: [1 - INT32_MAX]
*/
bool isPositiveIteger(std::string s)
{
    return (std::regex_match(s.data(), std::regex(R"([1-9][0-9]*)"))
            && s.length() <= 10
            && std::stol(s) <= INT32_MAX);
}

unsigned int getJacobstahlNr(unsigned int n)
{
    return (n % 2 == 0) ? ((1<<n)-1)/3 : ((1<<n)+1)/3;
}

bool convertInputToList(std::string inputString, std::list<int> &inputList)
{
    std::istringstream ss(inputString);
    for (std::string token; ss >> token;) {
        if (isPositiveIteger(token) == false) {
            return false;
        }
        inputList.emplace_back(stoi(token));
    }
    return true;
}

bool parseInput(int argc, char *argv[], std::list<int> &inputList)
{
    if (argc != 2) {
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return false;
    }
    if (convertInputToList(argv[1], inputList) == false) {
        std::cerr << "Error: invalid input" << std::endl;
        return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    std::list<int> inputList;
    if (parseInput(argc, argv, inputList) == false) {
        return EXIT_FAILURE;
    }

    // test Jacobstahl
    for (int i=0; i<10; i++) {
        std::cout << getJacobstahlNr(i) << std::endl;
    }

    // test Pair
    Pair p1, p2;
    p1.first = 3;
    p1.second = 4;
    p2.first = 5;
    p1.second = 7;
    std::cout << (p1 < p2) << std::endl;
}

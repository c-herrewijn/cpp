
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

// works for n in range [0 - 30]
unsigned int getJacobstahlNr(unsigned int n)
{
    return (n % 2 == 0) ? ((1<<n)-1)/3 : ((1<<n)+1)/3;
}

int main(int argc, char *argv[])
{
    PmergeMe sorter;
    if (sorter.parseInput(argc, argv) == false) {
        return EXIT_FAILURE;
    }

    // test parsing
    std::cout << sorter._inputList.size() << std::endl;

    // test Jacobstahl
    for (int i=0; i<10; i++) {
        std::cout << getJacobstahlNr(i) << std::endl;
    }

    // test Pair
    PmergeMe::Pair p1, p2;
    p1.first = 3;
    p1.second = 4;
    p2.first = 5;
    p1.second = 7;
    std::cout << (p1 < p2) << std::endl;
}

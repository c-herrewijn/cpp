
#include <iostream>
#include <utility>
#include <list>
#include <sstream>
#include <regex>
#include <iterator>

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

// works for n in range [0 - 33]
unsigned int getJacobstahlNr(unsigned int n)
{
    return (n % 2 == 0) ? ((1UL<<n)-1)/3 : ((1UL<<n)+1)/3;
}


/*
NOTE:
- when calling this function, 'maxIndex' should be lst.size().
- this function assumes the list is sorted
*/
void binaryListInsertion(int nrToInsert, std::list<int> &lst, int minIndex,
                         int maxIndex)
{
    if (minIndex == maxIndex) {
        auto it = lst.begin();
        std::advance(it, minIndex);
        lst.insert(it, nrToInsert);
    }
    else {
        int midIndex = minIndex + (maxIndex - minIndex) / 2;
        auto itMid = lst.begin();
        std::advance(itMid, midIndex);
        if (nrToInsert < *itMid) {
            binaryListInsertion(nrToInsert, lst, minIndex, midIndex);
        }
        else {
            binaryListInsertion(nrToInsert, lst, midIndex+1, maxIndex);
        }
    }
}

int main(int argc, char *argv[])
{
    PmergeMe sorter;
    if (sorter.parseInput(argc, argv) == false) {
        return EXIT_FAILURE;
    }
    sorter.sortList();

    // test pair creation
    for (auto pair : sorter._pairList) {
        std::cout << pair.first << ", " << pair.second << std::endl;
    }

    // test binary list insertion
    std::list<int> lst;
    lst.emplace_back(3);
    lst.emplace_back(3);
    lst.emplace_back(5);
    lst.emplace_back(7);
    lst.emplace_back(100);

    auto it = lst.begin();
    binaryListInsertion(42, lst, 0, lst.size());
    for (int num : lst) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;

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

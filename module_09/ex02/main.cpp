
#include <iostream>
#include <utility>
#include <list>
#include <sstream>
#include <regex>
#include <iterator>
#include <chrono>

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

/*
NOTE:
- when calling this function, 'maxIndex' should be lst.size().
- this function assumes the list is sorted
*/
void binaryVectInsertion(int nrToInsert, std::vector<int> &v, int minIndex,
                         int maxIndex)
{
    if (minIndex == maxIndex) {
        auto it = v.begin();
        std::advance(it, minIndex);
        v.insert(it, nrToInsert);
    }
    else {
        int midIndex = minIndex + (maxIndex - minIndex) / 2;
        auto itMid = v.begin();
        std::advance(itMid, midIndex);
        if (nrToInsert < *itMid) {
            binaryVectInsertion(nrToInsert, v, minIndex, midIndex);
        }
        else {
            binaryVectInsertion(nrToInsert, v, midIndex+1, maxIndex);
        }
    }
}

int main(int argc, char *argv[])
{
    PmergeMe sorter;
    if (sorter.parseInput(argc, argv) == false) {
        return EXIT_FAILURE;
    }
    sorter.printInputList();

    // sorting with std::list
    const auto t0_l = std::chrono::steady_clock::now();
    sorter.sortList();
    const auto t1_l = std::chrono::steady_clock::now();
    sorter.printSortedList();
    std::cout << "Time to process " << argc - 1 << " elements with std::list : "
              << std::chrono::duration_cast<std::chrono::microseconds>(t1_l - t0_l).count()
              << " us" << std::endl;

    // sorting with std::vector
    const auto t0_v = std::chrono::steady_clock::now();
    sorter.sortVect();
    const auto t1_v = std::chrono::steady_clock::now();
    // sorter.printSortedVect();
    std::cout << "Time to process " << argc - 1 << " elements with std::vector : "
              << std::chrono::duration_cast<std::chrono::microseconds>(t1_v - t0_v).count()
              << " us" << std::endl;
}

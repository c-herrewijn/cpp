#include <algorithm>
#include <iostream>
#include <regex>

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
    *this = rhs;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    this->_inputList = rhs._inputList;
    this->_sortedList = rhs._sortedList;
    this->_pairList = rhs._pairList;
    this->_inputVect = rhs._inputVect;
    this->_sortedVect = rhs._sortedVect;
    this->_pairVect = rhs._pairVect;
    return *this;
}

/*
accepted range: [1 - INT32_MAX]
*/
bool PmergeMe::isPositiveIteger(std::string s)
{
    return (std::regex_match(s.data(), std::regex(R"([1-9][0-9]*)"))
            && s.length() <= 10
            && std::stol(s) <= INT32_MAX);
}

// works for n in range [0 - 33]
unsigned int PmergeMe::getJacobstahlNr(unsigned int n)
{
    return (n % 2 == 0) ? ((1UL<<n)-1)/3 : ((1UL<<n)+1)/3;
}

/*
NOTE:
- when calling this function, 'maxIndex' should be lst.size().
- this function assumes the list is sorted
*/
void PmergeMe::binaryListInsertion(int nrToInsert, std::list<int> &lst,
                                   int minIndex, int maxIndex)
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
void PmergeMe::binaryVectInsertion(int nrToInsert, std::vector<int> &v,
                                   int minIndex, int maxIndex)
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

bool PmergeMe::parseInput(int argc, char *argv[])
{
    if (argc < 2) {
        std::cerr << "Error: no numbers to sort" << std::endl;
        return false;
    }
    this->_numberCount = argc - 1;
    if (this->_convertInputToList(argc, argv) == false) {
        std::cerr << "Error: invalid input" << std::endl;
        return false;
    }
    this->_inputVect.reserve(this->_numberCount);
    this->_sortedVect.reserve(this->_numberCount);
    this->_pairVect.reserve((this->_numberCount + 1)/2);
    if (this->_convertInputToVect(argc, argv) == false) {
        std::cerr << "Error: invalid input" << std::endl;
        return false;
    }
    return true;
}

void PmergeMe::printInputList() const
{
    std::cout << "Before: ";
    for (int i : this->_inputList) {
        std::cout << " " << i;
    }
    std::cout << std::endl;
}

void PmergeMe::printSortedList() const
{
    std::cout << "After:  ";
    for (int i : this->_sortedList) {
        std::cout << " " << i;
    }
    std::cout << std::endl;
}

void PmergeMe::sortList()
{
    this->_createPairList();
    this->_mergeFirstIntoList();
    this->_insertSecondIntoList();
}

bool PmergeMe::_convertInputToList(int argc, char *argv[])
{
    for (int i=1; i<argc; i++) {
        if (isPositiveIteger(argv[i]) == false) {
            return false;
        }
        this->_inputList.emplace_back(std::atoi(argv[i]));
    }
    return true;
}

// if nr. is odd, end with a semi pair that only has 1 nr.
void PmergeMe::_createPairList()
{
    Pair semiPair;
    if (this->_numberCount % 2 == 1) {
        semiPair = Pair(this->_inputList.back());
        this->_inputList.pop_back();
    }
    for (auto it=this->_inputList.begin(); it!=this->_inputList.end();
            std::advance(it, 2)) {
        this->_pairList.emplace_back(
                           Pair(std::max(*it, *std::next(it, 1)),
                                std::min(*it, *std::next(it, 1))
                               ));
    }
    this->_pairList.sort();
    if (this->_numberCount % 2 == 1) {
        this->_pairList.push_back(semiPair);
    }
}

void PmergeMe::_mergeFirstIntoList()
{
    for (class PmergeMe::Pair &pair : this->_pairList) {
        if (pair.semiPair == false) {
            this->_sortedList.emplace_back(pair.first);
        }
    }
}

// jacobstahl range: 0 1 1 3 5 11 21 43; so index [2] is value 1
void PmergeMe::_insertSecondIntoList()
{
    size_t nrPairs = this->_pairList.size();
    this->_sortedList.emplace_front(this->_pairList.front().second);
    size_t nums_inserted = 1;
    size_t IndexlastPairSorted = 0;

    size_t jacobstahlIndex = 2;
    size_t jacobstahlNr = getJacobstahlNr(jacobstahlIndex++);
    while (IndexlastPairSorted < this->_pairList.size()) {
        size_t prevJacobstahlNr = jacobstahlNr;
        jacobstahlNr = getJacobstahlNr(jacobstahlIndex++);
        size_t pairIndex = jacobstahlNr - 1;
        while (pairIndex < jacobstahlNr && pairIndex >= prevJacobstahlNr) {
            if (pairIndex < nrPairs) {
                auto it = this->_pairList.begin();
                std::advance(it, pairIndex);
                binaryListInsertion(it->second, this->_sortedList, 0,
                                    pairIndex + nums_inserted);
                nums_inserted++;
            }
            pairIndex--;
        }
        IndexlastPairSorted = jacobstahlNr - 1;
    }
}

void PmergeMe::printInputVect() const
{
    std::cout << "Before: ";
    for (int i : this->_inputVect) {
        std::cout << " " << i;
    }
    std::cout << std::endl;
}

void PmergeMe::printSortedVect() const
{
    std::cout << "After:  ";
    for (int i : this->_sortedVect) {
        std::cout << " " << i;
    }
    std::cout << std::endl;
}

void PmergeMe::sortVect()
{
    this->_createPairVect();
    this->_mergeFirstIntoVect();
    this->_insertSecondIntoVect();
}

bool PmergeMe::_convertInputToVect(int argc, char *argv[])
{
    for (int i=1; i<argc; i++) {
        if (isPositiveIteger(argv[i]) == false) {
            return false;
        }
        this->_inputVect.emplace_back(std::atoi(argv[i]));
    }
    return true;
}

void PmergeMe::_createPairVect()
{
    Pair semiPair;
    if (this->_numberCount % 2 == 1) {
        semiPair = Pair(this->_inputVect.back());
        this->_inputVect.pop_back();
    }
    for (auto it=this->_inputVect.begin(); it!=this->_inputVect.end();
            std::advance(it, 2)) {
        this->_pairVect.emplace_back(
                           Pair(std::max(*it, *std::next(it, 1)),
                                std::min(*it, *std::next(it, 1))
                               ));
    }
    sort(this->_pairVect.begin(), this->_pairVect.end());
    if (this->_numberCount % 2 == 1) {
        this->_pairVect.push_back(semiPair);
    }
}

void PmergeMe::_mergeFirstIntoVect()
{
    for (class PmergeMe::Pair &pair : this->_pairVect) {
        if (pair.semiPair == false) {
            this->_sortedVect.emplace_back(pair.first);
        }
    }
}

void PmergeMe::_insertSecondIntoVect()
{
    size_t nrPairs = this->_pairVect.size();
    this->_sortedVect.emplace(this->_sortedVect.begin(),
                              this->_pairVect.front().second);
    size_t nums_inserted = 1;
    size_t IndexlastPairSorted = 0;

    size_t jacobstahlIndex = 2;
    size_t jacobstahlNr = getJacobstahlNr(jacobstahlIndex++);
    while (IndexlastPairSorted < this->_pairVect.size()) {
        size_t prevJacobstahlNr = jacobstahlNr;
        jacobstahlNr = getJacobstahlNr(jacobstahlIndex++);
        size_t pairIndex = jacobstahlNr - 1;
        while (pairIndex < jacobstahlNr && pairIndex >= prevJacobstahlNr) {
            if (pairIndex < nrPairs) {
                auto it = this->_pairVect.begin();
                std::advance(it, pairIndex);
                binaryVectInsertion(it->second, this->_sortedVect, 0,
                                    pairIndex + nums_inserted);
                nums_inserted++;
            }
            pairIndex--;
        }
        IndexlastPairSorted = jacobstahlNr - 1;
    }
}

PmergeMe::Pair::Pair() {}

PmergeMe::Pair::Pair(const Pair &rhs)
    : first(rhs.first), second(rhs.second), semiPair(rhs.semiPair) {}

PmergeMe::Pair::Pair(unsigned int second)
    : first(-1), second(second), semiPair(true) {}

PmergeMe::Pair::Pair(unsigned int first, unsigned int second)
    : first(first), second(second), semiPair(false) {}

PmergeMe::Pair::~Pair() {}

PmergeMe::Pair &PmergeMe::Pair::operator=(const Pair &rhs)
{
    this->first = rhs.first;
    this->second = rhs.second;
    this->semiPair = rhs.semiPair;
    return *this;
}

bool PmergeMe::Pair::operator<(Pair &rhs) const
{
    return (this->first < rhs.first);
}

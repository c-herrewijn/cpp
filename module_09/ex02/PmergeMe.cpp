#include <algorithm>
#include <iostream>
#include <sstream>

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
    return *this;
}

bool PmergeMe::parseInput(int argc, char *argv[])
{
    if (argc < 2) {
        std::cerr << "Error: no numbers to sort" << std::endl;
        return false;
    }
    if (this->_convertInputToList(argc, argv) == false) {
        std::cerr << "Error: invalid input" << std::endl;
        return false;
    }
    return true;
}

void PmergeMe::printInputList()
{
    std::cout << "Before: ";
    for (int i : this->_inputList) {
        std::cout << " " << i;
    }
    std::cout << std::endl;
}

void PmergeMe::printSortedList()
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
    this->_numberCount = argc - 1;
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
    for (auto i : this->_pairList) {
        if (i._semiPair == false) {
            this->_sortedList.emplace_back(i._first);
        }
    }
}

// jacobstahl range: 0 1 1 3 5 11 21 43; so index [2] is value 1
void PmergeMe::_insertSecondIntoList()
{
    size_t nrPairs = this->_pairList.size();
    this->_sortedList.emplace_front(this->_pairList.front()._second);
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
                binaryListInsertion(it->_second, this->_sortedList, 0,
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
    : _first(rhs._first), _second(rhs._second), _semiPair(rhs._semiPair) {}

PmergeMe::Pair::Pair(unsigned int second)
    : _first(-1), _second(second), _semiPair(true) {}

PmergeMe::Pair::Pair(unsigned int first, unsigned int second)
    : _first(first), _second(second), _semiPair(false) {}

PmergeMe::Pair::~Pair() {}

PmergeMe::Pair &PmergeMe::Pair::operator=(const Pair &rhs)
{
    this->_first = rhs._first;
    this->_second = rhs._second;
    this->_semiPair = rhs._semiPair;
    return *this;
}

bool PmergeMe::Pair::operator<(Pair &rhs) const
{
    return (this->_first < rhs._first);
}

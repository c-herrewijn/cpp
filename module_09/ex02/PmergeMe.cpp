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

void PmergeMe::_createPairList()
{
    if (this->_inputList.size() % 2 == 1) {
        this->_oddNumber = this->_inputList.front();
        this->_inputList.pop_front();
    }
    else {
        this->_oddNumber = -1;
    }
    for (auto it=this->_inputList.begin(); it!=this->_inputList.end();
            std::advance(it, 2)) {
        this->_pairList.emplace_back(
                           Pair(std::max(*it, *std::next(it, 1)),
                                std::min(*it, *std::next(it, 1))
                               ));
    }
    this->_pairList.sort();
}

void PmergeMe::sortList()
{
    this->_createPairList();

    // to do...
}

PmergeMe::Pair::Pair() {}

PmergeMe::Pair::Pair(const Pair &rhs)
    : first(rhs.first), second(rhs.second) {}

PmergeMe::Pair::Pair(unsigned int first, unsigned int second)
    : first(first), second(second) {}

PmergeMe::Pair::~Pair() {}

PmergeMe::Pair &PmergeMe::Pair::operator=(const Pair &rhs)
{
    this->first = rhs.first;
    this->second = rhs.second;
    return *this;
}

bool PmergeMe::Pair::operator<(Pair &rhs) const
{
    return (this->first < rhs.first);
}

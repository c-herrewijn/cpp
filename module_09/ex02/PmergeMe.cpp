#include <iostream>
#include <sstream>

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
    *this = obj;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    // TODO: copy all attributes
    this->_inputList = obj._inputList;
    return *this;
}

bool PmergeMe::_convertInputToList(std::string inputString)
{
    std::istringstream ss(inputString);
    for (std::string token; ss >> token;) {
        if (isPositiveIteger(token) == false) {
            return false;
        }
        this->_inputList.emplace_back(stoi(token));
    }
    return true;
}

bool PmergeMe::parseInput(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return false;
    }
    if (this->_convertInputToList(argv[1]) == false) {
        std::cerr << "Error: invalid input" << std::endl;
        return false;
    }
    return true;
}

bool PmergeMe::Pair::operator<(Pair &rhs) const
{
    return (this->first < rhs.first);
}
bool PmergeMe::Pair::operator>(Pair &rhs) const
{
    return (this->first > rhs.first);
}

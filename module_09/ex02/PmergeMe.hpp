#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <list>

// utils
bool isPositiveIteger(std::string s);

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &obj);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &obj);

    class Pair;
    bool parseInput(int argc, char *argv[]);

// private:
    bool _convertInputToList(std::string s);
    std::list<int> _inputList;
};

class PmergeMe::Pair {
public:
    unsigned int first;
    unsigned int second;

    bool operator<(Pair &rhs) const;
    bool operator>(Pair &rhs) const;
};

#endif

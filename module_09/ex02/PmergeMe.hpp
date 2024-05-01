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
    void sortList();

// private:
    bool _convertInputToList(std::string s);
    void _createPairList();
    std::list<int> _inputList;
    std::list<Pair> _pairList;
    int _oddNumber;
};

class PmergeMe::Pair {
public:
    Pair();
    Pair(unsigned int first, unsigned int second);

    unsigned int first;
    unsigned int second;
    bool operator<(Pair &rhs) const;
};

#endif

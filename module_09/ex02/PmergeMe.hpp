#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <list>
#include <vector>

// utils
bool isPositiveIteger(std::string s);
unsigned int getJacobstahlNr(unsigned int n);
void binaryListInsertion(int nrToInsert, std::list<int> &lst, int minIndex,
                         int maxIndex);
void binaryVectInsertion(int nrToInsert, std::vector<int> &v, int minIndex,
                         int maxIndex);

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &rhs);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &rhs);
    bool parseInput(int argc, char *argv[]);

    // list
    void sortList();
    void printInputList();
    void printSortedList();

    // vector
    void sortVect();
    void printInputVect();
    void printSortedVect();

private:
    class Pair;
    int _numberCount;

    // list
    bool _convertInputToList(int argc, char *argv[]);
    void _createPairList();
    void _mergeFirstIntoList();
    void _insertSecondIntoList();
    std::list<int> _inputList;
    std::list<int> _sortedList;
    std::list<Pair> _pairList;

    // vector
    bool _convertInputToVect(int argc, char *argv[]);
    void _createPairVect();
    void _mergeFirstIntoVect();
    void _insertSecondIntoVect();
    std::vector<int> _inputVect;
    std::vector<int> _sortedVect;
    std::vector<Pair> _pairVect;
};

class PmergeMe::Pair {
public:
    Pair();
    Pair(unsigned int first, unsigned int second);
    Pair(unsigned int second);
    Pair(const Pair &rhs);
    ~Pair();

    Pair &operator=(const Pair &rhs);
    bool operator<(Pair &rhs) const;

    unsigned int first;
    unsigned int second;
    bool semiPair; // true means only the "second" value is filled
};

#endif


#include <iostream>
#include <utility>

#include "PmergeMe.hpp"

unsigned int getJacobstahlNr(unsigned int n)
{
    return (n % 2 == 0) ? ((1<<n)-1)/3 : ((1<<n)+1)/3;
}

int main()
{
    for (int i=0; i<10; i++) {
        std::cout << getJacobstahlNr(i) << std::endl;
    }

    Pair p1, p2;
    p1.first = 3;
    p1.second = 4;
    p2.first = 5;
    p1.second = 7;
    std::cout << (p1 < p2) << std::endl;
}

#include <deque>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

#include "easyfind.hpp"

#define ANSI_RED   "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_CYAN  "\x1b[36m"
#define ANSI_RESET "\x1b[0m"

template <typename T>
void testCase(T &container, int valueToFind)
{
    typename T::iterator it = easyfind(container, valueToFind);
    if (it != container.end()) {
        std::cout << "Value found: " << ANSI_GREEN << *it << ANSI_RESET << ", "
                  << "rest of the container: ";
        while (++it != container.end()) {
            std::cout << *it << ", ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Value " ANSI_RED << valueToFind << ANSI_RESET
                  << " not found!" << std::endl;
    }

}

int main()
{
    std::vector<int> myIntVect {10, 20, 30, 20, 10, 50};
    std::list<int> myIntList {10, 20, 30, 20, 10, 50};
    std::deque<int> myIntDeque {10, 20, 30, 20, 10, 50};

    // test vector
    std::cout << ANSI_CYAN << "Testing vector..." << ANSI_RESET << std::endl;
    testCase(myIntVect, 10);
    testCase(myIntVect, 20);
    testCase(myIntVect, 30);
    testCase(myIntVect, 40);
    testCase(myIntVect, 50);

    // test list
    std::cout << ANSI_CYAN << "\nTesting list..." << ANSI_RESET << std::endl;
    testCase(myIntList, 10);
    testCase(myIntList, 20);
    testCase(myIntList, 30);
    testCase(myIntList, 40);
    testCase(myIntList, 50);

    // test deque
    std::cout << ANSI_CYAN << "\nTesting deque..." << ANSI_RESET << std::endl;
    testCase(myIntDeque, 10);
    testCase(myIntDeque, 20);
    testCase(myIntDeque, 30);
    testCase(myIntDeque, 40);
    testCase(myIntDeque, 50);
}

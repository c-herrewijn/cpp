#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include <stdexcept>
#include <set>
#include <vector>

#include "Span.hpp"

#define ANSI_RED   "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_CYAN  "\x1b[36m"
#define ANSI_RESET "\x1b[0m"

void testRangeError()
{
    std::cout << ANSI_RED << "\ntesting range error: " << ANSI_RESET << std::endl;
    Span sp = Span(3);
    try {
        sp.addNumber(3);
        sp.addNumber(1);
        sp.addNumber(4);
        sp.addNumber(9);
    }
    catch (std::range_error &e) {
        std::cout << e.what() << std::endl;
    }
}

void createRandomNumbers(Span &sp, std::vector<int> &randNumVector, size_t n) {
    try {
        unsigned int scaleFactor = 1 + (UINT_MAX / (static_cast<long long unsigned int>(100) + 100 * pow(n, 2)));
        for (size_t i=0; i<n; i++)
            randNumVector.emplace_back(rand() / scaleFactor );
        for (size_t i=0; i<n; i++)
        {
            sp.addNumber(randNumVector[i]);
        }
    }
    catch (std::range_error &e) {
        std::cout << e.what() << std::endl;
    }
}

void printExtraInfo(std::vector<int> &randNumVector, size_t n)
{
    std::cout << ANSI_GREEN << "created numbers: " << ANSI_RESET << std::flush;
    for (size_t i=0; i<n; i++)
    {
        std::cout << randNumVector[i] << ", ";
    }
    std::cout << std::endl;

    std::cout << ANSI_GREEN << "ordered:         " << ANSI_RESET << std::flush;
    std::multiset<int> orderedMultiSet;
    for (size_t i=0; i<n; i++)
    {
        orderedMultiSet.emplace(randNumVector[i]);
    }
    for (auto it = orderedMultiSet.begin(); it != orderedMultiSet.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

void testShortestSpan(Span &sp, size_t n){
    try {
        std::cout << "shortest span... : " << std::flush;
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (std::logic_error &e) {
        std::cout << e.what() << std::endl;
    }
}

void testLongestSpan(Span &sp, size_t n){
    try {
        std::cout << "longest span.... : " << std::flush;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::logic_error &e) {
        std::cout << e.what() << std::endl;
    }
}

void testSpanLen(size_t n)
{
    std::cout << ANSI_CYAN << "\nn = " << n << ANSI_RESET << std::endl;
    Span sp(n);
    std::vector<int> randNumVector;
    randNumVector.reserve(n);

    createRandomNumbers(sp, randNumVector, n);
    if (n < 100)
        printExtraInfo(randNumVector, n);
    testShortestSpan(sp, n);
    testLongestSpan(sp, n);
}

int main()
{
    // std::srand(time(0));
    std::srand(42);

    testSpanLen(0);
    testSpanLen(1);
    testSpanLen(5);
    testSpanLen(50);
    testSpanLen(500);
    testSpanLen(5000);
    testSpanLen(50000);
    testSpanLen(500000);

    testRangeError();
}

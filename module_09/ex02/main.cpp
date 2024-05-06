#include <chrono>
#include <iostream>

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    PmergeMe sorter;
    if (sorter.parseInput(argc, argv) == false) {
        return EXIT_FAILURE;
    }
    sorter.printInputList();

    // sorting with std::list
    const auto t0_l = std::chrono::steady_clock::now();
    sorter.sortList();
    const auto t1_l = std::chrono::steady_clock::now();
    sorter.printSortedList();
    std::cout << "Time to process " << argc - 1 << " elements with std::list : "
              << std::chrono::duration_cast<std::chrono::microseconds>(t1_l - t0_l).count()
              << " us" << std::endl;

    // sorting with std::vector
    const auto t0_v = std::chrono::steady_clock::now();
    sorter.sortVect();
    const auto t1_v = std::chrono::steady_clock::now();
    // sorter.printSortedVect();
    std::cout << "Time to process " << argc - 1 << " elements with std::vector : "
              << std::chrono::duration_cast<std::chrono::microseconds>(t1_v - t0_v).count()
              << " us" << std::endl;
}

#include <exception>
#include <iostream>
#include <string>

#include "Array.hpp"

#define ANSI_GREEN "\x1b[32m"
#define ANSI_RED   "\x1b[31m"
#define ANSI_RESET "\x1b[0m"

template <typename T>
void printArray(Array<T> &myArr)
{
    std::cout << "content: ";
    for (size_t i=0; i<myArr.size(); i++) {
        if (i != myArr.size() - 1) {
            std::cout << myArr[i] << ", ";
        }
        else {
            std::cout << myArr[i] << "\n";
        }
    }
}

void testConstructors()
{
    std::cout << ANSI_GREEN << "testing constructors:\n" << ANSI_RESET;

    // default construtor (size 0):
    std::cout << "default constructor\n";
    Array<int> emptyArr;
    std::cout << " - size empty array: " << emptyArr.size() << "\n";

    // unsigned int constructor
    std::cout << "unsigned int constructor\n";
    unsigned int size = 5;
    Array<int> myArr(size);
    std::cout << " - size initialized array: " << myArr.size() << "\n - ";
    printArray(myArr);

    // change some values, to test if they stay unchanged by copy constructor
    std::cout << "copy constructor\n";
    std::cout << " - set some values of original:\n   - ";
    myArr[0] = 17;
    myArr[1] = 18;
    printArray(myArr);

    std::cout << " - make a copy with copy constructor: \n   - ";
    Array<int>copyArr(myArr);
    printArray(copyArr);

    std::cout << " - adjust values of original array, the copy should stay unchanged\n";
    myArr[0] = 117;
    myArr[1] = 118;
    std::cout << "   - original array (adjusted): ";
    printArray(myArr);
    std::cout << "   - copy array (not adjusted): ";
    printArray(copyArr);
}

void testCopyAssignmentOperator()
{
    std::cout << ANSI_GREEN << "testing assignement operator:\n" << ANSI_RESET;

    // original array
    unsigned int size = 5;
    Array<int> myArr(size);
    myArr[0] = 31;
    myArr[1] = 32;
    std::cout << "Original array: ";
    printArray(myArr);

    std::cout << "Copy via assignement operator: ";
    Array<int>copyArr = myArr;
    printArray(copyArr);

    std::cout << "adjust some values of the copy, the origianl should stay unchanged\n";
    copyArr[0] += 100;
    copyArr[1] += 100;
    copyArr[2] += 100;
    std::cout << "contents of both arrays:\n";
    std::cout << " - original array (adjusted): ";
    printArray(myArr);
    std::cout << " - copy array (not adjusted): ";
    printArray(copyArr);
}

void testIndexValid()
{
    std::cout << ANSI_GREEN << "testing valid index access:\n" << ANSI_RESET;
    Array<int> myArr(5);

    myArr[0] = 42;
    std::cout << "initial value: " << myArr[0] << "\n";
    myArr[0] += 100;
    std::cout << "adjusted value: " << myArr[0] << "\n";
    myArr[4] = 4;
    std::cout << "initial value: " << myArr[4] << "\n";
    myArr[4] += 100;
    std::cout << "adjusted value: " << myArr[4] << "\n";
}

void testIndexInvalid()
{
    std::cout << ANSI_RED << "testing invalid index access:\n" << ANSI_RESET;
    Array<int> myArr(5);

    try {
        myArr[-1] = 42;
    }
    catch (const std::out_of_range &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try {
        myArr[5] = 42;
    }
    catch (const std::out_of_range &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try {
        myArr[12] = 42;
    }
    catch (const std::out_of_range &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    // empty array
    Array<int> emptyArr;
    try {
        emptyArr[0] = 42;
    }
    catch (const std::out_of_range &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

int main()
{
    testConstructors();
    testCopyAssignmentOperator();
    testIndexValid();
    testIndexInvalid();
}

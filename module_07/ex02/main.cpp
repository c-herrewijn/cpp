#include <exception>
#include <iostream>
#include <string>

#include "Array.hpp"

#define ANSI_RED   "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_CYAN "\x1b[36m"
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

template <typename T>
void testConstructors(T initalVal1, T initalVal2, T deltaTest)
{
    std::cout << ANSI_GREEN << "testing constructors:\n" << ANSI_RESET;

    // default construtor (size 0):
    std::cout << "default constructor (empty)\n";
    Array<T> emptyArr;
    std::cout << " - size empty array: " << emptyArr.size() << "\n";

    // fixed length constructor
    std::cout << "constructor fixed length\n";
    unsigned int size = 5;
    Array<T> myArr(size);
    std::cout << " - size initialized array: " << myArr.size() << "\n - ";
    printArray(myArr);

    // change some values, to test if they stay unchanged by copy constructor
    std::cout << "copy constructor\n";
    std::cout << " - set some values of original:\n   - ";
    myArr[0] = initalVal1;
    myArr[1] = initalVal2;
    printArray(myArr);

    std::cout << " - make a copy with copy constructor: \n   - ";
    Array<T>copyArr(myArr);
    printArray(copyArr);

    std::cout <<
              " - adjust values of the copied array, the original should stay unchanged\n";
    copyArr[0] += deltaTest;
    copyArr[1] += deltaTest;
    copyArr[2] += deltaTest;
    std::cout << "   - original array: ";
    printArray(myArr);
    std::cout << "   - copy array (adjusted): ";
    printArray(copyArr);
}

template <typename T>
void testConstructorsConst()
{
    std::cout << ANSI_GREEN << "testing constructors:\n" << ANSI_RESET;

    // default construtor (size 0):
    std::cout << "default constructor (empty)\n";
    Array<T> emptyArr;
    std::cout << " - size empty array: " << emptyArr.size() << "\n";

    // fixed length constructor
    std::cout << "constructor fixed length\n";
    unsigned int size = 5;
    Array<T> myArr(size);
    std::cout << " - size initialized array: " << myArr.size() << "\n - ";
    printArray(myArr);
}

template <typename T>
void testCopyAssignmentOperator(T initalVal1, T initalVal2, T deltaTest)
{
    std::cout << ANSI_GREEN << "testing assignement operator:\n" << ANSI_RESET;

    // original array
    unsigned int size = 5;
    Array<T> myArr(size);
    myArr[0] = initalVal1;
    myArr[1] = initalVal2;
    std::cout << "Original array: ";
    printArray(myArr);

    std::cout << "Copy via assignement operator: ";
    Array<T>copyArr = myArr;
    printArray(copyArr);

    std::cout <<
              "adjust some values of the copy, the origianl should stay unchanged\n";
    copyArr[0] += deltaTest;
    copyArr[1] += deltaTest;
    copyArr[2] += deltaTest;
    std::cout << "contents of both arrays:\n";
    std::cout << " - original array (adjusted): ";
    printArray(myArr);
    std::cout << " - copy array (not adjusted): ";
    printArray(copyArr);
}

template <typename T>
void testIndexValid(T initalVal1, T initalVal2, T deltaTest)
{
    std::cout << ANSI_GREEN << "testing valid index access:\n" << ANSI_RESET;
    Array<T> myArr(5);

    myArr[0] = initalVal1;
    std::cout << "initial value: " << myArr[0] << "\n";
    myArr[0] += deltaTest;
    std::cout << "adjusted value: " << myArr[0] << "\n";
    myArr[4] = initalVal2;
    std::cout << "initial value: " << myArr[4] << "\n";
    myArr[4] += deltaTest;
    std::cout << "adjusted value: " << myArr[4] << "\n";
}

template <typename T>
void testIndexInvalid(T testVal)
{
    std::cout << ANSI_RED << "testing invalid index access:\n" << ANSI_RESET;
    Array<T> myArr(5);

    try {
        myArr[-1] = testVal;
    }
    catch (const std::out_of_range &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try {
        myArr[5] = testVal;
    }
    catch (const std::out_of_range &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try {
        myArr[12] = testVal;
    }
    catch (const std::out_of_range &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    // empty array
    Array<T> emptyArr;
    try {
        emptyArr[0] = testVal;
    }
    catch (const std::out_of_range &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

int main()
{
    // test integers
    std::cout << ANSI_CYAN << "Tesing integers" << ANSI_RESET << std::endl;
    testConstructors(17, 18, 100);
    testCopyAssignmentOperator(22, 23, 100);
    testIndexValid(42, 43, 100);
    testIndexInvalid(42);

    // test strings
    std::cout << ANSI_CYAN << "Tesing strings" << ANSI_RESET << std::endl;
    std::string s1 = "cat";
    std::string s2 = "dog";
    std::string s3 = "-adjusted";
    testConstructors(s1, s2, s3);
    testCopyAssignmentOperator(s1, s2, s3);
    testIndexValid(s1, s2, s3);
    testIndexInvalid(s1);
}

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

#define  ANSI_GREEN  "\x1b[32m"
#define  ANSI_RESET  "\x1b[0m"

int main()
{
    Data myData;
    myData.str = "hello there!";
    myData.chars[0] = 'a';
    myData.chars[1] = 'b';
    myData.chars[2] = 'c';
    myData.b = true;

    // uintptr_t is an integer that holds an 'unspecified' pointer, comparable to to void*
    uintptr_t serializedData = Serializer::serialize(&myData);
    Data *myDataPtr = Serializer::deserialize(serializedData);

    std::cout << ANSI_GREEN << "compare values:" << ANSI_RESET << std::endl;
    std::cout << myDataPtr->str << std::endl
              << myDataPtr->chars[0] << myDataPtr->chars[1] << myDataPtr->chars[2] << std::endl
              << myDataPtr->b << std::endl;

    //compare pointers
    std::cout << ANSI_GREEN << "compare pointers:" << ANSI_RESET << std::endl;
    std::cout << "&myData            " << &myData << std::endl;
    std::cout << "myDataPtr          " << myDataPtr << std::endl;
    std::cout << "serializedData     " << serializedData << std::endl;
    std::cout << "&myData in decimal " << reinterpret_cast<unsigned long>(&myData) << std::endl;
}

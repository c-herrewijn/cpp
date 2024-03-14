#include "Serializer.hpp"
#include <iostream>
#include <string>
#include <sstream>

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
    Data myData2 = *(Serializer::deserialize(serializedData));

    std::cout << ANSI_GREEN << "compare values:" << ANSI_RESET << std::endl;
    std::cout << myData2.str << std::endl
              << myData2.chars[0] << myData2.chars[1] << myData2.chars[2] << std::endl
              << myData2.b << std::endl;

    //compare pointers
    std::cout << ANSI_GREEN << "compare pointers:" << ANSI_RESET << std::endl;
    std::cout << "uintptr_t        " << serializedData << std::endl;
    std::cout << "Data*            " << &myData << std::endl;
    std::stringstream ss;
    ss << &myData;
    std::cout << "Data* in decimal " << std::stol(ss.str(), 0, 16) << std::endl;
}

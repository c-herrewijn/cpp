#include "ScalarConverter.hpp"

#include <iostream>
#include <string>

#define  ANSI_BLUE  "\x1b[34m"
#define  ANSI_GREEN  "\x1b[32m"
#define  ANSI_RESET  "\x1b[0m"

static void test(std::string str)
{
    std::cout << ANSI_GREEN << "\ninput: " << str << ANSI_RESET << std::endl;
    ScalarConverter::convert(str);
}

int main()
{
    // chars (single quotes optional, except for digits)
    std::cout << ANSI_BLUE << "\nCHARS" << ANSI_RESET << std::endl;
    test("a");
    test("'a'");
    test("'3'");
    test("*");
    test("\t");

    // integers
    std::cout << ANSI_BLUE << "\nINTEGERS" << ANSI_RESET << std::endl;
    test("0");
    test("-65");
    test("65");
    test("2147483647"); // int max
    test("-2147483648"); // int min
    test("2147483648"); // int max + 1
    test("-2147483649"); // int min - 1
    test("99999999999999999999999"); // way to big
}

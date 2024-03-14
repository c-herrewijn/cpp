#include "ScalarConverter.hpp"
#include <iostream>

#define  ANSI_CYAN  "\x1b[36m"
#define  ANSI_GREEN  "\x1b[32m"
#define  ANSI_RESET  "\x1b[0m"

// static void testCases();

int main(int argc, char *argv[])
{
    if (argc == 2) {
        ScalarConverter::convert(argv[1]);
    }
    else {
        std::cout << "invalid input" << std::endl;
        // testCases();
    }
}

// static void test(std::string str)
// {
//     std::cout << ANSI_GREEN << "\ninput: " << str << ANSI_RESET << std::endl;
//     ScalarConverter::convert(str);
// }

// static void testCases(void)
// {
//     // chars (single quotes optional, except for digits)
//     std::cout << ANSI_CYAN << "\nCHARS" << ANSI_RESET << std::endl;
//     test("a");
//     test("'a'");
//     test("'3'");
//     test("*");
//     test("'\t'");

//     // integers
//     std::cout << ANSI_CYAN << "\nINTEGERS" << ANSI_RESET << std::endl;
//     test("0");
//     test("7");
//     test("-65");
//     test("65");
//     test("200");
//     test("16777217"); // smallest int not uniquely representable as float
//     test("2147483647"); // int max
//     test("-2147483648"); // int min

//     // floats
//     std::cout << ANSI_CYAN << "\nFLOATS" << ANSI_RESET << std::endl;
//     test("nanf");
//     test("inff");
//     test("-inff");
//     test(".1f");
//     test(".0f");
//     test("65.0f");
//     test("-65.0f");
//     test("65.1234f");
//     test("65.12345f");
//     test("1.1234567890123456f");

//     // double
//     std::cout << ANSI_CYAN << "\nDOUBLES" << ANSI_RESET << std::endl;
//     test("nan");
//     test("inf");
//     test("-inf");
//     test("0.1");
//     test("65.");
//     test("21474.83649");
//     test("16777217.0");
//     test("2147483647."); // int max
//     test("2147483648."); // int max + 1
//     test("-2147483649."); // int min - 1
//     test("1.12345678901234");
//     test("1.1234567890123456");

//     // invalid input
//     std::cout << ANSI_CYAN << "\nINVALID INPUT" << ANSI_RESET << std::endl;
//     test("'12'"); // invalid because of quotes
//     test("1.2."); // multiple dots
//     test("2147483648"); // int max + 1
//     test("-2147483649"); // int min - 1
//     test("99999999999999999999999"); // way to big
//     test("9999999999999999999"); // way to big
//     test("-12f"); // no dot
//     test("1.123456789012345678"); // more than 18 decimals
// }

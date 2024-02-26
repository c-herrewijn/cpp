#include "ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <limits>

#define  ANSI_GREEN  "\x1b[32m"
#define  ANSI_RESET  "\x1b[0m"

static void test(std::string str)
{
    std::cout << ANSI_GREEN << "\ninput: " << str << ANSI_RESET << std::endl;
    ScalarConverter::convert(str);
}

int main()
{
    // tests from assignment
    test("0");
    test("nan");
    test("42.0f");

    // integers
    // test("0");
    // test("42");

    // limits
    // test(std::to_string(std::numeric_limits<int>::max()));
    // test(std::to_string((long)std::numeric_limits<int>::max() + 1));
    // test(std::to_string(std::numeric_limits<int>::min()));
    // test(std::to_string((long)std::numeric_limits<int>::min() - 1));

    // doubles
    // test("0.0");
    // test("42.0");
    // test("42.0123");
    // test("3.01e9"); // smaller than INT_MAX
    // test("2.148e9"); // larger than INT_MAX
    // test("3.402e39"); // larger than FLOAT_MAX
    // test("3.402e400"); // larger than DOUBLE_MAX

    // test("42.2e6"); // non standard exp
    // test("-4.22e7"); // negatives
    // test("4.22-e7"); //
    // test("-4.22-e7"); //
    // test("-42.42-e7"); //

    // test("inf");
    // test("-inf");
    // test("nan");

    // floats
    // test("0f");
    // test("42.42f");
    // test("3.01e9f"); // smaller than INT_MAX
    // test("2.148e9f"); // larger than INT_MAX
    // test("3.402e39f"); // larger than FLOAT_MAX
    // test("3.402e39"); // larger than FLOAT_MAX
    // test("3.402e400"); // larger than FLOAT_MAX
    // test("3.402e400f"); // larger than DOUBLE_MAX

    // test("dummy");
    // test("0");
    // test("7");
    // test("nan");
    // test("42.0f");

    // std::cout << "bool: " << (1e6 == 1000000) << std::endl;

    // int
    // test("1");
    // test("10");
    // test("100");
    // test("1000");
    // test("10000");
    // test("100000");
    // test("1000000");
    // test("10000000");
    // test("100000000");
    // test("1000000000");
    // test("10000000000");

    // chars
    // test("'a'");
    // test("'0'");
    // test("'*'");
}

#include <iostream>
#include <sstream>
#include <string>
// #include <ctype>

#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "invalid number of arguments" << std::endl;
        return EXIT_FAILURE;
    }

    RPN rpn;
    (void)argv;
}

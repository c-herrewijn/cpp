#include <iostream>

#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "invalid number of arguments" << std::endl;
        return EXIT_FAILURE;
    }
    RPN rpn;
    if (rpn.runInput(argv[1]) == true) {
        std::cout << rpn.getResult() << std::endl;
        return EXIT_SUCCESS;
    }
    else {
        std::cerr << "Error" << std::endl;
        return EXIT_FAILURE;
    }
}

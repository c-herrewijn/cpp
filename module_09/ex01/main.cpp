#include <iostream>

#include "RPN.hpp"

int main(int argc, char *argv[])
{
    RPN rpn;
    std::string errString = "";

    if (argc != 2) {
        std::cout << "Error: invalid number of arguments" << std::endl;
        return EXIT_FAILURE;
    }
    if (rpn.runInput(argv[1], errString) == true) {
        std::cout << rpn.getResult() << std::endl;
        return EXIT_SUCCESS;
    }
    else {
        std::cerr << "Error: " << errString << std::endl;
        return EXIT_FAILURE;
    }
}

#include <iostream>
#include <sstream>
#include <string>

#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "invalid number of arguments" << std::endl;
        return EXIT_FAILURE;
    }

    RPN rpn;
    bool error = false;
    std::istringstream ss(argv[1]);
    for (std::string tokenString; ss >> tokenString;) {
        if (tokenString.size() != 1) {
            error = true;
            break;
        }
        char c = tokenString[0];
        if (std::isdigit(c)) {
            rpn.addNumberToStack(c - '0');
        }
        else if (c == '+' || c == '-' || c == '/' || c == '*') {
            if (rpn.executeOperator(c) == false) {
                error = true;
                break;
            }
        }
        else {
            error = true;
            break;
        }
    }

    if (error == false && rpn.verifyResult()) {
        std::cout << rpn.getResult() << std::endl;
        return EXIT_SUCCESS;
    }
    else {
        std::cerr << "Error" << std::endl;
        return EXIT_FAILURE;
    }
}

#include "Bureaucrat.h"
#include <iostream>

int main()
{
    // correct cases
    try {
        std::cout << Bureaucrat("Benny", 1);
    }
    catch (std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }

    try {
        std::cout << Bureaucrat("Cenny", 10);
    }
    catch (std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }

    try {
        std::cout << Bureaucrat("Denny", 150);
    }
    catch (std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }

    // error cases
    try {
        std::cout << Bureaucrat("Benny", -10);
    }
    catch (std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }

    try {
        std::cout << Bureaucrat("Benny", 0);
    }
    catch (std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }

    try {
        std::cout << Bureaucrat("Benny", 151);
    }
    catch (std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }
}

#include "Bureaucrat.h"
#include <iostream>

int main()
{
    Bureaucrat b1("Benny", 10);
    std::cout << b1;

    Bureaucrat b2("Benny", -10);
    std::cout << b2;

    Bureaucrat b3("Benny", 0);
    std::cout << b3;

    Bureaucrat b4("Benny", 1);
    std::cout << b4;

    Bureaucrat b5("Benny", 150);
    std::cout << b5;

    Bureaucrat b6("Benny", 151);
    std::cout << b6;
}

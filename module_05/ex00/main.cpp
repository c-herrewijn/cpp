#include "Bureaucrat.h"
#include <iostream>

int main()
{
    // Test Constructor Happy flow
    std::cout << "testing constructors happy flow..." << std::endl;
    try {
        std::cout << "  " << Bureaucrat("King", 1) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }

    try {
        std::cout << "  " << Bureaucrat("MidManager", 10) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }

    try {
        std::cout << "  " << Bureaucrat("HumbleServant", 150) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }

    // Test Constructor Error Cases
    std::cout << "testing constructors error cases..." << std::endl;
    try {
        std::cout << "  " << Bureaucrat("Benny", -10) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }

    try {
        std::cout << "  " << Bureaucrat("Benny", 0);
    }
    catch (std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }

    try {
        std::cout << "  " << Bureaucrat("Benny", 151);
    }
    catch (std::exception &e) {
        std::cout << "error: " << e.what() << std::endl;
    }

    // Test Increment grade Happy flow
    std::cout << "testing increment happy case ..." << std::endl;
    Bureaucrat WimAlex = Bureaucrat("Willem Alexander", 2);
    std::cout << "  " << WimAlex << std::endl;
    WimAlex.incrementGrade();
    std::cout << "  " << WimAlex << std::endl;

    Bureaucrat RisingStar = Bureaucrat("Rising Star", 10);
    std::cout << "  " << RisingStar << std::endl;
    RisingStar.incrementGrade();
    RisingStar.incrementGrade();
    RisingStar.incrementGrade();
    std::cout << "  " << RisingStar << std::endl;

    // Test Increment grade error case flow
    std::cout << "testing increment error case ..." << std::endl;
    std::cout << "  " << WimAlex << std::endl;
    try {
        WimAlex.incrementGrade();
    }
    catch (std::exception &e) {
        std::cout << "  error: " << e.what() << std::endl;
    }
    std::cout << "  " << WimAlex << std::endl;

    // Test Decrement grade Happy flow
    std::cout << "testing decrement happy case ..." << std::endl;
    Bureaucrat desperado = Bureaucrat("Desperado", 149);
    std::cout << "  " << desperado << std::endl;
    try {
        desperado.decrementGrade();
    }
    catch (std::exception &e) {
        std::cout << "  error: " << e.what() << std::endl;
    }
    std::cout << "  " << desperado << std::endl;

    // Test Decrement grade error case
    std::cout << "testing decrement error case ..." << std::endl;
    std::cout << "  " << desperado << std::endl;
    try {
        desperado.decrementGrade();
    }
    catch (std::exception &e) {
        std::cout << "  error: " << e.what() << std::endl;
    }
    std::cout << "  " << desperado << std::endl;
}

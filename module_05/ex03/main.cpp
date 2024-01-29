#include "Intern.h"
#include "Bureaucrat.h"
#include "AForm.h"
#include <iostream>
#include <exception>

#define ANSI_GREEN "\x1b[32m"
#define ANSI_RED   "\x1b[31m"
#define ANSI_RESET "\x1b[0m"

void startTests(Bureaucrat &b)
{
    Intern someRandomIntern;

    std::cout << ANSI_GREEN << "Testing robotomy request..."
              << ANSI_RESET << std::endl;
    AForm *rrf = someRandomIntern.makeForm("robotomy request", "Rick");
    b.signForm(*rrf);
    b.executeForm(*rrf);
    delete rrf;

    std::cout << ANSI_GREEN << "Testing shrubbery creation..."
              << ANSI_RESET << std::endl;
    AForm *scf = someRandomIntern.makeForm("shrubbery creation", "Sonia");
    b.signForm(*scf);
    b.executeForm(*scf);
    delete scf;

    std::cout << ANSI_GREEN << "Testing presidential creation..."
              << ANSI_RESET << std::endl;
    AForm *ppf = someRandomIntern.makeForm("presidential pardon", "Peter");
    b.signForm(*ppf);
    b.executeForm(*ppf);
    delete ppf;

    std::cout << ANSI_RED << "Testing wrong form..."
              << ANSI_RESET << std::endl;
    AForm *wf = someRandomIntern.makeForm("wrong form", "Ghost");
    b.signForm(*wf);
    b.executeForm(*wf);
    delete wf;
}

int main()
{
    int exitStatus = EXIT_SUCCESS;
    try {
        Bureaucrat b("PowerUser", 1);
        startTests(b);
    }
    catch (std::exception &e) {
        std::cout << "An error occured: " << e.what() << std::endl;
        exitStatus = EXIT_FAILURE;
    }
    exit(exitStatus);
}

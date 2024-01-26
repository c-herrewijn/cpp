#include "Intern.h"
#include "Bureaucrat.h"
#include "AForm.h"
#include <iostream>
#include <exception>

void startTests(Bureaucrat &b)
{
    Intern someRandomIntern;
    AForm *rrf = someRandomIntern.makeForm("robotomy request", "Rick");
    AForm *scf = someRandomIntern.makeForm("shrubbery creation", "Sonia");
    AForm *ppf = someRandomIntern.makeForm("presidential pardon", "Peter");

    b.signForm(*rrf);
    b.executeForm(*rrf);
    delete rrf;

    b.signForm(*scf);
    b.executeForm(*scf);
    delete scf;

    b.signForm(*ppf);
    b.executeForm(*ppf);
    delete ppf;
}

int main()
{
    try {
        Bureaucrat b("PowerUser", 1);
        startTests(b);
    }
    catch (std::exception &e) {
        std::cout << "An error occured: " << e.what() << std::endl;
        exit(1);
    }
}

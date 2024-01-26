#include "Intern.h"
#include "Bureaucrat.h"
#include "AForm.h"
#include <iostream>
#include <exception>

void startTests(Bureaucrat &b)
{
    Intern someRandomIntern;
    AForm *rrf = someRandomIntern.makeForm("robotomy request", "Rick");
    b.signForm(*rrf);
    b.executeForm(*rrf);
    delete rrf;

    AForm *scf = someRandomIntern.makeForm("shrubbery creation", "Sonia");
    b.signForm(*scf);
    b.executeForm(*scf);
    delete scf;

    AForm *ppf = someRandomIntern.makeForm("presidential pardon", "Peter");
    b.signForm(*ppf);
    b.executeForm(*ppf);
    delete ppf;

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

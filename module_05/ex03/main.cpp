#include "Intern.h"
#include "AForm.h"
#include <iostream>
#include <exception>

int main()
{
    Intern someRandomIntern;
    AForm *rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    delete rrf;

    // todo: add tests
}

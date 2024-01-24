#include "Intern.h"
#include "AForm.h"
#include <iostream>
#include <exception>

int main()
{
    Intern someRandomIntern;
    AForm *rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    // todo: add tests
}

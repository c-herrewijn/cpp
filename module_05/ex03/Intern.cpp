#include "Intern.h"
#include <iostream>
#include <AForm.h>
#include <PresidentialPardonForm.h>
#include <RobotomyRequestForm.h>
#include <ShrubberyCreationForm.h>

Intern::Intern() {}
Intern::~Intern() {}

Intern::Intern(const Intern &obj)
{
    *this = obj;
};

Intern &Intern::operator=(const Intern &obj)
{
    (void)obj;
    return *this;
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
    (void)formName;
    (void)formTarget;
    return NULL; // todo
}

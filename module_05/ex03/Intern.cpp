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

AForm *Intern::newPresidentialPardonForm(std::string formTarget)
{
    return new PresidentialPardonForm(formTarget);
}

AForm *Intern::newRobotomyRequestForm(std::string formTarget)
{
    return new RobotomyRequestForm(formTarget);
}

AForm *Intern::newShrubberyCreationForm(std::string formTarget)
{
    return new ShrubberyCreationForm(formTarget);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
    const int nrForms = 3;
    std::string formNames[nrForms] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };

    typedef  AForm *(*newForm)(std::string formTarget);
    newForm creators[nrForms] = {
        Intern::newPresidentialPardonForm,
        Intern::newRobotomyRequestForm,
        Intern::newShrubberyCreationForm
    };

    int i = 0;
    AForm *newform = nullptr;
    while (i < nrForms) {
        if (formName == formNames[i]) {
            newform = creators[i](formTarget);
            break;
        }
        i++;
    }
    return newform;
};

#include "Intern.h"
#include "AForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include <iostream>

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

    typedef  AForm *(*newFormFuncPtr)(std::string formTarget);
    newFormFuncPtr creators[nrForms] = {
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
    if (newform == nullptr) {
        std::string errorstr = "Form not created. Form: '" + formName +
                               "' is not a valid form!";
        throw Intern::InvalidFormnameException(errorstr);
    }
    return newform;
};

// constructor of exception class with initialization list
Intern::InvalidFormnameException::InvalidFormnameException(const std::string &message)
    : std::logic_error(message)
{}

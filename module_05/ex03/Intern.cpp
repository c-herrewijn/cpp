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

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
    // supported form names
    const int nrForms = 3;
    std::string formNames[nrForms] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };

    // matching creator functions per formame (pointers to lambda functions)
    typedef AForm *(*creatorFuncPtr)(std::string formTarget);
    creatorFuncPtr creators[nrForms] = {
        +[](std::string formTarget) {return (AForm *) new PresidentialPardonForm(formTarget);},
        +[](std::string formTarget) {return (AForm *) new RobotomyRequestForm(formTarget);},
        +[](std::string formTarget) {return (AForm *) new PresidentialPardonForm(formTarget);}
    };

    // select and execute correct creator function
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

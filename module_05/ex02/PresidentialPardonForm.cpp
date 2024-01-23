#include "PresidentialPardonForm.h"
#include <iostream>
#include <string>

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
    AForm("Presidential Pardon Form", 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm
    &obj) : AForm(obj)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=
(const PresidentialPardonForm &obj)
{
    (void)obj;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    (void)executor;
    std::cout << "Let it be known! " << this->getTarget()
              << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


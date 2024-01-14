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

void PresidentialPardonForm::Execute(Bureaucrat &b) const
{
    std::cout << b.getName() << " executed " << this->getName()
              << " for " << this->getTarget() << std::endl;
    std::cout << "Let it be known! " << this->getTarget()
              << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &obj)
{
    out << "Form name: " << obj.getName() << std::endl
        << " - target: " << obj.getTarget() << std::endl
        << " - isSigned:" << obj.getIsSigned() << std::endl
        << " - required Grade to Execute: " << obj.getReqGradeToExecute() << std::endl
        << " - required Grade to sign: " << obj.getReqGradeToSign();
    return (out);
}

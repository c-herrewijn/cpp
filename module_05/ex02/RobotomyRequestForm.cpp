#include "RobotomyRequestForm.h"
#include <iostream>
#include <string>

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
    AForm("Robotomy Request Form", 72, 45, target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm
    &obj) : AForm(obj)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=
(const RobotomyRequestForm &obj)
{
    (void)obj;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    std::cout << executor.getName() << " executed " << this->getName()
              << " for " << this->getTarget() << std::endl;
    std::cout << "TODO: RobotomyRequestForm!!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &obj)
{
    out << "Form name: " << obj.getName() << std::endl
        << " - target: " << obj.getTarget() << std::endl
        << " - isSigned:" << obj.getIsSigned() << std::endl
        << " - required Grade to Execute: " << obj.getReqGradeToExecute() << std::endl
        << " - required Grade to sign: " << obj.getReqGradeToSign();
    return (out);
}

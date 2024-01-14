#include "ShrubberyCreationForm.h"
#include <iostream>
#include <string>

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
    AForm("Shrubbery Creation Form", 145, 137, target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm
    &obj) : AForm(obj)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=
(const ShrubberyCreationForm &obj)
{
    (void)obj;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    (void)executor;
    std::cout << "TODO: ShrubberyCreationForm!!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &obj)
{
    out << "Form name: " << obj.getName() << std::endl
        << " - target: " << obj.getTarget() << std::endl
        << " - isSigned:" << obj.getIsSigned() << std::endl
        << " - required Grade to Execute: " << obj.getReqGradeToExecute() << std::endl
        << " - required Grade to sign: " << obj.getReqGradeToSign();
    return (out);
}

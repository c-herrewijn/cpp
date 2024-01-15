#include "ShrubberyCreationForm.h"

#include <iostream>
#include <string>
#include <fstream>

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
    std::string fileName =  this->getTarget() + "_shrubbery";
    std::ofstream ofs;
    ofs.open(fileName.c_str());
    ofs << this->drawShrubbery() << std::endl;
    ofs.close();
}

std::string ShrubberyCreationForm::drawShrubbery() const
{
    std::string trees =
        "          &&& &&  & && \n"
        "      && &\\/&\\|& ()|/ @, && \n"
        "      &\\/(/&/&||/& /_/)_&/_& \n"
        "   &() &\\/&|()|/&\\/ '%\" & () \n"
        "  &_\\_&&_\\ |& |&&/&__%_/_& && \n"
        "&&   && & &| &| /& & % ()& /&& \n"
        " ()&_---()&\\&\\|&&-&&--%---()~ \n"
        "     &&     \\||| \n"
        "             ||| \n"
        "             ||| \n"
        "             ||| \n"
        "       , -=-~  .-^- _ \n"
        "\n"
        "\n"
        "\n"
        "              v .   ._, |_  ., \n"
        "           `-._\\/  .  \\ /    |/_ \n"
        "               \\\\  _\\, y | \\// \n"
        "         _\\_.___\\\\, \\\\/ -.\\|| \n"
        "           `7-,--.`._||  / / , \n"
        "           /'     `-. `./ / |/_.' \n"
        "                     |    |// \n"
        "                     |_    / \n"
        "                     |-   | \n"
        "                     |   =| \n"
        "                     |    | \n"
        "--------------------/ ,  . \\--------._ \n"
        "\n"
        "\n"
        "\n"
        "           \\/ |    |/\n"
        "        \\/ / \\||/  /_/___/_\n"
        "         \\/   |/ \\/\n"
        "    _\\__\\_\\   |  /_____/_\n"
        "           \\  | /          /\n"
        "  __ _-----`  |{,-----------~\n"
        "            \\ }{\n"
        "             }{{\n"
        "             }}{\n"
        "             {{}\n"
        "       , -=-~{ .-^- _\n";
    return trees;
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

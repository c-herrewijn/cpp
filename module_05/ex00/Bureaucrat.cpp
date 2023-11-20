// Bureaucrat.cpp
#include "Bureaucrat.h"
#include <iostream>
#include <string>
#include <stdexcept>

Bureaucrat::Bureaucrat() {}
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    if (grade >= 1 && grade <= 150) {
        this->grade = grade;
    }
    else {
        if (grade < 1) {
            throw std::invalid_argument("grade too low!");
        }
        else {
            throw std::invalid_argument("grade too high!");
        }
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    (void)obj;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return (out);
}

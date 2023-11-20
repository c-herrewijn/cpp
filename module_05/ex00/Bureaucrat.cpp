// Bureaucrat.cpp
#include "Bureaucrat.h"
#include <iostream>
#include <string>

Bureaucrat::Bureaucrat() {}
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    if (grade >= 0 && grade <= 150) {
        this->grade = grade;
    }
    else {
        // todo throw exception!
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
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

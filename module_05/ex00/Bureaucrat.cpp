// Bureaucrat.cpp
#include "Bureaucrat.h"
#include <iostream>
#include <string>
#include <stdexcept>

Bureaucrat::Bureaucrat() {}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade >= 1 && grade <= 150) {
        this->_grade = grade;
    }
    else {
        if (grade < 1) {
            throw GradeTooHighException();
        }
        else {
            throw GradeTooLowException();
        }
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) :
    _grade(obj._grade), _name(obj._name) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    (void)obj;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return (out);
}

// Note: incrementing the grade decremets(!) the value by 1, as per the assignment
void Bureaucrat::incrementGrade(void)
{
    int newGrade = this->_grade - 1;
    if (newGrade < 1) {
        throw GradeTooHighException();
    }
    else {
        this->_grade = newGrade;
    }
}

// Note: decrementing the grade increments(!) the value by 1, as per the assignment
void Bureaucrat::decrementGrade(void)
{
    int newGrade = this->_grade + 1;
    if (newGrade > 150) {
        throw GradeTooLowException();
    }
    else {
        this->_grade = newGrade;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade Too High!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade Too Low!";
}

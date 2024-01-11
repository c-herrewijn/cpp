#include "Form.h"
#include "Bureaucrat.h"
#include <iostream>

Form::Form(const std::string name, int reqGradeToSign, int reqGradeToExecute) :
    _name(name),
    _isSigned(false),
    _reqGradeToSign(reqGradeToSign),
    _reqGradeToExecute(reqGradeToExecute)
{
    if (reqGradeToSign < 1 || reqGradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (reqGradeToSign > 150 || reqGradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

Form::Form() : _reqGradeToSign(1), _reqGradeToExecute(1) {}

Form::Form(const Form &obj) :
    _name(obj._name),
    _isSigned(obj._isSigned),
    _reqGradeToSign(obj._reqGradeToSign),
    _reqGradeToExecute(obj._reqGradeToExecute)
{}

Form::~Form() {}

const std::string Form::getName() const
{
    return this->_name;
}

bool Form::getIsSigned() const
{
    return this->_isSigned;
}

int Form::getReqGradeToSign() const
{
    return this->_reqGradeToSign;
}

int Form::getReqGradeToExecute() const
{
    return this->_reqGradeToExecute;
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= this->getReqGradeToSign()) {
        this->_isSigned = true;
    }
    else {
        throw Form::GradeTooLowException();
    }
}

// disable (i.e. make private) the assignement operator, because it has const attributes
Form &Form::operator=(const Form &obj)
{
    (void)obj;
    return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade Too High!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade Too Low!";
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    out << "Form name: " << obj.getName()
        << "; isSigned:" << obj.getIsSigned()
        << "; required Grade to Sign: " << obj.getReqGradeToSign()
        << "; required Grade to Execute: " << obj.getReqGradeToExecute();
    return (out);
}

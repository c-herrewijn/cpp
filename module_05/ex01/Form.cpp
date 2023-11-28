#include "Form.h"
#include "Bureaucrat.h"
#include <iostream>

Form::Form(const std::string name, int reqGradeToExecute, int reqGradeToSign) :
    _name(name),
    _isSigned(false),
    _reqGradeToExecute(reqGradeToExecute),
    _reqGradeToSign(reqGradeToSign)
{
    if (reqGradeToExecute < 1 || reqGradeToSign < 1) {
        throw GradeTooHighException();
    }
    if (reqGradeToExecute > 150 || reqGradeToSign > 150) {
        throw GradeTooLowException();
    }
}

Form::Form() : _reqGradeToExecute(1), _reqGradeToSign(1) {}

Form::Form(const Form &obj) :
    _name(obj._name),
    _isSigned(obj._isSigned),
    _reqGradeToExecute(obj._reqGradeToExecute),
    _reqGradeToSign(obj._reqGradeToSign)
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

int Form::getReqGradeToExecute() const
{
    return this->_reqGradeToExecute;
}

int Form::getReqGradeToSign() const
{
    return this->_reqGradeToSign;
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
        << "; required Grade to Execute: " << obj.getReqGradeToExecute()
        << "; required Grade to sign: " << obj.getReqGradeToSign();
    return (out);
}

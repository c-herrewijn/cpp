#include "Form.h"
#include "Bureaucrat.h"
#include <iostream>

Form::Form(const std::string name, int reqGradeToExecute, int reqGradeToSign) :
    name(name)
{
    if (reqGradeToExecute < 1 || reqGradeToSign < 1) {
        throw GradeTooHighException();
    }
    if (reqGradeToExecute > 150 || reqGradeToSign > 150) {
        throw GradeTooLowException();
    }
    this->isSigned = false;
    this->reqGradeToExecute = reqGradeToExecute;
    this->reqGradeToSign = reqGradeToSign;
}

Form::Form() {}

Form::Form(const Form &obj) :
    name(obj.name),
    isSigned(obj.isSigned),
    reqGradeToExecute(obj.reqGradeToExecute),
    reqGradeToSign(obj.reqGradeToSign)
{}

Form::~Form() {}

const std::string Form::getName() const
{
    return this->name;
}

bool Form::getIsSigned() const
{
    return this->isSigned;
}

int Form::getReqGradeToExecute() const
{
    return this->reqGradeToExecute;
}

int Form::getReqGradeToSign() const
{
    return this->reqGradeToSign;
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= this->getReqGradeToSign()) {
        this->isSigned = true;
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

#include "AForm.h"
#include "Bureaucrat.h"
#include <iostream>

AForm::AForm(const std::string name, int reqGradeToSign, int reqGradeToExecute,
             std::string target) :
    _name(name),
    _isSigned(false),
    _reqGradeToSign(reqGradeToSign),
    _reqGradeToExecute(reqGradeToExecute),
    _target(target)
{
    if (reqGradeToSign < 1 || reqGradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (reqGradeToSign > 150 || reqGradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm() : _reqGradeToSign(1), _reqGradeToExecute(1) {}

AForm::AForm(const AForm &obj) :
    _name(obj._name),
    _isSigned(obj._isSigned),
    _reqGradeToSign(obj._reqGradeToSign),
    _reqGradeToExecute(obj._reqGradeToExecute),
    _target(obj._target)
{}

AForm::~AForm() {}

const std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getIsSigned() const
{
    return this->_isSigned;
}

int AForm::getReqGradeToSign() const
{
    return this->_reqGradeToSign;
}

int AForm::getReqGradeToExecute() const
{
    return this->_reqGradeToExecute;
}

std::string AForm::getTarget() const
{
    return this->_target;
}

void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= this->getReqGradeToSign()) {
        std::cout << b.getName() << " signed: " << this->getName()
                  << " for " << this->getTarget() << std::endl;
        this->_isSigned = true;
    }
    else {
        throw AForm::GradeTooLowException();
    }
}

void AForm::validateExecution(Bureaucrat &b) const
{
    if (this->getIsSigned() == false) {
        throw AForm::UnsignedExecutionException();
    }
    if (b.getGrade() > this->getReqGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }
}

// disable (i.e. make private) the assignement operator, because it has const attributes
AForm &AForm::operator=(const AForm &obj)
{
    (void)obj;
    return *this;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade Too High!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade Too Low!";
}

const char *AForm::UnsignedExecutionException::what() const throw()
{
    return "Unsigned form can not be executed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
    out << "Form name: " << obj.getName()
        << "; isSigned:" << obj.getIsSigned()
        << "; required Grade to sign: " << obj.getReqGradeToSign()
        << "; required Grade to execute: " << obj.getReqGradeToExecute();
    return (out);
}

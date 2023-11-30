#include "AForm.h"
#include "Bureaucrat.h"
#include <iostream>

AForm::AForm(const std::string name, int reqGradeToExecute,
             int reqGradeToSign) :
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

AForm::AForm() : _reqGradeToExecute(1), _reqGradeToSign(1) {}

AForm::AForm(const AForm &obj) :
    _name(obj._name),
    _isSigned(obj._isSigned),
    _reqGradeToExecute(obj._reqGradeToExecute),
    _reqGradeToSign(obj._reqGradeToSign)
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

int AForm::getReqGradeToExecute() const
{
    return this->_reqGradeToExecute;
}

int AForm::getReqGradeToSign() const
{
    return this->_reqGradeToSign;
}

void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= this->getReqGradeToSign()) {
        this->_isSigned = true;
    }
    else {
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

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
    out << "Form name: " << obj.getName()
        << "; isSigned:" << obj.getIsSigned()
        << "; required Grade to Execute: " << obj.getReqGradeToExecute()
        << "; required Grade to sign: " << obj.getReqGradeToSign();
    return (out);
}

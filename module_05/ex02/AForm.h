#ifndef FORM_H
# define  FORM_H

#include <string>
#include "Bureaucrat.h"

class Bureaucrat;

class  AForm {
public:
    AForm(const std::string name, int reqGradeToSign, int reqGradeToExecute,
          std::string target);
    AForm(const AForm &obj);
    ~AForm();

    const std::string getName() const;
    bool getIsSigned() const;
    int getReqGradeToSign() const;
    int getReqGradeToExecute() const;
    std::string getTarget() const;
    void beSigned(Bureaucrat &b);
    virtual void beExecuted(Bureaucrat &b) const = 0;

    class GradeTooLowException;
    class GradeTooHighException;
    class UnsignedExecutionException;

private:
    const std::string _name;
    bool _isSigned;
    const int _reqGradeToSign;
    const int _reqGradeToExecute;
    const std::string _target;
    AForm();
    AForm &operator=(const AForm &obj);
};

class AForm::GradeTooLowException : public std::exception {
public:
    virtual const char *what() const throw();
};

class AForm::GradeTooHighException : public std::exception {
public:
    virtual const char *what() const throw();
};

class AForm::UnsignedExecutionException : public std::exception {
public:
    virtual const char *what() const throw();
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif

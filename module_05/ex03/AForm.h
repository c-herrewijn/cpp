#ifndef FORM_H
# define FORM_H

#include <string>
#include "Bureaucrat.h"

class Bureaucrat;

class AForm {
public:
    AForm(const std::string name, int reqGradeToSign, int reqGradeToExecute,
          std::string target);
    AForm(const AForm &obj);
    virtual ~AForm();

    const std::string getName() const;
    bool getIsSigned() const;
    int getReqGradeToSign() const;
    int getReqGradeToExecute() const;
    std::string getTarget() const;
    void beSigned(Bureaucrat const &signer);
    void beExecuted(Bureaucrat const &executor) const;
    class GradeTooLowException;
    class GradeTooHighException;
    class UnsignedExecutionException;

private:
    virtual void execute(Bureaucrat const &executor) const = 0;
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

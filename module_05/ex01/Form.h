#ifndef FORM_H
# define  FORM_H

#include <string>
#include "Bureaucrat.h"

class Bureaucrat;

class  Form {
public:
    Form(const std::string name, int reqGradeToExecute,
         int reqGradeToSign);
    ~Form();
    const std::string getName() const;
    bool getIsSigned() const;
    int getReqGradeToExecute() const;
    int getReqGradeToSign() const;
    void beSigned(Bureaucrat &b);
    class GradeTooLowException;
    class GradeTooHighException;

private:
    const std::string _name;
    bool _isSigned;
    const int _reqGradeToExecute;
    const int _reqGradeToSign;
    Form();
    Form(const Form &obj);
    Form &operator=(const Form &obj);
};

class Form::GradeTooLowException : public std::exception {
public:
    virtual const char *what() const throw();
};

class Form::GradeTooHighException : public std::exception {
public:
    virtual const char *what() const throw();
};

std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif

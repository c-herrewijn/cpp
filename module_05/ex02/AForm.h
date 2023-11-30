#ifndef FORM_H
# define  FORM_H

#include <string>
#include "Bureaucrat.h"

class Bureaucrat;

class  AForm {
public:
    AForm(const std::string name, int reqGradeToExecute,
          int reqGradeToSign);
    ~AForm();
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
    AForm();
    AForm(const AForm &obj);
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

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif

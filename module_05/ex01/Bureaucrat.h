#ifndef BUREAUCRAT_H
# define  BUREAUCRAT_H

#include <string>
#include <exception>
#include "Form.h"

class Form;

class  Bureaucrat {
public:
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void incrementGrade(void);
    void decrementGrade(void);
    void signForm(Form &form);
    class GradeTooLowException;
    class GradeTooHighException;

private:
    int grade;
    const std::string name;
    Bureaucrat();
    Bureaucrat(const Bureaucrat &obj);
    Bureaucrat &operator=(const Bureaucrat &obj);
};

class Bureaucrat::GradeTooLowException : public std::exception {
public:
    virtual const char *what() const throw();
};

class Bureaucrat::GradeTooHighException: public std::exception {
public:
    virtual const char *what() const throw();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif

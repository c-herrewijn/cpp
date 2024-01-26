#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <string>
#include <exception>
#include "AForm.h"

class AForm;

class Bureaucrat {
public:
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void incrementGrade(void);
    void decrementGrade(void);
    void signForm(AForm &form);
    void executeForm(AForm const &form);

private:
    int _grade;
    const std::string _name;
    Bureaucrat();
    Bureaucrat(const Bureaucrat &obj);
    Bureaucrat &operator=(const Bureaucrat &obj);
    class GradeTooLowException;
    class GradeTooHighException;
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

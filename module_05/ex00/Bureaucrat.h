#ifndef BUREAUCRAT_H
# define  BUREAUCRAT_H

#include <string>
#include <exception>

class  Bureaucrat {
public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &obj);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void incrementGrade(void);
    void decrementGrade(void);
    class GradeTooLowException;
    class GradeTooHighException;

private:
    int grade;
    const std::string name;
    Bureaucrat();
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

#ifndef INTERN_H
# define INTERN_H
# include <string>
# include <stdexcept>
# include "AForm.h"

class Intern {
public:
    Intern();
    Intern(const Intern &obj);
    ~Intern();
    Intern &operator=(const Intern &obj);
    AForm *makeForm(std::string formName, std::string formTarget);

private:
    static AForm *newPresidentialPardonForm(std::string formTarget);
    static AForm *newRobotomyRequestForm(std::string formTarget);
    static AForm *newShrubberyCreationForm(std::string formTarget);
    class InvalidFormnameException;
};

class Intern::InvalidFormnameException : public std::logic_error {
public:
    InvalidFormnameException(const std::string &message);
};

#endif

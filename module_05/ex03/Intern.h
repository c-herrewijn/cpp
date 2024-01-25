#ifndef INTERN_H
# define INTERN_H
# include <string>
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
};

#endif

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include "AForm.h"
# include <string>

class PresidentialPardonForm : public AForm {
public:
    ~PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    void execute(Bureaucrat const &executor) const;

private:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &obj);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
};

#endif

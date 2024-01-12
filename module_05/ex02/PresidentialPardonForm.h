#ifndef PRESIDENTIALPARDONFORM_H
# define  PRESIDENTIALPARDONFORM_H

# include "AForm.h"
# include <string>

class  PresidentialPardonForm : public AForm {
public:
    ~PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    void beExecuted(Bureaucrat &b) const;

private:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &obj);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &obj);

#endif

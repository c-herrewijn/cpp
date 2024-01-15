#ifndef SHRUBBERYCREATIONFORM_H
# define  SHRUBBERYCREATIONFORM_H

# include "AForm.h"
# include <string>

class  ShrubberyCreationForm : public AForm {
public:
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    void execute(Bureaucrat const &executor) const;

private:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &obj);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &obj);

#endif

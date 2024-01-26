#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include "AForm.h"
# include <string>

class RobotomyRequestForm : public AForm {
public:
    ~RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    void execute(Bureaucrat const &executor) const;

private:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &obj);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
};

#endif

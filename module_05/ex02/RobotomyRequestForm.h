#ifndef ROBOTOMYREQUESTFORM_H
# define  ROBOTOMYREQUESTFORM_H

# include "AForm.h"
# include <string>

class  RobotomyRequestForm : public AForm {
public:
    ~RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    void beExecuted(Bureaucrat &b) const;

private:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &obj);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &obj);

#endif

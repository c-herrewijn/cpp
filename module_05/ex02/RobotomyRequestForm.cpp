#include "RobotomyRequestForm.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <sys/time.h>

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
    AForm("Robotomy Request Form", 72, 45, target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm
    &obj) : AForm(obj)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=
(const RobotomyRequestForm &obj)
{
    (void)obj;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    (void)executor;
    // get random nr. between 0 and 1
    struct timeval currTime;
    gettimeofday(&currTime, NULL);
    srand(currTime.tv_usec);
    float randnr = ((float)std::rand() / (float)RAND_MAX);

    std::cout << "Drrrill drrrrrillll brrr krrr kggggr!!" << std::endl;
    if (randnr > 0.5) {
        std::cout << this->getTarget() << " has been robotomized successfully!"
                  << std::endl;
    }
    else {
        std::cout << "Robotomy for " << this->getTarget() << " has failed!"
                  << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &obj)
{
    out << "Form name: " << obj.getName() << std::endl
        << " - target: " << obj.getTarget() << std::endl
        << " - isSigned:" << obj.getIsSigned() << std::endl
        << " - required Grade to Execute: " << obj.getReqGradeToExecute() << std::endl
        << " - required Grade to sign: " << obj.getReqGradeToSign();
    return (out);
}

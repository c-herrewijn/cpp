#include "RobotomyRequestForm.h"
#include <iostream>
#include <string>
#include <chrono>
#include <random>

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
    unsigned int seed = std::chrono::steady_clock::now().time_since_epoch().count();
    srand(seed);

    std::cout << "Drrrill drrrrrillll brrr krrr kggggr!!" << std::endl;
    float randnr = ((float)std::rand() / (float)RAND_MAX);
    if (randnr > 0.5) {
        std::cout << this->getTarget() << " has been robotomized successfully!"
                  << std::endl;
    }
    else {
        std::cout << "Robotomy for " << this->getTarget() << " has failed!"
                  << std::endl;
    }
}

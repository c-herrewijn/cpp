#include <Harl.h>
#include <string>
#include <iostream>

Harl::t_complainMap Harl::complainMap[] = {
    {"DEBUG", &Harl::debug},
    {"INFO", &Harl::info},
    {"WARNING", &Harl::warning},
    {"ERROR", &Harl::error},
};

void Harl::complain(std::string level)
{
    size_t nrComplaints = sizeof(Harl::complainMap) / sizeof(Harl::t_complainMap);
    for (size_t i=0; i<nrComplaints; i++) {
        if (level == complainMap[i].level) {
            (this->*Harl::complainMap[i].complainFunction)();
        }
    }
}

void Harl::debug(void)
{
    std::cout << "Debug line" << std::endl;
}

void Harl::info(void)
{
    std::cout << "Info line" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "Warning line" << std::endl;
}

void Harl::error(void)
{
    std::cout << "Error line" << std::endl;
}

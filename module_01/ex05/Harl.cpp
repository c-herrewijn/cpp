#include <Harl.h>
#include <string>
#include <iostream>

void Harl::complain(std::string level)
{
    t_complainMap complainMap[] = {
        {"info", &Harl::info},
        {"debug", &Harl::debug},
        {"warning", &Harl::warning},
        {"error", &Harl::error},
    };
    size_t nr_complaints = sizeof(complainMap) / sizeof(t_complainMap);

    for (size_t i=0; i<nr_complaints; i++) {
        if (level == complainMap[i].level) {
            (this->*complainMap[i].complainFunction)();
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

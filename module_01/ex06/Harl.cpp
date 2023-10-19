#include <Harl.h>
#include <string>
#include <iostream>

Harl::t_complainMap Harl::complainMap[] = {
    {"DEBUG", &Harl::debug},
    {"INFO", &Harl::info},
    {"WARNING", &Harl::warning},
    {"ERROR", &Harl::error},
};

void Harl::complain(std::string complainLevelStr) const
{
    int complainLevel = Harl::getComplainLevelInt(complainLevelStr);
    if (complainLevel == -1) {
        std::cout << "Invalid complaint filter!" << std::endl
                  << "Valid options are: DEBUG, INFO, WARNING, ERROR" << std::endl;
        return ;
    }
    switch (complainLevel) {
    case 0:
        (this->*Harl::complainMap[complainLevel].complainFunction)();
        complainLevel++;
        [[fallthrough]];
    case 1:
        (this->*Harl::complainMap[complainLevel].complainFunction)();
        complainLevel++;
        [[fallthrough]];
    case 2:
        (this->*Harl::complainMap[complainLevel].complainFunction)();
        complainLevel++;
        [[fallthrough]];
    case 3:
        (this->*Harl::complainMap[complainLevel].complainFunction)();
        break;
    }
}

int Harl::getComplainLevelInt(std::string complainLevelStr) const
{
    int complainLevel = -1;
    size_t nrComplaints = sizeof(Harl::complainMap) / sizeof(Harl::t_complainMap);
    for (size_t i=0; i<nrComplaints; i++) {
        if (complainLevelStr == complainMap[i].level) {
            complainLevel = (int)i;
        }
    }
    return (complainLevel);
}

void Harl::debug(void) const
{
    std::cout << "[ DEBUG ]" << std::endl
              << "This is an extra debug line" << std::endl << std::endl;
}

void Harl::info(void) const
{
    std::cout << "[ INFO ]" << std::endl
              << "This is general information" << std::endl << std::endl;
}

void Harl::warning(void) const
{
    std::cout << "[ WARNING ]" << std::endl
              << "This your last warning!" << std::endl << std::endl;
}

void Harl::error(void) const
{
    std::cout << "[ ERROR ]" << std::endl
              << "Error! I want to speak to the manager!" << std::endl << std::endl;
}

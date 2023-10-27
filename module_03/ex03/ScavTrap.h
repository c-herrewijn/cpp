#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <ClapTrap.h>

class ScavTrap : public ClapTrap {
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap &obj);
    ~ScavTrap();
    ScavTrap &operator=(ScavTrap &obj);

    void guardGate();
    void attack(const std::string &target);
};

#endif

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <ClapTrap.h>

class ScavTrap : virtual public ClapTrap {
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap &obj);
    ~ScavTrap();
    ScavTrap &operator=(ScavTrap &obj);

    void guardGate();
    void attack(const std::string &target);

protected:
    static int _hitPointsBase;
    static int _energyPointsBase;
    static int _attackDamageBase;
};

#endif

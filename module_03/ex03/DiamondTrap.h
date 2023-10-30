#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include <ScavTrap.h>
#include <FragTrap.h>

class DiamondTrap : public ScavTrap, public FragTrap {
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap &obj);
    ~DiamondTrap();
    DiamondTrap &operator=(DiamondTrap &obj);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void whoAmI();

private:
    std::string _name;
};

#endif

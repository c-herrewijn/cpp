#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap {
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &obj);
    ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &obj);
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

protected:
    ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage);

private:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;
};

#endif

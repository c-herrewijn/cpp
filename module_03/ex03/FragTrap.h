#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <ClapTrap.h>

class FragTrap : virtual public ClapTrap {
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap &obj);
    ~FragTrap();
    FragTrap &operator=(FragTrap &obj);

    void highFivesGuys(void);
    void attack(const std::string &target);

protected:
    static int _hitPointsBase;
    static int _energyPointsBase;
    static int _attackDamageBase;
};

#endif

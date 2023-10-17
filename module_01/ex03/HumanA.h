#ifndef HUMANA_H
#define HUMANA_H

#include <Weapon.h>
#include <string>

class HumanA {
public:
    HumanA(std::string name, Weapon &weapon);
    void attack(void) const;

private:
    std::string name;
    Weapon &weapon;
};

#endif

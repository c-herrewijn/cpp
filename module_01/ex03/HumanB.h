#ifndef HUMANB_H
#define HUMANB_H

#include <Weapon.h>
#include <string>

class HumanB {
public:
    HumanB(std::string name);
    void attack(void) const;
    void setWeapon(Weapon &weapon);

private:
    std::string name;
    Weapon *weapon;
};

#endif
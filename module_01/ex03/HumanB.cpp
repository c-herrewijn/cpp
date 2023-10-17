#include <Weapon.h>
#include <HumanB.h>
#include <string>
#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {};

void HumanB::attack(void) const
{
    if (this->weapon) {
        std::cout << this->name << " attacks with their "
                  << this->weapon->getType() << std::endl;
    }
    else {
        std::cout << this->name << " attacks unarmed!" << std::endl;
    }
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

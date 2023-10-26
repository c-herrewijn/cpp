#include <ClapTrap.h>
#include <iostream>
#include <limits>

ClapTrap::ClapTrap() :
    _name("MrDefault"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{}

ClapTrap::ClapTrap(std::string name) :
    _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{}

ClapTrap::ClapTrap(const ClapTrap &obj) :
    _name(obj._name),
    _hitPoints(obj._hitPoints),
    _energyPoints(obj._energyPoints),
    _attackDamage(obj._attackDamage)
{}

ClapTrap::~ClapTrap() {}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
    this->_name = obj._name;
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->_hitPoints <= 0) {
        std::cout << this->_name << " can't attack because it is dead!"
                  << std::endl;
    }
    else if (this->_energyPoints <= 0) {
        std::cout << this->_name << " can't attack: no energy left!"
                  << std::endl;
    }
    else {
        this->_energyPoints--;
        std::cout << this->_name << " attacks " << target << " causing "
                  << this->_attackDamage << " points of damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints <= 0) {
        std::cout << this->_name << " can't repair itself because it is dead!"
                  << std::endl;
    }
    else if (this->_energyPoints <= 0) {
        std::cout << this->_name << " can't repair itself: no energy left!"
                  << std::endl;
    }
    else {
        this->_energyPoints--;
        this->_hitPoints += amount;
        std::cout << this->_name << " repairs itself and heals " << amount
                  << " hit points!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints <= 0) {
        std::cout << this->_name << " is hit for " << amount
                  << " damage, but is already dead!" << std::endl;
    }
    else {
        std::cout << this->_name << " is hit and takes " << amount
                  << " points of damage!" << std::endl;
        if ((long long int)amount >= (long long int)std::numeric_limits<int>::max()) {
            this->_hitPoints = 0;
        }
        else {
            this->_hitPoints -= (int)amount;
        }
        if (this->_hitPoints <= 0) {
            std::cout << this->_name << " died!" << std::endl;
        }
    }
}

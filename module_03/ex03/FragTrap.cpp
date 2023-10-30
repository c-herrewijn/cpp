#include <FragTrap.h>
#include <ClapTrap.h>

#include <iostream>
#include <string>

int FragTrap::_hitPointsBase = 100;
int FragTrap::_energyPointsBase = 100;
int FragTrap::_attackDamageBase = 30;

FragTrap::FragTrap() : ClapTrap("MrDefaultFrag", FragTrap::_hitPointsBase,
                                    FragTrap::_energyPointsBase,
                                    FragTrap::_attackDamageBase)
{
    std::cout << "FragTrap Constructor called..." << std::endl;
}

FragTrap::FragTrap(std::string name) :
    ClapTrap(name, FragTrap::_hitPointsBase, FragTrap::_energyPointsBase,
             FragTrap::_attackDamageBase)
{
    std::cout << "FragTrap Constructor called..." << std::endl;
}

FragTrap::FragTrap(FragTrap &obj)
{
    std::cout << "FragTrap Copy Constructor called..." << std::endl;
    *this = obj;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called..." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &obj)
{
    std::cout << "FragTrap Copy Assignment Operator called..." << std::endl;
    this->_name = obj._name;
    this->_hitPoints = obj._hitPoints;
    this->_energyPoints = obj._energyPoints;
    this->_attackDamage = obj._attackDamage;
    return *this;
}

void FragTrap::attack(const std::string &target)
{
    if (this->_hitPoints <= 0) {
        std::cout << "FragTrap " << this->_name << " can't attack because it is dead!"
                  << std::endl;
    }
    else if (this->_energyPoints <= 0) {
        std::cout << "FragTrap " << this->_name << " can't attack: no energy left!" <<
                  std::endl;
    }
    else {
        this->_energyPoints--;
        std::cout << "FragTrap " << this->_name << " attacks " << target << " causing "
                  << this->_attackDamage << " points of damage!" << std::endl;
    }
}

void FragTrap::highFivesGuys()
{
    if (this->_hitPoints <= 0) {
        std::cout << this->_name << " can't high five because it is dead!"
                  << std::endl;
    }
    else if (this->_energyPoints <= 0) {
        std::cout << this->_name << " can't high five: no energy left!"
                  << std::endl;
    }
    else {
        this->_energyPoints--;
        std::cout << this->_name << " suggests a high-five!" << std::endl;
    }
}

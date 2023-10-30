#include <ClapTrap.h>
#include <ScavTrap.h>
#include <FragTrap.h>
#include <DiamondTrap.h>

#include <iostream>
#include <string>

DiamondTrap::DiamondTrap() :
    ClapTrap("mrDefault_clap_name", FragTrap::_hitPointsBase,
             ScavTrap::_energyPointsBase, FragTrap::_attackDamageBase),
    _name("mrDefault")
{
    std::cout << "DiamondTrap Constructor called..." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :
    ClapTrap(name + "_clap_name", FragTrap::_hitPointsBase,
             ScavTrap::_energyPointsBase, FragTrap::_attackDamageBase),
    _name(name)
{
    std::cout << "DiamondTrap Constructor called..." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &obj)
{
    std::cout << "DiamondTrap Copy Constructor called..." << std::endl;
    *this = obj;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called..." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &obj)
{
    std::cout << "DiamondTrap Copy Assignment Operator called..." << std::endl;
    this->_name = obj._name;
    this->ClapTrap::_name = obj.ClapTrap::_name;
    this->_hitPoints = obj._hitPoints;
    this->_energyPoints = obj._energyPoints;
    this->_attackDamage = obj._attackDamage;
    return *this;
}

void DiamondTrap::attack(const std::string &target)
{
    this->ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
    this->ScavTrap::takeDamage(amount);
}

void DiamondTrap::beRepaired(unsigned int amount)
{
    this->ScavTrap::beRepaired(amount);
}

void DiamondTrap::whoAmI()
{
    if (this->_hitPoints <= 0) {
        std::cout << "DiamondTrap " << this->_name
                  << " can't tell its name because it is dead!" << std::endl;
    }
    else if (this->_energyPoints <= 0) {
        std::cout << "DiamondTrap " << this->_name
                  << " can't tell its name: no energy left!" << std::endl;
    }
    else {
        this->_energyPoints--;
        std::cout << "Name: " << this->_name << std::endl;
        std::cout << "ClapTrap name: " << this->ScavTrap::_name << std::endl;
    }
}

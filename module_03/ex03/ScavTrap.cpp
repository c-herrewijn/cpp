#include <ScavTrap.h>

#include <iostream>
#include <string>

int ScavTrap::_hitPointsBase = 100;
int ScavTrap::_energyPointsBase = 50;
int ScavTrap::_attackDamageBase = 20;

ScavTrap::ScavTrap() : ClapTrap("MrDefaultScav", ScavTrap::_hitPointsBase,
                                    ScavTrap::_energyPointsBase,
                                    ScavTrap::_attackDamageBase)
{
    std::cout << "ScavTrap Constructor called..." << std::endl;
}

ScavTrap::ScavTrap(std::string name) :
    ClapTrap(name, ScavTrap::_hitPointsBase, ScavTrap::_energyPointsBase,
             ScavTrap::_attackDamageBase)
{
    std::cout << "ScavTrap Constructor called..." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &obj)
{
    *this = obj;
    std::cout << "ScavTrap Copy Constructor called..." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called..." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &obj)
{
    std::cout << "ScavTrap Copy Assignment Operator called..." << std::endl;
    this->_name = obj._name;
    this->_hitPoints = obj._hitPoints;
    this->_energyPoints = obj._energyPoints;
    this->_attackDamage = obj._attackDamage;
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->_hitPoints <= 0) {
        std::cout << "ScavTrap " << this->_name << " can't attack because it is dead!"
                  << std::endl;
    }
    else if (this->_energyPoints <= 0) {
        std::cout << "ScavTrap " << this->_name << " can't attack: no energy left!" <<
                  std::endl;
    }
    else {
        this->_energyPoints--;
        std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing "
                  << this->_attackDamage << " points of damage!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    if (this->_hitPoints <= 0) {
        std::cout << this->_name << " can't guard the gate because it is dead!"
                  << std::endl;
    }
    else if (this->_energyPoints <= 0) {
        std::cout << this->_name << " can't guard the gate: no energy left!"
                  << std::endl;
    }
    else {
        this->_energyPoints--;
        std::cout << this->_name << " is guarding the gate!" << std::endl;
    }
}

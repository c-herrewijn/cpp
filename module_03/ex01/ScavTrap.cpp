#include <ScavTrap.h>

#include <iostream>
#include <string>

ScavTrap::ScavTrap() : ClapTrap("MrDefaultScav", 100, 50, 20)
{
    std::cout << "Default ScavTrap Constructor called..." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrap Constructor called..." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &obj) :
    ClapTrap(obj._name, obj._hitPoints, obj._energyPoints, obj._attackDamage)
{
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

void ScavTrap::guardGate()
{
    std::cout << this->_name << " is guarding the gate" << std::endl;
}

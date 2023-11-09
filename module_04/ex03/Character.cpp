#include "Character.h"
#include "AMateria.h"
#include "Ice.h"
#include "Cure.h"

#include <iostream>

AMateria *Character::floor[100] = {};

Character::Character() : name(""), inventory{} {}
Character::Character(std::string name) : name(name), inventory{} {}

Character::Character(const Character &obj) : inventory{}
{
    *this = obj;
}

Character::~Character()
{
    int nrSlotsInventory = sizeof(this->inventory) / sizeof(this->inventory[0]);
    for (int i=0; i<nrSlotsInventory; i++) {
        if (this->inventory[i] != NULL) {
            delete this->inventory[i];
        }
    }
}

Character &Character::operator=(const Character &obj)
{
    this->name = obj.name;

    // copy inventory, and delete current inventory
    int nrSlotsInventory = sizeof(this->inventory) / sizeof(this->inventory[0]);
    for (int i=0; i<nrSlotsInventory; i++) {
        if (this->inventory[i] != NULL) {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
        if (obj.inventory[i] != NULL) {
            if (obj.inventory[i]->getType() == "ice") {
                this->inventory[i] = new Ice();
            }
            if (obj.inventory[i]->getType() == "cure") {
                this->inventory[i] = new Cure();
            }
        }
    }
    return *this;
}

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *m)
{
    int nrSlotsInventory = sizeof(this->inventory) / sizeof(this->inventory[0]);
    for (int i=0; i<nrSlotsInventory; i++) {
        if (this->inventory[i] == m) {
            std::cout << "Error: materia " << m->getType()
                      << " is already equiped (in slot: " << i << ")" <<  std::endl;
            return ;
        }
    }
    for (int i=0; i<nrSlotsInventory; i++) {
        if (this->inventory[i] == NULL) {
            this->inventory[i] = m;
            std::cout << this->name << " equips " << m->getType() << " materia in slot: "
                      << i << std::endl;
            return ;
        }
    }
    std::cout << "Error: no space in inventory left! (materia not equiped)"
              << std::endl;
}

void Character::unequip(int idx)
{
    int nrSlotsInventory = sizeof(this->inventory) / sizeof(this->inventory[0]);
    if (idx < 0 || idx >= nrSlotsInventory) {
        std::cout << "Error: can not unequip, index [" << idx
                  << "] is not in range!" << std::endl;
    }
    else if (this->inventory[idx]==NULL) {
        std::cout << "Error: inventory at index [" << idx
                  << "] is already empty!" << std::endl;
    }
    else {
        int nrSlotsFloor = sizeof(this->floor) / sizeof(this->floor[0]);
        for (int i=0; i<nrSlotsFloor; i++) {
            if (this->floor[i] == NULL) {
                this->floor[i] = this->inventory[idx];
                this->inventory[idx]=NULL;
                std::cout << this->name << " drops materia of type '"
                          << this->floor[i]->getType() << "' on the floor!" << std::endl;
                return ;
            }
        }
        std::cout << "Error: can not unequip, no space on the floor" << std::endl;
    }
}

void Character::use(int idx, ICharacter &target)
{
    int nrSlotsInventory = sizeof(this->inventory) / sizeof(this->inventory[0]);
    if (idx >= 0 && idx < nrSlotsInventory) {
        if (this->inventory[idx] == NULL) {
            std::cout << "Error: no materia in slot " << idx << std::endl;
        }
        else {
            this->inventory[idx]->use(target);
        }
    }
    else {
        std::cout << "Error: slot " << idx << " is not in range!" << std::endl;
    }
}

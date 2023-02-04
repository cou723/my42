#include "Character.hpp"
Character::Character(const Character* c) {
    *this = c;
}

Character::Character(const std::string name) : _name(name) {
    for (size_t i = 0; i < this->_inventory_size; i++)
        this->_inventory[i] = 0;
}

Character::~Character() {}

Character* Character::operator=(const Character& c) {
    if (this != &c) {
        this->_name = c._name;
        for (size_t i = 0; i < this->_inventory_size; i++)
            this->_inventory[i] = c._inventory[i];
    }
    return this;
}

std::string const& Character::getName() const {
    return this->_name;
}

void Character::equip(AMateria* m) {
    for (size_t i = 0; i < this->_inventory_size; i++) {
        if (this->_inventory[i] == 0) {
            this->_inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 && idx >= this->_inventory_size)
        return;
    this->_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 && idx >= this->_inventory_size)
        return;
    if (this->_inventory[idx] == 0)
        return;
    this->_inventory[idx]->use(target);
}

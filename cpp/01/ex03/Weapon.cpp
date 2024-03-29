#include "Weapon.hpp"
#include <string>

Weapon::Weapon() {}

Weapon::Weapon(std::string type) : _type(type) {}

const std::string Weapon::getType() {
    return this->_type;
}

void Weapon::setType(std::string type) {
    this->_type = type;
}

Weapon::~Weapon() {}

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string name, Weapon &weapon)
    : _weapon(weapon), _name(name) {}

void HumanA::attack() {
    std::cout << this->_name << " attacks with their "
              << this->_weapon.getType() << std::endl;
}

void HumanA::setType(std::string type) { this->_weapon.setType(type); }

HumanA::~HumanA() {}

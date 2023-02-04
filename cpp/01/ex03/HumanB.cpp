#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name) : _weapon(NULL), _name(name) {}

void HumanB::attack() {
    std::cout << this->_name << " attacks with their "
              << this->_weapon->getType() << std::endl;
}

void HumanB::setType(std::string type) { this->_weapon->setType(type); }

void HumanB::setWeapon(Weapon &weapon) { this->_weapon = &weapon; }

HumanB::~HumanB() {}

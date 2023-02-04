#include "ScavTrap.hpp"
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap constructor " << std::endl;
    this->_hit_points = this->_default_hit_points;
    this->_energy_points = this->_default_energy_points;
    this->_attack_damage = this->_default_attack_damage;
}

ScavTrap::ScavTrap(const ScavTrap& s) : ClapTrap(s) {
    std::cout << "Scav copy constructor " << std::endl;
    *this = s;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& s) {
    std::cout << "Scav copy assignment operator " << std::endl;
    if (this != &s) {
        this->_name = s._name;
        this->_hit_points = s._hit_points;
        this->_energy_points = s._energy_points;
        this->_attack_damage = s._attack_damage;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor " << std::endl;
}

void ScavTrap::guardGate() {
    if (this->_hit_points == 0)
        std::cout
            << this->_name
            << " could not shift to Gate Keeper Mode because hit points were 0."
            << std::endl;
    else if (this->_energy_points == 0)
        std::cout << this->_name
                  << " could not shift to Gate Keeper Mode because energy "
                     "points were 0."
                  << std::endl;
    else
        std::cout << "<< Gate Keeper Mode >>" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->_hit_points == 0)
        std::cout << this->_name
                  << " could not attack because hit points were 0."
                  << std::endl;
    else if (this->_energy_points == 0)
        std::cout << this->_name
                  << " could not attack because energy points were 0."
                  << std::endl;
    else {
        std::cout << "ScavTrap " << this->_name << " attacks " << target
                  << ", causing " << this->_attack_damage
                  << " points of damage!" << std::endl;
        this->_energy_points -= 1;
    }
}

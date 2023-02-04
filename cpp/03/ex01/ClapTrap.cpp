#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name)
    : _name(name),
      _hit_points(this->_default_hit_points),
      _energy_points(this->_default_energy_points),
      _attack_damage(this->_default_attack_damage) {
    std::cout << "ClapTrap constructor " << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c) {
    std::cout << "ClapTrap copy constructor " << std::endl;
    *this = c;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor " << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& c) {
    if (&c != this) {
        this->_name = c._name;
        this->_attack_damage = c._attack_damage;
        this->_energy_points = c._energy_points;
        this->_hit_points = c._hit_points;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (this->_hit_points == 0)
        std::cout << this->_name
                  << " could not attack because hit points were 0."
                  << std::endl;
    else if (this->_energy_points == 0)
        std::cout << this->_name
                  << " could not attack because energy points were 0."
                  << std::endl;
    else {
        std::cout << "ClapTrap " << this->_name << " attacks " << target
                  << ", causing " << this->_attack_damage
                  << " points of damage!" << std::endl;
        this->_energy_points -= 1;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << this->_name << " took " << amount
              << " points of damage!" << std::endl;
    if (this->_hit_points >= amount)
        this->_hit_points -= amount;
    else
        this->_hit_points = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hit_points == 0)
        std::cout << this->_name
                  << " could not repair because hit points were 0."
                  << std::endl;
    else if (this->_energy_points == 0)
        std::cout << this->_name
                  << " could not repair because energy points were 0."
                  << std::endl;
    else {
        std::cout << this->_name << " repaired " << amount << " points."
                  << std::endl;
        this->_energy_points -= 1;
        this->_hit_points += amount;
    }
}

#include "DiamondTrap.hpp"
#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name), ScavTrap(name), FragTrap(name) {
    std::cout << "DiamondTrap constructor " << std::endl;
    this->_name = name;
    this->ClapTrap::_name = name + "_clap_name";
    this->_hit_points = FragTrap::_default_hit_points;
    this->_energy_points = ScavTrap::_default_energy_points;
    this->_attack_damage = FragTrap::_default_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& d)
    : ClapTrap(d), ScavTrap(d), FragTrap(d) {
    std::cout << "DiamondTrap copy constructor " << std::endl;
    *this = d;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& d) {
    std::cout << "DiamondTrap copy assignment operator " << std::endl;
    if (this != &d) {
        this->_name = d._name;
        this->ClapTrap::_name = d.ClapTrap::_name;
        this->_hit_points = d._hit_points;
        this->_energy_points = d._energy_points;
        this->_attack_damage = d._attack_damage;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor " << std::endl;
}

void DiamondTrap::whoAmI() {
    if (this->_hit_points == 0) {
        std::cout << this->_name
                  << " could not whoAmI() because hit points were 0."
                  << std::endl;
        return;
    }
    if (this->_energy_points == 0) {
        std::cout << this->_name
                  << " could not whoAmI() because energy points were 0."
                  << std::endl;
        return;
    }
    std::cout << this->_name << " " << this->ClapTrap::_name << std::endl;
}

void DiamondTrap::displayAllStatus() const {
    std::cout << "NAME : " << this->_name << " ,C_NAME : " << this->ClapTrap::_name
              << " ,HP : " << this->_hit_points << " ,EP : " << this->_energy_points
              << " ,AD : " << this->_attack_damage << std::endl;
}
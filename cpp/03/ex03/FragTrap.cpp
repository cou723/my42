#include "FragTrap.hpp"
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

FragTrap::FragTrap(std::string name)
    : ClapTrap(name,
               this->_default_hit_points,
               this->_default_energy_points,
               this->_default_attack_damage) {
    std::cout << "FragTrap constructor " << std::endl;
}

FragTrap::FragTrap(const FragTrap& f) : ClapTrap(f) {
    std::cout << "FragTrap copy constructor " << std::endl;
    *this = f;
}

FragTrap& FragTrap::operator=(const FragTrap& f) {
    std::cout << "FragTrap assignment operator " << std::endl;
    if (this != &f) {
        this->_name = f._name;
        this->_hit_points = f._hit_points;
        this->_energy_points = f._energy_points;
        this->_attack_damage = f._attack_damage;
    }
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor " << std::endl;
}

void FragTrap::highFivesGuys() {
    if (this->_hit_points == 0) {
        std::cout << this->_name
                  << " could not highFiveGuys() because hit points were 0."
                  << std::endl;
        return;
    }
    if (this->_energy_points == 0) {
        std::cout << this->_name
                  << " could not highFiveGuys() because energy points were 0."
                  << std::endl;
        return;
    }
    std::string five;

    std::cout << "FragTrap " << this->_name
              << " requests a high five!(press enter to high five)";
    std::getline(std::cin, five);
}
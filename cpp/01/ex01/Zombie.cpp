#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie() {}

void Zombie::announce() {
    std::cout << this->_name << ": BraiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) { this->_name = name; }

Zombie::~Zombie() {
    std::cout << "delete \"" << this->_name << "\"" << std::endl;
}

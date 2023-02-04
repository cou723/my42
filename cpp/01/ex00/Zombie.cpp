#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(std::string name) { this->_name = name; }

void Zombie::announce() {
    std::cout << this->_name << ": BraiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
    std::cout << "delete \"" << this->_name << "\"" << std::endl;
}

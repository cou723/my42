#include "Animal.hpp"
#include <iostream>
Animal::Animal() {
    std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const Animal& a) {
    std::cout << "Animal copy constructor" << std::endl;
    *this = a;
}

Animal::~Animal() {
    std::cout << "Animal destructor" << std::endl;
}

Animal& Animal::operator=(const Animal& a) {
    this->_type = a._type;
    return *this;
}

std::string Animal::getType() const {
    return this->_type;
}
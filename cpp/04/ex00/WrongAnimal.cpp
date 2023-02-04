#include "WrongAnimal.hpp"
#include <iostream>
WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a) {
    std::cout << "WrongAnimal copy constructor" << std::endl;
    *this = a;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a) {
    this->_type = a._type;
    return *this;
}

std::string WrongAnimal::getType() const {
    return this->_type;
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal \"Default makeSound\"" << std::endl;
}
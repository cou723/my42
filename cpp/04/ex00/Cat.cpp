#include "Cat.hpp"
#include <iostream>
Cat::Cat() : Animal() {
    std::cout << "Cat default constructor" << std::endl;
    this->_type = "Cat";
}

Cat::Cat(const Cat& c) : Animal(c) {
    std::cout << "Cat copy constructor" << std::endl;
    *this = c;
}

Cat::~Cat() {
    std::cout << "Cat destructor" << std::endl;
}

Cat& Cat::operator=(const Cat& c) {
    this->_type = c._type;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Cat \"...\"" << std::endl;
}
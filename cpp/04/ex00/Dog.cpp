#include "Dog.hpp"
#include <iostream>
Dog::Dog() : Animal() {
    std::cout << "Dog default constructor" << std::endl;
    this->_type = "Dog";
}

Dog::Dog(const Dog& d) : Animal(d) {
    std::cout << "Dog copy constructor" << std::endl;
    *this = d;
}

Dog::~Dog() {
    std::cout << "Dog destructor" << std::endl;
}

Dog& Dog::operator=(const Dog& d) {
    this->_type = d._type;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "DOG \"DOG!!\"" << std::endl;
}
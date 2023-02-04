#include "Dog.hpp"
#include <iostream>
#include "Brain.hpp"
Dog::Dog() : Animal() {
    std::cout << "Dog default constructor" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(const Dog& d) : Animal(d) {
    std::cout << "Dog copy constructor" << std::endl;
    *this = d;
}

Dog::~Dog() {
    std::cout << "Dog destructor" << std::endl;
    delete this->_brain;
}

Dog& Dog::operator=(const Dog& d) {
    this->_type = d._type;
    this->_brain = new Brain(*d._brain);
    return *this;
}

void Dog::makeSound() const {
    std::cout << "DOG \"DOG!!\"" << std::endl;
}

const Brain* Dog::getBrain() const{
    return this->_brain;
}

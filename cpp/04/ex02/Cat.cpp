#include "Cat.hpp"
#include <iostream>
#include "Brain.hpp"
Cat::Cat() : Animal() {
    std::cout << "Cat default constructor" << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(const Cat& c) : Animal(c) {
    std::cout << "Cat copy constructor" << std::endl;
    *this = c;
    this->_brain = new Brain(*c._brain);
}

Cat::~Cat() {
    std::cout << "Cat destructor" << std::endl;
    delete this->_brain;
}

Cat& Cat::operator=(const Cat& c) {
    this->_type = c._type;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Cat \"...\"" << std::endl;
}

const Brain* Cat::getBrain() const{
    return this->_brain;
}

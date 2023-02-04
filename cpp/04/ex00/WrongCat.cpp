#include "WrongCat.hpp"
#include <iostream>
WrongCat::WrongCat() : WrongAnimal() {
    std::cout << "WrongCat default constructor" << std::endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& c) : WrongAnimal(c) {
    std::cout << "WrongCat copy constructor" << std::endl;
    *this = c;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& c) {
    this->_type = c._type;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat\"...\"" << std::endl;
}
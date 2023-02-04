#include "Ice.hpp"
#include <iostream>
#include "AMateria.hpp"
Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& i) : AMateria(i) {
    *this = i;
}
Ice::~Ice() {}

Ice* Ice::operator=(const Ice& i) {
    if (this != &i) {
        this->_type = i._type;
    }
    return this;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"
              << std::endl;
}
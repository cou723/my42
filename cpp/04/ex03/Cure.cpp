#include "Cure.hpp"
#include <iostream>
#include "AMateria.hpp"
Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& i) : AMateria(i) {
    *this = i;
}
Cure::~Cure() {}

Cure* Cure::operator=(const Cure& i) {
    if (this != &i) {
        this->_type = i._type;
    }
    return this;
}
AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
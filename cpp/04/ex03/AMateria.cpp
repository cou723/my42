#include "AMateria.hpp"
#include <iostream>
AMateria::AMateria() : _type("") {}
AMateria::AMateria(std::string const& type) : _type(type) {}
AMateria::AMateria(const AMateria& am) {
    *this = am;
}
AMateria* AMateria::operator=(const AMateria& am) {
    if (this != &am) {
        this->_type = am._type;
    }
    return this;
}
AMateria::~AMateria() {}

std::string const& AMateria::getType() const{
    return this->_type;
}

void AMateria::use(ICharacter& target){
    std::cout << target.getName() <<std::endl;
}
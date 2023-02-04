#include "MateriaSource.hpp"
MateriaSource::MateriaSource() {
    for (size_t i = 0; i < this->_materia_limit; i++)
        this->_materia[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& ms) {
    *this = ms;
}

MateriaSource* MateriaSource::operator=(const MateriaSource& ms) {
    if (this != &ms) {
        for (size_t i = 0; i < this->_materia_limit; i++)
            this->_materia[i] = ms._materia[i];
    }
    return this;
}

MateriaSource::~MateriaSource() {
    for (size_t i = 0; i < this->_materia_limit; i++) {
        delete this->_materia[i];
    }
}

void MateriaSource::learnMateria(AMateria* am) {
    for (size_t i = 0; i < this->_materia_limit; i++) {
        if (this->_materia[i] == 0) {
            this->_materia[i] = am;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    for (size_t i = 0; i < this->_materia_limit; i++) {
        if (this->_materia[i] != 0 && this->_materia[i]->getType() == type)
            return this->_materia[i];
    }
    return 0;
}
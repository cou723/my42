#ifndef I_MATERIA_SOURCE_H
#define I_MATERIA_SOURCE_H
#include "AMateria.hpp"
#include<string>
class IMateriaSource {
   public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif /* I_MATERIA_SOURCE_H */

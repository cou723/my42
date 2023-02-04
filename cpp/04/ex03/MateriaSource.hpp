// #ifndef MATERIA_SOURCE_H
// #define MATERIA_SOURCE_H
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
class MateriaSource : virtual public IMateriaSource {
   private:
    static const int _materia_limit = 4;
    AMateria* _materia[_materia_limit];

   public:
    MateriaSource();
    MateriaSource(const MateriaSource& ms);
    virtual ~MateriaSource();
    MateriaSource* operator=(const MateriaSource& ms);

    void learnMateria(AMateria* am);
    AMateria* createMateria(std::string const& type);
};

// #endif /* MATERIA_SOURCE_H */

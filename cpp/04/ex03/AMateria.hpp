#ifndef A_MATERIA_H
#define A_MATERIA_H
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
   protected:
    std::string _type;

   public:
    AMateria();
    AMateria(std::string const& type);
    AMateria(const AMateria& am);
    AMateria* operator=(const AMateria& am);
    virtual ~AMateria();

    std::string const& getType() const;  // Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif /* A_MATERIA_H */

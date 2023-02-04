#ifndef ICE_H
#define ICE_H
#include "AMateria.hpp"
class Ice : virtual public AMateria {
   public:
    Ice();
    Ice(const Ice& i);
    ~Ice();
    Ice* operator=(const Ice& i);

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif /* ICE_H */

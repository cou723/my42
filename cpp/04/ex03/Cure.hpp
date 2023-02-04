#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"
class Cure : virtual public AMateria {
   public:
    Cure();
    Cure(const Cure& i);
    ~Cure();
    Cure* operator=(const Cure& i);

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif /* CURE_H */

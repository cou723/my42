#ifndef WRONG_CAT_H
#define WRONG_CAT_H
#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal {
   public:
    WrongCat();
    WrongCat(const WrongCat& d);
    ~WrongCat();
    WrongCat& operator=(const WrongCat& d);

    void makeSound() const;
};

#endif /* WRONG_CAT_H */

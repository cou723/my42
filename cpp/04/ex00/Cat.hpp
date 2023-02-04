#ifndef CAT_H
#define CAT_H
#include "Animal.hpp"
class Cat : public Animal {
   public:
    Cat();
    Cat(const Cat& d);
    ~Cat();
    Cat& operator=(const Cat& d);

    virtual void makeSound() const;
};

#endif /* CAT_H */

#ifndef DOG_H
#define DOG_H
#include "Animal.hpp"
class Dog : public Animal {
   public:
    Dog();
    Dog(const Dog& d);
    ~Dog();
    Dog& operator=(const Dog& d);

    virtual void makeSound() const;
};

#endif /* DOG_H */

#ifndef DOG_H
#define DOG_H
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal {
   private:
    Brain* _brain;

   public:
    Dog();
    Dog(const Dog& d);
    ~Dog();
    Dog& operator=(const Dog& d);

    virtual void makeSound() const;
    const Brain* getBrain() const;
};

#endif /* DOG_H */

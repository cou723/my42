#ifndef CAT_H
#define CAT_H
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal {
   private:
    Brain* _brain;

   public:
    Cat();
    Cat(const Cat& d);
    ~Cat();
    Cat& operator=(const Cat& d);

    virtual void makeSound() const;
    const Brain* getBrain() const;
};

#endif /* CAT_H */

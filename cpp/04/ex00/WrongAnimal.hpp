 #ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H
#include <string>
class WrongAnimal {
   protected:
    std::string _type;

   public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& a);
    ~WrongAnimal();
    WrongAnimal& operator=(const WrongAnimal& a);

    std::string getType() const;
    void makeSound() const;
};

#endif /* WRONG_ANIMAL_H */

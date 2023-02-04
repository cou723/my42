#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define ARRAY_COUNT 10

int main() {
    std::cout << "-- subject test (memory leaks test) --" << std::endl;
    {
        Animal* A[ARRAY_COUNT];
        for (size_t i = 0; i < ARRAY_COUNT / 2; i++)
            A[i] = new Dog();
        for (size_t i = ARRAY_COUNT / 2; i < ARRAY_COUNT; i++)
            A[i] = new Cat();
        for (size_t i = 0; i < ARRAY_COUNT; i++)
            delete A[i];
    }
    std::cout << std::endl << "-- deep copy dog test --" << std::endl;
    {
        Dog d1;
        Dog d2(d1);
        std::cout << d1.getBrain() << std::endl;
        std::cout << d2.getBrain() << std::endl;
    }
    std::cout << std::endl << "-- deep copy cat test --" << std::endl;
    {
        Cat c1;
        Cat c2(c1);
        std::cout << c1.getBrain() << std::endl;
        std::cout << c2.getBrain() << std::endl;
    }
    // Animal a; cannot declare variable ‘a’ to be of abstract type ‘Animal’
    return 0;
}
#include "Zombie.hpp"
#include <iostream>

int main() {
    Zombie *zombies;
    try {
        zombies = zombieHorde(5, "Bob");
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        zombies[i].announce();
    }
    delete[] zombies;
    return 0;
}

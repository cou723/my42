#include "Zombie.hpp"
int main() {
    Zombie *zombie = newZombie("Zombie");
    zombie->announce();
    delete zombie;
    randomChump("Random Zombie");
    return 0;
}

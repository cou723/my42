#include <iostream>
#include <string>
#include "FragTrap.hpp"

void display_message(std::string s) {
    std::cout << "--" << s << "--" << std::endl;
}

int main() {
     {
        display_message("-- Constructor test --");
        FragTrap a;
        display_message("-- Named Constructor test --");
        FragTrap b("Name");
        display_message("-- Copy Constructor test --");
        FragTrap c(b);
        display_message("-- Assignment Constructor test --");
        a = c;
    }
    display_message("");

    FragTrap f("Bob");
    display_message("Attack Test");
    f.attack("Alice");
    display_message("Take Damage Test");
    f.takeDamage(2);
    display_message("Be Repaired Test");
    f.beRepaired(1);
    display_message("high fives guys test");
    f.highFivesGuys();
    display_message("Test to see if energy points can be reduced to zero.");
    for (size_t i = 0; i < 100; i++)
        f.beRepaired(1);
    display_message("Test to see if nothing can be done when energy points run out.");
    f.attack("Alice");
    f.beRepaired(1);
    f.highFivesGuys();
    display_message("Test to see if you cannot do anything once you run out of hit points.");
    f.takeDamage(1000);
    f.attack("Alice");
    f.beRepaired(1);
    f.highFivesGuys();
    return 0;
}
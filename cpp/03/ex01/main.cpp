#include <iostream>
#include <string>
#include "ScavTrap.hpp"

void display_message(std::string s) {
    std::cout << "--" << s << "--" << std::endl;
}

int main() {
    {
        display_message("-- Constructor test --");
        ScavTrap a;
        display_message("-- Named Constructor test --");
        ScavTrap b("Name");
        display_message("-- Copy Constructor test --");
        ScavTrap c(b);
        display_message("-- Assignment Constructor test --");
        a = c;
    }
    display_message("");

    ScavTrap s("Bob");
    display_message("Attack Test");
    s.attack("Alice");
    display_message("Take Damage Test");
    s.takeDamage(2);
    display_message("Be Repaired Test");
    s.beRepaired(1);
    display_message("gate mode test");
    s.guardGate();
    display_message("Test to see if energy points can be reduced to zero.");
    for (size_t i = 0; i < 47; i++)
        s.beRepaired(1);
    display_message("Test to see if nothing can be done when energy points run out.");
    s.attack("Alice");
    s.beRepaired(1);
    s.guardGate();
    display_message("Test to see if you cannot do anything once you run out of hit points.");
    s.takeDamage(1000);
    s.attack("Alice");
    s.beRepaired(1);
    s.guardGate();
    return 0;
}
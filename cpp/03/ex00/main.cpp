#include <iostream>
#include <string>
#include "ClapTrap.hpp"

void display_message(std::string s) {
    std::cout << "--" << s << "--" << std::endl;
}

int main() {
    {
        display_message("Constructor test");
        ClapTrap a;
        display_message("Named Constructor test");
        ClapTrap b("Name");
        display_message("Copy Constructor test");
        ClapTrap c(b);
        display_message("Assignment Constructor test");
        a = c;
    }
    display_message("");

    ClapTrap c("Bob");
    display_message("Attack Test");
    c.attack("Alice");
    display_message("Take Damage Test");
    c.takeDamage(2);
    display_message("Be Repaired Test");
    c.beRepaired(1);
    display_message("Test to see if energy points can be reduced to zero.");
    c.beRepaired(1);
    c.beRepaired(1);
    c.beRepaired(1);
    c.beRepaired(1);
    c.beRepaired(1);
    c.beRepaired(1);
    c.beRepaired(1);
    display_message("Test to see if nothing can be done when energy points run out.");
    c.attack("Alice");
    c.beRepaired(1);
    display_message("Test to see if you cannot do anything once you run out of hit points.");
    c.takeDamage(1000);
    c.attack("Alice");
    c.beRepaired(1);
    return 0;
}
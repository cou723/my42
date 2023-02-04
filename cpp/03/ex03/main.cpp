#include <iostream>
#include <string>
#include "DiamondTrap.hpp"

void display_message(std::string s) {
    std::cout << "--" << s << "--" << std::endl;
}

int main() {
    {
        display_message("-- Constructor test --");
        DiamondTrap a;
        display_message("-- Named Constructor test --");
        DiamondTrap b("Name");
        display_message("-- Copy Constructor test --");
        DiamondTrap c(b);
        display_message("-- Assignment Constructor test --");
        a = c;
    }
    display_message("");

    DiamondTrap d("Bob");
    display_message("Attack Test");
    d.attack("Alice");
    display_message("Take Damage Test");
    d.takeDamage(2);
    display_message("Be Repaired Test");
    d.beRepaired(1);
    display_message("Test to see if energy points can be reduced to zero.");
    for (size_t i = 0; i < 47; i++)
        d.beRepaired(1);
    d.displayAllStatus();
    display_message("Test special");
    d.whoAmI();
    d.highFivesGuys();
    d.guardGate();
    display_message(
        "Test to see if nothing can be done when energy points run out.");
    d.beRepaired(1);
    d.displayAllStatus();
    d.attack("Alice");
    d.beRepaired(1);
    d.highFivesGuys();
    display_message(
        "Test to see if you can do anything once you run out of hit points.");
    d.takeDamage(1000);
    d.displayAllStatus();
    d.attack("Alice");
    d.beRepaired(1);
    d.highFivesGuys();
    return 0;
}
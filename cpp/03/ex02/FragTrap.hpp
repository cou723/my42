#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H

#include <string>
#include "ClapTrap.hpp"
class FragTrap : public ClapTrap {
   private:
    static const unsigned int _default_hit_points = 100;
    static const unsigned int _default_energy_points = 100;
    static const unsigned int _default_attack_damage = 30;

   public:
    FragTrap(std::string name = "Default");
    FragTrap(const FragTrap& f);
    FragTrap& operator=(const FragTrap& f);
    ~FragTrap();

    void highFivesGuys();
};

#endif /* FRAG_TRAP_H */

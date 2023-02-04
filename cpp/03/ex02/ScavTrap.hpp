#ifndef FFAA156B_8807_4C5A_843B_D89263F625AB_H
#define FFAA156B_8807_4C5A_843B_D89263F625AB_H
#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

#include <string>
#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap {
   private:
    static const unsigned int _default_hit_points = 100;
    static const unsigned int _default_energy_points = 50;
    static const unsigned int _default_attack_damage = 20;

   public:
    ScavTrap(std::string name = "Default");
    ScavTrap(const ScavTrap& s);
    ScavTrap& operator=(const ScavTrap& s);
    ~ScavTrap();

    void guardGate();
    void attack(const std::string& target);
};

#endif /* SCAV_TRAP_H */


#endif /* FFAA156B_8807_4C5A_843B_D89263F625AB_H */

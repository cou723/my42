#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <string>
class ClapTrap {
   private:
    const static unsigned int _default_hit_points = 10;
    const static unsigned int _default_energy_points = 10;
    const static unsigned int _default_attack_damage = 0;

   protected:
    std::string _name;
    unsigned int _hit_points;
    unsigned int _energy_points;
    unsigned int _attack_damage;

   public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& c);
    ClapTrap& operator=(const ClapTrap& c);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif /* CLAP_TRAP_H */

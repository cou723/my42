#ifndef DIAMOND_TRAP_H
#define DIAMOND_TRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
class DiamondTrap : public ScavTrap, public FragTrap {
   private:
    std::string _name;  // 再宣言して別の実体になっている

   public:
    DiamondTrap(const DiamondTrap& d);
    DiamondTrap(std::string name = "Default");
    DiamondTrap& operator=(const DiamondTrap& d);
    ~DiamondTrap();

    void whoAmI();
    void displayAllStatus() const;
};

#endif /* DIAMOND_TRAP_H */

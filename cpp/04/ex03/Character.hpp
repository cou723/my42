#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : virtual public ICharacter {
   private:
   static const int	_inventory_size = 4;
    std::string _name;
    AMateria* _inventory[_inventory_size];

   public:
    Character(const Character* c);
    Character(const std::string name = "");
    ~Character();
    Character* operator=(const Character& c);

    std::string const& getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif /* CHARACTER_H */

#ifndef DD2B4710_6D6A_49AB_BDF1_7954008F8A55_H
#define DD2B4710_6D6A_49AB_BDF1_7954008F8A55_H
#include "Weapon.hpp"
class HumanB {
  private:
    Weapon *_weapon;
    std::string _name;

  public:
    HumanB(std::string name);
    void attack();
    void setType(std::string type);
    void setWeapon(Weapon &weapon);
    ~HumanB();
};

#endif /* DD2B4710_6D6A_49AB_BDF1_7954008F8A55_H */

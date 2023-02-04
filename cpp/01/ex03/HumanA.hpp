#ifndef BED7C48A_00A5_45C7_9579_64E369CE2ABF_H
#define BED7C48A_00A5_45C7_9579_64E369CE2ABF_H
#include "Weapon.hpp"
class HumanA {
  private:
    Weapon &_weapon;
    std::string _name;

  public:
    HumanA(std::string name, Weapon &weapon);
    void attack();
    void setType(std::string type);
    ~HumanA();
};

#endif /* BED7C48A_00A5_45C7_9579_64E369CE2ABF_H */

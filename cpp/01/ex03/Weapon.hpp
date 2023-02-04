#ifndef A44A68F7_F904_42B7_90FB_57F4CAD585AF_H
#define A44A68F7_F904_42B7_90FB_57F4CAD585AF_H
#include <string>
class Weapon {
  private:
    std::string _type;

  public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();
    void setType(std::string type);
    const std::string getType();
};

#endif /* A44A68F7_F904_42B7_90FB_57F4CAD585AF_H */

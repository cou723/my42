#ifndef AD25F547_5334_4046_9474_748C401DA3F6_H
#define AD25F547_5334_4046_9474_748C401DA3F6_H

#include <string>

class Zombie {
  private:
    std::string _name;

  public:
    Zombie(std::string name);
    void announce();
    ~Zombie();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif /* AD25F547_5334_4046_9474_748C401DA3F6_H */
